#ifndef GRAPHICSAUTODEPTHITEM_H
#define GRAPHICSAUTODEPTHITEM_H

// QT
#include <QGraphicsItem>

// CUBATOR
#include <GraphicsTypes.h>

class GraphicsAutoDepthItem : public QGraphicsItem
{
public:

    enum { Type = GRAPHICS_AUTODEPTH_TYPE };

    int type() const;

    GraphicsAutoDepthItem();
};

#endif // GRAPHICSAUTODEPTHITEM_H
