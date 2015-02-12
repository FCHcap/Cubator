#include "GridCalculatorProcess.h"

GridCalculatorProcess::GridCalculatorProcess(QObject * parent) : DefaultProcess(parent)
{
    _verticesList = 0;
}

GridCalculatorProcess::~GridCalculatorProcess(){

}

void GridCalculatorProcess::setVertexList(DVertexList &list){
    _verticesList = &list;
}

void GridCalculatorProcess::run(){
    CubException e;
    e.setMethod("GridCalculatorProcess::run");

    try{
        if(!_verticesList){
            e.setBrief(BRIEF00);
            e.setError(ERROR08);
        }

        DTriangleList * triangles = _verticesList->triangles();
        DTGrid * grid = _verticesList->grid();
        grid->clear();

        if(triangles->isEmpty()){
            e.setBrief(BRIEF00);
            e.setError(ERROR09);
            throw e;
        }

        emit processNameUpdated(PROCESS02);

        // Initializes the grid
        QRectF bd = _verticesList->bounds();
        QRect b;
        b.setX((int) bd.x());
        b.setY((int) bd.y());
        b.setWidth(bd.width()/STITCH+1);
        b.setHeight(bd.height()/STITCH+1);
        grid->setBounds(b);

        for(int i=0; i<b.width(); i++){
            int x = (int) bd.x() + i*STITCH;
            for(int j=0; j<b.height(); j++){
                int y = (int) bd.y() + j*STITCH;
                DTGridItem gi;
                QRect r;
                r.setX(x);
                r.setY(y);
                r.setWidth(STITCH);
                r.setHeight(STITCH);
                gi._bounds = r;
                grid->append(gi);
            }
        }

        // Updates the grid
        int ts = triangles->size();
        for(int i=0; i<ts; i++){
            DTriangle &t = (*triangles)[i];
            if(!t.circumCenterIsValid()) _verticesList->updateCircumCenter(t);

            QPolygonF p1;
            p1 << ((DVertex&)(*_verticesList)[t.v1()]).toPointF() << ((DVertex&)(*_verticesList)[t.v2()]).toPointF() << ((DVertex&)(*_verticesList)[t.v3()]).toPointF();
            for(int j=0; j<grid->size(); j++){
                DTGridItem & gi = (*grid)[j];
                QPolygonF p, p2;
                QRect r = gi._bounds;

                p2 << QPointF(r.x(), r.y()) << QPointF(r.x()+r.width(), r.y()) << QPointF(r.x()+r.width(), r.y()+r.height()) << QPointF(r.x(), r.y()+r.height());
                p = p1.intersected(p2);
                if(!p.isEmpty() && !gi._triangles.contains(i))
                    gi._triangles.append(i);
                else
                    p = p2;
            }

            emit levelUpdated(i*100/ts);
        }
        emit levelUpdated(100);

    }
    catch(CubException &e){
        emit exceptionLaunched(e);
    }
}
