#include "VerticesLoadingProcess.h"

VerticesLoadingProcess::VerticesLoadingProcess()
{
    _vertices = 0;
}

void VerticesLoadingProcess::setVertices(DVertexList &vertices, const bool displayDepth){
    _vertices = &vertices;
    _displayDepth = displayDepth;
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

                GraphicsPointXYZItem *item = new GraphicsPointXYZItem(_displayDepth);
                item->setVertex(v, color);
                verticesItem->addToGroup(item);

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

