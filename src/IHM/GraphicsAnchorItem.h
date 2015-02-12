#ifndef GRAPHICSANCHORITEM_H
#define GRAPHICSANCHORITEM_H

// QT
#include <QtGui>

// CUBATOR
#include <GraphicsTypes.h>

class GraphicsAnchorsItem;

class GraphicsAnchorItem : public QGraphicsRectItem
{
public:
    enum { Type = GRAPHICS_ANCHOR_TYPE };
    enum Form { ELLIPSE, RECTANGLE };

    int type() const;
    GraphicsAnchorItem(QGraphicsItem * parent);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void setForm(Form form);

protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    QGraphicsItem * _parent;
    Form _form;
};

#endif // GRAPHICSANCHORITEM_H
