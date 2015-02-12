#ifndef DEDGE_H
#define DEDGE_H

#include "DVertexList.h"

class DEdge
{
public:
    DEdge();
    DEdge(const DVertexId v1 = -1, const DVertexId v2 = -1);
    ~DEdge();

    void setV1(const DVertexId v1);
    DVertexId v1() const;

    void setV2(const DVertexId v2);
    DVertexId v2() const;

    bool equals(const DEdge &other) const;


protected:
    DVertexId _v1;
    DVertexId _v2;
};

typedef QList<DEdge> DEdges;

#endif // DEDGE_H
