#include "VolumeCalculatorProcess.h"

VolumeCalculatorProcess::VolumeCalculatorProcess()
{
}

void VolumeCalculatorProcess::setUpMesh(const QString &mesh){
    _upMesh = mesh;
    _upSurface = MESH;
}

void VolumeCalculatorProcess::setUpLevel(const double &level){
    _upLevel = level;
    _upSurface = LEVEL;
}

void VolumeCalculatorProcess::setLoMesh(const QString &mesh){
    _loMesh = mesh;
    _loSurface = MESH;
}

void VolumeCalculatorProcess::setLoLevel(const double &level){
    _loLevel = level;
    _loSurface = LEVEL;
}

void VolumeCalculatorProcess::setVolumeItem(GraphicsVolumeItem *item){
    connect(this, SIGNAL(rectangleAdded(QRect)), item, SLOT(addRect(QRect)));
    connect(this, SIGNAL(surfaceUpdated(qreal)), item, SLOT(setSurface(qreal)));
    connect(this, SIGNAL(volumeUpdated(qreal)), item, SLOT(setVolume(qreal)));

    // copy the polyline
    _polyline.clearPoints();
    foreach(QPointF point, item->points()) _polyline.addPoint(point);
}

void VolumeCalculatorProcess::run(){
    try{
        if(_polyline.points().size() < 3) throw CubException(BRIEF00, MESSAGE07, "VolumeCalculatorProcess::start");

        DVertexList upVertices;
        DVertexList loVertices;
        bool cVolume = 1;

        if(_upSurface == MESH){
            loadVertices(_upMesh, upVertices);
            loadTriangles(_upMesh, *upVertices.triangles());
            loadGrid(_upMesh, *upVertices.grid());


            // Checks if the polyline is contained in the mesh
            try{
                if(!upVertices.bounds().contains(_polyline.boundingRect()))
                    throw CubException(BRIEF21, TEXT32 + _upMesh, "VolumeCalculatorProcess::start");
            }
            catch(CubException e){
                cVolume = 0;
                emit warningMessageLaunched(e);
            }
        }

        if(_loSurface == MESH){
            loadVertices(_loMesh, loVertices);
            loadTriangles(_loMesh, *loVertices.triangles());
            loadGrid(_loMesh, *loVertices.grid());

            // Checks if the polyline is contained in the mesh
            try{
                if(!loVertices.bounds().contains(_polyline.boundingRect()))
                    throw CubException(BRIEF21, TEXT32 + _loMesh, "VolumeCalculatorProcess::start");
            }
            catch(CubException e){
                cVolume = 0;
                emit warningMessageLaunched(e);
            }
        }

        QRectF rectf = _polyline.boundingRect();
        QRect rect(rectf.topLeft().toPoint(), rectf.bottomRight().toPoint());

        qreal surface = 0;
        qreal volume = 0;
        int size = rect.width() * rect.height();
        int cpt = 0;

        qreal ** uphv = 0;
        qreal ** lohv = 0;
        int hvsize = (rect.width()+1) * (rect.height()+1);

        if(_upSurface == MESH && cVolume){
            uphv = new qreal*[hvsize];
            for(int i=0; i<hvsize; i++) uphv[i] = 0;
        }
        if(_loSurface == MESH && cVolume){
            lohv = new qreal*[hvsize];
            for(int i=0; i<hvsize; i++) lohv[i] = 0;
        }

        emit processNameUpdated(PROCESS14);

        for(int i=rect.x(), ii=0; ii<rect.width(); i++, ii++){
            for(int j=rect.y(), jj=0; jj<rect.height(); j++, jj++){
                QRect r(QPoint(i, j), QSize(1, 1));
                if(_polyline.polylineContains(r)){
                    emit rectangleAdded(r);

                    if(cVolume){

                        qreal upLevel = 0;
                        qreal loLevel = 0;

                        if(_upSurface == MESH){

                            double x = i;
                            double y = j;
                            for(int iii=0; iii<4; iii++){
                                int it = 0;
                                switch (iii){
                                case 0: it = jj*rect.width()+1+ii; break;
                                case 1: it = jj*rect.width()+2+ii; x++; break;
                                case 2: it = (jj+1)*rect.width()+2+ii; y++; break;
                                case 3: it = (jj+1)*rect.width()+1+ii; x--; break;
                                }

                                if(!uphv[it]){
                                    uphv[it] = new qreal;
                                    upVertices.depthGridAt(QPointF(x, y), *uphv[it]);
                                }

                                upLevel += *uphv[it]/4;
                            }
                        }
                        else upLevel = _upLevel;

                        if(_loSurface == MESH){
                            double x = i;
                            double y = j;
                            for(int iii=0; iii<4; iii++){
                                int it = 0;
                                switch (iii){
                                case 0: it = jj*rect.width()+1+ii; break;
                                case 1: it = jj*rect.width()+2+ii; x++; break;
                                case 2: it = (jj+1)*rect.width()+2+ii; y++; break;
                                case 3: it = (jj+1)*rect.width()+1+ii; x--; break;
                                }

                                if(!lohv[it]){
                                    lohv[it] = new qreal;
                                    loVertices.depthGridAt(QPointF(x, y), *lohv[it]);
                                }

                                loLevel += *lohv[it]/4;
                            }
                        }
                        else loLevel = _loLevel;

                        if(upLevel > loLevel){
                            volume += upLevel - loLevel;
                        }
                    }
                    surface ++;
                }
                cpt++;
                emit levelUpdated(cpt * 100 / size);
            }
        }

        emit surfaceUpdated(surface);
        if(cVolume) emit volumeUpdated(volume);

        if(uphv){
            for(int i=0; i<hvsize; i++) delete uphv[i];
            delete[] uphv;
        }
        if(lohv){
            for(int i=0; i<hvsize; i++) delete lohv[i];
            delete[] lohv;
        }
    }
    catch(CubException & e){
        emit exceptionLaunched(e);
    }
}

void VolumeCalculatorProcess::loadVertices(const QString &table, DVertexList &vertices) throw (CubException){

    QString upFile = Data::vectorFileName(table);
    VerticesReaderProcess reader(upFile);
    reader.setVerticesList(vertices);
    connect(&reader, SIGNAL(levelUpdated(int)), this, SIGNAL(levelUpdated(int)));
    emit processNameUpdated(PROCESS15 + '\'' + table +"' ...");
    reader.run();
    CubException * e = reader.lastException();
    if(e) throw *e;
}

void VolumeCalculatorProcess::loadTriangles(const QString &table, DTriangleList &triangles) throw (CubException){

    QString upFile = Data::triangleFilename(table);
    TrianglesReaderProcess reader(upFile);
    reader.setTrianglesList(triangles);
    connect(&reader, SIGNAL(levelUpdated(int)), this, SIGNAL(levelUpdated(int)));
    emit processNameUpdated(PROCESS16 + '\'' + table + "' ...");
    reader.run();
    CubException * e = reader.lastException();
    if(e) throw *e;
}

void VolumeCalculatorProcess::loadGrid(const QString &table, DTGrid &grid) throw (CubException){

    QString file = Data::gridFilename(table);
    GridReaderProcess reader;
    reader.setGrid(grid);
    reader.setFilename(file);
    connect(&reader, SIGNAL(levelUpdated(int)), this, SIGNAL(levelUpdated(int)));
    emit processNameUpdated(PROCESS17 + '\'' + table + "' ...");
    reader.run();
    CubException * e = reader.lastException();
    if(e) throw *e;
}

qreal VolumeCalculatorProcess::mediumHeight(DVertexList &vertices, QRect &r) throw (CubException){

    qreal h=0;
    QPointF p = r.topLeft();
    for(int i=0; i<4; i++){
        if(i==1) p.setX(r.x()+1);
        else if(i==2) p.setY(r.y()+1);
        else if(i==3) p.setX(r.x());

        qreal hh = 0;
        CubException e(BRIEF22, "x = "+QString::number(p.x())+" - y = "+QString::number(p.y()), "VolumeCalculatorProcess::mediumHeight");
        if(!vertices.depthAt(p, hh)) throw e;
        h += hh;
    }
    return h/4;
}
