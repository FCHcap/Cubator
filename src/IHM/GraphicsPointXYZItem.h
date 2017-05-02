#ifndef GRAPHICSPOINTXYZITEM_H
#define GRAPHICSPOINTXYZITEM_H

// QT
#include <QGraphicsItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsSimpleTextItem>
#include <QPen>
#include <QPainter>

// CUBATOR
#include <DVertexList.h>
#include <GraphicsTypes.h>

/* Descriptif
 *
 * Affiche un point avec la profondeur à côté (utilisé pour l'affichage de vecteurs)
 * Colore le point selon le niveau de profondeur
 * */

class GraphicsPointXYZItem : public QGraphicsItem
{
public:
    GraphicsPointXYZItem(const bool displayDepth, QGraphicsItem *parent = 0);

    void setVertex(DVertex vertex, QColor color);

    DVertex vertex() const;
    QColor color() const;

    void setDisplayDepth(const bool displayDepth);
    bool displayDepth() const;

    enum { Type = GRAPHICS_POINT_XYZ_TYPE };

    int type() const;
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

protected:
    QGraphicsEllipseItem _point;
    QGraphicsSimpleTextItem _depth;
    QColor _color;
    DVertex _vertex;
    QRectF _rect;

};

#endif // GRAPHICSPOINTXYZITEM_H
