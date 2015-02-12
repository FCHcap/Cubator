#ifndef DATAWRITERPROCESS_H
#define DATAWRITERPROCESS_H

#include <QThread>

#include <Data.h>
#include <DataWriter.h>
#include <DVertexList.h>
#include <CubException.h>
#include <ProgressDialog.h>
#include <DefaultProcess.h>
#include <Messages.h>

class VectorsWriterProcess : public DefaultProcess{

    Q_OBJECT

public:
    VectorsWriterProcess(QString filename = "");

    void setFilename(QString filename);
    void setVerticesList(DVertexList &v);

public slots:
    virtual void run();

protected:
    QString _filename;
    DVertexList *_vertices;
};

class TrianglesWriterProcess : public DefaultProcess{

    Q_OBJECT

public:
    TrianglesWriterProcess(QString filename = "");

    void setFilename(QString filename);
    void setTrianglesList(DTriangleList &t);

public slots:
    virtual void run();

protected:
    QString _filename;
    DTriangleList *_triangles;
};

class ImageWriterProcess : public DefaultProcess{

    Q_OBJECT

public:
    ImageWriterProcess(QString filename = "");

    void setFilename(QString filename);
    void setMaximumSizeEdge(double mse = 0);
    void setVerticesList(DVertexList &v);

public slots:
    void run();

protected:
    inline QRect imageTriangleRect(const QRectF &rVertices, const QRectF &rTriangle);
    inline QRect imageRect(const QRectF &rVertices);

protected:
    QString _filename;
    double _mse;
    DVertexList *_vertices;
};



#endif // DATAWRITERPROCESS_H
