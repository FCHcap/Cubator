#include "MapManager.h"

// QT
#include <QMessageBox>

MapManager::MapManager(GraphicsScene *scene, QObject *parent, QWidget *widget) :
    QObject(parent),
    _scene(scene),
    _widget(widget)
{
    connect(&_eventManager, SIGNAL(graphicsMapUpdated()), this, SIGNAL(mapUpdated()));
    qRegisterMetaType<CubException>("CubException");
}

MapManager::~MapManager(){

    waitThreads();
    saveAllMapsWithQuestion();
    waitThreads();
    removeAllMaps();
}

void MapManager::waitThreads(){
    foreach(QPointer<QThread> thread, _threads){
        if(thread)
            thread->wait();
    }
    _threads.clear();
}

void MapManager::setScene(GraphicsScene *scene){ _scene = scene; }

void MapManager::setParentWidget(QWidget *widget){ _widget = widget; }

void MapManager::applySettings(){
    Settings * settings = Settings::getInstance();
    SettingsMaps smaps = settings->settingsMaps();
    foreach(QString filename, smaps.maps().keys()){
        QString filepath = smaps.maps().value(filename);
        addMap(filepath);
    }
}

void MapManager::newMap(const QString &filepath){

    if(!_scene) return;

    GraphicsMap * item = new GraphicsMap(0, &_eventManager);
    _scene->addItem(item);

    QString filename = InfoMap::filepathToFilename(filepath);
    QString map = InfoMap::filenameToMap(filename);
    Map mmap;

    mmap.item = item;
    mmap.filepath = filepath;

    _mMaps.insert(map, mmap);

    if(_mMaps.count() == 1) _mapSelected = map;

    emit mapManagerUpdated();
}

void MapManager::addMap(const QString &filepath){

    using namespace std;
    try{
        Map mmap;
        mmap.filepath = filepath;
        mmap.item = 0;

        QString map = InfoMap::filepathToMap(filepath);
        QString extension = InfoMap::filepathToExtension(filepath);
        _mMaps.insert(map, mmap);

        DefaultProcess * process = 0;

        if(extension == "dxf"){
            CubDxfReader * dxf = new CubDxfReader;
            dxf->setFilepath(filepath);
            process = dxf;

            connect(dxf, SIGNAL(mapGenerated(QString,GraphicsMap*)), this, SLOT(finishMapLoader(QString,GraphicsMap*)));
        }
        else if(extension == "pml"){
            PmlReader * pml = new PmlReader;
            pml->setFilepath(filepath);
            process = pml;

            connect(pml, SIGNAL(mapGenerated(QString,GraphicsMap*)), this, SLOT(finishMapLoader(QString,GraphicsMap*)));
        }
        else
            throw CubException(BRIEF09, TEXT01 + InfoMap::filepathToFilename(filepath), "MapManager::addMap");

        if(process){
            ProgressDialog * dialog = new ProgressDialog(_widget);
            dialog->setWindowTitle(TITLE21 + InfoMap::filepathToFilename(filepath));

            process->connectToProgressDialog(dialog);

            connect(process, SIGNAL(exceptionLaunched(CubException)), this, SLOT(showError(CubException)));

            QPointer<QThread> pthread = (QThread*) process;
            _threads.append(pthread);
            process->start();
        }
    }
    catch(CubException &e){
        ErrorDialog::errorDialog(_widget, e);
    }
}

void MapManager::removeMap(const QString & map){

    if(!_scene) return;

    if(_mMaps.contains(map)){

        Map mmap = _mMaps[map];
        if(mmap.item){
            _scene->removeItem(mmap.item);
            delete mmap.item;
        }

        _mMaps.remove(map);
        if(_mapSelected == map){
            _mapSelected.clear();
            if(_mMaps.count())
                _mapSelected = _mMaps.keys().first();
        }

        emit mapManagerUpdated();
    }
}

void MapManager::removeAllMaps(){

    foreach(QString map, _mMaps.keys()){
        removeMap(map);
    }
}

void MapManager::addIcon(const QString &filepath){

    try{
        QString extension = InfoMap::filepathToExtension(filepath);

        if(extension != "pml")
            throw CubException(BRIEF09, TEXT01 + InfoMap::filepathToFilename(filepath), "MapManager::addIcon");

        PmlReader * reader = new PmlReader;
        ProgressDialog * dialog = new ProgressDialog(_widget);
        dialog->setWindowTitle(TITLE21 + InfoMap::filepathToFilename(filepath));

        reader->setFilepath(filepath);
        reader->connectToProgressDialog(dialog);

        connect(reader, SIGNAL(mapGenerated(QString,GraphicsMap*)), this, SLOT(finishIconLoader(QString,GraphicsMap*)));
        connect(reader, SIGNAL(exceptionLaunched(CubException)), this, SLOT(showError(CubException)));
        reader->start();
    }
    catch(CubException &e){
        ErrorDialog::errorDialog(_widget, e);
    }
}

void MapManager::saveMap(const QString & map){

    try{

        if(_mMaps.contains(map)){

            Map mmap = _mMaps[map];

            // Checks if the file is in pml
            if(InfoMap::filepathToExtension(mmap.filepath) != "pml")
                throw CubException(BRIEF10, TEXT01 + InfoMap::filepathToFilename(mmap.filepath), "MapManager::saveMap");

            QMap<QString, GraphicsMap*> hmapsave;
            hmapsave.insert(filepath(map), mmap.item);

            PmlWriter * writer = new PmlWriter;
            ProgressDialog * dialog = new ProgressDialog(_widget);

            writer->setList(hmapsave);
            writer->connectToProgressDialog(dialog);

            QPointer<QThread> pthread = (QThread*) writer;
            _threads.append(pthread);

            mmap.item->setEdited(0);

            writer->start();
        }
    }
    catch(CubException &e){
        ErrorDialog::errorDialog(_widget, e);
    }
}

void MapManager::saveMapAs(){
    PmlSaveDialog dialog(_mMaps, _widget);
    dialog.exec();

    foreach(QString map, dialog.mapSaved()){
        if(_mMaps.contains(map)){
            Map mmap = _mMaps[map];
            _mMaps.insert(map, mmap);
        }
    }
}

void MapManager::saveAllMaps(){

    foreach(QString map, _mMaps.keys()){
        Map mmap = _mMaps[map];
        if(mmap.item->edited())
            saveMap(map);
    }
}

void MapManager::saveAllMapsWithQuestion(){

    foreach(QString map, _mMaps.keys()){
        Map mmap = _mMaps[map];
        if(mmap.item)
            if(mmap.item->edited()){
                if(QMessageBox::question(_widget, TITLE01, QUESTION04 + '\n' + TEXT01 + InfoMap::filepathToFilename(mmap.filepath), QMessageBox::Yes, QMessageBox::No) == QMessageBox::Yes)
                    saveMap(map);
            }
    }
}

void MapManager::selectMap(const QString &map){
    _mapSelected = map;
}

QString MapManager::mapSelected(){
    return _mapSelected;
}

QString MapManager::mapSelectedWithStatusUpdate(){
    QString map;
    if(_mMaps.contains(_mapSelected)){
        Map mmap = _mMaps[_mapSelected];
        if(mmap.item) (mmap.item->edited()) ? map = '*' + _mapSelected : map = _mapSelected;
    }
    return map;
}

QStringList MapManager::maps(){
    return _mMaps.keys();
}

QStringList MapManager::mapsWithStatusUpdate(){
    QStringList mapsnames;
    foreach(QString map, _mMaps.keys()){
        Map mmap = _mMaps[map];
        if(mmap.item)
            (mmap.item->edited()) ? mapsnames.append('*'+map) : mapsnames.append(map);
    }
    return mapsnames;
}

QString MapManager::filepath(const QString & map){

    if(_mMaps.contains(map)){
        Map mmap = _mMaps[map];
        return mmap.filepath;
    }
    return QString();
}

bool MapManager::mapExists(const QString &map){
    return _mMaps.contains(map);
}

GraphicsMap * MapManager::item(QString map){

    // recherche et retire l'astérisque de modification s'il existe
    if(map[0]=='*')
        map = map.remove(0, 1);

    if(_mMaps.contains(map)){
        Map mmap = _mMaps[map];
        return mmap.item;
    }

    return 0;
}

void MapManager::showError(CubException e){
    ErrorDialog::errorDialog(_widget, e);
}

void MapManager::finishIconLoader(QString icon, GraphicsMap * graphics){

    Q_UNUSED(icon)

    if(!_scene) return;

    try{
        GraphicsMap * map = item(_mapSelected);
        if(graphics && map){
            foreach(QString name, graphics->iconDefs()){
                GraphicsMapIconDef * icondef = graphics->iconDefItem(name);
                map->addIconDef(icondef);
                icondef->setParentItem(0);
                delete graphics;
                emit mapManagerUpdated();
            }
        }
    }
    catch(CubException & e){
        ErrorDialog::errorDialog(_widget, e);
    }
}

void MapManager::finishMapLoader(QString map, GraphicsMap * graphics){

    if(!_scene) return;

    try{
        if(!_mMaps.contains(map))
            throw CubException(BRIEF00, ERROR12, "MapManager::finishDxfLoader");

        if(graphics){

            Map mmap = _mMaps[map];
            mmap.item = graphics;
            _mMaps.insert(map, mmap);

            _scene->addItem(graphics);
            if(_mMaps.count() == 1) _mapSelected = map;

            graphics->setMapEventManager(&_eventManager); // connecte le gestionnaire d'évènements de cartes
            graphics->enableMonitorChanges(1); // active la surveillance des modifications
        }
        emit mapManagerUpdated();
    }
    catch(CubException & e){
        ErrorDialog::errorDialog(_widget, e);
    }
}
