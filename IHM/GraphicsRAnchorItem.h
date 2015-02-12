#ifndef GRAPHICSRANCHORITEM_H
#define GRAPHICSRANCHORITEM_H

// QT
#include <QGraphicsItem>

// CUBATOR
#include <GraphicsTypes.h>

#define SIZE_RANCHOR 10

class QGraphicsLineItem;
class GraphicsAnchorItem;

class GraphicsRAnchorItem : public QGraphicsItem
{
public:
    enum { Type = GRAPHICS_RANCHOR_TYPE };

    GraphicsRAnchorItem(QGraphicsItem * parent = 0);
    int type() const;

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void anchorUpdated(const QPointF aCenter);

    bool isSelected() const;

protected:
    GraphicsAnchorItem * _anchor;
    QGraphicsLineItem * _line;
    QPointF _center;
};

#endif // GRAPHICSRANCHORITEM_H
