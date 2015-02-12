#include "DVertexList.h"

DVertexList::DVertexList(){
    _mutex = new QMutex();
}

DVertexList::DVertexList(const DVertexList &other) : QList<DVertex>(other){
    _mutex = new QMutex();
}

DVertexList::~DVertexList(){
    delete _mutex;
}

DVertexList & DVertexList::operator=(const DVertexList &other){
    QList<DVertex> *l1, *l2;
    l1 = this;
    l2 = (QList<DVertex>*) &other;
    *l1 = *l2;
    return *this;
}

QMutex * DVertexList::mutex(){
    return _mutex;
}

DTriangleList *DVertexList::triangles(){
    return &_triangles;
}

DTGrid * DVertexList::grid(){
    return &_grid;
}

QPointF DVertexList::calculateCircumCenter(const DTriangle &t){

    const DVertex &v1 = at(t.v1());
    const DVertex &v2 = at(t.v2());
    const DVertex &v3 = at(t.v3());

    double epsilon = DBL_MIN;

    if(fabs(v1.y() - v2.y()) < epsilon && fabs(v2.y() - v3.y()) < epsilon){
        throw CubException(BRIEF00, ERROR04, "DVertexList::calculateCircumCenter");
    }

    double m1 = 0;
    double m2 = 0;

    double mx1 = 0;
    double mx2 = 0;

    double my1 = 0;
    double my2 = 0;

    double xc = 0;
    double yc = 0;

    if(fabs(v2.y() - v1.y()) < epsilon){
        m2 = -(v3.x() - v2.x()) / (v3.y() - v2.y());
        mx2 = (v2.x() + v3.x()) * 0.5;
        my2 = (v2.y() + v3.y()) * 0.5;

        // Calculate CircumCircle center (xc, yc)
        xc = (v2.x() + v1.x()) * 0.5;
        yc = m2 * (xc - mx2) + my2;
    }
    else if(fabs(v3.y() - v2.y()) < epsilon){
        m1 = -(v2.x() - v1.x()) / (v2.y() - v1.y());
        mx1 = (v1.x() + v2.x()) * 0.5;
        my1 = (v1.y() + v2.y()) * 0.5;

        // Calculate CircumCircle center (xc, yc)
        xc = (v3.x() + v2.x()) * 0.5;
        yc = m1 * (xc - mx1) + my1;
    }
    else{
        m1 = -(v2.x() - v1.x()) / (v2.y() - v1.y());
        m2 = -(v3.x() - v2.x()) / (v3.y() - v2.y());
        mx1 = (v1.x() + v2.x()) * 0.5;
        mx2 = (v2.x() + v3.x()) * 0.5;
        my1 = (v1.y() + v2.y()) * 0.5;
        my2 = (v2.y() + v3.y()) * 0.5;

        // Calculate CircumCircle center (xc, yc)
        xc = (m1 * mx1 - m2 * mx2 + my2 - my1) / (m1 - m2);
        yc = m1 * (xc - mx1) + my1;
    }

    return QPointF(xc, yc);
}

void DVertexList::updateCircumCenter(DTriangle &t){
    t.setCircumCenter(calculateCircumCenter((const DTriangle&)t));
}

bool DVertexList::inCircle(DTriangleId triangleId, DVertexId vectorId){

    if(triangleId < 0 || triangleId >= size()) throw CubException(BRIEF00, ERROR05, "DVertexList::inCircle");
    if(vectorId < 0 || vectorId >= size()) throw CubException(BRIEF00, ERROR06, "DVertexList::inCircle");

    return inCircle(_triangles.at(triangleId), at(vectorId).toPointF());
}

bool DVertexList::inCircle(const DTriangle &t, const QPointF &pos){

    const DVertex &v2 = (DVertex &) at(t.v2());

    QPointF center;

    if(t.circumCenterIsValid()){
        center = t.circumCenter();
    }
    else{
        center = calculateCircumCenter(t);
    }

    double dx = v2.x() - center.x();
    double dy = v2.y() - center.y();
    double rsqr = dx * dx + dy * dy;

    dx = pos.x() - center.x();
    dy = pos.y() - center.y();
    double drsqr = dx * dx + dy * dy;

    return (drsqr <= rsqr);
}

bool DVertexList::inTriangle(const DTriangle &t, const QPointF &pos){

    const DVertex &a = at(t.v1());
    const DVertex &b = at(t.v2());
    const DVertex &c = at(t.v3());

    int cpt = 0;

    for(int i=0; i<3; i++){

        const DVertex *v1 = 0;
        const DVertex *v2 = 0;
        const DVertex *v3 = 0;

        LineEquation e;

        switch(i){
        case 0:
            v1 = &a;
            v2 = &b;
            v3 = &c;
            break;

        case 1:
            v1 = &b;
            v2 = &c;
            v3 = &a;
            break;

        case 2:
            v1 = &c;
            v2 = &a;
            v3 = &b;
            break;
        }

        if(fabs(v1->x() - v2->x()) <= DBL_MIN){
            e.setParallelToY();
            e.setC(v1->x());

            if((v3->x() > e.c() && pos.x() > e.c()) || (v3->x() < e.c() && pos.x() < e.c())) cpt++;
            else if(pos.x() == e.c()){
                cpt++;
            }

            continue;
        }
        else if(fabs(v1->y() - v2->y()) <= DBL_MIN){
            e.setParallelToX();
            e.setC(v1->y());

            if((v3->y() > e.c() && pos.y() > e.c()) || (v3->y() < e.c() && pos.y() < e.c())) cpt++;
            else if(pos.y() == e.c()){
                cpt++;
            }

            continue;
        }
        else{
            e.setA((v1->y() - v2->y()) / (v1->x() - v2->x()));
            e.setB(v1->y() - e.a() * v1->x());

            if(fabs(e.a()) <= DBL_MIN){
                throw CubException (BRIEF00, ERROR07, "DVertexList::inTriangle");
            }

            // Calculates the coordinates of the point opposite, projected on the right.
            double lxv3 = (v3->y() - e.b()) / e.a();

            // Calculates the coordinates of the point selected, projected on the right.
            double lxpos = (pos.y() - e.b()) / e.a();

            if((v3->x() < lxv3 && pos.x() < lxpos) || (v3->x() > lxv3 && pos.x() > lxpos)) cpt++;
            else if(pos.x() == lxpos) cpt++;

            continue;
        }
    }

    return (cpt == 3);
}

bool DVertexList::triangleIsValid(const DTriangle &t, const double edgeLength){

    if(edgeLength <= DBL_MIN) return 1;

    const DVertex &a = at(t.v1());
    const DVertex &b = at(t.v2());
    const DVertex &c = at(t.v3());

    for(int i=0; i<3; i++){
        const DVertex *v1 = 0;
        const DVertex *v2 = 0;

        LineEquation e;

        switch(i){
        case 0:
            v1 = &a;
            v2 = &b;
            break;

        case 1:
            v1 = &b;
            v2 = &c;
            break;

        case 2:
            v1 = &c;
            v2 = &a;
            break;
        }

        if(sqrt(pow(v1->x() - v2->x(), 2) + pow(v1->y() - v2->y(), 2)) > edgeLength) return 0;
    }
    return 1;
}

QPointF DVertexList::calculateGravityCenter(const DTriangle &t){
    QPointF center;
    const DVertex &v1 = at(t.v1());
    const DVertex &v2 = at(t.v2());
    const DVertex &v3 = at(t.v3());
    center.setX((v1.x() + v2.x() + v3.x())/3);
    center.setY((v1.y() + v2.y() + v3.y())/3);
    return center;
}

QRectF DVertexList::bounds(){

    QRectF rect;

    if(size() > 0){
        rect.setLeft(at(0).x());
        rect.setRight(at(0).x());
        rect.setTop(at(0).y());
        rect.setBottom(at(0).y());

        for(int i=1; i<size(); i++){
            double x = at(i).x();
            double y = at(i).y();

            if(x < rect.left()) rect.setLeft(x);
            if(x > rect.right()) rect.setRight(x);
            if(y > rect.bottom()) rect.setBottom(y);
            if(y < rect.top()) rect.setTop(y);
        }
    }

    return rect;
}

QRectF DVertexList::boundsTriangle(const DTriangle &t){

    const DVertex &v1 = at(t.v1());
    const DVertex &v2 = at(t.v2());
    const DVertex &v3 = at(t.v3());

    QRectF rTriangle(QPointF(v1.x(), v1.y()), QPointF(v1.x(), v1.y()));

    for(int j = 0; j<2; j++){

        DVertex v;
        (!j)?v=v2:v=v3;

        if(v.x() < rTriangle.left()) rTriangle.setLeft(v.x());
        if(v.x() > rTriangle.right()) rTriangle.setRight(v.x());
        if(v.y() > rTriangle.bottom()) rTriangle.setBottom(v.y());
        if(v.y() < rTriangle.top()) rTriangle.setTop(v.y());
    }

    return rTriangle;
}

double DVertexList::depthMin(){

    double depth;

    (size() > 0) ? depth = at(0).z() : depth = -DBL_MIN;

    for(int i=1; i<size(); i++){
        if(fabs(depth) > fabs(at(i).z())) depth = at(i).z();
    }

    return depth;
}

double DVertexList::depthMax(){

    double depth;

    (size() > 0) ? depth = at(0).z() : depth = -DBL_MIN + 0.1;

    for(int i=0; i<size(); i++){
        if(fabs(depth) < fabs(at(i).z())) depth = at(i).z();
    }

    return depth;
}

bool DVertexList::depthAt(const QPointF &pos, double & depth){

    for(int i=0; i<this->size(); i++){
        if(fabs(pos.x()-this->at(i).x()) < DBL_MIN && fabs(pos.y()-this->at(i).y()) < DBL_MIN){
            return this->at(i).z();
        }
    }
    // Checks if the point is in a triangle
    for(int i=0; i<_triangles.size(); i++){

        DTriangle &t = _triangles[i];

        if(!t.circumCenterIsValid()) updateCircumCenter(t);
        if(inCircle(t, pos)){
            if(inTriangle(t, pos)){
                PlaneEquation pe = equation(t);
                depth = depthFromEquation(pe, pos);
                return true;
            }
        }
    }
    return false;
}

bool DVertexList::depthGridAt(const QPointF &pos, double &depth){

    for(int i=0; i<this->size(); i++){
        if(fabs(pos.x()-this->at(i).x()) < DBL_MIN && fabs(pos.y()-this->at(i).y()) < DBL_MIN){
            return this->at(i).z();
        }
    }

    // Checks if the point is in a triangle
    int ix = (int) ((pos.x()-_grid.bounds().x())/20);
    int iy = (int) ((pos.y()-_grid.bounds().y())/20);
    int id = ix*_grid.bounds().height()+iy;

    DTGridItem &gi = _grid[id];
    for(int i=0; i<gi._triangles.size(); i++){

        DTriangle &t = _triangles[gi._triangles[i]];

        if(!t.circumCenterIsValid()) updateCircumCenter(t);
        if(inCircle(t, pos)){
            if(inTriangle(t, pos)){
                PlaneEquation pe = equation(t);
                depth = depthFromEquation(pe, pos);
                return true;
            }
        }
    }
    return false;
}

QColor DVertexList::colorZ(const double &depth, const double &depthMax, const double &depthMin){

    int code = fabs(depth) * 510 / (fabs(depthMax) - fabs(depthMin));
    int r=0, g=0, b=0;

    if(code < 255){
        r = 255 - code;
        g = code;
    }
    else if(code == 255){
        g = code;
    }
    else{
        if(code > 510) code = 510;
        g = 510 - code;
        b = code - 255;
    }

    return QColor(r, g, b);
}

PlaneEquation DVertexList::equation(const DTriangle &t){
    return equation(at(t.v1()), at(t.v2()), at(t.v3()));
}

PlaneEquation DVertexList::equation(const DVertex &va, const DVertex &vb, const DVertex &vc){

    QVector3D vab, vac;
    vab.setX(vb.x() - va.x());
    vab.setY(vb.y() - va.y());
    vab.setZ(vb.z() - va.z());
    vac.setX(vc.x() - va.x());
    vac.setY(vc.y() - va.y());
    vac.setZ(vc.z() - va.z());


    PlaneEquation eq;
    eq.setA(vab.y() * vac.z() - vab.z() * vac.y());
    eq.setB(-(vab.x() * vac.z() - vab.z() * vac.x()));
    eq.setC(vab.x() * vac.y() - vab.y() * vac.x());

    eq.setD(-eq.a() * va.x() - eq.b() * va.y() - eq.c() * va.z());
    return eq;
}

double DVertexList::depthFromEquation(const PlaneEquation &eq, const QPointF &pos){
    return (-eq.a() * pos.x() -eq.b() * pos.y() -eq.d())/eq.c();
}
