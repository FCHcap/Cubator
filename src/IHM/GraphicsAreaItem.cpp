#include "GraphicsAreaItem.h"

GraphicsAreaItem::GraphicsAreaItem(QGraphicsItem *parent)
    : GraphicsPolylineItem(parent), _textItem(this)
{
    _surface = 0;

    setFlag(QGraphicsItem::ItemIsMovable, false);
    setFlag(QGraphicsItem::ItemIsSelectable, true);

    _textItem.setTransform(QTransform::fromScale(1.0, -1.0));
}

int GraphicsAreaItem::type() const {
    return Type;
}

qreal GraphicsAreaItem::surface() const {
    return _surface;
}

void GraphicsAreaItem::setBrushColor(const QColor color) {
    QPen pen(color);
    pen.setStyle(Qt::DashDotLine);
    this->setPen(pen);
}

void GraphicsAreaItem::setFont(const QFont font) {
    _textItem.setFont(font);
}

void GraphicsAreaItem::setTextColor(const QColor &color) {
    _textItem.setDefaultTextColor(color);
}

void GraphicsAreaItem::updateTextItem(){
    QString text;
    text.append(TEXT18 + QString::number(_surface, 'f', 4) + " m2");
    _textItem.setHtml(text);

    QRectF rect = boundingRect();
    _textItem.adjustSize();
    _textItem.setPos(rect.center().x() - _textItem.boundingRect().width()/2, rect.center().y() + _textItem.boundingRect().height()/2);
}

void GraphicsAreaItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    GraphicsPolylineItem::paint(painter, option, widget);
}

void GraphicsAreaItem::setSurface(qreal surface) {
    _surface = surface;
    updateTextItem();
}
