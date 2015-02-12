#include "GraphicsMeasureItem.h"

int GraphicsMeasureItem::type() const{
    return Type;
}

GraphicsMeasureItem::GraphicsMeasureItem(QGraphicsItem *parent) : QGraphicsItem(parent)
{

    _lineItem = new QGraphicsLineItem(this);
    _textItem = new QGraphicsSimpleTextItem(this);

    _textItem->setFlag(QGraphicsItem::ItemIgnoresTransformations);

    QPen pen;
    pen.setColor(QColor(0, 0, 200));
    _lineItem->setPen(pen);
}

GraphicsMeasureItem::~GraphicsMeasureItem(){
}

void GraphicsMeasureItem::setP1(const QPointF &point){
    _lineItem->setLine(QLineF(point, point));
}

void GraphicsMeasureItem::setP2(const QPointF &point){
    QLineF line = _lineItem->line();
    line.setP2(point);
    _lineItem->setLine(line);

    QPointF center = line.pointAt(0.5);
    qreal angle = line.angle();
    qreal length = line.length();

    QString text = QString("%1m").arg(length);
    _textItem->setText(text);
    _textItem->setPos(center);

    (angle > 90 && angle <= 270) ? _textItem->setRotation(angle + 180) : _textItem->setRotation(angle);
}

QRectF GraphicsMeasureItem::boundingRect() const{
    return childrenBoundingRect();
}

void GraphicsMeasureItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    _lineItem->paint(painter, option, widget);
    _textItem->paint(painter, option, widget);
}
