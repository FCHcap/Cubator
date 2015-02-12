#ifndef GRAPHICSVECTORSITEM_H
#define GRAPHICSVECTORSITEM_H

// QT
#include <QGraphicsItem>
#include <QPainter>

// CUBATOR
#include <DVertexList.h>
#include <GraphicsTypes.h>

// STL
#include <iostream>

class GraphicsVectorsItem : public QGraphicsItem
{
public:
    enum { Type = GRAPHICS_VECTORS_TYPE};

    GraphicsVectorsItem(QGraphicsItem *parent = 0);

    int type() const;
    void setVectors(DVertexList * vertex);
    void setPointSize(double ptSize);

    QRectF boundingRect() const;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    QColor color(double depth);

protected:
    DVertexList * _vectors;
    double _ptSize;
    double _depthMax;
    QRectF _bounds;
};

#endif // GRAPHICSVECTORSITEM_H
