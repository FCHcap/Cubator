#ifndef GRAPHICSPICTUREITEM_H
#define GRAPHICSPICTUREITEM_H

// QT
#include <QGraphicsItem>

// CUBATOR
#include <GraphicsTypes.h>
#include <CubException.h>

class GraphicsAnchorsItem;
class GraphicsRAnchorItem;
class GraphicsPointXYItem;

class GraphicsPictureItem : public QGraphicsItem
{
public:
    enum { Type = GRAPHICS_PICTURE_TYPE };
    enum Capture { FIRST_ANCHOR, LAST_ANCHOR, NOTHING };
    enum Anchor { TOP_LEFT_ANCHOR, TOP_RIGHT_ANCHOR, BOTTOM_LEFT_ANCHOR, BOTTOM_RIGHT_ANCHOR };
    GraphicsPictureItem(QGraphicsItem * parent = 0);
    int type() const;

    void anchorsUpdated(int width, Anchor anchor); // Position de l'image, taille (nombre réel)
    void rAnchorUpdated(qreal angle);
    void setFilepath(const QString filepath) throw (CubException);
    QString filepath() const;

    void setPixmapWidth(int width);
    int pixmapWidth() const;

    void setSceneCenter(const QPointF pos);
    QPointF sceneCenter() const;

    void setFirstAnchorScenePos(const QPointF &pos);
    QPointF firstAnchorScenePos() const;

    void setLastAnchorScenePos(const QPointF &pos);
    QPointF lastAnchorScenePos() const;

    void setFont(const QFont &font);
    QFont font() const;

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

protected:


protected:
    QGraphicsPixmapItem * _pi;
    GraphicsAnchorsItem * _anchors;
    GraphicsRAnchorItem * _ranchor;
    GraphicsPointXYItem * _firstAnchorItem;
    GraphicsPointXYItem * _lastAnchorItem;
    QPixmap _px;
    QString _filepath;
    QSize _size;
    Capture _capture;
    Capture _state; /* état du positionnement des ancres
                     * (nothing : aucune n'est positionnée,
                     * first_anchor : la première est positionnée,
                     * last_anchor : elles sont toutes positionnées) */
};

#endif // GRAPHICSPICTUREITEM_H
