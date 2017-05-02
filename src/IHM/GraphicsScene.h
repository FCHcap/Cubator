#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H

// QT
#include <QGraphicsScene>
#include <QMap>

// CUBATOR
#include <GraphicsMeshImageItem.h>
#include <GraphicsIconItem.h>
#include <GraphicsHatchItem.h>
#include <GraphicsBoatItem.h>
#include <GraphicsPolylineItem.h>
#include <GraphicsMeasureItem.h>
#include <GraphicsAreaItem.h>
#include <GraphicsVolumeItem.h>
#include <GraphicsMap.h>
#include <GraphicsMapLayer.h>
#include <GraphicsPointXYItem.h>
#include <Settings.h>
#include <Tools.h>

class GraphicsMap;

class GraphicsScene : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit GraphicsScene(QObject *parent = 0);

    void selectTool(Tool tool);
    Tool toolSelected();

    void setPen(QPen pen);
    QPen pen();

    void setMap(const GraphicsMap * map);
    GraphicsMap * map() const;

    void setIcon(const QString &icon);
    QString icon() const;

    GraphicsBoatItem * boatItem();

    void setPaintColor(QColor color);
    QColor paintColor();

    void setLineWidth(int lineWidth);
    int lineWidth();

    void setFont(QFont font);
    QFont font();

    void setTransform(QTransform transform);

protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);
    void wheelEvent(QGraphicsSceneWheelEvent *event);
    void keyPressEvent(QKeyEvent *event);

    void processMeshDepth(QGraphicsSceneMouseEvent * event);
    
signals:
    void mousePositionUpdated(QPointF);
    void mouseMeshDepthAdded(QString, double); // tablename, depth
    void mouseMeshDepthNotFound();
    void volumeShapeDefined(GraphicsVolumeItem *);
    void areaShapeDefined(GraphicsAreaItem *);
    void pointXYZAdded(QPointF);
    
public slots:
    void updateGpsPosition(const QPointF &position);

protected:

    Tool _toolSelected;
    GraphicsMap * _map;
    QString _icon;
    QString _boat;
    QGraphicsLineItem* _lineItem;
    GraphicsPolylineItem* _polylineItem;
    GraphicsIconItem * _iconItem;
    GraphicsPolylineItem* _pHatchItem;
    GraphicsMeasureItem * _measureItem;
    GraphicsAreaItem *_areaItem;
    GraphicsVolumeItem * _volumeItem;
    GraphicsBoatItem _boatItem;
    QTransform _transform;

    QPen _pen;
    QFont _font;
    
};

#endif // GRAPHICSSCENE_H
