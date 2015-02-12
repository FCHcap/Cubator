#include "VerticesLoadingProcess.h"

VerticesLoadingProcess::VerticesLoadingProcess()
{
    _vertices = 0;
}

void VerticesLoadingProcess::setVertices(DVertexList &vertices){
    _vertices = &vertices;
}

void VerticesLoadingProcess::run(){

    try{
        if(!_vertices) throw CubException(BRIEF00, ERROR08, "VerticesLoadingProcess::start");

        QGraphicsItemGroup * verticesItem = new QGraphicsItemGroup;
        DVertexList & vertices = *_vertices;

        const double dmax = vertices.depthMax();
        const double dmin = vertices.depthMin();

        int cpt = 0;
        int size = vertices.size();

        QMutexLocker locker(vertices.mutex());

        emit processNameUpdated(PROCESS10);
        emit levelUpdated(0);

        if(verticesItem->childItems().isEmpty()){
            foreach(DVertex v, vertices){
                QColor color = vertices.colorZ(v.z(), dmax, dmin);
                QGraphicsEllipseItem *ellipse = new QGraphicsEllipseItem(0, 0, 0.2, 0.2);
                ellipse->setCacheMode(QGraphicsItem::DeviceCoordinateCache);
                ellipse->setOpacity(1.0);
                ellipse->setPen(QPen(color));
                ellipse->setBrush(color);
                ellipse->setPos(v.toPointF() - QPointF(0.1, 0.1));
                verticesItem->addToGroup(ellipse);

                cpt++;
                emit levelUpdated((int) (cpt * 100 / size));
            }
        }

        emit verticesItemUpdated(verticesItem);
    }
    catch(const CubException & e){
        emit exceptionLaunched(e);
    }
}

