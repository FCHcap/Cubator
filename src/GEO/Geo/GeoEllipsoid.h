#ifndef GEOELLIPSOID_H
#define GEOELLIPSOID_H

// STL
#include <cmath>

// QT
#include <QString>
#include <QMap>

// LIBGEO
#include <GeoType.h>

class GeoEllipsoid{

public:

    GeoEllipsoid(){
        _a = 0;
        _b = 0;
    }

    void setA(double a){_a = a;}
    void setB(double b){_b = b;}
    //void setName(QString name){_name = name;}

    double a(){return _a;}
    double b(){return _b;}
    //QString name(){return _name;}
    double f(){return (_a - _b)/_a;}
    double e(){return sqrt(pow(_a, 2) - pow(_b, 2))/_a;}

private:
    double _a;
    double _b;
    //QString _name;
};

typedef QMap<ELLIPSOID, GeoEllipsoid> GeoEllipsoids;


#endif // GEOELLIPSOID_H
