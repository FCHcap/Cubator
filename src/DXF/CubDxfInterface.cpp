#include "CubDxfInterface.h"

CubDxfInterface::CubDxfInterface(GraphicsMap * map)
{
    _map = map;
}

void CubDxfInterface::setMap(GraphicsMap *map){
    _map = map;
}

GraphicsMap * CubDxfInterface::map(){
    return _map;
}

/** Called when header is parsed.  */
void CubDxfInterface::addHeader(const DRW_Header* data){
    Q_UNUSED(data)
}

/** Called for every line Type.  */
void CubDxfInterface::addLType(const DRW_LType& data){

    QVector<qreal> dash;
    for(int i=0; i< (signed int) data.path.size(); i++){
        dash << std::fabs(data.path[i]);
    }

    _hDashPattern.insert(QString::fromStdString(data.name), dash);

}
/** Called for every layer. */
void CubDxfInterface::addLayer(const DRW_Layer& data){

    QString layername = QString::fromStdString(data.name);

    QPen pen;

    // Sets the color
    int ccode = data.color;
    QColor color = QColor::fromRgbF(DRW::dxfColors[ccode][0], DRW::dxfColors[ccode][1], DRW::dxfColors[ccode][2]);
    pen.setColor(color);

    // Sets the linetype
    if(_hDashPattern.contains(QString::fromStdString(data.lineType))){
        pen.setDashPattern(_hDashPattern.value(QString::fromStdString(data.lineType)));
    }

    // Sets the lineweight
    if(data.lWeight >= 0 && data.lWeight <= 211){
        pen.setWidthF(data.lWeight * THOU);
    }

    _hLayers.insert(QString::fromStdString(data.name), pen);

    // Add layer to map
    if(!_map->layerExists(layername)){
        _map->addLayer(layername, 0);
    }

}
/** Called for every dim style. */
void CubDxfInterface::addDimStyle(const DRW_Dimstyle& data){
    Q_UNUSED(data)
}

/**
 * Called for every block. Note: all entities added after this
 * command go into this block until endBlock() is called.
*
 * @see endBlock()
 */
void CubDxfInterface::addBlock(const DRW_Block& data){
    Q_UNUSED(data)
}

/** Called to end the current block */
void CubDxfInterface::endBlock(){

}

/** Called for every point */
void CubDxfInterface::addPoint(const DRW_Point& data){

    QString layername = QString::fromStdString(data.layer);

    QGraphicsEllipseItem * ellipseItem = new QGraphicsEllipseItem;
    ellipseItem->setRect(data.basePoint.x - data.thickness / 2, data.basePoint.y - data.thickness / 2, data.thickness, data.thickness);

    // Add the item to layer
    GraphicsMapLayer * layer = _map->layerItem(layername);
    if(layer) layer->addToLayer(ellipseItem, 0);

    // Sets the pen
    if(_hLayers.contains(layername)){
        ellipseItem->setPen(_hLayers.value(layername));
    }

    // Sets the line type
    if(QString::fromStdString(data.lineType) != "BYLAYER"){
        if(_hDashPattern.contains(QString::fromStdString(data.lineType))){
            QPen pen = ellipseItem->pen();
            pen.setDashPattern(_hDashPattern.value(QString::fromStdString(data.lineType)));
            ellipseItem->setPen(pen);
        }
    }
}

/** Called for every line */
void CubDxfInterface::addLine(const DRW_Line& data){

    QString layername = QString::fromStdString(data.layer);

    QGraphicsLineItem* lineItem = new QGraphicsLineItem;
    lineItem->setLine(QLineF(QPointF(data.basePoint.x, data.basePoint.y), QPointF(data.secPoint.x, data.secPoint.y)));

    // Add the item to layer
    GraphicsMapLayer * layer = _map->layerItem(layername);
    if(layer) layer->addToLayer(lineItem, 0);

    // Sets the pen
    if(_hLayers.contains(layername)){
        lineItem->setPen(_hLayers.value(layername));
    }

    // Sets the line type
    if(QString::fromStdString(data.lineType) != "BYLAYER"){
        if(_hDashPattern.contains(QString::fromStdString(data.lineType))){
            QPen pen = lineItem->pen();
            pen.setDashPattern(_hDashPattern.value(QString::fromStdString(data.lineType)));
            lineItem->setPen(pen);
        }
    }
}

/** Called for every ray */
void CubDxfInterface::addRay(const DRW_Ray& data){
    Q_UNUSED(data)
}

/** Called for every xline */
void CubDxfInterface::addXline(const DRW_Xline& data){
    Q_UNUSED(data)
}

/** Called for every arc */
void CubDxfInterface::addArc(const DRW_Arc& data){
    Q_UNUSED(data)
}

/** Called for every circle */
void CubDxfInterface::addCircle(const DRW_Circle& data){
    Q_UNUSED(data)
}

/** Called for every ellipse */
void CubDxfInterface::addEllipse(const DRW_Ellipse& data){

    QString layername = QString::fromStdString(data.layer);

    QGraphicsEllipseItem * ellipseItem = new QGraphicsEllipseItem;
    ellipseItem->setRect(data.basePoint.x - data.thickness / 2, data.basePoint.y - data.thickness / 2, data.thickness, data.thickness);

    // Add the item to layer
    GraphicsMapLayer * layer = _map->layerItem(layername);
    if(layer) layer->addToLayer(ellipseItem, 0);

    // Sets the pen
    if(_hLayers.contains(layername)){
        ellipseItem->setPen(_hLayers.value(layername));
    }

    // Sets the line type
    if(QString::fromStdString(data.lineType) != "BYLAYER"){
        if(_hDashPattern.contains(QString::fromStdString(data.lineType))){
            QPen pen = ellipseItem->pen();
            pen.setDashPattern(_hDashPattern.value(QString::fromStdString(data.lineType)));
            ellipseItem->setPen(pen);
        }
    }
}

/** Called for every lwpolyline */
void CubDxfInterface::addLWPolyline(const DRW_LWPolyline& data){

    QString layername = QString::fromStdString(data.layer);

    GraphicsPolylineItem* polylineItem = new GraphicsPolylineItem;

    if(data.flags == 1) polylineItem->setClosed(1);
    for(int i=0; i< (signed int) data.vertlist.size(); i++){
        QPointF point;
        point.setX(data.vertlist.at(i)->x);
        point.setY(data.vertlist.at(i)->y);

        polylineItem->addPoint(point);
    }

    // Add the item to layer
    GraphicsMapLayer * layer = _map->layerItem(layername);
    if(layer) layer->addToLayer(polylineItem, 0);

    // Sets the pen
    if(_hLayers.contains(QString::fromStdString(data.layer))){
        polylineItem->setPen(_hLayers.value(QString::fromStdString(data.layer)));
    }

    // Sets the line type
    if(QString::fromStdString(data.lineType) != "BYLAYER"){
        if(_hDashPattern.contains(QString::fromStdString(data.lineType))){
            QPen pen = polylineItem->pen();
            pen.setDashPattern(_hDashPattern.value(QString::fromStdString(data.lineType)));
            polylineItem->setPen(pen);
        }
    }

}

/** Called for every polyline start */
void CubDxfInterface::addPolyline(const DRW_Polyline& data){

    QString layername = QString::fromStdString(data.layer);

    GraphicsPolylineItem* polylineItem = new GraphicsPolylineItem;

    polylineItem->setPen(_pen);
    for(int i=0; i< (signed int)data.vertlist.size(); i++){
        QPointF point;
        point.setX(data.vertlist.at(i)->basePoint.x);
        point.setY(data.vertlist.at(i)->basePoint.y);

        polylineItem->addPoint(point);
    }

    // Add the item to layer
    GraphicsMapLayer * layer = _map->layerItem(layername);
    if(layer) layer->addToLayer(polylineItem, 0);

    // Sets the pen
    if(_hLayers.contains(QString::fromStdString(data.layer))){
        polylineItem->setPen(_hLayers.value(QString::fromStdString(data.layer)));
    }

    // Sets the line type
    if(QString::fromStdString(data.lineType) != "BYLAYER"){
        if(_hDashPattern.contains(QString::fromStdString(data.lineType))){
            QPen pen = polylineItem->pen();
            pen.setDashPattern(_hDashPattern.value(QString::fromStdString(data.lineType)));
            polylineItem->setPen(pen);
        }
    }
}

/** Called for every spline */
void CubDxfInterface::addSpline(const DRW_Spline* data){
    Q_UNUSED(data)
}

    /** Called for every spline knot value */
void CubDxfInterface::addKnot(const DRW_Entity& data){
    Q_UNUSED(data)
}

/** Called for every insert. */
void CubDxfInterface::addInsert(const DRW_Insert& data){
    Q_UNUSED(data)
}

/** Called for every trace start */
void CubDxfInterface::addTrace(const DRW_Trace& data){
    Q_UNUSED(data)
}

/** Called for every 3dface start */
void CubDxfInterface::add3dFace(const DRW_3Dface& data){
    Q_UNUSED(data)
}

/** Called for every solid start */
void CubDxfInterface::addSolid(const DRW_Solid& data){
    Q_UNUSED(data)
}


/** Called for every Multi Text entity. */
void CubDxfInterface::addMText(const DRW_MText& data){
    Q_UNUSED(data)
}

/** Called for every Text entity. */
void CubDxfInterface::addText(const DRW_Text& data){

    QString layername = QString::fromStdString(data.layer);

    GraphicsTextItem * textItem = new GraphicsTextItem;
    QFont font;

    font.setPixelSize(data.height);

    textItem->setFlag(QGraphicsItem::ItemIgnoresTransformations);
    textItem->setText(QString::fromUtf8(data.text.c_str()));
    textItem->setPos(QPointF(data.basePoint.x, data.basePoint.y + 10));
    textItem->setRotation(-data.angle);
    textItem->setFont(font);

    // Add the item to layer
    GraphicsMapLayer * layer = _map->layerItem(layername);
    if(layer) layer->addToLayer(textItem, 0);
}

/**
 * Called for every aligned dimension entity.
 */
void CubDxfInterface::addDimAlign(const DRW_DimAligned *data){
    Q_UNUSED(data)
}
/**
 * Called for every linear or rotated dimension entity.
 */
void CubDxfInterface::addDimLinear(const DRW_DimLinear *data){
    Q_UNUSED(data)
}

    /**
 * Called for every radial dimension entity.
 */
void CubDxfInterface::addDimRadial(const DRW_DimRadial *data){
    Q_UNUSED(data)
}

    /**
 * Called for every diametric dimension entity.
 */
void CubDxfInterface::addDimDiametric(const DRW_DimDiametric *data){
    Q_UNUSED(data)
}

    /**
 * Called for every angular dimension (2 lines version) entity.
 */
void CubDxfInterface::addDimAngular(const DRW_DimAngular *data){
    Q_UNUSED(data)
}

    /**
 * Called for every angular dimension (3 points version) entity.
 */
void CubDxfInterface::addDimAngular3P(const DRW_DimAngular3p *data){
    Q_UNUSED(data)
}

/**
 * Called for every ordinate dimension entity.
 */
void CubDxfInterface::addDimOrdinate(const DRW_DimOrdinate *data){
    Q_UNUSED(data)
}

/**
     * Called for every leader start.
     */
void CubDxfInterface::addLeader(const DRW_Leader *data){
    Q_UNUSED(data)
}

    /**
     * Called for every hatch entity.
     */
void CubDxfInterface::addHatch(const DRW_Hatch *data){

    QString layername = QString::fromStdString(data->layer);

    GraphicsHatchItem * hatchItem = new GraphicsHatchItem;

    QPainterPath path;

    for(int i=0; i< (signed int) data->looplist.size(); i++){
        DRW_HatchLoop * hloop = data->looplist[i];

        QPolygonF polygon;
        for(int j=0; j< (signed int) hloop->objlist.size(); j++){

            DRW_Entity * entity = hloop->objlist[j];
            if(entity->eType == DRW::LINE){
                DRW_Line * line = (DRW_Line*) entity;
                polygon.append(QPointF(line->basePoint.x, line->basePoint.y));
                polygon.append(QPointF(line->secPoint.x, line->secPoint.y));
            }
            else if(entity->eType == DRW::POLYLINE){
                DRW_Polyline * polyline = (DRW_Polyline*) entity;

                for(int k=0; k< (signed int) polyline->vertlist.size(); k++){
                    DRW_Vertex * vertex = polyline->vertlist[k];
                    polygon.append(QPointF(vertex->basePoint.x, vertex->basePoint.y));
                }
            }
            else if(entity->eType == DRW::LWPOLYLINE){

                DRW_LWPolyline* polyline = (DRW_LWPolyline*) entity;
                for(int k=0; k< (signed int) polyline->vertlist.size(); k++){
                    DRW_Vertex2D * vertex = polyline->vertlist[k];
                    polygon.append(QPointF(vertex->x, vertex->y));
                }
            }
        }
        path.addPolygon(polygon);
    }

    // Sets the pen
    if(_hLayers.contains(QString::fromStdString(data->layer))){
        QPen pen = _hLayers.value(QString::fromStdString(data->layer));
        QColor color = pen.color();
        hatchItem->setPen(pen);
        hatchItem->setBrush(color);
    }

    // Sets the brush
    if(data->color){
        QColor color = QColor::fromRgbF(DRW::dxfColors[data->color][0], DRW::dxfColors[data->color][1], DRW::dxfColors[data->color][2]);
        QBrush brush = QBrush(color, Qt::BDiagPattern);
        hatchItem->setBrush(brush);
    }

    hatchItem->setPath(path);
    hatchItem->setOpacity(0.6);
    hatchItem->setZValue(-1);

    // Add the item to layer
    GraphicsMapLayer * layer = _map->layerItem(layername);
    if(layer){
        layer->addToLayer(hatchItem, 0);
    }
}

    /**
     * Called for every image entity.
     */
void CubDxfInterface::addImage(const DRW_Image *data){
    Q_UNUSED(data)
}

    /**
     * Called for every image definition.
     */
void CubDxfInterface::linkImage(const DRW_ImageDef *data){
    Q_UNUSED(data)
}

/**
 * Called for every comment in the DXF file (code 999).
 */
void CubDxfInterface::addComment(const char* comment){
    Q_UNUSED(comment)
}

/** Sets the current attributes for entities. */
/*    void CubDxfInterface::setExtrusion(double dx, double dy, double dz, double elevation) {
    extrusion->setDirection(dx, dy, dz){

}
            extrusion->setElevation(elevation){

}
}*/

/** @return the current attributes used for new entities. */
//    DL_Extrusion* getExtrusion() {
//        return extrusion{
//    }

void CubDxfInterface::writeHeader(DRW_Header& data){
    Q_UNUSED(data)
}

void CubDxfInterface::writeBlocks(){

}
void CubDxfInterface::writeBlockRecords(){

}
void CubDxfInterface::writeEntities(){

}
void CubDxfInterface::writeLTypes(){

}
void CubDxfInterface::writeLayers(){

}
void CubDxfInterface::writeDimstyles(){

}
