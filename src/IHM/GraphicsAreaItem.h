#ifndef GRAPHICSAREAITEM_H
#define GRAPHICSAREAITEM_H

// QT
#include <qgraphicsitem.h>
#include <QGraphicsTextItem>
#include <qtransform.h>

// CUBATOR
#include <GraphicsPolylineItem.h>
#include <Messages.h>

class GraphicsAreaItem : public QObject, public GraphicsPolylineItem
{
    Q_OBJECT

public:
    enum { Type = GRAPHICS_AREA_TYPE };
    GraphicsAreaItem(QGraphicsItem *parent = 0);

    int type() const;

    qreal surface() const;

    void setBrushColor(const QColor color);
    void setFont(const QFont font);
    void setTextColor(const QColor &color);

    void updateTextItem();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
public slots:
    void setSurface(qreal surface);

private:
    qreal _surface;
    QGraphicsTextItem _textItem;
};

#endif // GRAPHICSAREAITEM_H
