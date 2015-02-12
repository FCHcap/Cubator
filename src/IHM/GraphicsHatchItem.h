#ifndef GRAPHICSHATCHITEM_H
#define GRAPHICSHATCHITEM_H

// QT
#include <QtGui>

// CUBATOR
#include <GraphicsTypes.h>

class GraphicsHatchItem : public QGraphicsPathItem
{
public:
    GraphicsHatchItem(QGraphicsItem * parent = 0);
    GraphicsHatchItem(const GraphicsHatchItem & item);

    enum { Type = GRAPHICS_AUTODEPTH_TYPE};

    int type() const;
};

#endif // GRAPHICSHATCHITEM_H
