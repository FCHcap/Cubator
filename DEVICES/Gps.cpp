#include "Gps.h"

Gps::Gps(QObject *parent) : DeviceProcess(parent)
{
}

Gps::~Gps(){
    if(_settings) delete _settings;
}

void Gps::loadSettings(){
    Settings * settings = Settings::getInstance();
    SettingsGps * sgps = new SettingsGps;
    *sgps = settings->settingsGps();
    _settings = sgps;
}

#include <iostream>
using namespace std;

void Gps::processFrame(QByteArray &frame){

    // Remove the caracters '\r' and '\n'
    frame.chop(2);

    QString data(frame);
    QRegExp rxgga(RXGGA);
    QRegExp rxhdt(RXHDT);

    cout << "Frame : " << data.toStdString() << endl;

    if(rxgga.indexIn(data) != -1){
        SettingsGps * sgps = (SettingsGps *) _settings;

        QString lg = rxgga.cap(4);
        QString lt = rxgga.cap(2);
        double alt = rxgga.cap(9).toDouble();

        // Initializes the geodata object
        GeoData gd;
        QRegExp rxcd("^(\\d*)(\\d{2}\\.\\d*)$");

        if(!rxcd.indexIn(lg) == -1) return;
        int lgd = rxcd.cap(1).toInt(); // longitude degres
        double lgmd = rxcd.cap(2).toDouble(); // longitude minutes decimales

        if(!rxcd.indexIn(lt) == -1) return;
        int ltd = rxcd.cap(1).toInt(); // latitude degres
        double ltmd = rxcd.cap(2).toDouble(); // latitude minutes decimales

        gd.setCoord(ltd, ltmd, lgd, lgmd);
        gd.setHeight(alt);

        QStringList projections = CubGeo::listProjections();
        if(projections.contains(sgps->projection())){
            GeoData coordsRad = gd.toRad();
            GeoVecteur gv = geo.WGS84GeoToLambert(coordsRad, sgps->projection());
            emit positionUpdated(QPointF(gv.x(), gv.y()));
        }
        _timerInconsistent->start();
        return;
    }

    if(rxhdt.indexIn(data) != -1){
        double angle = rxhdt.cap(1).toDouble();
        Q_UNUSED(angle)
    }
}
