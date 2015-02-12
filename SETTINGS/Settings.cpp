#include <Settings.h>

Settings * Settings::_settings = NULL;

Settings::Settings() : QSettings("Fch", "Cubator"){

}

Settings::~Settings(){

}

Settings * Settings::getInstance(){
    if(_settings == NULL){
        _settings = new Settings();
    }

    return _settings;
}

void Settings::kill(){
    if(_settings != NULL){
        delete _settings;
        _settings = NULL;
    }
}

void Settings::setSettingsMaps(SettingsMaps settings){

    QMutexLocker locker(&_mutex);

    // Writing maps settings
    beginGroup("MapsFiles");
    QList<QString> slMaps = settings.maps().keys();
    for(int i=0; i<slMaps.count(); i++){
        setValue(slMaps[i],settings.maps()[slMaps[i]]);
    }
    endGroup();

    beginGroup("Maps");
    setValue("centering_gps", settings.centeringGps());
    setValue("enable_changes", settings.enableChanges());
    setValue("default_map", settings.defaultMap());
    setValue("enable_center_view", settings.enableCenterView());
    setValue("x_center_view", settings.centerView().x());
    setValue("y_center_view", settings.centerView().y());
    endGroup();

}

SettingsMaps Settings::settingsMaps(){

    QMutexLocker locker(&_mutex);

    SettingsMaps settings;

    beginGroup("MapsFiles");
    QMap<QString, QString> maps;
    QStringList keys = allKeys();
    QString key;

    foreach(key, keys) maps.insert(key, value(key).toString());
    settings.setMaps(maps);
    endGroup();

    beginGroup("Maps");
    settings.setCenteringGps(value("centering_gps", 0).toBool());
    settings.setEnableChanges(value("enable_changes", 0).toBool());
    settings.setDefaultMap(value("default_map", "").toString());
    settings.setEnableCenterView(value("enable_center_view", 0).toBool());

    QPointF pcv;
    pcv.setX(value("x_center_view", 0).toDouble());
    pcv.setY(value("y_center_view", 0).toDouble());
    settings.setCenterView(pcv);
    endGroup();

    return settings;
}

void Settings::setSettingsGps(SettingsGps settings){

    QMutexLocker locker(&_mutex);

    beginGroup("Gps");
    setSettingsDevice(settings);
    setValue("projection", settings.projection());
    endGroup();
}

SettingsGps Settings::settingsGps(){

    QMutexLocker locker(&_mutex);

    SettingsGps settings;
    beginGroup("Gps");
    settings = settingsDevice();
    settings.setProjection(value("projection").toString());
    endGroup();
    return settings;
}

void Settings::setSettingsSonar(SettingsSonar settings){

    QMutexLocker locker(&_mutex);

    beginGroup("Sonar");
    setSettingsDevice(settings);
    endGroup();
}

SettingsSonar Settings::settingsSonar(){

    QMutexLocker locker(&_mutex);

    SettingsSonar settings;
    beginGroup("Sonar");
    settings = (SettingsSonar) settingsDevice();
    endGroup();
    return settings;
}

void Settings::setSettingsBoats(SettingsBoats settings){

    QMutexLocker locker(&_mutex);

    // Writing settings boats files
    beginGroup("BoatsFiles");
    QList<QString> slBoats = settings.boats().keys();
    for(int i=0; i<slBoats.count(); i++){
        setValue(slBoats[i],settings.boats()[slBoats[i]]);
    }
    endGroup();
}

SettingsBoats Settings::settingsBoats(){

    QMutexLocker locker(&_mutex);

    SettingsBoats settings;

    beginGroup("BoatsFiles");
    QMap<QString, QString> boats;
    QStringList keys = allKeys();
    QString key;

    foreach(key, keys) boats.insert(key, value(key).toString());
    settings.setBoats(boats);
    endGroup();

    return settings;
}

void Settings::setSettingsGeo(SettingsGeo settings){

    QMutexLocker locker(&_mutex);

    // Save the ellipsoids
    beginGroup("Ellipsoids");
    GeoEllipsoids ellipsoids = settings.ellipsoids();

    foreach(QString ellName, ellipsoids.keys()){
        beginGroup(ellName);
        GeoEllipsoid ellipsoid = ellipsoids.value(ellName);
        setValue("a", (double) ellipsoid.a());
        setValue("b", (double) ellipsoid.b());
        endGroup();
    }
    endGroup();

    // Save the datums
    beginGroup("Datums");
    GeoDatums datums = settings.datums();

    foreach(QString datName, datums.keys()){
        beginGroup(datName);
        GeoDatum datum = datums.value(datName);
        setValue("ellipsoid", (QString) datum.ellipsoid());
        setValue("tx", (double) datum.tx());
        setValue("ty", (double) datum.ty());
        setValue("tz", (double) datum.tz());
        setValue("rx", (double) datum.rx());
        setValue("ry", (double) datum.ry());
        setValue("rz", (double) datum.rz());
        endGroup();
    }
    endGroup();

    // Save the projections
    beginGroup("Projections");
    GeoProjections projections = settings.projections();

    foreach(QString projName, projections.keys()){
        beginGroup(projName);
        GeoProjection projection = projections.value(projName);
        setValue("datum", (QString) projection.datum());
        setValue("n", (double) projection.n());
        setValue("c", (double) projection.c());
        setValue("lg0", (double) projection.lg0());
        setValue("xs", (double) projection.xs());
        setValue("ys", (double) projection.ys());
        endGroup();
    }
    endGroup();
}

SettingsGeo Settings::settingsGeo(){

    QMutexLocker locker(&_mutex);

    SettingsGeo settings;

    // Load the ellipsoids
    beginGroup("Ellipsoids");
    GeoEllipsoids ellipsoids;

    foreach(QString ellName, GeoConvers::listEllipsoids()){
        beginGroup(ellName);
        GeoEllipsoid ellipsoid;
        ellipsoid.setA(value("a", 0).toDouble());
        ellipsoid.setB(value("b", 0).toDouble());
        endGroup();

        ellipsoids.insert(ellName, ellipsoid);
    }
    endGroup();
    settings.setEllipsoids(ellipsoids);

    // Load the datums
    beginGroup("Datums");
    GeoDatums datums;

    foreach(QString datName, GeoConvers::listDatums()){
        beginGroup(datName);
        GeoDatum datum;
        datum.setEllipsoid(value("ellipsoid", "").toString());
        datum.setTx(value("tx", 0).toDouble());
        datum.setTy(value("ty", 0).toDouble());
        datum.setTz(value("tz", 0).toDouble());
        datum.setRx(value("rx", 0).toDouble());
        datum.setRy(value("ry", 0).toDouble());
        datum.setRz(value("rz", 0).toDouble());
        endGroup();

        datums.insert(datName, datum);
    }
    endGroup();
    settings.setDatums(datums);

    // Load the projections
    beginGroup("Projections");
    GeoProjections projections;

    foreach(QString projName, GeoConvers::listProjections()){
        beginGroup(projName);
        GeoProjection projection;
        projection.setDatum(value("datum", "").toString());
        projection.setN(value("n", 0).toDouble());
        projection.setC(value("c", 0).toDouble());
        projection.setLg0(value("lg0", 0).toDouble());
        projection.setXs(value("xs", 0).toDouble());
        projection.setYs(value("ys", 0).toDouble());
        endGroup();

        projections.insert(projName, projection);
    }
    endGroup();
    settings.setProjections(projections);

    return settings;
}

void Settings::setSettingsStatusBar(SettingsStatusBar settings){
    QMutexLocker locker(&_mutex);

    beginGroup("StatusBar");
    setValue("projection", settings.projection());
    setValue("gpsFormat", settings.gpsFormat());
    endGroup();
}

SettingsStatusBar Settings::settingsStatusBar(){
    QMutexLocker locker(&_mutex);
    SettingsStatusBar statusBar;
    beginGroup("StatusBar");
    statusBar.setProjection(value("projection", "").toString());
    statusBar.setGpsFormat(value("gpsFormat", "").toString());
    endGroup();
    return statusBar;
}

void Settings::setSettingsDevice(const SettingsDevice &settings){

    setValue("name", settings.name());
    setValue("bauds", settings.rate());
    setValue("databits", settings.dataBits());
    setValue("parity", settings.parity());
    setValue("stopbit", settings.stopBit());
    setValue("flowcontrol", settings.flowControl());
    setValue("enabled", settings.enabled());
}

SettingsDevice Settings::settingsDevice(){

    SettingsDevice settings;
    settings.setName(value("name").toString());
    settings.setRate(value("bauds").toString());
    settings.setDataBits(value("databits").toString());
    settings.setParity(value("parity").toString());
    settings.setStopBit(value("stopbit").toString());
    settings.setFlowControl(value("flowcontrol").toString());
    settings.setEnabled(value("enabled").toBool());
    return settings;
}
