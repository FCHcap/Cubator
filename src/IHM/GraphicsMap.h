#ifndef GRAPHICSMAP_H
#define GRAPHICSMAP_H

// QT
#include <QStringList>
#include <QMap>
#include <QCoreApplication>

// CUBATOR
#include <GraphicsItemList.h>
#include <GraphicsTypes.h>
#include <GraphicsMapLayer.h>
#include <GraphicsMapIconDef.h>
#include <GraphicsMapBoatDef.h>
#include <GraphicsMeshImageItem.h>
#include <GraphicsIconItem.h>
#include <CubException.h>
#include <GraphicsMapEventManager.h>

class GraphicsMapLayer;

class GraphicsMap : public QGraphicsItem{

    Q_DECLARE_TR_FUNCTIONS(GraphicsMap)

public:

    enum { Type = GRAPHICS_MAP_TYPE };

    int type() const;

    GraphicsMap(QGraphicsItem * parent = 0, GraphicsMapEventManager * manager = 0);

    void setEdited(bool edited);
    bool edited() const;
    void setMapEventManager(GraphicsMapEventManager * eventManager);

    void enableMonitorChanges(bool enable = 1);

    // Management layers
    GraphicsMapLayer * addLayer(const QString &layername, bool mapEdited = 1);
    void removeLayer(const QString &layername);

    bool layerExists(const QString &layername);
    void selectLayer(const QString &layername);
    QString layerSelected();
    bool layerIsVisible(const QString &layername);
    void setLayerVisibility(const QString &layername, bool visible);
    QStringList layers();
    GraphicsMapLayer * layerItem(const QString &layername);
    int layersItemsCount() const;

    void setDefaultLayer(const QString &layername);
    QString defaultLayer() const;

    QMap<QString, GraphicsMeshImageItem*> meshes();

    // Management icons
    void addIconDef(GraphicsMapIconDef * icondef);
    GraphicsMapIconDef * addIconDef(const QString &iconname);
    void removeIconDef(const QString &iconname);
    void updateIcons(const QString &iconname, GraphicsMapIconDef * icondef =0);

    bool iconDefExists(const QString &iconname);
    void selectIconDef(const QString &iconname);
    QString iconDefSelected() const;
    QStringList iconDefs() const;
    GraphicsMapIconDef * iconDefItem(const QString &iconname);
    int iconsDefItemsCount() const;

    // Management boats
    void addBoatDef(GraphicsMapBoatDef * boatdef);
    GraphicsMapBoatDef * addBoatDef(const QString &boatname);
    void removeBoatDef(const QString &boatname);

    QStringList boatDefs() const;
    GraphicsMapBoatDef * boatDefItem(const QString &boatname);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void updateBoundingRect();

    // Management tables



protected:
    QMap<QString, GraphicsMapLayer*> _mLayers;
    QMap<QString, GraphicsMapIconDef*> _mIcons;
    QMap<QString, GraphicsMapBoatDef*> _mBoats;
    GraphicsMapEventManager * _eventManager;
    QString _layerSelected;
    QString _defaultLayer;
    QString _iconSelected;
    QRectF _rect;
    bool _edited;
    bool _monitorChangesEnabled;
};

#endif // GRAPHICSMAP_H
