#ifndef GEOCONSTLAMBERT_H
#define GEOCONSTLAMBERT_H

class GeoConstLambert
{
public:
    GeoConstLambert(){
        _n = 0;
        _c = 0;
        _xs = 0;
        _ys = 0;
        _lg0 = 0;
    }

    void setN(double n){_n = n;}
    void setC(double c){_c = c;}
    void setXs(double xs){_xs = xs;}
    void setYs(double ys){_ys = ys;}
    void setLong0(double lg0){_lg0 = lg0;}
    double n(){return _n;}
    double c(){return _c;}
    double xs(){return _xs;}
    double ys(){return _ys;}
    double lg0(){return _lg0;}

protected:
    double _n;
    double _c;
    double _xs;
    double _ys;
    double _lg0;
};

#endif // GEOCONSTLAMBERT_H
