#ifndef GRAPHICSMAPBOATDEF_H
#define GRAPHICSMAPBOATDEF_H

// QT
#include <QGraphicsItemGroup>

// CUBATOR
#include <GraphicsTypes.h>
#include <GraphicsMapItemDef.h>

class GraphicsMapBoatDef : public GraphicsMapItemDef
{
public:
    enum { Type = GRAPHICS_BOATDEF_TYPE };
    int type() const {return Type;}

    GraphicsMapBoatDef(QGraphicsItem * parent = 0) : GraphicsMapItemDef(parent){}
};

#endif // GRAPHICSMAPBOATDEF_H
