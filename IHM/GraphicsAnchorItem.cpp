#include "GraphicsAnchorItem.h"

// CUBATOR
#include <GraphicsAnchorsItem.h>
#include <GraphicsRAnchorItem.h>

GraphicsAnchorItem::GraphicsAnchorItem(QGraphicsItem *parent):
    QGraphicsRectItem(parent)
{
    _parent = parent;
    _form = RECTANGLE;

    setBrush(QBrush(Qt::black));
    setFlag(QGraphicsItem::ItemIsSelectable);
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIgnoresTransformations);
}

int GraphicsAnchorItem::type() const{
    return Type;
}

void GraphicsAnchorItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    Q_UNUSED(option)
    Q_UNUSED(widget)

    painter->setPen(pen());
    painter->setBrush(brush());
    if(_form == RECTANGLE){
        painter->drawRect(rect());
    }
    else{
        painter->drawEllipse(rect());
    }
}

void GraphicsAnchorItem::setForm(Form form){
    _form = form;
}

#include <iostream>
using namespace std;

void GraphicsAnchorItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    QGraphicsItem::mouseMoveEvent(event);
    if(_parent->type() == GRAPHICS_ANCHORS_TYPE){
        GraphicsAnchorsItem* item = qgraphicsitem_cast<GraphicsAnchorsItem*>(_parent);
        item->anchorUpdated(this);
    }
    else if(_parent->type() == GRAPHICS_RANCHOR_TYPE){
        GraphicsRAnchorItem* item = qgraphicsitem_cast<GraphicsRAnchorItem*>(_parent);
        item->anchorUpdated(this->boundingRect().center());

    }
}

void GraphicsAnchorItem::mousePressEvent(QGraphicsSceneMouseEvent *event){
    QGraphicsItem::mousePressEvent(event);
    if(_parent->type() == GRAPHICS_ANCHORS_TYPE){
        GraphicsAnchorsItem* item = qgraphicsitem_cast<GraphicsAnchorsItem*>(_parent);
        item->resetOffset();
    }
}
