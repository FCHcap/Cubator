#ifndef GEOCONVERS_H
#define GEOCONVERS_H

// QT
#include <QStringList>
#include <QMap>
#include <QString>

// LIBGEO
#include <GeoType.h>
#include <GeoEllipsoid.h>
#include <GeoDatum.h>
#include <GeoProjection.h>
#include <GeoVecteur.h>
#include <GeoData.h>
#include <GeoException.h>
#include <GeoMessages.h>

// STL
#include <cfloat>
#include <climits>
#include <iostream>

class GeoConvers{

public:

    GeoConvers(){}
    ~GeoConvers(){}

    static QStringList listProjections();
    static QStringList listDatums();
    static QStringList listEllipsoids();

    void setProjections(GeoProjections projections);
    void setDatums(GeoDatums datums);
    void setEllipsoids(GeoEllipsoids ellipsoids);

    GeoVecteur WGS84GeoToLambert(GeoData data, PROJECTION projection) throw (GeoException);
    GeoData lambertToWGS84Geo(GeoVecteur, PROJECTION projection) throw (GeoException);

public:
    //Calcul de la latitude isométrique (IGN ALG0001)
    static double calcLatIso(double phi, double e);

    //Calcul de la latitude phi à partir de la latitude isométrique lbd (IGN ALG0002)
    static double latFromLatIso(const double &lIso, const double &e, const double &eps);

    //Projection Lambert (IGN ALG0003)
    static void projLambert(double lbd, double phi, double n, double c, double e, double ldbC, double xs, double ys, double &x, double &y);

    //Transformation coordonnées Lambert -> coordonnées géographiques (IGN ALG0004)
    static void LambToGeo(double n, double e, double c, double lbdC, double xs, double ys, double x, double y, double eps, double &lbd, double &phi);

    //Transformation coordonnées géographiques -> cartésiennes (IGN ALG0009)
    static void geoToCart(double lbd, double phi, double he, double a, double e, double &x, double &y, double &z);

    //Transformation coordonnées cartésiennes -> géographiques (IGN ALG0012)
    static void cartToGeo(double x, double y, double z, double a, double e, double epsilon, double &lbd, double &phi, double &he);

    //Transformation à 7 paramètres entre deux système géodésique (IGN ALG0013)
    static void transf7par(double tx, double ty, double tz, double d, double rx, double ry, double rz, double ux, double uy, double uz, double &vx, double &vy, double &vz);

    //Transformation ) 7 paramètres entre deux système géodésique (IGN ALG0013 bis)
    static void transf7parInv(double tx, double ty, double tz, double d, double rx, double ry, double rz, double ux, double uy, double uz, double &vx, double &vy, double &vz);

    //Calcul de la grande normale (IGN ALG0021)
    static double calcN(double phi, double a, double e);

    //Calcul des paramètres de projection (IGN ALG0054)
    static void calcParametersLambertSecant(double a, double e, double lbd0, double phi0, double phi1, double phi2, double x0, double y0, double &se, double &lbdC, double& n, double& c, double& xs, double& ys);

protected:
    GeoProjections _projections;
    GeoDatums _datums;
    GeoEllipsoids _ellipsoids;
};
#endif // GEOCONVERS_H
