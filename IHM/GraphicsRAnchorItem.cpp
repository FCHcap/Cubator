#include "GraphicsRAnchorItem.h"

// QT
#include <QGraphicsLineItem>
#include <QGraphicsEllipseItem>
#include <QPen>
#include <QBrush>

// CUBATOR
#include <GraphicsAnchorItem.h>
#include <GraphicsPictureItem.h>

// STL
#include <cmath>

GraphicsRAnchorItem::GraphicsRAnchorItem(QGraphicsItem *parent) :
    QGraphicsItem(parent)
{
    _line = new QGraphicsLineItem(this);
    _anchor = new GraphicsAnchorItem(this);

    this->setScale(-1);

    setFlag(QGraphicsItem::ItemIgnoresTransformations);

    QPen pen(Qt::red);
    pen.setStyle(Qt::DashLine);
    _line->setLine(0, 0, 0, 0);
    _line->setPen(pen);

    QRectF rect(-SIZE_RANCHOR/2, -SIZE_RANCHOR/2, SIZE_RANCHOR, SIZE_RANCHOR);
    _anchor->setForm(GraphicsAnchorItem::ELLIPSE);
    _anchor->setRect(rect);
    _anchor->setPos(0, 0);
    pen.setStyle(Qt::SolidLine);
    _anchor->setPen(pen);
    _anchor->setBrush(QBrush(Qt::red));

    setCursor(Qt::ArrowCursor);
}

int GraphicsRAnchorItem::type() const{
    return Type;
}

QRectF GraphicsRAnchorItem::boundingRect() const{
    return childrenBoundingRect();
}

void GraphicsRAnchorItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    Q_UNUSED(painter)
    Q_UNUSED(option)
    Q_UNUSED(widget)
}

void GraphicsRAnchorItem::anchorUpdated(const QPointF aCenter){
    QGraphicsItem * parent = this->parentItem();
    if(!parent) return; // quitte la méthode si aucun parent n'est configuré

    QPointF center = parent->mapToItem(_anchor, parent->boundingRect().center());

    qreal angle = atan((aCenter.y()-center.y())/(aCenter.x()-center.x()));
    angle *= 180 / M_PI; // convertit en degrés

    if(aCenter.x() < center.x()){
        angle += 180;
    }

    if(parent->type() == GRAPHICS_PICTURE_TYPE){
        GraphicsPictureItem * picture = qgraphicsitem_cast<GraphicsPictureItem*>(parent);
        picture->rAnchorUpdated(90-angle);
        _line->setLine(QLineF(QPointF(SIZE_RANCHOR/2, SIZE_RANCHOR/2), this->mapFromItem(_anchor, aCenter))); // met à jour la ligne
    }
}

bool GraphicsRAnchorItem::isSelected() const{
    if(_anchor->isSelected()) return true;
    return false;
}

