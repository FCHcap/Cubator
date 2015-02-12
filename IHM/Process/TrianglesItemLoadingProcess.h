#ifndef TRIANGLESITEMLOADINGPROCESS_H
#define TRIANGLESITEMLOADINGPROCESS_H

// QT
#include <QPen>
#include <QGraphicsItemGroup>
#include <QGraphicsEllipseItem>

// CUBATOR
#include <DefaultProcess.h>
#include <DVertexList.h>
#include <Messages.h>

class TrianglesItemLoadingProcess : public DefaultProcess
{
    Q_OBJECT

    typedef struct ENode{
        DVertexId id;
        ENode *next;
    } ENode;

    typedef struct GTriangle{
        QGraphicsLineItem *ab;
        QGraphicsLineItem *bc;
        QGraphicsLineItem *ca;
    } GTriangle;

public:
    TrianglesItemLoadingProcess();
    void setVertices(DVertexList &vertices);

public slots:
    void run();

signals:
    void trianglesItemUpdated(QGraphicsItemGroup *);

protected:
    DVertexList *_vertices;
};

#endif // TRIANGLESITEMLOADINGPROCESS_H
