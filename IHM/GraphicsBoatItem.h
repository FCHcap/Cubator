#ifndef GRAPHICSBOATITEM_H
#define GRAPHICSBOATITEM_H

// QT
#include <QGraphicsItemGroup>

// CUBATOR
#include <GraphicsTypes.h>
#include <GraphicsMapBoatDef.h>
#include <GraphicsPolylineItem.h>

class GraphicsBoatItem : public QGraphicsItem{

public:
    enum { Type = GRAPHICS_BOAT_TYPE };
    int type() const;

    GraphicsBoatItem(QGraphicsItem * parent = 0);

    void setBoatDef(GraphicsMapBoatDef * boatDef);
    GraphicsMapBoatDef * boatDef() const;

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    GraphicsMapBoatDef * _boatDef;
};

#endif // GRAPHICSBOATITEM_H
