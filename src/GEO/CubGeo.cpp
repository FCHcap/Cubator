#include "CubGeo.h"

CubGeo::CubGeo(){
    loadSettings();
}

CubGeo::~CubGeo(){

}

void CubGeo::loadSettings(){

    Settings * settings = Settings::getInstance();
    SettingsGeo sgeo = settings->settingsGeo();
    _projections = sgeo.projections();
    _datums = sgeo.datums();
    _ellipsoids = sgeo.ellipsoids();
}
