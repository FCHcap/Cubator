#ifndef GRAPHICSMAPLAYER_H
#define GRAPHICSMAPLAYER_H

// QT
#include <QStringList>
#include <QMap>
#include <QEvent>
#include <QGraphicsSceneDragDropEvent>

// CUBATOR
#include <GraphicsTypes.h>
#include <CubException.h>

class GraphicsMap;

class GraphicsMapLayer : public QGraphicsItem{

public:
    enum { Type = GRAPHICS_LAYER_TYPE };

    int type() const;

    GraphicsMapLayer(QGraphicsItem * parent = 0);

    void setName(const QString & name);
    QString name() const;

    void setEditable(bool editable = 1);
    bool editable() const;

    void setFlags(QGraphicsItem *item);
    void setFlags(QGraphicsItem * item, bool enable);

    void setSelectToolEnabled(bool enable = 1);
    bool selectToolEnabled() const;

    void updateEditionAuthorization();

    void addToLayer(QGraphicsItem *item, bool layerEdited = 1);
    void updateZValue();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void updateBoundingRect();

    void itemEdited();
    QList<QGraphicsItem*> picturesList() const;
    QStringList picturesFilepaths() const;

protected:
    QString _name;
    qreal _elevation;
    QRectF _rect;
    bool _editable; // indique si l'édition du calque est autorisée
    bool _selectToolEnabled; // indique si l'outil de sélection est activé
};

#endif // GRAPHICSMAPLAYER_H
