#ifndef SETTINGS_H
#define SETTINGS_H

// QT
#include <QSettings>
#include <QMap>
#include <QStringList>
#include <QPointF>
#include <QMutex>

// CUBATOR
#include <GeoEllipsoid.h>
#include <GeoConvers.h>

class SettingsMaps{

public:
    void setMaps(QMap<QString, QString> maps){_maps = maps;}
    QMap<QString, QString> maps() const {return _maps;}
    void setCenteringGps(bool centeringGps){_centeringGps = centeringGps;}
    bool centeringGps() const {return _centeringGps;}
    void setEnableChanges(bool enableChanges){_enableChanges = enableChanges;}
    bool enableChanges() const {return _enableChanges;}
    void setDefaultMap(QString defaultMap){_defaultMap = defaultMap;}
    QString defaultMap() const {return _defaultMap;}
    void setEnableCenterView(bool enableCenterView){_enableCenterView = enableCenterView;}
    bool enableCenterView() const {return _enableCenterView;}
    void setCenterView(QPointF centerView){_centerView = centerView;}
    QPointF centerView() const {return _centerView;}

protected:
    QMap<QString, QString> _maps; //<filename, filepath>
    bool _centeringGps;
    bool _enableChanges;
    QString _defaultMap;
    bool _enableCenterView;
    QPointF _centerView;

};

class SettingsBoats{
public:
    void setBoats(QMap<QString, QString> boats){_boats = boats;}
    QMap<QString, QString> boats() const{return _boats;}

protected:
    QMap<QString, QString> _boats; //<filename, filepath>
};

class SettingsDevice{

public:
    void setName(QString name){_name = name;}
    QString name() const {return _name;}

    void setRate(QString bauds){_bauds = bauds;}
    QString rate() const {return _bauds;}

    void setDataBits(QString dataBits){_dataBits = dataBits;}
    QString dataBits() const {return _dataBits;}

    void setParity(QString parity){_parity = parity;}
    QString parity() const {return _parity;}

    void setStopBit(QString stopBit){_stopBit = stopBit;}
    QString stopBit() const {return _stopBit;}

    void setFlowControl(QString flowControl){_flowControl = flowControl;}
    QString flowControl() const {return _flowControl;}

    void setEnabled(bool enabled){_enabled = enabled;}
    bool enabled() const {return _enabled;}

protected:
    QString _name;
    QString _bauds;
    QString _dataBits;
    QString _parity;
    QString _stopBit;
    QString _flowControl;
    bool _enabled;
};

typedef SettingsDevice SettingsSonar;

class SettingsGps : public SettingsDevice{

public:
    SettingsGps(){}
    SettingsGps(const SettingsDevice & other){
        SettingsDevice * sd1 = (SettingsDevice*) this;
        *sd1 = other;
    }
    SettingsGps & operator = (const SettingsDevice & other){
        SettingsDevice * sd1 = (SettingsDevice*) this;
        *sd1 = other;
        return *this;
    }

    void setProjection(QString projection){_projection = projection;}
    QString projection() const{return _projection;}

protected:
    QString _projection;
};

class SettingsGeo{

public:
    void setEllipsoids(GeoEllipsoids list){_ellipsoids = list;}
    GeoEllipsoids ellipsoids(){return _ellipsoids;}

    void setDatums(GeoDatums list){_datums = list;}
    GeoDatums datums(){return _datums;}

    void setProjections(GeoProjections list){_projections = list;}
    GeoProjections projections(){return _projections;}

protected:
    GeoEllipsoids _ellipsoids;
    GeoDatums _datums;
    GeoProjections _projections;
};

class SettingsStatusBar{
public:
    void setProjection(const QString proj){_projection = proj;}
    QString projection() const {return _projection;}

    void setGpsFormat(const QString gpsFormat){_gpsFormat = gpsFormat;}
    QString gpsFormat() const{return _gpsFormat;}

protected:
    QString _projection;
    QString _gpsFormat;
};

class Settings : public QSettings
{
protected:
    Settings();
    ~Settings();

public:

    static Settings* getInstance();

    static void kill();

    void setSettingsMaps(SettingsMaps settings);
    SettingsMaps settingsMaps();

    void setSettingsGps(SettingsGps settings);
    SettingsGps settingsGps();

    void setSettingsSonar(SettingsSonar settings);
    SettingsSonar settingsSonar();

    void setSettingsBoats(SettingsBoats settings);
    SettingsBoats settingsBoats();

    void setSettingsGeo(SettingsGeo settings);
    SettingsGeo settingsGeo();

    void setSettingsStatusBar(SettingsStatusBar settings);
    SettingsStatusBar settingsStatusBar();

protected:
    void setSettingsDevice(const SettingsDevice &settings);
    SettingsDevice settingsDevice();

protected:
    static Settings *_settings;
    QMutex _mutex;
};

#endif // SETTINGS_H
