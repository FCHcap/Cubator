#ifndef TRIANGLESREADERPROCESS_H
#define TRIANGLESREADERPROCESS_H

// Qt
#include <Qt>

// CUBATOR
#include <DefaultProcess.h>
#include <DTriangleList.h>

class TrianglesReaderProcess : public DefaultProcess{

    Q_OBJECT

public:
    TrianglesReaderProcess(QString filename = "");

    void setFilename(QString filename);
    void setTrianglesList(DTriangleList &t);

public slots:
    virtual void run();

protected:
    QString _filename;
    DTriangleList *_triangles;
};

#endif // TRIANGLESREADERPROCESS_H
