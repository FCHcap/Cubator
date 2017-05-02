#include "GraphicsPointXYZItem.h"

#include <QFont>

GraphicsPointXYZItem::GraphicsPointXYZItem(const bool displayDepth = false, QGraphicsItem *parent) :
    QGraphicsItem(parent),
    _point(this),
    _depth(this)
{
    _depth.setVisible(displayDepth);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemIsMovable, false);
}

void GraphicsPointXYZItem::setVertex(DVertex vertex, QColor color) {
    QPointF pos = vertex.toPointF() - QPointF(0.2, 0.2);
    QRectF rect(pos.x(), pos.y(), 0.4, 0.4);
    QFont font;

    _color = color;
    _vertex = vertex;

    font.setPixelSize(5);

    _point.setRect(rect);
    _point.setCacheMode(QGraphicsItem::DeviceCoordinateCache);
    _point.setOpacity(1);
    _point.setPen(QPen(color));
    _point.setBrush(QBrush(color));

    QString zstr = QString::number(vertex.z(), 'f', 2);
    _depth.setText(zstr);
    _depth.setTransform(QTransform::fromScale(1.0, -1.0));
    _depth.setPos(vertex.toPointF() + QPointF(0.3, 0.3));
    _depth.setFont(font);
    _depth.setPen(QPen(color));
    _depth.setBrush(QBrush(color));
}

DVertex GraphicsPointXYZItem::vertex() const {
    return _vertex;
}

QColor GraphicsPointXYZItem::color() const {
    return _color;
}

void GraphicsPointXYZItem::setDisplayDepth(const bool displayDepth) {
    _depth.setVisible(displayDepth);
}

bool GraphicsPointXYZItem::displayDepth() const {
    return _depth.isVisible();
}

int GraphicsPointXYZItem::type() const {
    return Type;
}

QRectF GraphicsPointXYZItem::boundingRect() const {
    return this->childrenBoundingRect();
}

void GraphicsPointXYZItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option)
    Q_UNUSED(widget)

    if(isSelected()){
        QPen pen = QPen(Qt::black);
        pen.setStyle(Qt::DashLine);

        painter->setPen(pen);
        painter->drawRect(this->boundingRect());
    }
}

void GraphicsPointXYZItem::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    QGraphicsItem::mousePressEvent(event);
    setSelected(1);
}
