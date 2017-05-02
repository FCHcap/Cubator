#include "GraphicsMapLayer.h"

// CUBATOR
#include <GraphicsMap.h>
#include <GraphicsPictureItem.h>
#include <GraphicsMeshItem.h>

int GraphicsMapLayer::type() const{
    return Type;
}

GraphicsMapLayer::GraphicsMapLayer(QGraphicsItem *parent) : QGraphicsItem(parent){
    _elevation = 0;
    _editable = 0;
    _selectToolEnabled = 0;
}

void GraphicsMapLayer::updateBoundingRect(){
    _rect = childrenBoundingRect();
}

void GraphicsMapLayer::itemEdited(){
    if(parentItem()->type() == GraphicsMap::Type){
        GraphicsMap * map = qgraphicsitem_cast<GraphicsMap*>(parentItem());
        map->setEdited(1);
    }
}

QList<QGraphicsItem *> GraphicsMapLayer::picturesList() const{
    QList<QGraphicsItem*> list;
    foreach(QGraphicsItem * item, childItems()){
        if(item->type() == GRAPHICS_PICTURE_TYPE){
            list.append(item);
        }
    }
    return list;
}

QStringList GraphicsMapLayer::picturesFilepaths() const{
    QList<QGraphicsItem*> items = picturesList();
    QStringList list;
    foreach(QGraphicsItem* item, items){
        GraphicsPictureItem * pictureItem = qgraphicsitem_cast<GraphicsPictureItem*> (item);
        list.append(pictureItem->filepath());
    }
    return list;
}

void GraphicsMapLayer::setName(const QString & name){_name = name;}

QString GraphicsMapLayer::name() const{return _name;}

void GraphicsMapLayer::setEditable(bool editable){
    _editable = editable;
    itemEdited();
    updateEditionAuthorization();
}

bool GraphicsMapLayer::editable() const {return _editable;}

void GraphicsMapLayer::setFlags(QGraphicsItem *item){
    bool enable = (_editable && _selectToolEnabled)? 1 : 0;
    setFlags(item, enable);
}

void GraphicsMapLayer::setFlags(QGraphicsItem *item, bool enable){

    item->setFlag(QGraphicsItem::ItemIsSelectable, enable);

    if(item->type() != GRAPHICS_VOLUME_TYPE)
        item->setFlag(QGraphicsItem::ItemIsMovable, enable);
}

void GraphicsMapLayer::setSelectToolEnabled(bool enable){
    _selectToolEnabled = enable;
    updateEditionAuthorization();
}

bool GraphicsMapLayer::selectToolEnabled() const{return _selectToolEnabled;}

void GraphicsMapLayer::updateEditionAuthorization(){

    bool enable = (_editable && _selectToolEnabled)? 1 : 0;

    foreach(QGraphicsItem * item, this->childItems()){
        setFlags(item, enable);
    }
}

void GraphicsMapLayer::addToLayer(QGraphicsItem *item, bool layerEdited){
    item->setZValue(zValue());
    item->setParentItem(this);
    setFlags(item);

    switch(item->type())
    {
    case QGraphicsLineItem::Type:
        item->setZValue(zValue() +1);
        break;

    case GraphicsTextItem::Type:
        item->setZValue(zValue() +2);
    }

    QGraphicsItem * parent = parentItem();
    if(parent->type() == GraphicsMap::Type && layerEdited){
        GraphicsMap * map = qgraphicsitem_cast<GraphicsMap*>(parent);
        map->updateBoundingRect();
        map->setEdited(1);
    }

    updateBoundingRect();
}

void GraphicsMapLayer::updateZValue(){
    foreach(QGraphicsItem * item, childItems()){
        item->setZValue(zValue());
    }
}

QRectF GraphicsMapLayer::boundingRect() const {
    return _rect;
}

void GraphicsMapLayer::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    Q_UNUSED(painter)
    Q_UNUSED(option)
    Q_UNUSED(widget)
}
