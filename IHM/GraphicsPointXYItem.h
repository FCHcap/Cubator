#ifndef GRAPHICSPOINTXYITEM_H
#define GRAPHICSPOINTXYITEM_H

// QT
#include <QtGui>

// CUBATOR
#include <CubGeo.h>
#include <GeoData.h>
#include <GeoVecteur.h>
#include <GeoException.h>
#include <Messages.h>
#include <GraphicsTypes.h>
#include <GraphicsMapLayer.h>
#include <Settings.h>

#define SGPS "GPS"
#define SCART "CART"
#define SLEFT "LEFT"
#define SRIGHT "RIGHT"

class GraphicsPointXYItem : public QGraphicsEllipseItem
{
public:
    enum { Type = GRAPHICS_POINTXY_TYPE };
    enum TCoords{GPS, CART, MANUAL};
    enum Position{LEFT, RIGHT};

    int type() const;

    explicit GraphicsPointXYItem(QGraphicsItem *parent = 0);

    void setFont(const QFont &font);
    QFont font() const;

    void setPen(const QPen &pen);
    QPen pen() const;

    void setBrush(const QBrush &brush);
    QBrush brush() const;

    void setPos(const QPointF &pos);
    QPointF pos() const;

    void setPosition(Position position);
    Position position() const;

    void setManualPos(QPointF position);
    QPointF manualPos() const;

    void setPositionFromString(QString position);
    QString positionToString() const;

    void setTypeCoords(TCoords tCoords);
    TCoords typeCoords() const;

    void setTypeCoordsFromString(QString coords);
    QString typeCoordsToString() const;

    void setTransform(const QTransform &matrix, bool combine);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);

protected:
    void updateCoordsGPS();
    void updateCoordsCart();
    void updateCoordsManual();
    void updateTextItem();

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

    QGraphicsSimpleTextItem _text;
    QString _tGPS;
    QString _tCart;
    QString _tMan;
    TCoords _tCoords;
    Position _tPos;
    QPointF _mPos;
};

#endif // GRAPHICSPOINTXYITEM_H
