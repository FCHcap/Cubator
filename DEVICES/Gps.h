#ifndef GPS_H
#define GPS_H

#define RXGGA "^\\$\\D{2}GGA,([\\d.]*),([\\d.]*),(\\D{1}),([\\d.]*),(\\D{1}),(\\d{1}),(\\d*),([\\d.]*),([-\\d.]*),(\\D*),([\\d.]*),(\\D{1}),(.*),([^\\d]*)(\\w*)$"
#define RXHDT "^\\$\\D{2}HDT,([\\d.]*),T$"

// QT
#include <QObject>
#include <QPointF>

// CUBATOR
#include <DeviceProcess.h>
#include <Settings.h>
#include <CubGeo.h>

class Gps : public DeviceProcess
{
    Q_OBJECT

public:
    Gps(QObject *parent = 0);
    ~Gps();

signals:
    void positionUpdated(QPointF);

protected:
    virtual void loadSettings();

public slots:
    void processFrame(QByteArray &frame);

protected:
    CubGeo geo;
};

#endif // GPS_H
