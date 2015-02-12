#ifndef GRAPHICSMEASUREITEM_H
#define GRAPHICSMEASUREITEM_H

// QT
#include <QGraphicsItem>
#include <QPen>

// CUBATOR
#include <GraphicsTypes.h>

class GraphicsMeasureItem : public QGraphicsItem
{
public:

    enum { Type = GRAPHICS_MEASURE_TYPE };

    int type() const;
    explicit GraphicsMeasureItem(QGraphicsItem * parent = 0);
    ~GraphicsMeasureItem();

    void setP1(const QPointF & point);
    void setP2(const QPointF & point);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    QGraphicsLineItem * _lineItem;
    QGraphicsSimpleTextItem * _textItem;
};

#endif // GRAPHICSMEASUREITEM_H
