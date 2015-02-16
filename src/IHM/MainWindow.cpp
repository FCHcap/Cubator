#include "MainWindow.h"
#include "ui_MainWindow.h"

// CUBATOR
#include <GraphicsPictureItem.h>

MainWindow *MainWindow::_window = NULL;

MainWindow::MainWindow() :
    QMainWindow(0),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    try{

        // initialize les attributs
        _actionSelected = 0;

        // initialize les barre de status
        QWidget * statusPosWidget = new QWidget();
        _statusPos.setParent(statusPosWidget);
        _statusPosGeo.setParent(statusPosWidget);

        QVBoxLayout * sbLayout = new QVBoxLayout;
        sbLayout->addWidget(&_statusPos, 1, Qt::AlignLeft);
        sbLayout->addWidget(&_statusPosGeo, 1, Qt::AlignLeft);
        statusPosWidget->setLayout(sbLayout);

        ui->statusbar->addPermanentWidget(statusPosWidget,1);
        ui->statusbar->addPermanentWidget(&_statusDepth, 1);

        // crée et lance le thread GPS
        _gps = new Gps();
        QThread * thread = new QThread;
        _gps->moveToThread(thread);

        connect(_gps, SIGNAL(exceptionLaunched(CubException)), this, SLOT(showError(CubException)));
        connect(this, SIGNAL(reloadDevicesSettings()), _gps, SLOT(reloadSettings()));
        connect(this, SIGNAL(enableGps(bool)), _gps, SLOT(setEnabled(bool)));
        connect(this, SIGNAL(destroyed()), _gps, SLOT(quit()));
        connect(thread, SIGNAL(started()), _gps, SLOT(run()));
        connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
        thread->start();

        // crée la scène
        _scene = new GraphicsScene(this);

        // connecte le GPS et la scène
        connect(_gps, SIGNAL(positionUpdated(QPointF)), _scene, SLOT(updateGpsPosition(QPointF)));

        // initialize le gestionnaire de cartes
        _mapManager.setScene(_scene);
        _mapManager.setParentWidget(this);
        _mapManager.applySettings();
        updateToolbarsMenus();

        // connecte le gestionnaire de carte
        connect(&_mapManager, SIGNAL(mapManagerUpdated()), this, SLOT(updateMapCb()));
        connect(&_mapManager, SIGNAL(mapUpdated()), this, SLOT(updateMapCb()));

        // initialize le gestionnaire de bateaux
        _boatManager.setScene(_scene);
        _boatManager.setParentWidget(this);
        _boatManager.applySettings();

        // connecte le gestionnaire de bateaux
        connect(&_boatManager, SIGNAL(boatManagerUpdated()), this, SLOT(updateBoatCb()));
        _boatManager.connectToGps(_gps);

        // paramètre la vue
        ui->graphicsView->setScene(_scene);
        ui->graphicsView->setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing | QPainter::HighQualityAntialiasing);
        ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground);

        // crée l'indicateur du gps
        QBoxLayout * layout = new QVBoxLayout(ui->graphicsView);
        GpsWidget * gpsWidget = new GpsWidget(ui->graphicsView);
        connect(_gps, SIGNAL(enabled(bool)), gpsWidget, SLOT(enable(bool)));
        connect(_gps, SIGNAL(positionUpdated(QPointF)), gpsWidget, SLOT(updatePosition(QPointF)));
        connect(_gps, SIGNAL(connected(bool)), gpsWidget, SLOT(connect(bool)));
        connect(_gps, SIGNAL(timeout()), gpsWidget, SLOT(timeout()));
        connect(_gps, SIGNAL(inconsistentData()), gpsWidget, SLOT(inconsistentData()));
        connect(_gps, SIGNAL(connected(bool)), gpsWidget, SLOT(setVisible(bool)));

        layout->addWidget(gpsWidget, 0, Qt::AlignRight);
        layout->addStretch();

        ui->graphicsView->scale(1, -1); // inverse l'axe y (0,0 en bas à gauche)

        // connecte la scène
        connect(_scene, SIGNAL(mousePositionUpdated(QPointF)), this, SLOT(updateMousePosition(QPointF)));
        connect(_scene, SIGNAL(mouseMeshDepthAdded(QString, double)), this, SLOT(addMouseMeshDepth(QString, double)));
        connect(_scene, SIGNAL(mouseMeshDepthNotFound()), this, SLOT(clearMeshDepth()));
        connect(_scene, SIGNAL(volumeShapeDefined(GraphicsVolumeItem*)), this, SLOT(calculateVolume(GraphicsVolumeItem*)));
        connect(_scene, SIGNAL(pointXYZAdded(QPointF)), this, SLOT(addPointXYZ(QPointF)));

        initCbToolBar();
        updateTableCb();

        selectTool(ui->actionMoveTool);

        // charge les paramètres de la barre de status
        Settings * settings = Settings::getInstance();
        SettingsStatusBar ssb = settings->settingsStatusBar();
        _sbPro = ssb.projection();
        _sbGpsFrm = ssb.gpsFormat();
    }
    catch(CubException &e){
        ErrorDialog::errorDialog(this, e);
    }
}

MainWindow::~MainWindow()
{
    disconnect(&_mapManager, SIGNAL(mapManagerUpdated()), this, SLOT(updateMapCb()));
    disconnect(&_mapManager, SIGNAL(mapUpdated()), this, SLOT(updateMapCb()));
    disconnect(_scene, SIGNAL(mousePositionUpdated(QPointF)), this, SLOT(updateMousePosition(QPointF)));
    disconnect(_scene, SIGNAL(mouseMeshDepthAdded(QString,double)), this, SLOT(addMouseMeshDepth(QString, double)));
    disconnect(_scene, SIGNAL(mouseMeshDepthNotFound()), this, SLOT(clearMeshDepth()));
    delete ui;
}

MainWindow *MainWindow::getInstance(){
    if(!_window) _window = new MainWindow();
    return _window;
}

void MainWindow::kill(){
    if(_window){
        delete _window;
        _window = 0;
    }
}

void MainWindow::initCbToolBar(){
    // Initialise les barres d'outils
    _cbMaps = new QComboBox(this);
    _cbLayers = new QComboBox(this);
    _cbIcons = new QComboBox(this);
    _cbBoats = new QComboBox(this);
    _cbTables = new QComboBox(this);

    _cbMaps->setMinimumWidth(130);
    _cbLayers->setMinimumWidth(130);
    _cbIcons->setMinimumWidth(130);
    _cbBoats->setMinimumWidth(130);
    _cbTables->setMinimumWidth(130);

    ui->toolBarCb->addWidget(new QLabel(TEXT20, this)); // Map
    ui->toolBarCb->addWidget(_cbMaps);
    ui->toolBarCb->addSeparator();
    ui->toolBarCb->addWidget(new QLabel(TEXT21, this)); // Layer
    ui->toolBarCb->addWidget(_cbLayers);
    ui->toolBarCb->addSeparator();
    ui->toolBarCb->addWidget(new QLabel(TEXT22, this)); // Icon
    ui->toolBarCb->addWidget(_cbIcons);
    ui->toolBarCb->addSeparator();
    ui->toolBarCb->addWidget(new QLabel(TEXT23, this)); // Boat
    ui->toolBarCb->addWidget(_cbBoats);
    ui->toolBarCb->addSeparator();
    ui->toolBarCb->addWidget(new QLabel(TEXT24, this)); // Table
    ui->toolBarCb->addWidget(_cbTables);

    connect(_cbMaps, SIGNAL(currentIndexChanged(QString)), this, SLOT(cbMapsIndexChanged(QString)));
    connect(_cbLayers, SIGNAL(currentIndexChanged(QString)), this, SLOT(cbLayersIndexChanged(QString)));
    connect(_cbIcons, SIGNAL(currentIndexChanged(QString)), this, SLOT(cbIconsIndexChanged(QString)));
    connect(_cbBoats, SIGNAL(currentIndexChanged(QString)), this, SLOT(cbBoatsIndexChanged(QString)));
}

void MainWindow::selectTool(QAction *action){
    triggerTool(action);
}

void MainWindow::updateMapCb(){

    QString mapSelected = _mapManager.mapSelectedWithStatusUpdate();

    // Met à jour la combobox '_cbMaps'
    _cbMaps->setUpdatesEnabled(0); // Désactive le traitement des évènements du cb pour éviter un déclenchement d'évènement redondant
    if(_lastMapsItems != _mapManager.mapsWithStatusUpdate()){
        _cbMaps->clear();
        _cbMaps->addItems(_mapManager.mapsWithStatusUpdate());
        _lastMapsItems = _mapManager.mapsWithStatusUpdate();
    }

    // Update the text selected
    if(_cbMaps->currentText() != mapSelected){
        int imaps = _cbMaps->findText(mapSelected);
        if(imaps != -1)
            _cbMaps->setCurrentIndex(imaps);
    }
    _cbMaps->setUpdatesEnabled(1);

    updateLayerCb();
    updateIconCb();
    updateBoatCb();

    updateToolbarsMenus();
}

void MainWindow::updateLayerCb(){
    GraphicsMap * mapSelected = _mapManager.item(_mapManager.mapSelected());
    if(mapSelected){
        if(_lastLayersItems != mapSelected->layers()){
            // update combobox
            _cbLayers->clear();
            _cbLayers->addItems(mapSelected->layers());
            _lastLayersItems = mapSelected->layers();
        }

        int ilayer = _cbLayers->findText(mapSelected->layerSelected());
        if(ilayer != -1){
            _cbLayers->setCurrentIndex(ilayer);
        }
        else{
            _cbLayers->setCurrentIndex(0);
        }
    }
    else{
        _cbLayers->clear();
    }

    updateToolbarsMenus();
}

void MainWindow::updateIconCb(){
    GraphicsMap * mapSelected = _mapManager.item(_mapManager.mapSelected());
    if(mapSelected){
        // update combobox
        _cbIcons->clear();
        _cbIcons->addItems(mapSelected->iconDefs());

        int iicon = _cbIcons->findText(mapSelected->iconDefSelected());
        if(iicon != -1) _cbIcons->setCurrentIndex(iicon);
    }
    else{
        _cbIcons->clear();
    }

    updateToolbarsMenus();
}

void MainWindow::updateBoatCb(){

    QStringList boatsNames = _boatManager.boats();
    _cbBoats->clear();
    _cbBoats->addItems(boatsNames);
    QString boatSelected = _boatManager.boatSelected();
    if(!boatSelected.isEmpty()){
        int iboat = _cbBoats->findText(boatSelected);
        if(iboat != -1) _cbBoats->setCurrentIndex(iboat);
    }
}

void MainWindow::updateTableCb(){

    Data * data = Data::getInstance();

    QStringList tablesNames = data->tables();
    QString tableSelected = _cbTables->currentText();

    _cbTables->clear();
    _cbTables->addItems(tablesNames);

    if(!tableSelected.isEmpty()){
        int itable = _cbTables->findText(tableSelected);
        if(itable != -1) _cbTables->setCurrentIndex(itable);
    }
}

void MainWindow::showSettingsDialog(){
    SettingsDialog dialog(this);
    if(dialog.exec() == QDialog::Accepted){
        if(dialog.devicesUpdated()){
            emit reloadDevicesSettings();
        }
        if(dialog.statusBarUpdated()){
            Settings * settings = Settings::getInstance();
            SettingsStatusBar ssb = settings->settingsStatusBar();
            _sbPro = ssb.projection();
            _sbGpsFrm = ssb.gpsFormat();
        }
    }
}

void MainWindow::updateToolbarsMenus(){

    bool enable = 0;

    GraphicsMap * mapSelected = _mapManager.item(_mapManager.mapSelected());

    bool mapEdited = 0;
    bool layerEditable = 0;


    // Met à jour les éléments graphiques liés aux cartes
    if(mapSelected) enable = _cbMaps->count() > 0;
    ui->actionMoveTool->setVisible(enable);
    ui->actionMapRemove->setEnabled(enable);
    ui->actionMapVisibility->setEnabled(enable);

    // Met à jour les éléments du menu liés aux calques
    enable = 0;
    if(mapSelected) enable = InfoMap::filepathToExtension(_mapManager.filepath(_mapManager.mapSelected())) == "pml";
    ui->actionMapLayerAdd->setEnabled(enable);
    ui->actionMapLayerEditable->setEnabled(enable);
    ui->actionMapLayerElevation->setEnabled(enable);
    ui->actionMapLayerOpacity->setEnabled(enable);
    ui->actionMapLayerRemove->setEnabled(enable);
    ui->actionMapLayerVisibility->setEnabled(enable);

    // Met à jour les outils de dessin
    if(mapSelected){
        GraphicsMapLayer * layerItem = mapSelected->layerItem(mapSelected->layerSelected());
        if(layerItem)
            if(layerItem->editable()) layerEditable = 1;
        mapEdited = mapSelected->edited();
    }
    ui->actionSelectTool->setVisible(layerEditable);
    ui->actionPointAddTool->setVisible(layerEditable);
    ui->actionPointXyAddTool->setVisible(layerEditable);
    ui->actionLineAddTool->setVisible(layerEditable);
    ui->actionPolylineAddTool->setVisible(layerEditable);
    ui->actionFillTool->setVisible(layerEditable);
    ui->actionTextAddTool->setVisible(layerEditable);
    ui->actionMeasureAddTool->setVisible(layerEditable);
    ui->actionPictureTool->setVisible(layerEditable);
    ui->actionColorSelectTool->setVisible(layerEditable);
    ui->actionLineWidthTool->setVisible(layerEditable);
    ui->actionFontTool->setVisible(layerEditable);
    ui->actionVolumeTool->setVisible(layerEditable);

    // Met à jour les outils de sauvegarde
    enable = 0;
    if(mapSelected) enable = mapSelected->edited();
    ui->actionMapSave->setEnabled(mapEdited);
    ui->actionMapSaveAs->setEnabled(mapEdited);
    ui->actionMapSaveAll->setEnabled(mapEdited);
    ui->actionSaveTool->setEnabled(mapEdited);
    ui->actionSaveAllTool->setEnabled(mapEdited);

    // Met à jour les outils de création d'icônes
    enable = 0;
    if(mapSelected){
        GraphicsMapLayer * layerItem = mapSelected->layerItem(mapSelected->layerSelected());
        if(layerItem)
            if(layerItem->editable() && _cbIcons->count() > 0) enable = 1;
    }
    ui->actionIconAddTool->setVisible(enable);
    ui->actionIconXYAddTool->setVisible(enable);
}

void MainWindow::showError(CubException exception){
    ErrorDialog::errorDialog(this, exception);
}

void MainWindow::triggerTool(QAction * action){

    CubException e;
    e.setMethod("MainWindow::triggerTool");

    GraphicsMap * map = _mapManager.item(_cbMaps->currentText());
    if(!map) return; //throw CubException(BRIEF00, ERROR24, "MainWindow::triggerTool");

    GraphicsMapLayer * layer = map->layerItem(_cbLayers->currentText());
    if(!layer) return; //throw CubException(BRIEF00, ERROR25, "MainWindow::triggerTool");

    action->setEnabled(0);

    try{
        if(action == ui->actionSaveTool){
            _mapManager.saveMap(_mapManager.mapSelected());
            return; // L'action sera mise à jour par la méthode : updateToolbarsMenus()
        }

        else if(action == ui->actionSaveAllTool){
            _mapManager.saveAllMaps();
            return; // L'action sera mise à jour par la méthode : updateToolbarsMenus()
        }
        else if(action == ui->actionColorSelectTool){
            QColor color = QColorDialog::getColor(_scene->paintColor(), this);
            if(color.isValid())
                _scene->setPaintColor(color);
        }

        else if(action == ui->actionLineWidthTool){
            int lineWidth = QInputDialog::getInt(this, TITLE08, MESSAGE02, _scene->lineWidth(), 1, 10);
            _scene->setLineWidth(lineWidth);
        }

        else if(action == ui->actionPictureTool){
            QString filepath = QFileDialog::getOpenFileName(this, TITLE23, getUserDocumentsLocation(), TEXT35+"(*.png)");
            if(!filepath.isEmpty()){
                GraphicsPictureItem * pictureItem = new GraphicsPictureItem();
                pictureItem->setFilepath(filepath);
                if(_scene){
                    pictureItem->setPos(ui->graphicsView->mapToScene(0, 0));
                }

                layer->addToLayer(pictureItem);
            }
        }

        else if(action == ui->actionFontTool){
            bool ok;
            QFont font = QFontDialog::getFont(&ok, _scene->font(), this);
            if(ok == true){
                _scene->setFont(font);
            }
        }

        else if(action == ui->actionIconXYAddTool){
            CreateIconDialog dialog(this);
            action->setEnabled(0);
            if(dialog.exec() == QDialog::Accepted){
                GraphicsMapIconDef * icondef = map->iconDefItem(_cbIcons->currentText());
                if(!icondef) throw CubException(BRIEF00, ERROR26, "MainWindow::triggerTool (actionIconXYAddTool)");

                GraphicsIconItem * icon = new GraphicsIconItem;
                icon->setIconDef(icondef);
                icon->setDate(dialog.date().toString("dd/MM/yyyy"));
                icon->setPos(dialog.position());
                icon->setRotation(dialog.rotation());
                layer->addToLayer(icon);
            }
        }

        else if(action == ui->actionSettings){
            showSettingsDialog();
        }

        else if(action == ui->actionMeshTool){
            MeshDialog dialog(this);
            if(dialog.init())
                dialog.exec();
        }

        else if(action == ui->actionPrintInPng){
            if(_scene){

                QImage image(ui->graphicsView->size()*3, QImage::Format_ARGB32);
                image.fill(Qt::white);

                QPainter painter(&image);
                painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing | QPainter::HighQualityAntialiasing);

                QString filepath = QFileDialog::getSaveFileName(this, TITLE22, getUserPicturesLocation(), TEXT34 + "(*.png)");

                if(!filepath.isEmpty()){
                    ui->graphicsView->render(&painter);
                    if(!image.save(filepath, "PNG", 100)){
                        ErrorDialog::errorDialog(this, BRIEF08, TEXT01 + filepath);
                    }
                }
            }
        }

        else goto bdrawing;
    }
    catch(CubException &e){
        ErrorDialog::errorDialog(this, e);
    }

    action->setEnabled(1);
    return;


    // Buttons of drawing
    bdrawing:

    Tool tool = NO;

    if(action == ui->actionMoveTool) {
        tool = TMOVE;
        ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);
    } else {
        if(action == ui->actionSelectTool) tool = TSELECT;
        else if(action == ui->actionPointAddTool) tool = TPOINT;
        else if(action == ui->actionPointXyAddTool) tool = TPOINTXY;
        else if(action == ui->actionLineAddTool) tool = TLINE;
        else if(action == ui->actionPolylineAddTool) tool = TPOLYLINE;
        else if(action == ui->actionTextAddTool) tool = TTEXT;
        else if(action == ui->actionMeasureAddTool) tool = TMEASURE;
        else if(action == ui->actionFillTool) tool = TPAINT;
        else if(action == ui->actionIconAddTool) tool = TICON;
        else if(action == ui->actionVolumeTool) tool = TVOLUME;
        else if(action == ui->actionPointXyzDbAddTool) tool = TPOINTXYZ;
        ui->graphicsView->setDragMode(QGraphicsView::NoDrag);
    }


    if(action == ui->actionSelectTool && _actionSelected != ui->actionSelectTool){layer->setSelectToolEnabled(1);}
    else if(_actionSelected == ui->actionSelectTool){layer->setSelectToolEnabled(0);}

    if(_actionSelected && _actionSelected != action) _actionSelected->setEnabled(1); // ré-active l'ancien outil grisé
    _actionSelected = action;

    _scene->selectTool(tool);
}

void MainWindow::triggerMenu(QAction * action){

    GraphicsMap * mapSelected = _mapManager.item(_mapManager.mapSelected());
    GraphicsMapLayer * layerSelected = 0;

    if(mapSelected){
        layerSelected = mapSelected->layerItem(mapSelected->layerSelected());
    }

    try{
        if(action == ui->actionFileExit){
            close();
            return;
        }
        else if(action == ui->actionMapNew || action == ui->actionMapAdd){
            bool ok = 0;

            while(!ok){
                try{
                    QString filepath;
                    (action == ui->actionMapNew) ? filepath = QFileDialog::getOpenFileName(this, TITLE03, getUserDocumentsLocation(), TEXT09+"(*.dxf *.pml)") : filepath = QFileDialog::getOpenFileName(this, "Open a map file", getUserDocumentsLocation(), "Map files (*.dxf *.pml)");
                    if(filepath.isNull()) return;

                    // si aucune extension n'est spécifiée, ajoute l'extension "pml" au path du fichier
                    if(InfoMap::filepathToExtension(filepath) != "pml") filepath = filepath + ".pml";

                    QString map = InfoMap::filepathToMap(filepath);

                    if(_mapManager.mapExists(map)) throw CubException(BRIEF20, ERROR19, "MainWindow::onMenuTriggered");

                    if(action == ui->actionMapNew){
                        _mapManager.newMap(filepath);
                        _mapManager.saveMap(map); // crée un nouveau fichier
                    }
                    else{
                        _mapManager.addMap(filepath);
                    }
                    ok = 1; // quitte la boucle
                }
                catch(const CubException &e){
                    ErrorDialog::errorDialog(this, e);
                }
            }
        }

        else if(action == ui->actionMapRemove){

            SelectItemDialog dialog(this);
            dialog.setItemsList(_mapManager.maps());
            dialog.setButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
            dialog.setWindowTitle(TITLE09);
            if(dialog.exec() == QDialog::Accepted){
                _mapManager.removeMap(dialog.itemSelected());
            }
            updateToolbarsMenus();
        }

        else if(action == ui->actionMapSave){

            _mapManager.saveMap(_mapManager.mapSelected());
        }

        else if(action == ui->actionMapSaveAs){

            _mapManager.saveMapAs();
        }

        else if(action == ui->actionMapSaveAll){
            _mapManager.saveAllMaps();
        }

        else if(action == ui->actionMapVisibility){
            QStringList maps = _mapManager.maps();
            QMap<QString, bool> mvis;

            foreach(QString map, maps){
                GraphicsMap * mapItem = _mapManager.item(map);
                mvis.insert(map, mapItem->isVisible());
            }

            CheckItemsDialog dialog(this);
            dialog.setItems(mvis);
            dialog.setWindowTitle(TITLE13);
            dialog.exec();
            mvis = dialog.items();
            foreach(QString map, mvis.keys()){
                GraphicsMap * mapItem = _mapManager.item(map);
                mapItem->setVisible(mvis.value(map));
            }
        }

        else if(action == ui->actionMapLayerAdd){
            QString name = QInputDialog::getText(this, TITLE11, TEXT25);
            if(name.isEmpty()) throw CubException(ERROR20, "", "MainWindow::onMenuTriggered");

            QString map = _mapManager.mapSelected();
            GraphicsMap * mapItem = _mapManager.item(map);
            if(mapItem->layerExists(name)) throw CubException(ERROR21, TEXT25 + name, "MainWindow::onMenuTriggered");
            mapItem->addLayer(name);
            updateLayerCb();
        }

        else if(action == ui->actionMapLayerRemove){
            QString map = _mapManager.mapSelected();
            GraphicsMap * mapItem = _mapManager.item(map);
            QStringList layers = mapItem->layers();
            SelectItemDialog dialog(this);
            dialog.setItemsList(layers);
            dialog.setWindowTitle(TITLE12);
            dialog.setButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
            if(dialog.exec() == QDialog::Accepted){
                mapItem->removeLayer(dialog.itemSelected());
            }
            updateLayerCb();
        }

        else if(action == ui->actionMapLayerVisibility){
            QString map = _mapManager.mapSelected();
            GraphicsMap * mapItem = _mapManager.item(map);
            QStringList layers = mapItem->layers();

            QMap<QString, bool> lvis;
            foreach(QString layer, layers){
                lvis.insert(layer, mapItem->layerIsVisible(layer));
            }

            CheckItemsDialog dialog(this);
            dialog.setItems(lvis);
            dialog.setWindowTitle(TITLE10);

            dialog.exec();
            lvis = dialog.items();
            foreach(QString layer, lvis.keys()){
                mapItem->setLayerVisibility(layer, lvis[layer]);
            }
            updateLayerCb();
        }

        else if(action == ui->actionMapLayerElevation){
            QString map = _mapManager.mapSelected();
            GraphicsMap * mapItem = _mapManager.item(map);
            QStringList layers = mapItem->layers();

            QMap<QString, int> lz;
            foreach(QString layer, layers){
                GraphicsMapLayer * item = mapItem->layerItem(layer);
                if(item)
                    lz.insert(layer, (int) item->zValue());
            }

            InputIntToStringDialog dialog(this);
            dialog.setLayers(lz);
            dialog.setDescription(MESSAGE03);
            if(dialog.exec() == QDialog::Accepted){
                lz = dialog.layers();
                foreach(QString layer, lz.keys()){
                    GraphicsMapLayer * item = mapItem->layerItem(layer);
                    if(item){
                        double zvalue = (double) lz[layer];
                        if(lz.value(layer) != item->zValue()){
                            item->setZValue(zvalue);
                        }
                    }
                }
            }
        }

        else if(action == ui->actionMapLayerOpacity){
            QString map = _mapManager.mapSelected();
            GraphicsMap * mapItem = _mapManager.item(map);
            QStringList layers = mapItem->layers();

            QMap<QString, int> lz;
            foreach(QString layer, layers){
                GraphicsMapLayer * item = mapItem->layerItem(layer);
                if(item)
                    lz.insert(layer, (int) (item->opacity() * 100));
            }

            InputIntToStringDialog dialog(this);
            dialog.setLayers(lz);
            dialog.setDescription(MESSAGE04);
            if(dialog.exec() == QDialog::Accepted){
                lz = dialog.layers();
                foreach(QString layer, lz.keys()){
                    GraphicsMapLayer * item = mapItem->layerItem(layer);
                    if(item){
                        if(lz.value(layer) != item->opacity()){
                            item->setOpacity((double) lz[layer] / 100);
                            mapItem->setEdited(1);
                        }
                    }
                }
            }
        }

        else if(action == ui->actionMapLayerEditable){
            QString map = _mapManager.mapSelected();
            QString extension = InfoMap::filepathToExtension(_mapManager.filepath(_mapManager.mapSelected()));
            if(extension != "pml"){
                QMessageBox::information(this, TITLE14, MESSAGE05);
                return;
            }
            GraphicsMap * mapItem = _mapManager.item(map);

            QStringList layers = mapItem->layers();

            QMap<QString, bool> ledt;
            foreach(QString layer, layers){
                ledt.insert(layer, mapItem->layerItem(layer)->editable());
            }

            CheckItemsDialog dialog(this);
            dialog.setItems(ledt);
            dialog.setWindowTitle(TITLE15);
            dialog.exec();
            ledt = dialog.items();
            foreach(QString layer, ledt.keys()){
                mapItem->layerItem(layer)->setEditable(ledt[layer]);
            }
            updateToolbarsMenus();
        }

        else if(action == ui->actionMapInsertIconDefinition){
            try{
                QString filepath = QFileDialog::getOpenFileName(this, TITLE16, getUserDocumentsLocation(), TEXT26+"(*.dxf *.pml)");
                if(filepath.isNull()) return;

                // If nothing extension specified, add the extension "pml" to filepath
                if(InfoMap::filepathToExtension(filepath) != "pml") filepath = filepath + ".pml";

                _mapManager.addIcon(filepath);
            }
            catch(const CubException &e){
                ErrorDialog::errorDialog(this, e);
            }
        }

        else if(action == ui->actionMapRemoveIconDefinition){
            GraphicsMap* map = _mapManager.item(_mapManager.mapSelected());
            if(!map) return;
            QStringList items = map->iconDefs();

            SelectItemDialog dialog(this);
            dialog.setItemsList(items);
            dialog.setButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

            if(dialog.exec() == QDialog::Accepted){
                QString itemSelected = dialog.itemSelected();
                map->removeIconDef(itemSelected);
            }
        }

        else if(action == ui->actionMapInsertMesh){
            GraphicsMap * map = _mapManager.item(_mapManager.mapSelected());
            if(!map) return;
            Data * data = Data::getInstance();
            QStringList items = data->tables();

            SelectItemDialog dialog(this);
            dialog.setItemsList(items);
            dialog.setButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

            if(dialog.exec() == QDialog::Accepted){
                GraphicsMapLayer * layer = map->layerItem(map->layerSelected());
                if(!layer) return;

                GraphicsMeshImageItem * meshItem = new GraphicsMeshImageItem;
                meshItem->setTableName(dialog.itemSelected());

                layer->addToLayer(meshItem);
            }
        }

        else if(action == ui->actionMapRemoveMesh){
            GraphicsMap * map = _mapManager.item(_mapManager.mapSelected());
            if(!map) return;
            QMap<QString, GraphicsMeshImageItem*> meshes = map->meshes();

            SelectItemDialog dialog(this);
            dialog.setItemsList(meshes.keys());
            dialog.setButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

            if(dialog.exec() == QDialog::Accepted){
                delete meshes[dialog.itemSelected()];
                map->setEdited(1);
            }
        }

        else if(action == ui->actionMapCenteringGps){
            if(ui->actionMapCenteringGps->isChecked())
                connect(_gps, SIGNAL(positionUpdated(QPointF)), ui->graphicsView, SLOT(updatePosition(QPointF)));
            else
                disconnect(_gps, SIGNAL(positionUpdated(QPointF)), ui->graphicsView, SLOT(updatePosition(QPointF)));
        }

        else if(action == ui->actionDbEditTables){
            DbTableEditDialog dialog(this);
            if(dialog.init()){
                dialog.exec();
                updateTableCb();
            }
        }

        else if(action == ui->actionDbShowTable){
            DbShowTableDialog dialog(this);
            if(dialog.init())
                dialog.exec();
        }

        else if(action == ui->actionDbAddFileXYZ){
            FileXyzReaderDialog dialog(this);
            if(dialog.init())
                dialog.exec();
        }

        else if(action == ui->actionDbConvertToNgf){
            ConvertToNgfDialog dialog(this);
            dialog.exec();
        }

        else if(action == ui->actionDevicesEnableGps){
            emit enableGps(ui->actionDevicesEnableGps->isChecked());
        }

        else if(action == ui->actionDevicesEnableSounder){
            emit enableSonar(ui->actionDevicesEnableSounder->isChecked());
        }

        else if(action == ui->actionToolsSettings){
            showSettingsDialog();
        }

        else if(action == ui->actionConvertMapFile){
            ConvertMapFileDialog dialog(this);
            dialog.exec();
        }
    }
    catch(const CubException &e){
        ErrorDialog::errorDialog(this, e);
    }
}

void MainWindow::cbMapsIndexChanged(QString map){
    if(map.isEmpty()) return;
    if(map[0] == '*') map.remove(0, 1);

    _mapManager.selectMap(map);
    _scene->setMap(_mapManager.item(map));
    updateLayerCb();
    updateIconCb();
}

void MainWindow::cbLayersIndexChanged(const QString &layer){
    if(layer.isEmpty()) return;
    QString mapSelected = _mapManager.mapSelected();
    GraphicsMap * mapItem = _mapManager.item(mapSelected);
    if(mapItem){
        mapItem->selectLayer(layer);

        // if the layer is not editable, disable drawing tool selected
        if(!mapItem->layerItem(layer)->editable()){
            selectTool(ui->actionMoveTool);
        }
    }
    updateToolbarsMenus();
}

void MainWindow::cbIconsIndexChanged(const QString &icon){
    if(icon.isEmpty()) return;
    _scene->setIcon(icon);
}

void MainWindow::cbBoatsIndexChanged(const QString &boat){
    if(boat.isEmpty()) return;
    _boatManager.selectBoat(boat);
}

void MainWindow::updateMousePosition(QPointF position){
    QString sPos = QString("X : %1 - Y : %2").arg(position.x(), 0, 'f', 4).arg(position.y(), 0, 'f', 4);
    _statusPos.setText(sPos);

    try{
        GeoData data = _geo.lambertToWGS84Geo(GeoVecteur(position.x(), position.y(), 0), _sbPro);
        data=data.toFormat(_sbGpsFrm);
        _statusPosGeo.setText(TEXT03+data.getLatitude()+" "+TEXT02+data.getLongitude());
    }
    catch(GeoException &e){
    }
}

void MainWindow::addMouseMeshDepth(QString tableName, double depth){
    QString sDepth = _statusDepth.text();
    if(!sDepth.isEmpty()) sDepth.append(" - ");
    sDepth.append(tableName + " : " + QString::number(depth, 'f', 4));
    _statusDepth.setText(sDepth);
}

void MainWindow::clearMeshDepth(){
    _statusDepth.clear();
}

void MainWindow::closeEvent(QCloseEvent *event){
    //_mapManager.removeAllMaps();
    QMainWindow::closeEvent(event);
}

void MainWindow::calculateVolume(GraphicsVolumeItem *item){

    VolumeCalculatorDialog dialog(this);
    dialog.setVolumeItem(item);
    dialog.exec();
    if(dialog.error() || !dialog.calculated()) delete item;
}

void MainWindow::addPointXYZ(QPointF position){

    QString tableSelected = _cbTables->currentText();

    if(!tableSelected.isEmpty()){
        QString filename = Data::vectorFileName(tableSelected);
        if(QFile::exists(Data::triangleFilename(tableSelected))){
            if(QMessageBox::question(this, TITLE01, QUESTION01, QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes){
                QFile::remove(Data::triangleFilename(tableSelected));
                QFile::remove(Data::gridFilename(tableSelected));
                QFile::remove(Data::imageFilename(tableSelected));
            }
            else return;
        }

        double height = QInputDialog::getDouble(this, TITLE02, TEXT00, 0, -DBL_MAX, DBL_MAX, 4);
        VectorsWriter writer(filename, 1);
        writer.writeVertex(DVertex(position.x(), position.y(), height));
    }
}
