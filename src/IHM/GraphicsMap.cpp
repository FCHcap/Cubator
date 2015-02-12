#include "GraphicsMap.h"

int GraphicsMap::type() const{
    return Type;
}

GraphicsMap::GraphicsMap(QGraphicsItem *parent, GraphicsMapEventManager * manager) : QGraphicsItem(parent){
    _edited = 0;
    _monitorChangesEnabled = 0;
    _eventManager = manager;
}

void GraphicsMap::setEdited(bool edited){
    if(!_monitorChangesEnabled) return; // quitte la méthode si la surveillance des modifications est désactivée

    _edited = edited;
    if(_eventManager) _eventManager->updateGraphicsMap();
}

bool GraphicsMap::edited() const{
    return _edited;
}

void GraphicsMap::setMapEventManager(GraphicsMapEventManager *eventManager){
    _eventManager = eventManager;
}

void GraphicsMap::enableMonitorChanges(bool enable){
    _monitorChangesEnabled = enable;
}

GraphicsMapLayer * GraphicsMap::addLayer(const QString &layername, bool mapEdited){

    if(_mLayers.contains(layername)) throw CubException(BRIEF14, ERROR13, "GraphicsMap::addLayer");

    GraphicsMapLayer * layer = new GraphicsMapLayer;
    layer->setName(layername);
    _mLayers.insert(layername, layer);

    layer->setParentItem(this);

    updateBoundingRect();
    if(mapEdited) setEdited(1);

    return layer;
}

void GraphicsMap::removeLayer(const QString &layername){

    if(!_mLayers.contains(layername)) throw CubException(BRIEF15, ERROR14, "GraphicsMapItemList::removeLayer");

    GraphicsMapLayer * layer = _mLayers.value(layername);

    _mLayers.remove(layername);
    delete layer;

    setEdited(1);
}

bool GraphicsMap::layerExists(const QString &layername){

    return _mLayers.contains(layername);
}

void GraphicsMap::selectLayer(const QString &layername){
    _layerSelected = layername;
}

QString GraphicsMap::layerSelected(){
    return _layerSelected;
}

bool GraphicsMap::layerIsVisible(const QString &layername){

    bool visible = 0;

    if(_mLayers.contains(layername)){
        GraphicsMapLayer * layer = _mLayers[layername];
        visible = layer->isVisible();
    }
    return visible;
}

void GraphicsMap::setLayerVisibility(const QString &layername, bool visible){

    if(_mLayers.contains(layername)){
        GraphicsMapLayer * layer = _mLayers[layername];
        if(layer->isVisible() != visible){
            setEdited(1);
            layer->setVisible(visible);
        }
    }
}

QStringList GraphicsMap::layers(){
    return _mLayers.keys();
}

GraphicsMapLayer * GraphicsMap::layerItem(const QString &layername){

    GraphicsMapLayer * layer = 0;

    if(_mLayers.contains(layername)){
        layer = _mLayers[layername];
    }

    return layer;
}

int GraphicsMap::layersItemsCount() const{

    int cpt = 0;

    foreach(QString layername, _mLayers.keys()){

        GraphicsMapLayer * layer = _mLayers[layername];

        if(layer) cpt += layer->childItems().count();
    }

    return cpt;
}

QMap<QString, GraphicsMeshImageItem*> GraphicsMap::meshes(){
    QMap<QString, GraphicsMeshImageItem*> meshes;
    foreach(QGraphicsItem * item, childItems()){
        if(item->type() == GraphicsMapLayer::Type){
            GraphicsMapLayer * layer = qgraphicsitem_cast<GraphicsMapLayer*>(item);
            foreach(QGraphicsItem * item2, layer->childItems()){
                if(item2->type() == GraphicsMeshImageItem::Type){
                    GraphicsMeshImageItem * mesh = qgraphicsitem_cast<GraphicsMeshImageItem*>(item2);
                    meshes.insert(mesh->tableName(), mesh);
                }
            }
        }
    }
    return meshes;
}

void GraphicsMap::addIconDef(GraphicsMapIconDef * icondef){

    if(!icondef) return;

    if(_mIcons.contains(icondef->name()))  throw CubException(BRIEF16, ERROR15, "GraphicsMap::addIcon");

    _mIcons.insert(icondef->name(), icondef);
    updateIcons(icondef->name(), icondef);
    setEdited(1);
}

GraphicsMapIconDef * GraphicsMap::addIconDef(const QString &iconName){

    if(_mIcons.contains(iconName)) throw CubException(BRIEF16, ERROR15, "GraphicsMap::addIcon");

    GraphicsMapIconDef * iconDef = new GraphicsMapIconDef;
    iconDef->setName(iconName);
    _mIcons.insert(iconName, iconDef);
    updateIcons(iconDef->name(), iconDef);
    setEdited(1);

    return iconDef;
}

void GraphicsMap::removeIconDef(const QString &iconName){

    if(!_mIcons.contains(iconName)) throw CubException(BRIEF17, ERROR16, "GraphicsMap::removeIconDef");

    GraphicsMapIconDef * iconDef = _mIcons.value(iconName);

    _mIcons.remove(iconName);
    updateIcons(iconName, 0);
    delete iconDef;

    setEdited(1);
}

void GraphicsMap::updateIcons(const QString &iconName, GraphicsMapIconDef *icondef){

    foreach(QGraphicsItem * item, childItems()){
        if(item->type() == GraphicsMapLayer::Type){
            GraphicsMapLayer * layer = qgraphicsitem_cast<GraphicsMapLayer*>(item);
            foreach(QGraphicsItem * item2, layer->childItems()){
                if(item2->type() == GraphicsIconItem::Type){
                    GraphicsIconItem * icon = qgraphicsitem_cast<GraphicsIconItem*>(item2);
                    if(icon->name() == iconName) icon->setIconDef(icondef);
                }
            }
        }
    }
}

bool GraphicsMap::iconDefExists(const QString &icondef){
    return _mIcons.contains(icondef);
}

void GraphicsMap::selectIconDef(const QString &icondef){
    _iconSelected = icondef;
}

QString GraphicsMap::iconDefSelected() const{
    return _iconSelected;
}

QStringList GraphicsMap::iconDefs() const{
    return _mIcons.keys();
}

GraphicsMapIconDef * GraphicsMap::iconDefItem(const QString &icondef){

    GraphicsMapIconDef * icon = 0;

    if(_mIcons.contains(icondef)){
        icon = _mIcons[icondef];
    }

    return icon;
}

int GraphicsMap::iconsDefItemsCount() const{

    int cpt = 0;

    foreach(QString icondefname, _mIcons.keys()){
        GraphicsMapIconDef * icondef = _mIcons[icondefname];

        if(icondef) cpt += icondef->childItems().count();
    }
    return cpt;
}

void GraphicsMap::addBoatDef(GraphicsMapBoatDef *boatdef){
    if(!boatdef) return;

    if(_mBoats.contains(boatdef->name()))  throw CubException(BRIEF18, ERROR17, "GraphicsMap::addIcon");

    _mBoats.insert(boatdef->name(), boatdef);
    setEdited(1);
}

GraphicsMapBoatDef * GraphicsMap::addBoatDef(const QString &boatName){

    if(_mBoats.contains(boatName)) throw CubException(BRIEF18, ERROR17, "GraphicsMap::addBoatDef");

    GraphicsMapBoatDef * boatDef = new GraphicsMapBoatDef;
    boatDef->setName(boatName);
    _mBoats.insert(boatName, boatDef);
    setEdited(1);

    return boatDef;
}

void GraphicsMap::removeBoatDef(const QString &boatName){
    if(!_mBoats.contains(boatName)) throw CubException(BRIEF19, ERROR18, "GraphicsMap::removeBoatDef");

    GraphicsMapBoatDef * boatDef = _mBoats.value(boatName);

    _mBoats.remove(boatName);
    delete boatDef;

    setEdited(1);
}

QStringList GraphicsMap::boatDefs() const{
    return _mBoats.keys();
}

GraphicsMapBoatDef * GraphicsMap::boatDefItem(const QString &boatName){
    GraphicsMapBoatDef * boat = 0;

    if(_mBoats.contains(boatName)){
        boat = _mBoats[boatName];
    }

    return boat;
}

QRectF GraphicsMap::boundingRect() const{
    return _rect;
}

void GraphicsMap::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    Q_UNUSED(painter)
    Q_UNUSED(option)
    Q_UNUSED(widget)
}

void GraphicsMap::updateBoundingRect(){
    _rect = childrenBoundingRect();
}
