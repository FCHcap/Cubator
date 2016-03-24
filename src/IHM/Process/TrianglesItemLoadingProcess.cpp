#include "TrianglesItemLoadingProcess.h"

TrianglesItemLoadingProcess::TrianglesItemLoadingProcess()
{
    _vertices = 0;
}

void TrianglesItemLoadingProcess::setVertices(DVertexList &vertices){
    _vertices = &vertices;
}

void TrianglesItemLoadingProcess::run(){

    try{

        QGraphicsItemGroup * trianglesItem = new QGraphicsItemGroup;
        trianglesItem->setCacheMode(QGraphicsItem::DeviceCoordinateCache);

        QPen pen(Qt::SolidLine);
        pen.setColor(Qt::red);
        pen.setWidth(1);
        pen.setCosmetic(true);

        if(!_vertices) throw CubException(BRIEF00, ERROR08, "TrianglesItemLoadingProcess::start");

        DVertexList &vertices = *_vertices;

        int cpt = 0;
        int size = vertices.triangles()->size();

        QMutexLocker locker(vertices.mutex());

        emit processNameUpdated(PROCESS09);
        emit levelUpdated(0);

        if(trianglesItem->childItems().isEmpty()){

            int vcount = vertices.count();

            ENode ** edg = new ENode*[vcount];
            for(int i=0; i<vcount; i++){
                edg[i] = NULL;
            }

            DTriangleList &triangles = *vertices.triangles();

            foreach(DTriangle t, triangles){

                const int v1 = t.v1();
                const int v2 = t.v2();
                const int v3 = t.v3();

                for(int i=2; i >=0 ; --i){
                    int vv1 = 0;
                    int vv2 = 0;

                    if(i == 0){
                        vv1 = v1;
                        vv2 = v2;
                    }
                    else if(i == 1){
                        vv1 = v2;
                        vv2 = v3;
                    }
                    else{
                        vv1 = v3;
                        vv2 = v1;
                    }

                    if(vv1 > vv2){
                        int vvt = vv1;
                        vv1 = vv2;
                        vv2 = vvt;
                    }

                    if(vv2 <= vcount){
                        ENode* cn = edg[vv1];
                        bool found = 0;
                        while(cn){
                            if(cn->id == vv2){
                                found = 1;
                                break;
                            }
                            cn = cn->next;
                        }

                        if(!found){
                            ENode *n = new ENode;
                            n->id = vv2;
                            n->next = 0;

                            if(edg[vv1] == 0) edg[vv1] = n;
                            else{
                                ENode *cn = edg[vv1];
                                while(cn){
                                    if(cn->next == 0){
                                        cn->next = n;
                                        break;
                                    }
                                    cn = cn->next;
                                }
                            }
                            const DVertex &dvv1 = vertices.at(vv1);
                            const DVertex &dvv2 = vertices.at(vv2);

                            QGraphicsLineItem *line= new QGraphicsLineItem(dvv1.x(), dvv1.y(), dvv2.x(), dvv2.y());

                            line->setPen(pen);
                            trianglesItem->addToGroup(line);
                        }
                    }
                }
                cpt ++;
                emit levelUpdated((int) (cpt * 100 / size));
            }

            /*for(int i=0; i<vcount; i++){
                if(edg[i]){
                    ENode *n = edg[i];
                    ENode *nn = 0;
                    while(n){
                        nn = n->next;
                        delete n;
                        n = nn;
                    }
                }
            }*/
        }

        emit trianglesItemUpdated(trianglesItem);
    }
    catch (const CubException & e){
        emit exceptionLaunched(e);
    }
}
