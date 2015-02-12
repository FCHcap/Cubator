#include "DataWriterProcess.h"

VectorsWriterProcess::VectorsWriterProcess(QString filename){
    _filename = filename;
    _vertices = 0;
}

void VectorsWriterProcess::setFilename(QString filename){
    _filename = filename;
}

void VectorsWriterProcess::setVerticesList(DVertexList &v){
    _vertices = &v;
}

void VectorsWriterProcess::run(){
    try{
        if(!_vertices)
            throw CubException(BRIEF00, ERROR08, "VectorsWriterProcess::start");

        DVertexList & vertices = *_vertices;

        VectorsWriter writer(_filename);
        int size = vertices.count();

        emit processNameUpdated(PROCESS05);

        int i=0;
        foreach(DVertex v, vertices){
            writer.writeVertex(v);
            i++;
            emit levelUpdated(i * 100 /size);
        }
        emit levelUpdated(100);
    }
    catch(const CubException &e){
        emit exceptionLaunched(e);
    }
}

TrianglesWriterProcess::TrianglesWriterProcess(QString filename){
    _filename = filename;
    _triangles = 0;
}

void TrianglesWriterProcess::setFilename(QString filename){
    _filename = filename;
}

void TrianglesWriterProcess::setTrianglesList(DTriangleList &t){
    _triangles = &t;
}

void TrianglesWriterProcess::run(){
    try{
        if(!_triangles)
            throw CubException(BRIEF00, ERROR08, "TrianglesWriterProcess::start");

        DTriangleList & triangles = *_triangles;
        TrianglesWriter writer(_filename);
        int size = triangles.count();

        emit processNameUpdated(PROCESS06);

        int i=0;
        foreach(DTriangle t, triangles){
            writer.writeTriangle(t);
            i++;
            emit levelUpdated(i * 100 / size);
        }
        emit levelUpdated(100);
    }
    catch(const CubException &e){
        emit exceptionLaunched(e);
    }
}

ImageWriterProcess::ImageWriterProcess(QString filename){
    _filename = filename;
    _mse = 0;
    _vertices = 0;
}

void ImageWriterProcess::setFilename(QString filename){
    _filename = filename;
}

void ImageWriterProcess::setVerticesList(DVertexList &v){
    _vertices = &v;
}

void ImageWriterProcess::run(){
    try{
        if(!_vertices)
            throw CubException(BRIEF00, ERROR08, "ImageWriterProcess::start");

        DVertexList & vertices = *_vertices;

        emit processNameUpdated(PROCESS07);

        const double dmax = vertices.depthMax();
        const double dmin = vertices.depthMin();

        QRectF rVertices = vertices.bounds();
        QRect rImage = imageRect(rVertices);

        QImage img(rImage.width(), rImage.height(), QImage::Format_RGB32);
        img.fill(qRgb(255, 255, 255));

        int size = vertices.triangles()->size();
        int cpt = 0;

        double d = 0;
        QPointF pos;

        QMutexLocker locker(vertices.mutex());

        for(int i=0; i<size; i++){
            const DTriangle &t = vertices.triangles()->at(i);

            //Checks if the triangle is valid
            if(!vertices.triangleIsValid(t, _mse)) continue;

            PlaneEquation pe = vertices.equation(t);

            QRectF rTriangle = vertices.boundsTriangle(t);
            QRect bTri = imageTriangleRect(rVertices, rTriangle);

            for(int ii=bTri.left(); ii<=bTri.right(); ii++){
                pos.setX(((int) (rVertices.x())) + ii + 0.5);

                for(int jj=bTri.top(); jj<=bTri.bottom(); jj++){
                    pos.setY(((int) (rVertices.y())) + jj + 0.5);

                    if(!rTriangle.contains(pos)) continue;
                    if(vertices.inTriangle(t, pos)){
                        d = vertices.depthFromEquation(pe, pos);
                        img.setPixel(ii, jj, vertices.colorZ(d, dmax, dmin).toRgb().rgb());
                    }
                }
            }

            cpt++;
            emit levelUpdated(cpt * 100 / size);
        }

        if(!img.save(_filename, "BMP", 100)){
            throw CubException(BRIEF08, TEXT01 + _filename, "ImageWriterProcess::run");
        }
        emit levelUpdated(100);
    }
    catch(const CubException &e){
        emit exceptionLaunched(e);
    }
}

void ImageWriterProcess::setMaximumSizeEdge(double mse){
    _mse = mse;
}

inline QRect ImageWriterProcess::imageTriangleRect(const QRectF &rVertices, const QRectF &rTriangle){
    return QRect(QPoint(rTriangle.x() - rVertices.x(), rTriangle.y() - rVertices.y()), QPoint(rTriangle.x() + rTriangle.width() - rVertices.x() +1, rTriangle.y() + rTriangle.height() - rVertices.y() +1));

}

inline QRect ImageWriterProcess::imageRect(const QRectF &rVertices){
    return QRect (0, 0, (int) rVertices.right() - rVertices.left() +1, (int) rVertices.bottom() - rVertices.top() +1);
}
