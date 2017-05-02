#include "MeshDialog.h"
#include <Data.h>
#include "ui_MeshDialog.h"

#include <QMessageBox>

extern QString defaultConnection;

MeshDialog::MeshDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MeshDialog)
{

    ui->setupUi(this);
    _twp = 0;
    _iwp = 0;
    _vlp = 0;
    _tlp = 0;
    _vpxItem = 0;
    _verticesItem = 0;
    _trianglesItem = 0;

    _triangleSelected[0] = 0;
    _triangleSelected[1] = 0;
    _triangleSelected[2] = 0;

    // Crée la scène
    _scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(_scene);
    ui->graphicsView->scale(1, -1);
    ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground);

    ui->cbShowVertex->setChecked(0);
    ui->cbShowTriangles->setChecked(0);
    ui->cbShowImage->setChecked(1);

    ui->gbA->setVisible(0);
    ui->gbB->setVisible(0);
    ui->gbC->setVisible(0);

    ui->gbTriangle->setVisible(0);

    connect(ui->graphicsView, SIGNAL(scenePositionUpdated(QPointF)), this, SLOT(updateScenePosition(QPointF)));

    setWindowTitle(TITLE17);

    ui->progressBar->setVisible(0);
    ui->lProcessName->setVisible(0);
}

MeshDialog::~MeshDialog()
{
    removeItems();
    delete ui;
}

// Initialise la combobox
bool MeshDialog::init(){

    QStringList tables;

    try{
        Data *data = Data::getInstance();
        tables = data->tables();
    }
    catch(const CubException &e){
        ErrorDialog::errorDialog(this, e);
        return 0;
    }

    ui->cbTable->addItems(tables);
    return 1;
}


// Libère la mémoire allouée pour les sommets, triangles et l'image
void MeshDialog::removeItems(){

    if(_verticesItem){
        QList<QGraphicsItem*> childs = _verticesItem->childItems();
        for(int i=0; i<childs.size(); i++) delete childs[i];
        delete _verticesItem;
        _verticesItem = 0;
    }

    if(_trianglesItem){
        QList<QGraphicsItem*> childs = _trianglesItem->childItems();
        for(int i=0; i<childs.size(); i++) delete childs[i];
        delete _trianglesItem;
        _trianglesItem = 0;
    }

    if(_vpxItem){
        _scene->removeItem(_vpxItem);
        delete _vpxItem;
        _vpxItem = 0;
    }

    if(_triangleSelected[0]) {_scene->removeItem(_triangleSelected[0]); _triangleSelected[0] = 0;}
    if(_triangleSelected[1]) {_scene->removeItem(_triangleSelected[1]); _triangleSelected[1] = 0;}
    if(_triangleSelected[2]) {_scene->removeItem(_triangleSelected[2]); _triangleSelected[2] = 0;}
}

// Charge les sommets
void MeshDialog::loadVertices(){

    _vertex.clear();
    VerticesReader vreader(Data::vectorFileName(ui->cbTable->currentText()));
    while(!vreader.atEnd()){
        _vertex.append(vreader.readVertex());
    }
}

// Charge les triangles
void MeshDialog::loadTriangles(){

    DTriangleList *triangles = _vertex.triangles();
    triangles->clear();
    TrianglesReader treader(Data::triangleFilename(ui->cbTable->currentText()));
    while(!treader.atEnd()){
        triangles->append(treader.readTriangle());
    }
}

void MeshDialog::loadGrid(){

    DTGrid *grid = _vertex.grid();
    grid->clear();
    GridReader reader(Data::gridFilename(ui->cbTable->currentText()));
    grid->setBounds(reader.readBounds());
    while(!reader.atEnd())
        grid->append(reader.readGridItem());
}

// Lance le thread de triangulation
void MeshDialog::triangulate(){

    enableTools(0);

    Delaunay * dp = new Delaunay;
    //QThread * dt = new QThread;
    dp->setVertices(_vertex);

    //dp->connectToThread(dt);
    connect(dp, SIGNAL(levelUpdated(int)), ui->progressBar, SLOT(setValue(int)));
    connect(dp, SIGNAL(processNameUpdated(QString)), ui->lProcessName, SLOT(setText(QString)));
    connect(dp, SIGNAL(exceptionLaunched(CubException)), this, SLOT(showException(CubException)));
    connect(dp, SIGNAL(finished()), this, SLOT(launchProcess()));

    //dp->moveToThread(dt);
    //dt->start();
    dp->start();
}

void MeshDialog::createGrid(){
    enableTools(0);

    GridCalculatorProcess * gc = new GridCalculatorProcess;
    //QThread * gt = new QThread;
    gc->setVertexList(_vertex);
    //gc->connectToThread(gt);
    connect(gc, SIGNAL(levelUpdated(int)), ui->progressBar, SLOT(setValue(int)));
    connect(gc, SIGNAL(processNameUpdated(QString)), ui->lProcessName, SLOT(setText(QString)));
    connect(gc, SIGNAL(exceptionLaunched(CubException)), this, SLOT(showException(CubException)));
    connect(gc, SIGNAL(finished()), this, SLOT(launchProcess()));

    //gc->moveToThread(gt);
    //gt->start();
    gc->start();
}

// Lance le thread d'écriture des triangles
void MeshDialog::writeTriangles(){
    enableTools(0);

    TrianglesWriterProcess * twp = new TrianglesWriterProcess;
    //QThread * twt = new QThread;
    QString table = ui->cbTable->currentText();
    twp->setFilename(Data::triangleFilename(table));
    twp->setTrianglesList(*_vertex.triangles());
    //twp->connectToThread(twt);
    connect(twp, SIGNAL(levelUpdated(int)), ui->progressBar, SLOT(setValue(int)));
    connect(twp, SIGNAL(processNameUpdated(QString)), ui->lProcessName, SLOT(setText(QString)));
    connect(twp, SIGNAL(exceptionLaunched(CubException)), this, SLOT(showException(CubException)));
    connect(twp, SIGNAL(finished()), this, SLOT(launchProcess()));
    //twp->moveToThread(twt);
    //twt->start();
    twp->start();
}

// Lance le thread d'écriture d'image
void MeshDialog::writeImage(){
    enableTools(0);

    double lme = QInputDialog::getDouble(this, TITLE18, TEXT27, 0, -1000, 1000);

    ImageWriterProcess * iwp = new ImageWriterProcess;
    iwp->setFilename(Data::imageFilename(ui->cbTable->currentText()));
    iwp->setVerticesList(_vertex);
    iwp->setMaximumSizeEdge(lme);
    connect(iwp, SIGNAL(levelUpdated(int)), ui->progressBar, SLOT(setValue(int)));
    connect(iwp, SIGNAL(processNameUpdated(QString)), ui->lProcessName, SLOT(setText(QString)));
    connect(iwp, SIGNAL(exceptionLaunched(CubException)), this, SLOT(showException(CubException)));
    connect(iwp, SIGNAL(finished()), this, SLOT(launchProcess()));

    iwp->start();
}

void MeshDialog::writeGrid(){
    enableTools(0);

    GridWriterProcess * gwp = new GridWriterProcess;
    //QThread * gwt = new QThread;
    gwp->setGrid(*_vertex.grid());
    gwp->setFilename(Data::gridFilename(ui->cbTable->currentText()));
    //gwp->connectToThread(gwt);
    connect(gwp, SIGNAL(levelUpdated(int)), ui->progressBar, SLOT(setValue(int)));
    connect(gwp, SIGNAL(processNameUpdated(QString)), ui->lProcessName, SLOT(setText(QString)));
    connect(gwp, SIGNAL(exceptionLaunched(CubException)), this, SLOT(showException(CubException)));
    connect(gwp, SIGNAL(finished()), this, SLOT(launchProcess()));
    //gwp->moveToThread(gwt);
    //gwt->start();
    gwp->start();
}

// Gère l'activation des commandes graphiques
void MeshDialog::enableTools(bool enable){

    ui->cbTable->setEnabled(enable);
    ui->pbCalculate->setEnabled(enable);
    ui->pbWritingImage->setEnabled(enable);
    ui->cbShowTriangles->setEnabled(enable);
    ui->cbShowVertex->setEnabled(enable);
    ui->cbShowImage->setEnabled(enable);
    ui->pbCalculate->setEnabled(enable);
    ui->progressBar->setVisible(!enable);
    ui->lProcessName->setVisible(!enable);
}

void MeshDialog::enableTools(){
    enableTools(1);
}
void MeshDialog::launchProcess(){

    if(!_processList.isEmpty()){
        void (MeshDialog:: * _process)() = (void (MeshDialog::*)()) _processList.takeFirst();
        (this->*_process)();
    }
}

void MeshDialog::onPbCalculate(){
    _processList.append(&MeshDialog::triangulate);
    _processList.append(&MeshDialog::writeTriangles);
    _processList.append(&MeshDialog::createGrid);
    _processList.append(&MeshDialog::writeGrid);
    _processList.append(&MeshDialog::writeImage);
    _processList.append(&MeshDialog::enableTools);
    launchProcess();
}

void MeshDialog::onPbWriteImage(){
    _processList.push_back(&MeshDialog::writeImage);
    launchProcess();
}

void MeshDialog::updateImage(){

    QImage img(Data::imageFilename(ui->cbTable->currentText()), "BMP");

    QPixmap px;
    px.convertFromImage(img, Qt::ColorOnly);

    if(_vpxItem){
        delete _vpxItem;
        _vpxItem = 0;
    }

    QRectF bounds = _vertex.bounds();
    int xmin = (int) bounds.left();
    int ymin = (int) bounds.bottom();

    _vpxItem = new QGraphicsPixmapItem(px);
    _vpxItem->setOffset(xmin, ymin - img.height());
    _vpxItem->setTransformationMode(Qt::SmoothTransformation);

    _scene->addItem(_vpxItem);
}

// Affiche l'exception
void MeshDialog::showException(CubException e){
    ErrorDialog::errorDialog(this, e);
}

// Cette fonction est appelée à la fin de l'exécution du thread de chargement des sommets
void MeshDialog::setVerticesItem(QGraphicsItemGroup * verticesItem){

    _verticesItem = verticesItem;
    if(_verticesItem){
        _scene->addItem(_verticesItem);
        _verticesItem->setVisible(ui->cbShowVertex->isChecked());
    }

    enableTools(1);
}

// Cette fonction est appelée à la fin de l'exécution du thread de chargement des triangles
void MeshDialog::setTrianglesItem(QGraphicsItemGroup * trianglesItem){

    _trianglesItem = trianglesItem;
    if(_trianglesItem){
        _scene->addItem(_trianglesItem);
        _trianglesItem->setVisible(ui->cbShowTriangles->isChecked());
    }

    enableTools(1);
}

// Affiche les informations des triangles
void MeshDialog::updateScenePosition(QPointF position){

    bool showZ = ui->graphicsView->isMousePressed();

    ui->lZ->setText("Z : ---");
    ui->lAX->setText("X : ---");
    ui->lAY->setText("Y : ---");
    ui->lAZ->setText("Z : ---");
    ui->lAIndex->setText(TEXT28+"---");
    ui->lBX->setText("X : ---");
    ui->lBY->setText("Y : ---");
    ui->lBZ->setText("Z : ---");
    ui->lBIndex->setText(TEXT28+"---");
    ui->lCX->setText("X : ---");
    ui->lCY->setText("Y : ---");
    ui->lCZ->setText("Z : ---");
    ui->lCIndex->setText(TEXT28+"---");
    ui->lTIndex->setText(TEXT28+"---");
    if(_triangleSelected[0]) {_scene->removeItem(_triangleSelected[0]); _triangleSelected[0] = 0;}
    if(_triangleSelected[1]) {_scene->removeItem(_triangleSelected[1]); _triangleSelected[1] = 0;}
    if(_triangleSelected[2]) {_scene->removeItem(_triangleSelected[2]); _triangleSelected[2] = 0;}

    ui->lZ->setVisible(showZ);
    ui->gbA->setVisible(showZ);
    ui->gbB->setVisible(showZ);
    ui->gbC->setVisible(showZ);
    ui->gbTriangle->setVisible(showZ);

    if(ui->graphicsView->isMousePressed()){
        QMutexLocker(_vertex.mutex());
        DTriangleList *triangles = _vertex.triangles();
        for(int i=0; i<triangles->size(); i++){

            DTriangle &t = (*triangles)[i];

            if(!t.circumCenterIsValid()) _vertex.updateCircumCenter(t);
            if(_vertex.inCircle(t, position)){
                if(_vertex.inTriangle(t, position)){
                    double z=0;
                    _vertex.depthGridAt(position, z);
                    ui->lZ->setText(QString("Z : %1").arg(z));
                    if(ui->lZ->text().contains("-nan")){
                        QString temp ="";
                    }
                    ui->lAX->setText("X : " + QString::number(_vertex.at(t.v1()).x(), 'f', 4));
                    ui->lAY->setText("Y : " + QString::number(_vertex.at(t.v1()).y(), 'f', 4));
                    ui->lAZ->setText("Z : " + QString::number(_vertex.at(t.v1()).z(), 'f', 4));
                    ui->lAIndex->setText(TEXT28 + QString::number(t.v1()));
                    ui->lBX->setText("X : " + QString::number(_vertex.at(t.v2()).x(), 'f', 4));
                    ui->lBY->setText("Y : " + QString::number(_vertex.at(t.v2()).y(), 'f', 4));
                    ui->lBZ->setText("Z : " + QString::number(_vertex.at(t.v2()).z(), 'f', 4));
                    ui->lBIndex->setText(TEXT28 + QString::number(t.v2()));
                    ui->lCX->setText("X : " + QString::number(_vertex.at(t.v3()).x(), 'f', 4));
                    ui->lCY->setText("Y : " + QString::number(_vertex.at(t.v3()).y(), 'f', 4));
                    ui->lCZ->setText("Z : " + QString::number(_vertex.at(t.v3()).z(), 'f', 4));
                    ui->lCIndex->setText(TEXT28 + QString::number(t.v3()));
                    ui->lTIndex->setText(TEXT28 + QString::number(i));

                    QPen pen(Qt::blue);
                    _triangleSelected[0] = new QGraphicsLineItem(QLineF (_vertex.at(t.v1()).toPointF(), _vertex.at(t.v2()).toPointF())); _triangleSelected[0]->setPen(pen);
                    _triangleSelected[1] = new QGraphicsLineItem(QLineF (_vertex.at(t.v2()).toPointF(), _vertex.at(t.v3()).toPointF())); _triangleSelected[1]->setPen(pen);
                    _triangleSelected[2] = new QGraphicsLineItem(QLineF (_vertex.at(t.v3()).toPointF(), _vertex.at(t.v1()).toPointF())); _triangleSelected[2]->setPen(pen);

                    _scene->addItem(_triangleSelected[0]);
                    _scene->addItem(_triangleSelected[1]);
                    _scene->addItem(_triangleSelected[2]);
                    break;
                }
            }
        }
    }

    ui->lX->setText(QString("X : %1").arg(position.x(), 0, 'f', 4));
    ui->lY->setText(QString("Y : %2").arg(position.y(), 0, 'f', 4));
}

// Cette fonction est appelée sous l'action du combobox
void MeshDialog::selectTable(QString table){

    try{
        removeItems();

        Data::initTable(table);

        loadVertices();
        loadTriangles();
        loadGrid();

        updateImage();

        QRectF bounds = _vertex.bounds();
        int xmin = (int) bounds.left();
        int xmax = (int) bounds.right() +1;
        int ymin = (int) bounds.bottom();
        int ymax = (int) bounds.top() +1;

        _vpxItem->setVisible(ui->cbShowImage->isChecked());

        ui->graphicsView->setSceneRect(_vpxItem->boundingRect());
        ui->graphicsView->centerOn(xmin + (xmax - xmin) / 2, ymin + (ymax - ymin) / 2);
    }
    catch(const CubException &e){
        ErrorDialog::errorDialog(this, e);
    }

    _scene->update();
}

// Cette fonction est appelée sous l'action de la checkbox (affichage des sommets)
void MeshDialog::showVertex(bool show){

    if(show && !_verticesItem){
        enableTools(0);

        VerticesLoadingProcess * vlp = new VerticesLoadingProcess();
        vlp->setVertices(_vertex, false);
        connect(vlp, SIGNAL(levelUpdated(int)), ui->progressBar, SLOT(setValue(int)));
        connect(vlp, SIGNAL(processNameUpdated(QString)), ui->lProcessName, SLOT(setText(QString)));
        connect(vlp, SIGNAL(exceptionLaunched(CubException)), this, SLOT(showException(CubException)));
        connect(vlp, SIGNAL(verticesItemUpdated(QGraphicsItemGroup*)), this, SLOT(setVerticesItem(QGraphicsItemGroup*)));
        vlp->start();
    }
    else{
        if(_verticesItem) _verticesItem->setVisible(show);
    }
}

// Cette fonction est appelée sous l'action de la checkbox (affichage des triangles)
void MeshDialog::showTriangles(bool show){

    if(show && !_trianglesItem){
        enableTools(0);

        TrianglesItemLoadingProcess * tlp = new TrianglesItemLoadingProcess;
        tlp->setVertices(_vertex);
        connect(tlp, SIGNAL(levelUpdated(int)), ui->progressBar, SLOT(setValue(int)));
        connect(tlp, SIGNAL(processNameUpdated(QString)), ui->lProcessName, SLOT(setText(QString)));
        connect(tlp, SIGNAL(exceptionLaunched(CubException)), this, SLOT(showException(CubException)));
        connect(tlp, SIGNAL(trianglesItemUpdated(QGraphicsItemGroup*)), this, SLOT(setTrianglesItem(QGraphicsItemGroup*)));
        tlp->start();
    }
    else{
        if(_trianglesItem) _trianglesItem->setVisible(show);
    }
}

// Cette fonction est appelée sous l'action de la checkbox (affichage de l'image)
void MeshDialog::showImage(bool show){
    if(_vpxItem){
        _vpxItem->setVisible(show);
    }
}
