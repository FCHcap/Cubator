#ifndef GRAPHICSTEXTITEM_H
#define GRAPHICSTEXTITEM_H

// QT
#include <QtGui>
#include <QObject>
#include <QCoreApplication>

// CUBATOR
#include <GraphicsTypes.h>
#include <GraphicsTextDialog.h>
#include <GraphicsMapLayer.h>
#include <GraphicsItem.h>

class GraphicsTextItem : public QGraphicsSimpleTextItem, public GraphicsItem
{

    Q_DECLARE_TR_FUNCTIONS(GraphicsTextItem)

public:
    enum { Type = GRAPHICS_TEXT_TYPE };

    int type() const;
    explicit GraphicsTextItem(QGraphicsItem *parent = 0);
    void edit(QGraphicsSceneMouseEvent *event);

protected:
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);
};

#endif // GRAPHICSTEXTITEM_H
