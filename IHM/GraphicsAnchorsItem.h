#ifndef GRAPHICSANCHORSITEM_H
#define GRAPHICSANCHORSITEM_H

// QT
#include <QtGui>

// CUBATOR
#include <GraphicsTypes.h>

#define SIZE_ANCHOR 10

class GraphicsAnchorItem;

class GraphicsAnchorsItem : public QGraphicsItem
{
public:
    enum { Type = GRAPHICS_ANCHORS_TYPE };
    GraphicsAnchorsItem(QGraphicsItem * parent = 0);
    int type() const;

    void setSize(QSize size);
    void setRect(QRectF rect);
    void anchorUpdated(GraphicsAnchorItem * sender);
    bool anchorSelected() const;
    void resetOffset();

    void setRatioEnable(bool enable = 1);
    void setRotation(qreal angle);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    QList<QRectF> anchorBounds() const;

protected:
    GraphicsAnchorItem * _anchors[4];
    QGraphicsItem * _parent;
    bool _ratioEnabled;
    QSize _size;
    bool _pictureIsMovable;
    qreal _offsetx;
};

#endif // GRAPHICSANCHORSITEM_H
