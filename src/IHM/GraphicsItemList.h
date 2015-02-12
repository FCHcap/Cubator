#ifndef GRAPHICSITEMLIST_H
#define GRAPHICSITEMLIST_H

#include <QList>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <GraphicsPolylineItem.h>
#include <GraphicsHatchItem.h>
#include <GraphicsTextItem.h>

class GraphicsTextItem;

class GraphicsItemList
{
public:
    GraphicsItemList();
    ~GraphicsItemList();

    void setCenter(QPointF center);
    QPointF center();

    void setName(QString name);
    QString name();

    void setOverviewColor(QColor color);
    QColor overviewColor();

    void setSelectionColor(QColor color);
    QColor selectionColor();

    void setBounds(QRectF bounds);
    QRectF bounds();

    void setVisible(bool visible);
    bool visible();

    bool contains(QGraphicsItem * item);

    QList<QGraphicsItem*> list();

    QGraphicsLineItem * createLineItem();
    QGraphicsEllipseItem * createEllipseItem();
    GraphicsTextItem * createTextItem();
    GraphicsPolylineItem * createPolylineItem();
    GraphicsHatchItem * createHatchItem();
    QGraphicsItemGroup * createItemGroup();

    void removeGraphicsItem(QGraphicsItem*);

protected:
    QPointF _center;
    QString _name;
    QColor _overviewColor;
    QColor _selectionColor;
    QRectF _bounds;
    QList<QGraphicsItem*> _list;
    bool _visible;
};

#endif // GRAPHICSITEMLIST_H
