#include "GraphicsItem.h"

GraphicsItem::GraphicsItem(QGraphicsItem * item)
{
    _item = item;
}

void GraphicsItem::itemEdited(){

    if(_item->parentItem())
        if(_item->parentItem()->type() == GRAPHICS_LAYER_TYPE){
            GraphicsMapLayer * layer = qgraphicsitem_cast<GraphicsMapLayer*>(_item->parentItem());
            layer->itemEdited();
        }
}
