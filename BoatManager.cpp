#include "BoatManager.h"

BoatManager::BoatManager(GraphicsScene *scene, QObject *parent, QWidget *widget) :
QObject(parent),
_widget(widget)
{
    qRegisterMetaType<CubException>("CubException");
    setScene(scene);
    _boatItem.setZValue(100);
}

BoatManager::~BoatManager(){

    removeAllBoatsFiles();
}

void BoatManager::setScene(GraphicsScene *scene){ _scene = scene; if(scene) scene->addItem(&_boatItem);}

void BoatManager::setParentWidget(QWidget *widget){ _widget = widget; }

void BoatManager::applySettings(){
    Settings * settings = Settings::getInstance();
    SettingsBoats sboats = settings->settingsBoats();
    foreach(QString filename, sboats.boats().keys()){
        if(sboats.boats().contains(filename)){
            QString filepath = sboats.boats().value(filename);
            addBoatFile(filepath);
        }
    }
}

void BoatManager::addBoatFile(const QString &filepath){
    try{
        QString extension = InfoMap::filepathToExtension(filepath);

        QString boatFile = InfoMap::filepathToMap(filepath);
        _mBoatsDefs.insert(boatFile, Boats());

        if(extension != "pml"){
            ErrorDialog::errorDialog(_widget, BRIEF23, TEXT01 + InfoMap::filepathToFilename(filepath));
            return;
        }

        PmlReader * reader = new PmlReader;
        ProgressDialog * dialog = new ProgressDialog(_widget);

        reader->setFilepath(filepath);
        reader->connectToProgressDialog(dialog);

        connect(reader, SIGNAL(mapGenerated(QString,GraphicsMap*)), this, SLOT(finishBoatLoader(QString,GraphicsMap*)));
        connect(reader, SIGNAL(exceptionLaunched(CubException)), this, SLOT(showError(CubException)));

        reader->start();
    }
    catch(CubException e){
        ErrorDialog::errorDialog(_widget, e);
    }
}

void BoatManager::removeBoatFile(const QString &boatFile){

    if(_mBoatsDefs.contains(boatFile)){

        Boats boats = _mBoatsDefs[boatFile];
        _mBoatsDefs.remove(boatFile);

        GraphicsMapBoatDef * boatDefSelected = _boatItem.boatDef(); // Get the current boat definition pointer

        foreach(QString boatName, boats.keys()){
            GraphicsMapBoatDef * boatDef = boats[boatName];
            if(boatDefSelected == boatDef){
                if(_mBoatsDefs.count()){
                    Boats boats2 = _mBoatsDefs[0];
                    if(boats.size())
                        _boatItem.setBoatDef(boats2[0]);
                }
                delete boatDef;
            }
        }
        emit boatManagerUpdated();
    }
}

void BoatManager::removeAllBoatsFiles(){

    foreach(QString boatName, _mBoatsDefs.keys()){
        removeBoatFile(boatName);
    }
}

void BoatManager::selectBoat(const QString &boatSelected){

    GraphicsMapBoatDef * boatDef = 0;
    foreach(QString boatFile, _mBoatsDefs.keys()){
        Boats boat = _mBoatsDefs[boatFile];

        foreach(QString boatName, boat.keys()){
            if(boatName == boatSelected) boatDef = boat[boatName];
        }
    }
    _boatItem.hide();
    _boatItem.setBoatDef(boatDef);
    _boatItem.show();
}

QString BoatManager::boatSelected() const{
    QString boatSelected;
    if(_boatItem.boatDef()) boatSelected = _boatItem.boatDef()->name();

    return boatSelected;
}

QStringList BoatManager::boats(){

    QStringList boatsList;

    foreach(QString boatFile, _mBoatsDefs.keys()){
        Boats boats = _mBoatsDefs[boatFile];
        boatsList.append(boats.keys());
    }
    return boatsList;
}

void BoatManager::connectToGps(Gps *gps){
    connect(gps, SIGNAL(positionUpdated(QPointF)), this, SLOT(updateGpsPosition(QPointF)));
}

void BoatManager::showError(CubException e){
    ErrorDialog::errorDialog(_widget, e);
}

void BoatManager::finishBoatLoader(QString boatFile, GraphicsMap *graphics){

    try{
        if(graphics){

            Boats boats = _mBoatsDefs[boatFile];
            QStringList boatsDefsNames = graphics->boatDefs(); // List of boats defs in the pml file

            foreach(QString boatDefName, boatsDefsNames){
                GraphicsMapBoatDef * boatDef = graphics->boatDefItem(boatDefName);
                boats.insert(boatDefName, boatDef);
                boatDef->setParentItem(0);
            }
            _mBoatsDefs.insert(boatFile, boats);
            delete graphics;

            if(_mBoatsDefs.size() == 1 && !boatsDefsNames.isEmpty())
                selectBoat(boats.end().key());
        }
        emit boatManagerUpdated();
    }
    catch(CubException &e){
        ErrorDialog::errorDialog(_widget, e);
    }
}

void BoatManager::updateGpsPosition(QPointF position){
    _boatItem.setPos(position);
}
