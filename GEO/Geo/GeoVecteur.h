#ifndef GEOVECTEUR_H
#define GEOVECTEUR_H

class GeoVecteur{

public:
    GeoVecteur(){
        _x = 0;
        _y = 0;
        _z = 0;
    }
    GeoVecteur(double x, double y, double z){
        _x = x;
        _y = y;
        _z = z;
    }

    void setX(double x){_x = x;}
    void setY(double y){_y = y;}
    void setZ(double z){_z = z;}

    double x(){return _x;}
    double y(){return _y;}
    double z(){return _z;}

private:
    double _x;
    double _y;
    double _z;
};

#endif // GEOVECTEUR_H
