#include "GraphicsHatchItem.h"

GraphicsHatchItem::GraphicsHatchItem(QGraphicsItem *parent) : QGraphicsPathItem(parent){

}

GraphicsHatchItem::GraphicsHatchItem(const GraphicsHatchItem &item) : QGraphicsPathItem(item.parentItem()){
    setParentItem(item.parentItem());

    // Copy the pen
    setPen(item.pen());
    setBrush(item.brush());

    // Copy the polygons
    setPath(item.path());
}

int GraphicsHatchItem::type() const{
    return Type;
}
