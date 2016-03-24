#ifndef GPS_H
#define GPS_H

#define RXGGA "^\\$[A-Z]{2}GGA,([\\d\\.]+),([\\d\\.]+),([NS]),([\\d\\.]+),([EW]),(\\d),(\\d+),([\\d\\.]+),([\\d\\.])+,M,([\\d\\.])+,M,[\\d\\.]*,\\d*(\\*[0-9a-fA-F]+)$"
#define RXHDT "^\\$[A-Z]{2}HDT,([\\d\\.]*),T$"

// QT
#include <QObject>
#include <QPointF>

// CUBATOR
#include <DeviceProcess.h>
#include <Settings.h>
#include <CubGeo.h>

struct GpsData {
    QPointF position;
    qint8 satellites;
    bool dgps;
    qreal altitude;
};
Q_DECLARE_METATYPE(GpsData)

class Gps : public DeviceProcess
{
    Q_OBJECT

public:
    Gps(QObject *parent = 0);
    ~Gps();

signals:
    void positionUpdated(QPointF);
    void gpsDataUpdated(GpsData);
    void positionRecovered(bool);

protected:
    virtual void loadSettings();

protected slots:
    void onEnabled(bool);
    void onConnected(bool);
    void onTimeout();
    void onInconsistentData();

public slots:
    void processFrame(QByteArray &frame);

protected:
    CubGeo geo;
};


#endif // GPS_H
