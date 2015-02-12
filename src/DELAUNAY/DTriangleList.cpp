#include "DTriangleList.h"

DTriangle::DTriangle(const DVertexId v1, const DVertexId v2, const DVertexId v3)
{
    _v1 = (DVertexId)v1;
    _v2 = (DVertexId)v2;
    _v3 = (DVertexId)v3;
    _circumCenterIsValid = false;
}

DTriangle::DTriangle(const DTriangle &other){
    _v1 = other._v1;
    _v2 = other._v2;
    _v3 = other._v3;
    _circumCenter = other._circumCenter;
    _circumCenterIsValid = other._circumCenterIsValid;
}

DTriangle & DTriangle::operator =(const DTriangle & other){
    _v1 = other._v1;
    _v2 = other._v2;
    _v3 = other._v3;
    _circumCenter = other._circumCenter;
    _circumCenterIsValid = other._circumCenterIsValid;
    return *this;
}

DTriangle::~DTriangle(){

}

void DTriangle::setV1(const DVertexId v1){
    _v1 = (DVertexId)v1;
    _circumCenterIsValid = false;
}

DVertexId DTriangle::v1() const{
    return _v1;
}

void DTriangle::setV2(const DVertexId v2){
    _v2 = (DVertexId)v2;
    _circumCenterIsValid = false;
}

DVertexId DTriangle::v2() const{
    return _v2;
}

void DTriangle::setV3(const DVertexId v3){
    _v3 = (DVertexId)v3;
    _circumCenterIsValid = false;
}

DVertexId DTriangle::v3() const{
    return _v3;
}

bool DTriangle::isNeighbor(const DTriangle &t) const{

    int commonPts = 0;
    if((_v1 == t.v1()) || (_v1 == t.v2()) || (_v1 == t.v3())) commonPts++;
    if((_v2 == t.v1()) || (_v2 == t.v2()) || (_v2 == t.v3())) commonPts++;
    if((_v3 == t.v1()) || (_v3 == t.v2()) || (_v3 == t.v3())) commonPts++;

    if(commonPts == 2) return 1;
    return 0;
}

void DTriangle::setCircumCenter(const QPointF &center){
    _circumCenter = center;
    _circumCenterIsValid = true;
}

bool DTriangle::circumCenterIsValid() const{
    return _circumCenterIsValid;
}

QPointF DTriangle::circumCenter() const{
    return _circumCenter;
}


