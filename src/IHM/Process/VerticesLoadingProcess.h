#ifndef VERTICESLOADINGPROCESS_H
#define VERTICESLOADINGPROCESS_H

// QT
#include <QPen>
#include <QGraphicsItemGroup>
#include <QGraphicsEllipseItem>

// CUBATOR
#include <DefaultProcess.h>
#include <DVertexList.h>
#include <Messages.h>
#include <GraphicsPointXYZItem.h>

class VerticesLoadingProcess : public DefaultProcess
{
    Q_OBJECT

public:
    VerticesLoadingProcess();

    void setVertices(DVertexList & vertices, const bool displayDepth);

public slots:
    void run();

signals:
    void verticesItemUpdated(QGraphicsItemGroup *);

protected:
    DVertexList * _vertices;
    bool _displayDepth;
};

#endif // VERTICESLOADINGPROCESS_H
