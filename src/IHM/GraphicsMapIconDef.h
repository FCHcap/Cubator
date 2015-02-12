#ifndef GRAPHICSMAPICONDEF_H
#define GRAPHICSMAPICONDEF_H

// QT
#include <QtGui>

// CUBATOR
#include <GraphicsMapItemDef.h>
#include <GraphicsTypes.h>

class GraphicsMapIconDef : public GraphicsMapItemDef{

public:
    enum { Type = GRAPHICS_ICONDEF_TYPE };

    int type() const {return Type;}

    GraphicsMapIconDef(QGraphicsItem * parent = 0) : GraphicsMapItemDef(parent){}

    void setSelectionColor(const QColor &color){_selectionColor = color;}
    QColor selectionColor(){return _selectionColor;}

protected:
    QColor _selectionColor;
};


#endif // GRAPHICSMAPICONDEF_H
