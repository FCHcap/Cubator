#include "PmlReader.h"

// CUBATOR
#include <GraphicsMeshImageItem.h>
#include <GraphicsPictureItem.h>

// STL
#include <iostream>

using namespace std;

PmlReader::PmlReader(const QString &filepath) {
    _filepath = filepath;
}

void PmlReader::setFilepath(const QString &filepath) {
    _filepath = filepath;
}

QString PmlReader::filepath() const {
    return _filepath;
}

void PmlReader::run(){

    emit processNameUpdated(PROCESS12);
    emit levelUpdated(0);

    // Reading file
    if(!QFile::exists(_filepath)){
        emit exceptionLaunched(CubException(BRIEF25, TEXT01 + _filepath, "PmlReader::start"));
        return;
    }
    QDomDocument dom("Pml");
    QFile file(_filepath);
    if(!file.open(QIODevice::ReadOnly)){
        emit exceptionLaunched(CubException(BRIEF06, TEXT01 + _filepath, "PmlReader::start"));
        return;
    }
    QString errorParsing;
    int errorLine = 0;
    int errorColumn = 0;
    if(!dom.setContent(&file, 0, &errorParsing, &errorLine, &errorColumn)){
        file.close();
        QString error = MESSAGE06 + '\n' + errorParsing + '\n' + TEXT30 + QString::number(errorLine) + '\n' + TEXT31 + QString::number(errorColumn);
        emit exceptionLaunched(CubException(BRIEF04, error, "PmlReader::start"));
        return;
    }
    file.close();

    // Generating map
    GraphicsMap * map = new GraphicsMap;
    QDomElement racine = dom.documentElement();
    QDomElement element = racine.firstChildElement();

    // Calculates the count of nodes
    int size = 0;
    for(int i=0; i<racine.childNodes().count(); i++){
        size++;
        for(int j=0; j<racine.childNodes().at(i).childNodes().count(); j++) size++;
    }

    int cpt = 0; // Nodes counter
    while(!element.isNull()){

        QString tag = element.tagName();

        if(tag == "layer" || tag == "icondef" || tag == "boatdef"){

            GraphicsMapIconDef * icondef = 0;
            GraphicsMapBoatDef * boatdef = 0;
            GraphicsMapLayer * layer = 0;

            if(tag == "icondef"){
                icondef = map->addIconDef(element.attribute("name", ""));
                // Reading the center position
                QPointF center;
                center.setX(element.attribute("center-x", "0").toDouble());
                center.setY(element.attribute("center-y", "0").toDouble());
                icondef->setCenter(center);
                icondef->setSelectionColor(QColor(element.attribute("selection-color")));
            }
            else if(tag == "boatdef"){
                boatdef = map->addBoatDef(element.attribute("name", ""));
                //Reading the center position
                QPointF center;
                center.setX(element.attribute("center-x", "0").toDouble());
                center.setY(element.attribute("center-y", "0").toDouble());
                boatdef->setCenter(center);
            }
            else{
                layer = map->addLayer(element.attribute("name", ""), 0);
                layer->setZValue(element.attribute("elevation", "0").toDouble());
                layer->setOpacity(element.attribute("opacity", "1").toDouble());
                layer->setVisible((bool) element.attribute("visibility", "1").toInt());
                layer->setEditable((bool) element.attribute("editable", "0").toInt());

                if(element.hasAttribute("default")) {
                    map->setDefaultLayer(layer->name());
                }
            }

            // Lecture des points XY
            QDomNodeList layerPointsXY = element.elementsByTagName("pointXY");
            for(int i=0; i<layerPointsXY.count(); i++){
                if(layerPointsXY.at(i).isElement()){
                    QDomElement e = layerPointsXY.at(i).toElement();

                    GraphicsPointXYItem * pointItem = new GraphicsPointXYItem;
                    if(layer) layer->addToLayer(pointItem, 0);
                    pointItem->setPos(readingPoint(e));
                    pointItem->setFont(readingFontAttributes(e));
                    pointItem->setPen(readingPenAttributes(e));
                    pointItem->setBrush(readingBrushAttributes(e));
                    pointItem->setPositionFromString(e.attribute("position", SRIGHT));
                    pointItem->setTypeCoordsFromString(e.attribute("coordinates", SGPS));
                }
                cpt++;
                emit levelUpdated((int) cpt*100/size);
            }

            // Reading lines ...
            QDomNodeList layerLines = element.elementsByTagName("line");
            for(int i=0; i<layerLines.count(); i++){
                if(layerLines.at(i).isElement()){
                    QDomElement e1 = layerLines.at(i).toElement();

                    QGraphicsLineItem * lineItem = new QGraphicsLineItem;
                    lineItem->setPen(readingPenAttributes(e1));

                    if(icondef) icondef->addToGroup(lineItem);
                    else if(boatdef) boatdef->addToGroup(lineItem);
                    else layer->addToLayer(lineItem, 0);

                    for(int j=0; j<e1.childNodes().count(); j++){
                        if(e1.childNodes().at(j).isElement()){
                            QDomElement e2 = e1.childNodes().at(j).toElement();
                            QPointF p = readingPoint(e2);
                            QLineF l = lineItem->line();
                            (e2.tagName() == "p1") ? l.setP1(p) : l.setP2(p);
                            lineItem->setLine(l);
                        }
                    }
                }
                cpt++;
                emit levelUpdated((int) cpt * 100 / size);
            }

            // Reading hatchs ...
            QDomNodeList layerHatch = element.elementsByTagName("hatch");
            for(int i=0; i<layerHatch.count(); i++){
                if(layerHatch.at(i).isElement()){
                    QDomElement hatch = layerHatch.at(i).toElement();

                    GraphicsHatchItem * hatchItem = new GraphicsHatchItem;
                    QPainterPath hatchPath;
                    hatchItem->setPen(readingPenAttributes(hatch));
                    hatchItem->setBrush(readingBrushAttributes(hatch));

                    if(icondef) icondef->addToGroup(hatchItem);
                    else if(boatdef) boatdef->addToGroup(hatchItem);
                    else layer->addToLayer(hatchItem, 0);

                    for(int j=0; j<hatch.childNodes().count(); j++){
                        if(hatch.childNodes().at(j).isElement()){
                            QDomElement e1 = hatch.childNodes().at(j).toElement();
                            if(e1.tagName() == "polygon"){
                                QPolygonF polygon;
                                for(int k=0; k<e1.childNodes().count(); k++){
                                    if(e1.childNodes().at(k).isElement()){
                                        QDomElement e2 = e1.childNodes().at(k).toElement();
                                        if(e2.tagName() == "point") polygon.append(readingPoint(e2));
                                    }
                                }
                                hatchPath.addPolygon(polygon);
                            }
                        }
                    }
                    hatchItem->setPath(hatchPath);
                }
                cpt++;
                emit levelUpdated((int) cpt * 100 / size);
            }

            // Reading polylines ...
            QDomNodeList layerPolyline = element.elementsByTagName("polyline");
            for(int i=0; i<layerPolyline.count(); i++){
                if(layerPolyline.at(i).isElement()){
                    QDomElement polyline = layerPolyline.at(i).toElement();

                    GraphicsPolylineItem * polylineItem = new GraphicsPolylineItem;
                    polylineItem->setClosed((bool) polyline.attribute("closed", "0").toInt());
                    polylineItem->setPen(readingPenAttributes(polyline));

                    if(icondef) icondef->addToGroup(polylineItem);
                    else if(boatdef) boatdef->addToGroup(polylineItem);
                    else layer->addToLayer(polylineItem, 0);

                    for(int j=0; j<polyline.childNodes().count(); j++){
                        if(polyline.childNodes().at(j).isElement()){
                            QDomElement e1 = polyline.childNodes().at(j).toElement();
                            if(e1.tagName() == "point"){
                                polylineItem->addPoint(readingPoint(e1));
                            }
                        }
                    }
                }
                cpt++;
                emit levelUpdated((int) cpt * 100 / size);
            }

            // Reading texts ...
            QDomNodeList layerText = element.elementsByTagName("text");
            for(int i=0; i<layerText.count(); i++){
                if(layerText.at(i).isElement()){
                    QDomElement text = layerText.at(i).toElement();

                    GraphicsTextItem * textItem = new GraphicsTextItem;
                    textItem->setFont(readingFontAttributes(text));
                    textItem->setText(text.attribute("data", ""));
                    textItem->setRotation(text.attribute("angle", "0").toDouble());
                    textItem->setBrush(QBrush(QColor(text.attribute("color", "#000000"))));
                    textItem->setFlag(QGraphicsItem::ItemIgnoresTransformations);

                    if(icondef) icondef->addToGroup(textItem);
                    else if(boatdef) boatdef->addToGroup(textItem);
                    else layer->addToLayer(textItem, 0);

                    for(int j=0; j<text.childNodes().count(); j++){
                        if(text.childNodes().at(j).isElement()){
                            QDomElement e1 = text.childNodes().at(j).toElement();
                            if(e1.tagName() == "point")
                                textItem->setPos(readingPoint(e1));
                        }
                    }
                }
                cpt++;
                emit levelUpdated((int) cpt * 100 / size);
            }

            // Reading ellipses ...
            QDomNodeList layerEllipse = element.elementsByTagName("ellipse");
            for(int i=0; i<layerEllipse.count(); i++){
                if(layerEllipse.at(i).isElement()){
                    QDomElement ellipse = layerEllipse.at(i).toElement();

                    QGraphicsEllipseItem * ellipseItem = new QGraphicsEllipseItem;
                    ellipseItem->setPen(readingPenAttributes(ellipse));
                    if(ellipse.hasAttribute("brush_color")) {
                        ellipseItem->setBrush(readingBrushAttributes(ellipse));
                    }

                    if(icondef) icondef->addToGroup(ellipseItem);
                    else if(boatdef) boatdef->addToGroup(ellipseItem);
                    else layer->addToLayer(ellipseItem, 0);

                    ellipseItem->setRect(readingRectf(ellipse));

                    // Keeps the code below for compatibility with older version of pml files
                    for(int j=0; j<ellipse.childNodes().count(); j++){
                        if(ellipse.childNodes().at(j).isElement()){
                            QDomElement e1 = ellipse.childNodes().at(j).toElement();
                            if(e1.tagName() == "rect")
                                ellipseItem->setRect(readingRectf(e1));
                        }
                    }
                }
                cpt++;
                emit levelUpdated((int) cpt * 100 / size);
            }

            // lecture des images
            QDomNodeList pictures = element.elementsByTagName("picture");
            for(int i=0; i<pictures.count(); i++){
                if(pictures.at(i).isElement()){
                    QDomElement picture = pictures.at(i).toElement();
                    GraphicsPictureItem * pictureItem = new GraphicsPictureItem;

                    try{
                        QString picturePath = picture.attribute("filepath", "");
                        QString normalizedFilepath = this->normalizeFilepath(picturePath);
                        
                        pictureItem->setFilepath(normalizedFilepath);
                        pictureItem->setPixmapWidth(picture.attribute("width", "0").toInt());
                        pictureItem->setRotation(picture.attribute("rotation", "0").toDouble());

                        QPointF sCenter;
                        sCenter.setX(picture.attribute("sCenter-x", "0").toDouble());
                        sCenter.setY(picture.attribute("sCenter-y", "0").toDouble());
                        pictureItem->setSceneCenter(sCenter);

                        QPointF fas;
                        fas.setX(picture.attribute("fasx", "0").toDouble());
                        fas.setY(picture.attribute("fasy", "0").toDouble());
                        pictureItem->setFirstAnchorScenePos(fas);

                        QPointF las;
                        las.setX(picture.attribute("lasx", "0").toDouble());
                        las.setY(picture.attribute("lasy", "0").toDouble());
                        pictureItem->setLastAnchorScenePos(las);
                    }
                    catch(CubException &e){
                        emit exceptionLaunched(e);
                    }

                    if(layer) layer->addToLayer(pictureItem, 0);
                }
                cpt++;
                emit levelUpdated((int) cpt * 100 / size);
            }

            // Reading icons ...
            QDomNodeList layerIcons = element.elementsByTagName("icon");
            for(int i=0; i<layerIcons.count(); i++){
                if(layerIcons.at(i).isElement()){
                    QDomElement icon = layerIcons.at(i).toElement();

                    GraphicsIconItem * iconItem = new GraphicsIconItem;
                    QString iconName = icon.attribute("name", "");
                    iconItem->setName(iconName);
                    iconItem->setDate(icon.attribute("date", ""));
                    iconItem->setRotation((qreal) icon.attribute("angle", "0").toDouble());
                    QPointF pos;
                    pos.setX(icon.attribute("x", 0).toDouble());
                    pos.setY(icon.attribute("y", 0).toDouble());
                    iconItem->setPos(pos);

                    GraphicsMapIconDef * iconDef = map->iconDefItem(iconName);
                    if(iconDef) iconItem->setIconDef(iconDef);

                    if(layer) layer->addToLayer(iconItem);
                }
                cpt++;
                emit levelUpdated((int) cpt * 100 / size);
            }

            // Reading volumes ...
            QDomNodeList layerVolumes = element.elementsByTagName("volume");
            for(int i=0; i<layerVolumes.count(); i++){
                if(layerVolumes.at(i).isElement()){
                    QDomElement volume = layerVolumes.at(i).toElement();

                    GraphicsVolumeItem * volumeItem = new GraphicsVolumeItem;

                    for(int j=0; j<volume.childNodes().count(); j++){
                        if(volume.childNodes().at(j).isElement()){
                            QDomElement e1 = volume.childNodes().at(j).toElement();
                            if(e1.tagName() == "point"){
                                volumeItem->addPoint(readingPoint(e1));
                            }
                        }
                    }
                    volumeItem->setClosed(1);
                    volumeItem->setSurface(volume.attribute("surface", "0").toDouble());
                    volumeItem->setVolume(volume.attribute("volume", "0").toDouble());
                    volumeItem->setMeshColor(QColor(volume.attribute("mesh_color", "#000000")));
                    volumeItem->setTextColor(QColor(volume.attribute("text_color", "#000000")));
                    volumeItem->setFont(readingFontAttributes(volume));
                    volumeItem->setPen(readingPenAttributes(volume));
                    volumeItem->setTextVisible((bool) volume.attribute("text_visible", "1").toInt());

                    if(layer){
                        layer->addToLayer(volumeItem);
                        layer->setFlags(volumeItem);
                    }
                }
                cpt++;
                emit levelUpdated((int) cpt * 100 / size);
            }

            // Reading vertex ...
            QDomNodeList xyznodes = element.elementsByTagName("xyz");
            for(int i=0; i<xyznodes.count(); i++) {
                if(xyznodes.at(i).isElement()) {
                    QDomElement xyzelt = xyznodes.at(i).toElement();

                    GraphicsPointXYZItem * xyzitem = new GraphicsPointXYZItem(true);
                    xyzitem->setVertex(readingVertex(xyzelt), QColor(xyzelt.attribute("color", "#000000")));

                    if(layer) {
                        layer->addToLayer(xyzitem);
                        layer->setFlags(xyzitem);
                    }
                }
                cpt++;
                emit levelUpdated((int) cpt * 100 / size);
            }

            // reading mesh ...
            QDomNodeList meshNodes = element.elementsByTagName("mesh");
            for(int i=0; i<meshNodes.count(); i++) {
                if(meshNodes.at(i).isElement()) {
                    QDomElement meshNode = meshNodes.at(i).toElement();

                    GraphicsMeshItem *mesh = new GraphicsMeshItem;
                    layer->addToLayer(mesh);

                    QGraphicsItemGroup *vertices = new QGraphicsItemGroup;
                    mesh->setVertices(vertices);

                    QGraphicsItemGroup *triangles = new QGraphicsItemGroup;
                    mesh->setTriangles(triangles);

                    for(int j=0; j<meshNode.childNodes().count(); j++) {
                        QDomNode node = meshNode.childNodes().at(j);

                        if(node.isElement()) {
                            QDomElement elt = node.toElement();

                            if(elt.tagName() == "vertex") {
                                GraphicsPointXYZItem *xyz = new GraphicsPointXYZItem(false, vertices);
                                xyz->setVertex(readingVertex(elt), QColor(elt.attribute("color", "#000000")));
                            }

                            if(elt.tagName() == "line") {
                                QGraphicsLineItem *line = new QGraphicsLineItem(triangles);
                                line->setLine(readingLine(elt));
                                line->setPen(readingPenAttributes(elt));
                            }
                        }
                    }

                }
            }
            cpt++;
            emit levelUpdated((int) cpt * 100 / size);

        }
        cpt++;

        emit levelUpdated((int) cpt * 100 / size);

        element = element.nextSiblingElement();
    }
    emit levelUpdated(100);
    emit mapGenerated(InfoMap::filepathToMap(_filepath), map);
}

QLineF PmlReader::readingLine(QDomElement &element) {
    QLineF line;
    line.setP1(QPointF(element.attribute("x1", "0").toDouble(), element.attribute("y1", "0").toDouble()));
    line.setP2(QPointF(element.attribute("x2", "0").toDouble(), element.attribute("y2", "0").toDouble()));
    return line;
}

QPointF PmlReader::readingPoint(QDomElement &element){
    QPointF point;
    point.setX(element.attribute("x", "0").toDouble());
    point.setY(element.attribute("y", "0").toDouble());
    return point;
}

DVertex PmlReader::readingVertex(QDomElement &element) {
    DVertex vertex;
    vertex.setX(element.attribute("x", "0").toDouble());
    vertex.setY(element.attribute("y", "0").toDouble());
    vertex.setZ(element.attribute("z", "0").toDouble());
    return vertex;
}

QRectF PmlReader::readingRectf(QDomElement &element){
    QRectF rect;
    rect.setX(element.attribute("x", "0").toDouble());
    rect.setY(element.attribute("y", "0").toDouble());
    rect.setWidth(element.attribute("width", "0").toDouble());
    rect.setHeight(element.attribute("height", "0").toDouble());
    return rect;
}

QRect PmlReader::readingRect(QDomElement &element){
    QRect rect;
    rect.setX(element.attribute("x", "0").toInt());
    rect.setY(element.attribute("y", "0").toInt());
    rect.setWidth(element.attribute("width", "0").toInt());
    rect.setHeight(element.attribute("height", "0").toInt());
    return rect;
}

QPen PmlReader::readingPenAttributes(QDomElement &element){
    QPen pen;
    pen.setWidth(element.attribute("pen_weight", "1").toInt());
    pen.setStyle((Qt::PenStyle) element.attribute("qt_pen_style", "1").toInt());
    pen.setColor(QColor(element.attribute("pen_color", "#000000")));
    return pen;
}

QBrush PmlReader::readingBrushAttributes(QDomElement &element){
    QBrush brush;
    brush.setColor(QColor(element.attribute("brush_color", "#000000")));
    brush.setStyle(static_cast<Qt::BrushStyle> (element.attribute("brush_style", "12").toInt()));
    return brush;
}

QFont PmlReader::readingFontAttributes(QDomElement &element){
    QFont font;
    font.fromString(element.attribute("font", ""));
    font.setPixelSize(element.attribute("font_psize", "5").toInt());
    return font;
}

QString PmlReader::normalizeFilepath(const QString filepath) const {
    QFileInfo fileInfo(filepath);

    if(fileInfo.isRelative()) {
        QFileInfo pmlInfo(_filepath);
        fileInfo.setFile(pmlInfo.dir(), filepath);
    }

    return fileInfo.absoluteFilePath();
}
