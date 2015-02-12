#ifndef DTriangleList_H
#define DTriangleList_H

#include <QList>
#include <QVariant>
#include <QPointF>

#include <cmath>
#include <cfloat>

#include <DTypes.h>

class DTriangle
{

public:
    DTriangle(const DVertexId v1 = -1, const DVertexId v2 = -1, const DVertexId v3 = -1);
    DTriangle(const DTriangle &other);
    DTriangle & operator = (const DTriangle & other);
    ~DTriangle();

    void setV1(const DVertexId v1);
    DVertexId v1() const;

    void setV2(const DVertexId v2);
    DVertexId v2() const;

    void setV3(const DVertexId v3);
    DVertexId v3() const;

    bool isNeighbor(const DTriangle &t) const;

    void setCircumCenter(const QPointF &center);
    bool circumCenterIsValid() const;
    QPointF circumCenter() const;

protected:
    DVertexId _v1;
    DVertexId _v2;
    DVertexId _v3;

    QPointF _circumCenter;
    bool _circumCenterIsValid;
};

typedef QList<DTriangle> DTriangleList;

Q_DECLARE_METATYPE(DTriangle)

#endif // DTriangleList_H
