#define _USE_MATH_DEFINES

#include "GeoData.h"
#include <cmath>

GeoData::GeoData(){

    ltd=0;
    ltm=0;
    ltdd=0;
    ltmd=0;
    ltsd=0;
    lgd=0;
    lgm=0;
    lgdd=0;
    lgmd=0;
    lgsd=0;
    frm=UNKNOWN;
}

GeoData::GeoData(int ltd, int ltm, double ltsd, int lgd, int lgm, double lgsd, double height){

    this->ltd=ltd;
    this->ltm=ltm;
    this->ltdd=0;
    this->ltmd=0;
    this->ltsd=ltsd;
    this->lgd=lgd;
    this->lgm=lgm;
    this->lgdd=0;
    this->lgmd=0;
    this->lgsd=lgsd;
    this->height=height;

    frm=DMS;
}

GeoData::GeoData(int ltd, double ltmd, int lgd, double lgmd, double height){

    this->ltd=ltd;
    this->ltm=0;
    this->ltdd=0;
    this->ltmd=ltmd;
    this->ltsd=0;
    this->lgd=lgd;
    this->lgm=0;
    this->lgdd=0;
    this->lgmd=lgmd;
    this->lgsd=0;
    this->height=height;

    frm=DM;
}

GeoData::GeoData(double ltdd, double lgdd, CoordFormat frm, double height){

    this->ltd=0;
    this->ltm=0;
    this->ltdd=ltdd;
    this->ltmd=0;
    this->ltsd=0;
    this->lgd=0;
    this->lgm=0;
    this->lgdd=lgdd;
    this->lgmd=0;
    this->lgsd=0;
    this->frm=(frm==D)?D:RAD;
    this->height=height;
}

//Format ddmm.mmmmm : degrés, minutes, minutes décimales
GeoData::GeoData(QString lt, QString lg, double height){

    ltm=0;
    ltdd=0;
    ltsd=0;
    lgm=0;
    lgdd=0;
    lgsd=0;
    this->height = height;

    ltd=lt.left(2).toInt();
    ltmd=lt.right(2).toInt();

    lgd=lg.left(2).toInt();
    lgmd=lg.right(2).toInt();
}

void GeoData::setCoord(int ltd, int ltm, double ltsd, int lgd, int lgm, double lgsd){

    this->ltd=ltd;
    this->ltm=ltm;
    this->ltdd=0;
    this->ltmd=0;
    this->ltsd=ltsd;
    this->lgd=lgd;
    this->lgm=lgm;
    this->lgdd=0;
    this->lgmd=0;
    this->lgsd=lgsd;

    frm=DMS;
}

void GeoData::setCoord(int ltd, double ltmd, int lgd, double lgmd){

    this->ltd=ltd;
    this->ltm=0;
    this->ltdd=0;
    this->ltmd=ltmd;
    this->ltsd=0;
    this->lgd=lgd;
    this->lgm=0;
    this->lgdd=0;
    this->lgmd=lgmd;
    this->lgsd=0;

    frm=DM;
}

void GeoData::setCoord(double ltdd, double lgdd, CoordFormat frm){

    this->ltd=0;
    this->ltm=0;
    this->ltdd=ltdd;
    this->ltmd=0;
    this->ltsd=0;
    this->lgd=0;
    this->lgm=0;
    this->lgdd=lgdd;
    this->lgmd=0;
    this->lgsd=0;
    this->frm=(frm==D)?D:RAD;
}

//Format ddmm.mmmmm : degrés, minutes, minutes décimales
void GeoData::setCoord(QString lt, QString lg){

    ltm=0;
    ltdd=0;
    ltsd=0;
    lgm=0;
    lgdd=0;
    lgsd=0;

    ltd=lt.left(2).toInt();
    ltmd=lt.right(2).toInt();

    lgd=lg.left(2).toInt();
    lgmd=lg.right(2).toInt();
}

void GeoData::setHeight(double height){
    this->height = height;
}

GeoData GeoData::toD() const{

    double ltdd2=0;
    double lgdd2=0;

    if(frm==D) {ltdd2=ltdd;
                lgdd2=lgdd;}
    if(frm==DM) {ltdd2=ltd+ltmd/60;
                 lgdd2=lgd+lgmd/60;}
    if(frm==DMS) {ltdd2=ltd+(double)ltm/60+ltsd/3600;
                  lgdd2=lgd+(double)lgm/60+lgsd/3600;}
    if(frm==RAD) {ltdd2=ltdd*180/M_PI;
                  lgdd2=lgdd*180/M_PI;}

    return GeoData(ltdd2, lgdd2);
}

GeoData GeoData::toDm() const{

    int ltd2=0;
    int lgd2=0;
    double ltmd2=0;
    double lgmd2=0;

    if(frm==D) {ltd2=(int)ltdd; ltmd2=(ltdd-ltd2)*60;
                lgd2=(int)lgdd; lgmd2=(lgdd-lgd2)*60;}
    else if(frm==DM) {ltd2=ltd; ltmd2=ltmd;
                      lgd2=lgd; lgmd2=lgmd;}
    else if(frm==DMS) {ltd2=ltd; ltmd2=ltm+ltsd/60;
                       lgd2=lgd; lgmd2=lgm+lgsd/60;}
    else if(frm==RAD) {double ltrd=ltdd/M_PI*180;
                       double lgrd=lgdd/M_PI*180;
                       ltd2=(int)ltrd; ltmd2=(ltrd-ltd2)*60;
                       lgd2=(int)lgrd; lgmd2=(lgrd-lgd2)*60;}

    return GeoData(ltd2,ltmd2,lgd2,lgmd2);
}

GeoData GeoData::toDms() const{

    int ltd2=0;
    int ltm2=0;
    int lgd2=0;
    int lgm2=0;
    double ltsd2=0;
    double lgsd2=0;

    if(frm==D) {ltd2=(int)ltdd;double ltmt=(ltdd-ltd2)*60;ltm2=(int)ltmt;ltsd2=(ltmt-ltm2)*60;
                lgd2=(int)lgdd;double lgmt=(lgdd-lgd2)*60;lgm2=(int)lgmt;lgsd2=(lgmt-lgm2)*60;}
    else if(frm==DM) {ltd2=ltd;ltm2=(int)(ltmd);ltsd2=(ltmd-ltm2)*60;
                      lgd2=lgd;lgm2=(int)(lgmd);lgsd2=(lgmd-lgm2)*60;}
    else if(frm==DMS) {ltd2=ltd;ltm2=ltm;ltsd2=ltsd;
                       lgd2=lgd;lgm2=lgm;lgsd2=lgsd;}
    else if(frm==RAD) {double ltrd=ltdd/M_PI*180;
                       double lgrd=lgdd/M_PI*180;
                       ltd2=(int)ltrd;double ltmt=(ltrd-ltd2)*60;ltm2=(int)ltmt;ltsd2=(ltmt-ltm2)*60;
                       lgd2=(int)lgrd;double lgmt=(lgrd-lgd2)*60;lgm2=(int)lgmt;lgsd2=(lgmt-lgm2)*60;}

    return GeoData(ltd2,ltm2,ltsd2,lgd2,lgm2,lgsd2);
}

GeoData GeoData::toRad() const{

    double ltdd2=0;
    double lgdd2=0;

    if(frm==D) {ltdd2=ltdd*M_PI/180;
                lgdd2=lgdd*M_PI/180;}
    else if(frm==DM) {ltdd2=(ltd+ltmd/60)*M_PI/180;
                      lgdd2=(lgd+lgmd/60)*M_PI/180;}
    else if(frm==DMS) {ltdd2=(ltd+(double)ltm/60+ltsd/3600)*M_PI/180;
                       lgdd2=(lgd+(double)lgm/60+lgsd/3600)*M_PI/180;}
    else if(frm==RAD) {ltdd2=ltdd;
                       lgdd2=lgdd;}

    return GeoData(ltdd2,lgdd2,RAD);
}

GeoData GeoData::toFormat(QString frm) const{

    if(frm == SD) return this->toD();
    if(frm == SDM) return this->toDm();
    if(frm == SDMS) return this->toDms();
    if(frm == SRAD) return this->toRad();
    return GeoData();
}

bool GeoData::getCoord(double& ltdd, double& lgdd, CoordFormat frm){
    if(frm!=this->frm) return 0;

    ltdd=this->ltdd;
    lgdd=this->lgdd;

    return 1;
}

bool GeoData::getCoord(int& ltd, double& ltmd, int& lgd, double& lgmd){
    if(frm!=DM) return 0;

    ltd=this->ltd;
    ltmd=this->ltmd;
    lgd=this->lgd;
    lgmd=this->lgmd;

    return 1;
}

bool GeoData::getCoord(int & ltd, int & ltm, double & ltsd, int & lgd, int & lgm, double & lgsd){
    if(frm!=DMS) return 0;

    ltd=this->ltd;
    ltm=this->ltm;
    ltsd=this->ltsd;
    lgd=this->lgd;
    lgm=this->lgm;
    lgsd=this->lgsd;

    return 1;
}

double GeoData::getHeight(){
    return height;
}

QString GeoData::getLatitude(){
    QString text="NULL";
    if(frm==D) text.sprintf("%lf%c",ltdd,QChar(0x00B0).toLatin1());
    else if(frm==DM) text.sprintf("%d%c%lf\'",ltd,QChar(0x00B0).toLatin1(),ltmd);
    else if(frm==DMS) text.sprintf("%d%c%d\'%lf\"",ltd,QChar(0x00B0).toLatin1(),ltm,ltsd);
    else if(frm==RAD) text.sprintf("%lf RAD",ltdd);

    return text;
}

QString GeoData::getLongitude(){
    QString text="NULL";
    if(frm==D) text.sprintf("%lf%c",lgdd,QChar(0x00B0).toLatin1());
    else if(frm==DM) text.sprintf("%d%c%lf\'",lgd,QChar(0x00B0).toLatin1(),lgmd);
    else if(frm==DMS) text.sprintf("%d%c%d\'%lf\"",lgd,QChar(0x00B0).toLatin1(),lgm,lgsd);
    else if(frm==RAD) text.sprintf("%lf RAD",lgdd);

    return text;
}

GeoData::CoordFormat GeoData::getFormat(){
    return frm;
}

QStringList GeoData::formats(){
    QStringList list;
    list << SD << SDM << SDMS << SRAD;
    return list;
}


