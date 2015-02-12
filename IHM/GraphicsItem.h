#ifndef GRAPHICSITEM_H
#define GRAPHICSITEM_H

// QT
#include <QGraphicsItem>

// CUBATOR
#include <GraphicsMapLayer.h>

class GraphicsItem
{
public:
    GraphicsItem(QGraphicsItem * item);

protected:
    void itemEdited();

    QGraphicsItem * _item;
};

#endif // GRAPHICSITEM_H
