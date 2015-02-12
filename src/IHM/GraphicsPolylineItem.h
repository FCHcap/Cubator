#ifndef GRAPHICSPOLYLINEITEM_H
#define GRAPHICSPOLYLINEITEM_H

// QT
#include <QtGui>
#include <QList>

// CUBATOR
#include <GraphicsTypes.h>

// STL
#include <cfloat>
#include <cmath>

class GraphicsPolylineItem : public QGraphicsItem
{
public:
    enum { Type = GRAPHICS_POLYLINE_TYPE };

    typedef QVector<QPointF> GPIPOINTS;

    GraphicsPolylineItem(QGraphicsItem *parent = 0);
    ~GraphicsPolylineItem();

    int type() const;

    void addPoint(const QPointF & point);
    GPIPOINTS points() const;
    void clearPoints();

    QPen pen();
    void setPen(const QPen & pen);

    bool isClosed();
    void setClosed(bool closed);

    bool polylineContains(const QPointF &point) const;
    bool polylineContains(const QRect &rect) const;

    void showPoints(bool show = 1);
    QRectF boundingRect() const;

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    QPen _pen;
    GPIPOINTS _points;
    QRectF _rect;
    bool _closed;
    bool _pointsShown;
    bool _isFirstPoint;
    QPointF _lastPoint;
};

#endif // GRAPHICSPOLYLINEITEM_H
