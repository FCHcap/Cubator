#include "GraphicsImageItem.h"

int GraphicsImageItem::type() const{
    return Type;
}

GraphicsImageItem::GraphicsImageItem()
{
}

void GraphicsImageItem::setImagePath(const QString imagePath){
    _imagePath = imagePath;
}

QString GraphicsImageItem::imagePath() const{
    return _imagePath;
}
