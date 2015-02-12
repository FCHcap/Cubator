#ifndef CUBGEO_H
#define CUBGEO_H

// LIBGEO
#include <GeoConvers.h>
#include <GeoEllipsoid.h>
#include <GeoDatum.h>
#include <GeoProjection.h>
#include <GeoException.h>

// CUBATOR
#include <Settings.h>

class CubGeo : public GeoConvers
{
public:
    CubGeo();
    ~CubGeo();

    void loadSettings();
};


#endif // CUBGEO_H
