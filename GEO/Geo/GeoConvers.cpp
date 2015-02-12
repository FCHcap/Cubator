#include "GeoConvers.h"
#include <cmath>
#include <deque>

double GeoConvers::calcLatIso(double lt, double e){

    return log(tan(M_PI/4+lt/2)*pow((1-e*sin(lt))/(1+e*sin(lt)),(e/2)));
}

double GeoConvers::latFromLatIso(const double &lIso, const double &e, const double &eps){
    std::deque<double> phi;
    int i=0;

    phi.push_back(2*atan(exp(lIso))-M_PI/2);
    do{
        i++;
        double pLast = phi[i-1];
        phi.push_back(2*atan(pow((1+e*sin(pLast))/(1-e*sin(pLast)), e/2)*exp(lIso))-M_PI/2);
    }
    while(fabs(phi[i]-phi[i-1])>=eps);
    return phi[i];
}

void GeoConvers::projLambert(double lg, double lt, double n, double c, double e, double lbdC, double xs, double ys, double &x, double &y){
    double ltIso=calcLatIso(lt,e);

    x=xs+c*exp(-n*ltIso)*sin(n*(lg-lbdC));
    y=ys-c*exp(-n*ltIso)*cos(n*(lg-lbdC));
}

void GeoConvers::LambToGeo(double n, double e, double c, double lbdC, double xs, double ys, double x, double y, double eps, double &lbd, double &phi){

    double r=sqrt(pow(x-xs,2)+pow(ys-y,2));
    double g=atan((x-xs)/(ys-y));
    lbd=lbdC+g/n;
    double liso=(1/-n)*log(fabs(r/c));
    phi=latFromLatIso(liso, e, eps);
}

void GeoConvers::geoToCart(double lg, double lt, double he, double a, double e, double &x, double &y, double &z){

    double e2=pow(e,2);
    double n=calcN(lt,a,e);

    x=(n+he)*cos(lt)*cos(lg);
    y=(n+he)*cos(lt)*sin(lg);
    z=(n*(1-e2)+he)*sin(lt);
}

void GeoConvers::cartToGeo(double x, double y, double z, double a, double e, double epsilon, double &lg, double &lt, double &he){

    double e2=pow(e,2);
    double lt0 = 0;
    double lt1 = 0;

    lg=atan(y/x);
    lt0=atan(z/(sqrt(x*x+y*y)*(1-(a*e2)/sqrt(x*x+y*y+z*z))));
    lt1=atan(z/sqrt(x*x+y*y)*pow(1-((a*e2*cos(lt0))/(sqrt(x*x+y*y)*sqrt(1-e2*pow(sin(lt0),2)))),-1));

    while(fabs(lt1-lt0)>=epsilon){
        lt0=lt1;
        lt1=atan(z/sqrt(x*x+y*y)*pow(1-((a*e2*cos(lt0))/(sqrt(x*x+y*y)*sqrt(1-e2*pow(sin(lt0),2)))),-1));
    }

    lt=lt1;
    he=sqrt(x*x+y*y)/cos(lt)-a/sqrt(1-e2*pow(sin(lt),2));
}

void GeoConvers::transf7par(double tx, double ty, double tz, double d, double rx, double ry, double rz, double ux, double uy, double uz, double &vx, double &vy, double &vz){

    vx=tx+ux*(1+d)+uz*rx-uy*rz;
    vy=ty+uy*(1+d)+ux*rz-uz*rx;
    vz=tz+uz*(1+d)+uy*rx-ux*ry;
}

void GeoConvers::transf7parInv(double tx, double ty, double tz, double d, double rx, double ry, double rz, double ux, double uy, double uz, double &vx, double &vy, double &vz){

    vx=(tx-ux)*(d-1)+(tz-uz)*rx-(ty-uy)*rz;
    vy=(ty-uy)*(d-1)+(tx-ux)*rz-(tz-uz)*rx;
    vz=(tz-uz)*(d-1)+(ty-uy)*rx-(tx-ux)*ry;
}

double GeoConvers::calcN(double lt, double a, double e){

    return a/sqrt(1-pow(e,2)*pow(sin(lt),2));
}

void GeoConvers::calcParametersLambertSecant(double a, double e, double lbd0, double phi0, double phi1, double phi2, double x0, double y0, double &se, double &lbdC, double &n, double &c, double &xs, double &ys){

    using namespace std;

    lbdC = lbd0;
    se = e;

    double nphi1 = calcN(phi1, a, e);
    double nphi2 = calcN(phi2, a, e);
    double latphi1 = calcLatIso(phi1, e);
    double latphi2 = calcLatIso(phi2, e);

    n = log((nphi2 * cos(phi2)) / (nphi1 * cos(phi1))) / (latphi1 - latphi2);

    c = ((nphi1 * cos(phi1)) / n) * exp(n * latphi1);

    xs = x0;
    ys = y0;

    if(fabs(phi0 - M_PI/2)<=0.000001){
        xs = x0;
        ys = y0;
    }
    else{
        xs = x0;
        ys = y0 + c * exp(-n * calcLatIso(phi0, e));
    }
}

QStringList GeoConvers::listProjections(){
    QStringList projections;
    projections.append(PRO_LAMBERT1);
    projections.append(PRO_LAMBERT2);
    projections.append(PRO_LAMBERT3);
    projections.append(PRO_LAMBERT4);
    return projections;
}

QStringList GeoConvers::listDatums(){
    QStringList datums;
    datums.append(DAT_WGS84);
    datums.append(DAT_NTF);
    return datums;
}

QStringList GeoConvers::listEllipsoids(){
    QStringList ellipsoids;
    ellipsoids.append(ELL_WGS84);
    ellipsoids.append(ELL_CLARKE1880IGN);
    return ellipsoids;
}

void GeoConvers::setProjections(GeoProjections projections){
    _projections = projections;
}

void GeoConvers::setDatums(GeoDatums datums){
    _datums = datums;
}

void GeoConvers::setEllipsoids(GeoEllipsoids ellipsoids){
    _ellipsoids = ellipsoids;
}

GeoVecteur GeoConvers::WGS84GeoToLambert(GeoData data, PROJECTION projection) throw(GeoException){

    GeoProjection pro;
    GeoDatum dat;
    GeoEllipsoid clarke;
    GeoEllipsoid wgs84;

    if(!_projections.contains(projection)){
        GeoException e(GEO_BRIEF01, "GeoConvers::convertToLambert");
        throw e;
    }
    pro = _projections.value(projection);

    DATUM datum = pro.datum();
    if(!_datums.contains(datum)){
        GeoException e(GEO_BRIEF02, "GeoConvers::convertToLambert");
        throw e;
    }
    dat = _datums.value(datum);

    ELLIPSOID ellipsoid = dat.ellipsoid();
    if(!_ellipsoids.contains(ellipsoid)){
        GeoException e(GEO_BRIEF03, "GeoConvers::convertToLambert");
        throw e;
    }
    clarke = _ellipsoids.value(ellipsoid);
    wgs84 = _ellipsoids.value(ELL_WGS84);

    /* Convert geographicals coordinates to cartesians coordinates */
    double lg1=0, lt1=0, he1=0, x1=0, y1=0, z1=0;
    data = data.toRad();
    data.getCoord(lt1, lg1, GeoData::RAD);
    he1 = data.getHeight();

    geoToCart(lg1, lt1, he1, wgs84.a(), wgs84.e(), x1, y1, z1);

    /* Convert system wgs84 to ntf */
    double x2=0, y2=0, z2=0;

    transf7par(-dat.tx(), -dat.ty(), -dat.tz(), dat.scaleFactor(), dat.rx(), dat.ry(), dat.rz(), x1, y1, z1, x2, y2, z2);

    /* Convert cartesians coordinates to geographicals coordinates */
    double lg3=0, lt3=0, he3=0;

    cartToGeo(x2, y2, z2, clarke.a(), clarke.e(), 1*pow(10, -11), lg3, lt3, he3);

    /* Project coordinates to lambert */
    double x4=0, y4=0;

    projLambert(lg3, lt3, pro.n(), pro.c(), clarke.e(), pro.lg0(), pro.xs(), pro.ys(), x4, y4);

    GeoVecteur v(x4, y4, he3);
    return v;
}

GeoData GeoConvers::lambertToWGS84Geo(GeoVecteur v, PROJECTION projection) throw(GeoException){

    GeoProjection pro;
    GeoDatum dat;
    GeoEllipsoid clarke;
    GeoEllipsoid wgs84;

    if(!_projections.contains(projection)){
        GeoException e(GEO_BRIEF01, "GeoConvers::convertToLambert");
        throw e;
    }
    pro = _projections.value(projection);

    DATUM datum = pro.datum();
    if(!_datums.contains(datum)){
        GeoException e(GEO_BRIEF02, "GeoConvers::convertToLambert");
        throw e;
    }
    dat = _datums.value(datum);

    ELLIPSOID ellipsoid = dat.ellipsoid();
    if(!_ellipsoids.contains(ellipsoid)){
        GeoException e(GEO_BRIEF03, "GeoConvers::convertToLambert");
        throw e;
    }
    clarke = _ellipsoids.value(ellipsoid);
    wgs84 = _ellipsoids.value(ELL_WGS84);

    // Convert Lambert to geographicals coordinates (NGF)
    double lbd=0, phi=0;
    LambToGeo(pro.n(), clarke.e(), pro.c(), pro.lg0(), pro.xs(), pro.ys(), v.x(), v.y(), pow(10,-11), lbd, phi);

    // Convert NGF geographicals to cartesian coordinates (NGF)
    double x=0, y=0, z=0;
    geoToCart(lbd, phi, v.z(), clarke.a(), clarke.e(), x, y, z);

    // Convert NGF to WGS84 coordinates
    double x2=0, y2=0, z2=0;
    transf7par(dat.tx(), dat.ty(), dat.tz(), dat.scaleFactor(), dat.rx(), dat.ry(), dat.rz(), x, y, z, x2, y2, z2);

    // Convert WGS84 cartesian to geographicals coordinates (WGS84)
    double wlbd=0, wphi=0, whe=0;
    cartToGeo(x2, y2, z2, wgs84.a(), wgs84.e(), pow(10,-11), wlbd, wphi, whe);

    return GeoData(wphi, wlbd, GeoData::RAD, whe);
}
