#include "SettingsDialog.h"
#include "ui_SettingsDialog.h"

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);
    _bauds<<"1200"<<"2400"<<"4800"<<"9600"<<"19200"<<"38400";
    _com<<"1"<<"2"<<"3"<<"4";

    ui->cbDevicesGpsBauds->addItems(DeviceProcess::listBaudrate());
    ui->cbDevicesGpsDataBits->addItems(DeviceProcess::listDataBits());
    ui->cbDevicesGpsParity->addItems(DeviceProcess::listParity());
    ui->cbDevicesGpsStopBit->addItems(DeviceProcess::listStopBit());
    ui->cbDevicesGpsFlowControl->addItems(DeviceProcess::listFlowControl());

    ui->cbDevicesSonarBauds->addItems(DeviceProcess::listBaudrate());
    ui->cbDevicesSonarDataBits->addItems(DeviceProcess::listDataBits());
    ui->cbDevicesSonarParity->addItems(DeviceProcess::listParity());
    ui->cbDevicesSonarStopBit->addItems(DeviceProcess::listStopBit());
    ui->cbDevicesSonarFlowControl->addItems(DeviceProcess::listFlowControl());

    _mapsUpdated = 0;
    _iconsUpdated = 0;
    _boatsUpdated = 0;
    _databaseUpdated = 0;
    _devicesUpdated = 0;
    _statusBarUpdated = 0;

    _lastEllItem = 0;
    _lastDatItem = 0;
    _lastProItem = 0;

    // Connecte les paramètres de périphériques
    connect(ui->leDevicesGpsName, SIGNAL(editingFinished()), this, SLOT(updateDevice()));
    connect(ui->cbDevicesGpsBauds, SIGNAL(currentIndexChanged(int)), this, SLOT(updateDevice()));
    connect(ui->cbDevicesGpsDataBits, SIGNAL(currentIndexChanged(int)), this, SLOT(updateDevice()));
    connect(ui->cbDevicesGpsParity, SIGNAL(currentIndexChanged(int)), this, SLOT(updateDevice()));
    connect(ui->cbDevicesGpsStopBit, SIGNAL(currentIndexChanged(int)), this, SLOT(updateDevice()));
    connect(ui->cbDevicesGpsFlowControl, SIGNAL(currentIndexChanged(int)), this, SLOT(updateDevice()));
    connect(ui->cbDevicesGpsEnable, SIGNAL(clicked()), this, SLOT(updateDevice()));
    connect(ui->cbDevicesProjectionSystem, SIGNAL(currentIndexChanged(int)), this, SLOT(updateDevice()));
    connect(ui->leDevicesSonarName, SIGNAL(editingFinished()), this, SLOT(updateDevice()));
    connect(ui->cbDevicesSonarBauds, SIGNAL(currentIndexChanged(int)), this, SLOT(updateDevice()));
    connect(ui->cbDevicesSonarDataBits, SIGNAL(currentIndexChanged(int)), this, SLOT(updateDevice()));
    connect(ui->cbDevicesSonarParity, SIGNAL(currentIndexChanged(int)), this, SLOT(updateDevice()));
    connect(ui->cbDevicesSonarStopBit, SIGNAL(currentIndexChanged(int)), this, SLOT(updateDevice()));
    connect(ui->cbDevicesSonarFlowControl, SIGNAL(currentIndexChanged(int)), this, SLOT(updateDevice()));
    connect(ui->cbDevicesSonarEnable, SIGNAL(clicked()), this, SLOT(updateDevice()));

    // Connecte les paramètres de la barre de status
    connect(ui->cbStatusProjection, SIGNAL(currentIndexChanged(int)), this, SLOT(updateStatusBar()));
    connect(ui->cbStatusFormatGps, SIGNAL(currentIndexChanged(int)), this, SLOT(updateStatusBar()));

    loadSettings();
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

bool SettingsDialog::mapsUpdated(){
    return _mapsUpdated;
}

bool SettingsDialog::iconsUpdated(){
    return _iconsUpdated;
}

bool SettingsDialog::boatsUpdated(){
    return _boatsUpdated;
}

bool SettingsDialog::databaseUpdated(){
    return _databaseUpdated;
}

bool SettingsDialog::devicesUpdated(){
    return _devicesUpdated;
}

bool SettingsDialog::statusBarUpdated(){
    return _statusBarUpdated;
}

void SettingsDialog::onMapAddEvent(){
    QString filepath = QFileDialog::getOpenFileName(this, TITLE03, getUserDocumentsLocation(), TEXT09+"(*.dxf *.pml)");

    if(filepath != 0){
        QString map = InfoMap::filepathToMap(filepath);
        _mMaps.insert(map,filepath);
        QList<QString> slMaps = _mMaps.values();
        ui->lMaps->clear();
        ui->lMaps->addItems(slMaps);
        _mapsUpdated = 1;
    }

    updateMapDefault();
}

void SettingsDialog::onMapRemoveEvent(){

    QListWidgetItem* wItem = ui->lMaps->currentItem();

    if(!wItem) return;

    QString map = InfoMap::filepathToMap(wItem->text());

    if(_mMaps.contains(map)){
        _mMaps.remove(map);
        ui->lMaps->clear();
        ui->lMaps->addItems(_mMaps.values());
    }
    _mapsUpdated = 1;

    updateMapDefault();
}

void SettingsDialog::onMapsCenterViewEvent(bool enabled){
    if(enabled){
        ui->leMapsCenterViewX->setEnabled(1);
        ui->leMapsCenterViewY->setEnabled(1);
    }
    else{
        ui->leMapsCenterViewX->setEnabled(0);
        ui->leMapsCenterViewY->setEnabled(0);
    }
}

void SettingsDialog::onBoatAddEvent(){

    QString filepath = QFileDialog::getOpenFileName(this, TITLE20, getUserDocumentsLocation(), TEXT29+"(*.dxf *.pml)");

    if(filepath != 0){
        QString map = InfoMap::filepathToMap(filepath);
        _mBoats.insert(map,filepath);
        QStringList slBoats= _mBoats.keys();
        ui->lBoats->clear();
        ui->lBoats->addItems(slBoats);
        _boatsUpdated = 1;
    }
}

void SettingsDialog::onBoatRemoveEvent(){

    QListWidgetItem* wItem = ui->lBoats->currentItem();

    if(!wItem) return;

    QString item = wItem->text();
    if(_mBoats.contains(item)){
        _mBoats.remove(item);
        ui->lBoats->clear();
        ui->lBoats->addItems(_mBoats.keys());
    }
    _boatsUpdated = 1;
}

void SettingsDialog::onEllChangeEvent(){

    saveLastEllipsoid();

    /* Load the attributes of current item */
    QString name = ui->lwEllNames->currentItem()->text();

    GeoEllipsoid ge = _ellipsoids.value(name);
    ui->dsEllSemiMajorAxis->setValue(ge.a());
    ui->dsEllSemiMinorAxis->setValue(ge.b());
    _lastEllItem = ui->lwEllNames->currentItem();
}

void SettingsDialog::onDatChangeEvent(){

    saveLastDatum();

    /* Load the attributes of current datum */
    QString name = ui->lwDatNames->currentItem()->text();

    GeoDatum gd = _datums.value(name);
    ui->spDatTranslationX->setValue(gd.tx());
    ui->spDatTranslationY->setValue(gd.ty());
    ui->spDatTranslationZ->setValue(gd.tz());
    ui->spDatRotationX->setValue(gd.rx());
    ui->spDatRotationY->setValue(gd.ry());
    ui->spDatRotationZ->setValue(gd.rz());
    int index = ui->cbDatEll->findText(gd.ellipsoid());
    if(index != -1){
        ui->cbDatEll->setCurrentIndex(index);
    }
    ui->spDatSf->setValue(gd.scaleFactor());
    _lastDatItem = ui->lwDatNames->currentItem();
}

void SettingsDialog::onProChangeEvent(){

    saveLastProjection();

    /* Load the attributes of current item */
    QString name = ui->lwProNames->currentItem()->text();

    GeoProjection gp = _projections.value(name);
    ui->dsProC->setValue(gp.c());
    ui->dsProN->setValue(gp.n());
    ui->dsProL0->setValue(gp.lg0());
    ui->dsProXs->setValue(gp.xs());
    ui->dsProYs->setValue(gp.ys());

    int index = ui->cbProDatum->findText(gp.datum());
    if(index != -1){ui->cbProDatum->setCurrentIndex(index);}
    _lastProItem = ui->lwProNames->currentItem();
}

void SettingsDialog::onAcceptEvent(){
    writeSettings();
    accept();
}

void SettingsDialog::onRejectEvent(){
    reject();
}

void SettingsDialog::updateDevice(){
    _devicesUpdated = 1;
}

void SettingsDialog::updateStatusBar(){
    _statusBarUpdated = 1;
}

void SettingsDialog::loadSettings(){

    int index = 0;

    Settings * settings = Settings::getInstance();

    // Paramètre la page de cartes
    SettingsMaps smaps = settings->settingsMaps();
    _mMaps = smaps.maps();
    ui->lMaps->clear();
    ui->lMaps->addItems(_mMaps.values());
    ui->cbMapsCenteringGps->setChecked(smaps.centeringGps());
    ui->cbMapsEnableChanges->setChecked(smaps.enableChanges());
    ui->cbMapsCenterView->setChecked(smaps.enableCenterView());
    if(ui->cbMapsCenterView->isChecked()){
        ui->leMapsCenterViewX->setEnabled(1);
        ui->leMapsCenterViewY->setEnabled(1);
    }
    else{
        ui->leMapsCenterViewX->setEnabled(0);
        ui->leMapsCenterViewY->setEnabled(0);
    }
    ui->leMapsCenterViewX->setText(QString::number(smaps.centerView().x()));
    ui->leMapsCenterViewY->setText(QString::number(smaps.centerView().y()));
    updateMapDefault(smaps.defaultMap());

    // Paramètre la page de bateaux
    SettingsBoats sboats = settings->settingsBoats();
    _mBoats = sboats.boats();
    ui->lBoats->clear();
    ui->lBoats->addItems(_mBoats.keys());

    // Paramètre la page des périphériques
    SettingsGps sgps = settings->settingsGps();
    ui->leDevicesGpsName->setText(sgps.name());

    index = ui->cbDevicesGpsBauds->findText(sgps.rate());
    if(index != -1) ui->cbDevicesGpsBauds->setCurrentIndex(index);

    index = ui->cbDevicesGpsDataBits->findText(sgps.dataBits());
    if(index != -1) ui->cbDevicesGpsDataBits->setCurrentIndex(index);

    index = ui->cbDevicesGpsParity->findText(sgps.parity());
    if(index != -1) ui->cbDevicesGpsParity->setCurrentIndex(index);

    index = ui->cbDevicesGpsStopBit->findText(sgps.stopBit());
    if(index != -1) ui->cbDevicesGpsStopBit->setCurrentIndex(index);

    index = ui->cbDevicesGpsFlowControl->findText(sgps.flowControl());
    if(index != -1) ui->cbDevicesGpsFlowControl->setCurrentIndex(index);

    ui->cbDevicesGpsEnable->setChecked(sgps.enabled());

    ui->cbDevicesProjectionSystem->addItems(GeoConvers::listProjections());
    index = ui->cbDevicesProjectionSystem->findText(sgps.projection());
    if(index != -1) ui->cbDevicesProjectionSystem->setCurrentIndex(index);

    SettingsSonar sSonar = settings->settingsSonar();
    ui->leDevicesSonarName->setText(sSonar.name());

    index = ui->cbDevicesSonarBauds->findText(sSonar.rate());
    if(index != -1) ui->cbDevicesSonarBauds->setCurrentIndex(index);

    index = ui->cbDevicesSonarDataBits->findText(sSonar.dataBits());
    if(index != -1) ui->cbDevicesSonarDataBits->setCurrentIndex(index);

    index = ui->cbDevicesSonarParity->findText(sSonar.parity());
    if(index != -1) ui->cbDevicesSonarParity->setCurrentIndex(index);

    index = ui->cbDevicesSonarStopBit->findText(sSonar.stopBit());
    if(index != -1) ui->cbDevicesSonarStopBit->setCurrentIndex(index);

    index = ui->cbDevicesSonarFlowControl->findText(sSonar.flowControl());
    if(index != -1) ui->cbDevicesSonarFlowControl->setCurrentIndex(index);

    ui->cbDevicesSonarEnable->setChecked(sSonar.enabled());

    SettingsGeo sgeo = settings->settingsGeo();

    // Paramètre la page des éllipsoïdes
    _ellipsoids = sgeo.ellipsoids();
    ui->lwEllNames->addItems(_ellipsoids.keys());
    ui->lwEllNames->setCurrentRow(0);

    // Paramètre la page des datums
    _datums = sgeo.datums();
    ui->lwDatNames->addItems(_datums.keys());
    ui->cbDatEll->addItems(GeoConvers::listEllipsoids());
    ui->lwDatNames->setCurrentRow(0);

    // Paramètre la page des projections
    _projections = sgeo.projections();
    ui->lwProNames->addItems(_projections.keys());
    ui->cbProDatum->addItems(GeoConvers::listDatums());
    ui->lwProNames->setCurrentRow(0);

    // Paramètre la page de configuration de la barre de status
    SettingsStatusBar sStatusBar = settings->settingsStatusBar();
    ui->cbStatusProjection->addItems(_projections.keys());
    index = ui->cbStatusProjection->findText(sStatusBar.projection());
    if(index !=-1) ui->cbStatusProjection->setCurrentIndex(index);

    ui->cbStatusFormatGps->addItems(GeoData::formats());
    index = ui->cbStatusFormatGps->findText(sStatusBar.gpsFormat());
    if(index!=-1) ui->cbStatusFormatGps->setCurrentIndex(index);

    _devicesUpdated = 0;
}

void SettingsDialog::writeSettings(){

    Settings * settings = Settings::getInstance();

    settings->clear();

    // Writing maps settings
    SettingsMaps smaps;
    smaps.setMaps(_mMaps);
    smaps.setCenteringGps(ui->cbMapsCenteringGps->isChecked());
    smaps.setEnableChanges(ui->cbMapsEnableChanges->isChecked());
    smaps.setDefaultMap(ui->cbMapsDefault->currentText());
    smaps.setEnableCenterView(ui->cbMapsCenterView->isChecked());
    smaps.setCenterView(QPointF(ui->leMapsCenterViewX->text().toDouble(), ui->leMapsCenterViewY->text().toDouble()));
    settings->setSettingsMaps(smaps);

    // Writing boat settings
    SettingsBoats sboats;
    sboats.setBoats(_mBoats);
    settings->setSettingsBoats(sboats);

    // Writing gps settings
    SettingsGps sgps;
    sgps.setName(ui->leDevicesGpsName->text());
    sgps.setRate(ui->cbDevicesGpsBauds->currentText());
    sgps.setDataBits(ui->cbDevicesGpsDataBits->currentText());
    sgps.setParity(ui->cbDevicesGpsParity->currentText());
    sgps.setStopBit(ui->cbDevicesGpsStopBit->currentText());
    sgps.setFlowControl(ui->cbDevicesGpsFlowControl->currentText());
    sgps.setProjection(ui->cbDevicesProjectionSystem->currentText());
    sgps.setEnabled(ui->cbDevicesGpsEnable->isChecked());
    settings->setSettingsGps(sgps);

    SettingsSonar ssonar;
    ssonar.setName(ui->leDevicesSonarName->text());
    ssonar.setRate(ui->cbDevicesSonarBauds->currentText());
    ssonar.setDataBits(ui->cbDevicesSonarDataBits->currentText());
    ssonar.setParity(ui->cbDevicesSonarParity->currentText());
    ssonar.setStopBit(ui->cbDevicesSonarStopBit->currentText());
    ssonar.setFlowControl(ui->cbDevicesSonarFlowControl->currentText());
    ssonar.setEnabled(ui->cbDevicesSonarEnable->isChecked());
    settings->setSettingsSonar(ssonar);

    SettingsGeo sgeo;

    // Writing ellipsoids settings
    saveLastEllipsoid();
    sgeo.setEllipsoids(_ellipsoids);

    // Writing datums settings
    saveLastDatum();
    sgeo.setDatums(_datums);

    // Writing projections settings
    saveLastProjection();
    sgeo.setProjections(_projections);

    settings->setSettingsGeo(sgeo);

    // Ecriture des paramètres de la barre de status
    SettingsStatusBar ssb;
    ssb.setProjection(ui->cbStatusProjection->currentText());
    ssb.setGpsFormat(ui->cbStatusFormatGps->currentText());
    settings->setSettingsStatusBar(ssb);
}

void SettingsDialog::saveLastEllipsoid(){

    /* Save the attributs of last item */
    if(_lastEllItem){
        QString name = _lastEllItem->text();
        GeoEllipsoid ge = _ellipsoids.value(name);
        ge.setA(ui->dsEllSemiMajorAxis->value());
        ge.setB(ui->dsEllSemiMinorAxis->value());
        _ellipsoids.insert(name, ge);
    }
}

void SettingsDialog::saveLastDatum(){

    /* Save the attributs of last item */
    if(_lastDatItem){
        QString name = _lastDatItem->text();
        GeoDatum gd = _datums.value(name);
        gd.setTx(ui->spDatTranslationX->value());
        gd.setTy(ui->spDatTranslationY->value());
        gd.setTz(ui->spDatTranslationZ->value());
        gd.setRx(ui->spDatRotationX->value());
        gd.setRy(ui->spDatRotationY->value());
        gd.setRz(ui->spDatRotationZ->value());
        gd.setEllipsoid(ui->cbDatEll->currentText());
        gd.setScaleFactor(ui->spDatSf->value());
        _datums.insert(name, gd);
    }

}

void SettingsDialog::saveLastProjection(){

    /* Save the attributes of last item */
    if(_lastProItem){
        QString name = _lastProItem->text();
        GeoProjection gp = _projections.value(name);
        gp.setC(ui->dsProC->value());
        gp.setN(ui->dsProN->value());
        gp.setLg0(ui->dsProL0->value());
        gp.setXs(ui->dsProXs->value());
        gp.setYs(ui->dsProYs->value());

        gp.setDatum(ui->cbProDatum->currentText());

        _projections.insert(name, gp);
    }
}

void SettingsDialog::updateMapDefault(QString map){

    if(map.isEmpty()){
        map = ui->cbMapsDefault->currentText();
    }
    ui->cbMapsDefault->clear();
    ui->cbMapsDefault->addItems(_mMaps.keys());
    if(_mMaps.contains(map)){
        int index = ui->cbMapsDefault->findText(map);
        if(index != -1){
            ui->cbMapsDefault->setCurrentIndex(index);
        }
    }
}
