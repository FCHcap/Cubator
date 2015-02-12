#include "GraphicsVectorsItem.h"

using namespace std;

GraphicsVectorsItem::GraphicsVectorsItem(QGraphicsItem *parent) : QGraphicsItem(parent)
{
    _ptSize = 1;
    _depthMax = 0;
    _vectors = 0;
}

int GraphicsVectorsItem::type() const{
    return Type;
}

void GraphicsVectorsItem::setVectors(DVertexList *vectors){
    _vectors = vectors;
}

void GraphicsVectorsItem::setPointSize(double ptSize){
    _ptSize = ptSize;
}

QRectF GraphicsVectorsItem::boundingRect() const{
    QRectF bounds;

    if(_vectors){
        bounds = _vectors->bounds();
    }

    return bounds;
}

void GraphicsVectorsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem * option, QWidget * widget){

    Q_UNUSED(option)
    Q_UNUSED(widget)

    if(!_vectors) return;

    QMutexLocker vlocker(_vectors->mutex());
    DVertex vector;

    foreach(vector, *_vectors){
        painter->setPen(QPen(color(vector.z())));
        painter->drawEllipse(vector.toPointF(), _ptSize, _ptSize);
    }
}

QColor GraphicsVectorsItem::color(double depth){
    QColor c(0, 0, 0);
    if(depth - 1 < _depthMax) _depthMax = depth -1;
    int code = (int) (depth * 510 /_depthMax);

    if(code < 255){
        c.setRed(255-code);
        c.setGreen(code);
    }
    else if(code == 255){
        c.setGreen(255);
    }
    else{
        code -= 255;
        c.setBlue(255 - code);
        c.setGreen(code);
    }

    return c;
}
