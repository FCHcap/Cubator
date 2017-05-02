#ifndef GRAPHICSMESHITEM_H
#define GRAPHICSMESHITEM_H

// QT
#include <QtGui>

// CUBATOR
#include <GraphicsTypes.h>
#include <DTriangleList.h>
#include <DVertexList.h>
#include <GraphicsTypes.h>

class GraphicsMeshItem : public QGraphicsItem
{
public:
    enum { Type = GRAPHICS_MESH_ITEM_TYPE };

    GraphicsMeshItem(QGraphicsItem *parent = 0);

    QGraphicsItemGroup *triangles() const;
    QGraphicsItemGroup *vertices() const;

    int type() const;
    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

public slots:
    void setTriangles(QGraphicsItemGroup *triangles);
    void setVertices(QGraphicsItemGroup *vertices);

private:
    QGraphicsItemGroup *_triangles;
    QGraphicsItemGroup *_vertices;
};

#endif // GRAPHICSMESHITEM_H
