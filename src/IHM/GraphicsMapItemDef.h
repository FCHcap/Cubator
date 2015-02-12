#ifndef GRAPHICSMAPITEMDEF_H
#define GRAPHICSMAPITEMDEF_H

// QT
#include <QtGui>

// CUBATOR
#include <GraphicsTypes.h>

class GraphicsMapItemDef : public QGraphicsItemGroup
{
public:
    virtual int type() const = 0;

    GraphicsMapItemDef(QGraphicsItem * parent = 0) : QGraphicsItemGroup(parent){}
    void setName(const QString &name){_name = name;}
    QString name() const {return _name;}
    void setCenter(const QPointF &center){_center = center;}
    QPointF center() const {return _center;}

protected:
    QString _name;
    QPointF _center;
};

#endif // GRAPHICSMAPITEMDEF_H
