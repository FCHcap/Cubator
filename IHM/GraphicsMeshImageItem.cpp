#include "GraphicsMeshImageItem.h"

// CUBATOR
#include <DataReader.h>

GraphicsMeshImageItem::GraphicsMeshImageItem(QGraphicsItem * parent, const  QString &tableName) : QGraphicsItem(parent){
    setTableName(tableName);
    //_loadImage = 0;
    _px = 0;
}

int GraphicsMeshImageItem::type() const{
    return Type;
}

void GraphicsMeshImageItem::setTableName(const QString &tableName){
    _tableName = tableName;
    if(_tableName.isEmpty()) return;

    loadVertices();
    loadTriangles();
    loadGrid();
    loadImage();
    //_loadImage = 1;
}

QString GraphicsMeshImageItem::tableName() const{
    return _tableName;
}

bool GraphicsMeshImageItem::depthAt(const QPointF &pos, double & depth){
    return _mesh.depthAt(pos, depth);
}

double GraphicsMeshImageItem::depthAt(const QPointF &pos){
    double depth;
    if(depthAt(pos, depth)) return depth;
    return DBL_MAX;
}

bool GraphicsMeshImageItem::depthGridAt(const QPointF &pos, double &depth){
    return _mesh.depthGridAt(pos, depth);
}

double GraphicsMeshImageItem::depthGridAt(const QPointF &pos){
    double depth;
    if(depthGridAt(pos, depth)) return depth;
    return DBL_MAX;
}

QRectF GraphicsMeshImageItem::boundingRect() const{
    return childrenBoundingRect();
}

void GraphicsMeshImageItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    Q_UNUSED(painter)
    Q_UNUSED(option)
    Q_UNUSED(widget)
}

void GraphicsMeshImageItem::loadVertices(){
    _mesh.clear();
    VerticesReader vreader(Data::vectorFileName(_tableName));
    while(!vreader.atEnd()){
        _mesh.append(vreader.readVertex());
    }
}

void GraphicsMeshImageItem::loadTriangles(){
    DTriangleList *triangles = _mesh.triangles();
    triangles->clear();
    TrianglesReader treader(Data::triangleFilename(_tableName));
    while(!treader.atEnd()){
        triangles->append(treader.readTriangle());
    }
}

void GraphicsMeshImageItem::loadGrid(){
    DTGrid * grid = _mesh.grid();
    grid->clear();
    GridReader greader(Data::gridFilename(_tableName));
    grid->setBounds(greader.readBounds());
    while(!greader.atEnd()){
        grid->append(greader.readGridItem());
    }
}

void GraphicsMeshImageItem::loadImage(){

    if(_px) delete _px;

    if(_tableName.isEmpty()) return;

    _px = new QGraphicsPixmapItem(this);
    _px->setTransformationMode(Qt::SmoothTransformation);

    QImage img(Data::imageFilename(_tableName), "BMP");

    QPixmap px;
    px.convertFromImage(img, Qt::ColorOnly);

    QRectF bounds = _mesh.bounds();
    int xmin = (int) bounds.left();
    int ymin = (int) bounds.bottom();

    _px->setPixmap(px);
    _px->setOffset(xmin, ymin - img.height());
}
