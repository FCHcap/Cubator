#ifndef GEODATA_H
#define GEODATA_H

// QT
#include <QString>
#include <QStringList>
#include <QCoreApplication>

#define SD GeoData::tr("Decimal degrees")
#define SDM GeoData::tr("Degrees, decimal minutes")
#define SDMS GeoData::tr("Degrees, minutes, decimal seconds")
#define SRAD GeoData::tr("Radians")

class GeoData{

    Q_DECLARE_TR_FUNCTIONS(GeoData)

public:

    enum CoordFormat{DMS, DM, D, RAD, UNKNOWN};

    GeoData();
    GeoData(int ltd, int ltm, double ltsd, int lgd, int lgm, double lgsd, double height = 0);
    GeoData(int ltd, double ltmd, int lgd, double lgmd, double height = 0);
    GeoData(double ltds, double lgds, CoordFormat frm=D, double height = 0);
    GeoData(QString lt, QString lg, double height = 0);

    void setCoord(int ltd, int ltm, double ltsd, int lgd, int lgm, double lgsd);
    void setCoord(int ltd, double ltmd, int lgd, double lgmd);
    void setCoord(double ltds, double lgds, CoordFormat frm=D);
    void setCoord(QString lt, QString lg);
    void setHeight(double height);

    GeoData toRad() const;
    GeoData toDms() const;
    GeoData toDm() const;
    GeoData toD() const;
    GeoData toFormat(QString frm) const; // SD, SDM, SDMS, SRAD

    bool getCoord(double& ltdd, double& lgdd, CoordFormat frm);
    bool getCoord(int& ltd, double& ltmd, int& lgd, double& lgmd);
    bool getCoord(int& ltd, int& ltm, double& ltsd, int& lgd, int& lgm, double& lgsd);
    double getHeight();

    QString getLatitude();
    QString getLongitude();

    CoordFormat getFormat();

    static QStringList formats();

private:
    double ltdd;
    double ltmd;
    double ltsd;
    int ltd;
    int ltm;

    double lgdd;
    double lgmd;
    double lgsd;
    int lgd;
    int lgm;

    double height;

    CoordFormat frm;
};

#endif // GEODATA_H


