#include "GraphicsMeshItem.h"

GraphicsMeshItem::GraphicsMeshItem(QGraphicsItem *parent) : QGraphicsItem(parent)
{
    _vertices = 0;
    _triangles = 0;
}

QGraphicsItemGroup * GraphicsMeshItem::triangles() const {
    return _triangles;
}

QGraphicsItemGroup * GraphicsMeshItem::vertices() const {
    return _vertices;
}

int GraphicsMeshItem::type() const {
    return Type;
}

QRectF GraphicsMeshItem::boundingRect() const {
    return this->childrenBoundingRect();
}

void GraphicsMeshItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(painter)
    Q_UNUSED(option)
    Q_UNUSED(widget)
}

void GraphicsMeshItem::setTriangles(QGraphicsItemGroup *triangles) {
    _triangles = triangles;
    _triangles->setParentItem(this);
}

void GraphicsMeshItem::setVertices(QGraphicsItemGroup *vertices) {
    _vertices = vertices;
    _vertices->setParentItem(this);
}
