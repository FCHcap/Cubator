#ifndef VERTICESREADERPROCESS_H
#define VERTICESREADERPROCESS_H

// QT
#include <Qt>

// CUBATOR
#include <DefaultProcess.h>
#include <DVertexList.h>

class VerticesReaderProcess : public DefaultProcess{

    Q_OBJECT

public:
    VerticesReaderProcess(QString filename = "");

    void setFilename(QString filename);
    void setVerticesList(DVertexList &v);

public slots:
    virtual void run();

signals:
    void vertexRead(DVertex);
    void rowCountUpdated(int);

protected:
    QString _filename;
    DVertexList *_vertices;
};

#endif // VERTICESREADERPROCESS_H
