#ifndef DVertexList_H
#define DVertexList_H

// QT
#include <QList>
#include <QMap>
#include <QMutex>
#include <QVector3D>
#include <QVariant>
#include <QRectF>
#include <QPixmap>
#include <QCoreApplication>

// CUBATOR
#include <DTriangleList.h>
#include <DTypes.h>
#include <CubException.h>
#include <DTGrid.h>

// STL
#include <cmath>
#include <climits>

typedef QVector3D DVertex;

class LineEquation{

public:
    LineEquation(){_a = 0; _b = 0; _c = 0; _xParallel = 0; _yParallel = 0;}
    LineEquation(const LineEquation &other){_a = other._a; _b = other._b; _c = other._c; _xParallel = other._xParallel; _yParallel = other._yParallel;}
    ~LineEquation(){}

    double a(){return _a;}
    double b(){return _b;}
    double c(){return _c;}
    bool isParallelToX(){return _xParallel;}
    bool isParallelToY(){return _yParallel;}

    void setA(const double &a){_a = a;}
    void setB(const double &b){_b = b;}
    void setC(const double &c){_c = c;}
    void setParallelToX(bool parallel = 1){_xParallel = parallel;}
    void setParallelToY(bool parallel = 1){_yParallel = parallel;}

protected:
    double _a;
    double _b;
    double _c;
    bool _xParallel;
    bool _yParallel;
};

class PlaneEquation{

public:
    PlaneEquation(){_a = 0;_b = 0;_c = 0;_d = 0;}
    PlaneEquation(const PlaneEquation &other){_a = other._a; _b = other._b; _c = other._c; _d = other._d;}
    ~PlaneEquation(){}

    double a() const {return _a;}
    double b() const {return _b;}
    double c() const {return _c;}
    double d() const {return _d;}

    void setA(const double &a){_a = a;}
    void setB(const double &b){_b = b;}
    void setC(const double &c){_c = c;}
    void setD(const double &d){_d = d;}

protected:
    double _a;
    double _b;
    double _c;
    double _d;
};

class DVertexList : public QList<DVertex>
{
    Q_DECLARE_TR_FUNCTIONS(DVertexList)

public:

    DVertexList();
    DVertexList(const DVertexList &other);
    ~DVertexList();

    DVertexList & operator =(const DVertexList &other);

    QMutex * mutex();
    DTriangleList * triangles();
    DTGrid * grid();

    QPointF calculateCircumCenter(const DTriangle &t);
    void updateCircumCenter(DTriangle &t);
    bool inCircle(DTriangleId triangleId, DVertexId vectorId);
    bool inCircle(const DTriangle &t, const QPointF &pos);
    bool inTriangle(const DTriangle &t, const QPointF &pos);
    bool triangleIsValid(const DTriangle &t, const double edgeLength);

    QPointF calculateGravityCenter(const DTriangle &t);

    QRectF bounds();
    QRectF boundsTriangle(const DTriangle &t);
    double depthMin();
    double depthMax();
    bool depthAt(const QPointF &pos, double & depth);
    bool depthGridAt(const QPointF &pos, double &depth);

    static QColor colorZ(const double &depth, const double &depthMax, const double &depthMin = DBL_MIN);
    PlaneEquation equation(const DTriangle &t);
    PlaneEquation equation(const DVertex &va, const DVertex &vb, const DVertex &vc);
    static double depthFromEquation(const PlaneEquation &eq, const QPointF &pos);

protected:
    QMutex *_mutex;
    DTriangleList _triangles;
    DTGrid _grid;
};

Q_DECLARE_METATYPE(DVertex)

#endif // DVertexList_H
