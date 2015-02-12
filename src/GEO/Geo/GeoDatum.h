#ifndef GEODATUM_H
#define GEODATUM_H

// QT
#include <QMap>

// LIBGEO
#include <GeoType.h>

class GeoDatum
{
public:

    GeoDatum(){
        _tx = _ty = _tz = 0;
        _rx = _ry = _rz = 0;
        _sf = 0;
    }

    void setEllipsoid(ELLIPSOID ge){_ge = ge;}

    void setTx(int tx){_tx = tx;}
    void setTy(int ty){_ty = ty;}
    void setTz(int tz){_tz = tz;}
    void setRx(int rx){_rx = rx;}
    void setRy(int ry){_ry = ry;}
    void setRz(int rz){_rz = rz;}
    void setScaleFactor(int sf){_sf = sf;}

    ELLIPSOID ellipsoid(){return _ge;}
    int tx(){return _tx;}
    int ty(){return _ty;}
    int tz(){return _tz;}
    int rx(){return _rx;}
    int ry(){return _ry;}
    int rz(){return _rz;}
    int scaleFactor(){return _sf;}

protected:
    ELLIPSOID _ge;
    int _tx;
    int _ty;
    int _tz;
    int _rx;
    int _ry;
    int _rz;
    int _sf;
};

typedef QMap<DATUM, GeoDatum> GeoDatums;

#endif // GEODATUM_H
