#ifndef GRAPHICSICONITEM_H
#define GRAPHICSICONITEM_H

// QT
#include <QGraphicsItem>
#include <QDate>

// CUBATOR
#include <GraphicsTypes.h>
#include <GraphicsMapIconDef.h>
#include <GraphicsPolylineItem.h>
#include <CoordinatesDialog.h>
#include <DateDialog.h>

class GraphicsIconItem : public QGraphicsItem
{
public:
    enum { Type = GRAPHICS_ICON_TYPE };
    int type() const;

    GraphicsIconItem(QGraphicsItem * parent = 0, GraphicsMapIconDef * iconDef = 0);

    void setIconDef(const GraphicsMapIconDef * iconDef);
    GraphicsMapIconDef * iconDef() const;

    void setDate(QString date);
    QString date();

    void setName(const QString & name);
    QString name() const;

    void enableContextMenuEvent(bool cmv);

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);

protected:
    QString _date;
    QString _name;
    GraphicsMapIconDef * _iconDef;
    bool _cmv; // Context menu event enabled
};

#endif // GRAPHICSICONITEM_H
