#include "GraphicsItemList.h"

GraphicsItemList::GraphicsItemList()
{
    _visible = 1;
}

GraphicsItemList::~GraphicsItemList(){

    QGraphicsItem* item = 0;
    foreach(item, _list){
        QGraphicsScene * scene = item->scene();
        if(scene) scene->removeItem(item);
        delete item;
    }
}

void GraphicsItemList::setCenter(QPointF center){
    _center = center;
}

QPointF GraphicsItemList::center(){
    return _center;
}

void GraphicsItemList::setName(QString name){
    _name = name;
}

QString GraphicsItemList::name(){
    return _name;
}

void GraphicsItemList::setSelectionColor(QColor color){
    _selectionColor = color;
}

QColor GraphicsItemList::selectionColor(){
    return _selectionColor;
}

void GraphicsItemList::setBounds(QRectF bounds){
    _bounds = bounds;
}

QRectF GraphicsItemList::bounds(){
    return _bounds;
}

void GraphicsItemList::setVisible(bool visible){

    if(_visible == visible) return;
    _visible = visible;

    QGraphicsItem* item = 0;
    foreach(item, _list){
        item->setVisible(visible);
    }
}

bool GraphicsItemList::visible(){
    return _visible;
}

bool GraphicsItemList::contains(QGraphicsItem *item){
    if(_list.contains(item)) return 1;
    return 0;
}

void GraphicsItemList::setOverviewColor(QColor color){
    _overviewColor = color;
}

QColor GraphicsItemList::overviewColor(){
    return _overviewColor;
}

QList<QGraphicsItem*> GraphicsItemList::list(){
    return _list;
}

QGraphicsLineItem * GraphicsItemList::createLineItem(){
    QGraphicsLineItem * item = new QGraphicsLineItem;
    _list.append(item);
    return item;
}

QGraphicsEllipseItem * GraphicsItemList::createEllipseItem(){
    QGraphicsEllipseItem * item = new QGraphicsEllipseItem;
    _list.append(item);
    return item;
}

GraphicsTextItem * GraphicsItemList::createTextItem(){
    GraphicsTextItem * item = new GraphicsTextItem;
    _list.append(item);
    return item;
}

GraphicsPolylineItem * GraphicsItemList::createPolylineItem(){
    GraphicsPolylineItem * item = new GraphicsPolylineItem;
    _list.append(item);
    return item;
}

GraphicsHatchItem * GraphicsItemList::createHatchItem(){
    GraphicsHatchItem * item = new GraphicsHatchItem;
    _list.append(item);
    return item;
}

QGraphicsItemGroup * GraphicsItemList::createItemGroup(){
    QGraphicsItemGroup * group = new QGraphicsItemGroup;
    _list.append(group);
    return group;
}

void GraphicsItemList::removeGraphicsItem(QGraphicsItem * item){
    if(item){
        if(_list.contains(item)){
            _list.removeOne(item);
            QGraphicsScene * scene = item->scene();
            if(scene) scene->removeItem(item);
            delete item;
        }
    }
}
