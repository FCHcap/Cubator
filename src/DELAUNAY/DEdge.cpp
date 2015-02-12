#include "DEdge.h"

DEdge::DEdge(){
    _v1 = 0;
    _v2 = 0;
}

DEdge::DEdge(const DVertexId v1, const DVertexId v2)
{
    _v1 = (DVertexId)v1;
    _v2 = (DVertexId)v2;
}

DEdge::~DEdge(){
}

 void DEdge::setV1(const DVertexId v1){
     _v1 = (DVertexId)v1;
 }

 DVertexId DEdge::v1() const{
     return _v1;
 }

 void DEdge::setV2(const DVertexId v2){
     _v2 = (DVertexId)v2;
 }

 DVertexId DEdge::v2() const{
     return _v2;
 }


bool DEdge::equals(const DEdge &other) const{
    return (((_v1 == other.v2()) && (_v2 == other.v1())) || ((_v1 == other.v1()) && (_v2 == other.v2())));
}

