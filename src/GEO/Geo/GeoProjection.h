#ifndef GEOPROJECTION_H
#define GEOPROJECTION_H

// QT
#include <QString>
#include <QMap>

// LIBGEO
#include <GeoConstLambert.h>
#include <GeoType.h>

class GeoProjection{

public:
    void setDatum(DATUM datum){_datum = datum;}

    DATUM datum(){return _datum;}

    void setN(double n){_n = n;}
    double n(){return _n;}

    void setC(double c){_c = c;}
    double c(){return _c;}

    void setXs(double xs){_xs = xs;}
    double xs(){return _xs;}

    void setYs(double ys){_ys = ys;}
    double ys(){return _ys;}

    void setLg0(double lg0){_lg0 = lg0;}
    double lg0(){return _lg0;}

protected:
    double _n;
    double _c;
    double _xs;
    double _ys;
    double _lg0;

    DATUM _datum;
};

typedef QMap<PROJECTION, GeoProjection> GeoProjections;

#endif // GEOPROJECTION_H
