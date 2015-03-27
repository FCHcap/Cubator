#include "PmlWriter.h"

// QT
#include <QThread>
#include <QFileInfo>

// CUBATOR
#include <GraphicsHatchItem.h>
#include <GraphicsPolylineItem.h>
#include <GraphicsTextItem.h>
#include <GraphicsMeshImageItem.h>
#include <GraphicsIconItem.h>
#include <GraphicsPictureItem.h>

PmlWriter::PmlWriter(QObject * parent) : DefaultProcess(parent){
    _sortByType = 0;
    _cpt = 0;
    _size = 0;
}

// list <filepath, map>
void PmlWriter::setList(QMap<QString, GraphicsMap *> list){
    _list = list;
}

void PmlWriter::sortByType(bool sortByType){
    _sortByType = sortByType;
}

void PmlWriter::run(){

    try{
        //emit started();

        foreach(QString filepath, _list.keys()){

            QDomDocument doc("Pml");

            // Creates header
            QDomNode header = doc.createProcessingInstruction("xml","version=\"1.0\" encoding=\"UTF-8\"");
            doc.insertBefore(header, doc.firstChild());

            //Header
            emit processNameUpdated(PROCESS13 + filepath);
            emit levelUpdated(0);

            QDomElement root = doc.createElement("pml");
            doc.appendChild(root);

            GraphicsMap *pmlItem = _list.value(filepath);

            _size = pmlItem->iconsDefItemsCount();

            GraphicsMap map;
            // if sort by item type option is enabled ...
            if(_sortByType){
                GraphicsMapLayer * lineLayer = map.addLayer("lines", 0);
                GraphicsMapLayer * hatchLayer = map.addLayer("hatches", 0);
                GraphicsMapLayer * polylineLayer = map.addLayer("polylines", 0);
                GraphicsMapLayer * textLayer = map.addLayer("text", 0);
                GraphicsMapLayer * ellipseLayer = map.addLayer("ellipses", 0);
                GraphicsMapLayer * meshLayer = map.addLayer("meshes", 0);
                GraphicsMapLayer * iconLayer = map.addLayer("icons", 0);

                meshLayer->setZValue(0);
                hatchLayer->setZValue(10);
                polylineLayer->setZValue(20);
                iconLayer->setZValue(30);
                lineLayer->setZValue(40);
                ellipseLayer->setZValue(50);
                textLayer->setZValue(60);

                foreach(QGraphicsItem * item, pmlItem->childItems()){
                    if(item->type() == GraphicsMapLayer::Type){
                        GraphicsMapLayer * layer = qgraphicsitem_cast<GraphicsMapLayer*>(item);
                        foreach(QGraphicsItem * item2, layer->childItems()){
                            switch(item2->type()){
                            case QGraphicsLineItem::Type:
                            {
                                QGraphicsLineItem * line = qgraphicsitem_cast<QGraphicsLineItem*>(item2);
                                QGraphicsLineItem * nline = new QGraphicsLineItem;
                                nline->setLine(line->line());
                                nline->setPen(line->pen());
                                lineLayer->addToLayer(nline, 0);
                                break;
                            }
                            case GraphicsHatchItem::Type:
                            {
                                GraphicsHatchItem * hatch = qgraphicsitem_cast<GraphicsHatchItem*>(item2);
                                GraphicsHatchItem * nhatch = new GraphicsHatchItem;
                                nhatch->setPen(hatch->pen());
                                nhatch->setBrush(hatch->brush());
                                nhatch->setPath(hatch->path());
                                hatchLayer->addToLayer(nhatch, 0);
                                break;
                            }
                            case GraphicsPolylineItem::Type:
                            {
                                GraphicsPolylineItem * polyline = qgraphicsitem_cast<GraphicsPolylineItem*>(item2);
                                GraphicsPolylineItem * npolyline = new GraphicsPolylineItem;
                                npolyline->setPen(polyline->pen());
                                foreach(QPointF point, polyline->points()){
                                    npolyline->addPoint(point);
                                }
                                polylineLayer->addToLayer(npolyline, 0);
                                break;
                            }
                            case GraphicsTextItem::Type:
                            {
                                GraphicsTextItem * text = qgraphicsitem_cast<GraphicsTextItem*>(item2);
                                GraphicsTextItem * ntext = new GraphicsTextItem;
                                ntext->setPen(text->pen());
                                ntext->setBrush(text->brush());
                                ntext->setFont(text->font());
                                ntext->setText(text->text());
                                ntext->setRotation(text->rotation());
                                ntext->setPos(text->pos());
                                textLayer->addToLayer(ntext, 0);
                                break;
                            }
                            case QGraphicsEllipseItem::Type:
                            {
                                QGraphicsEllipseItem * ellipse = qgraphicsitem_cast<QGraphicsEllipseItem*>(item2);
                                QGraphicsEllipseItem * nellipse = new QGraphicsEllipseItem;
                                nellipse->setPen(ellipse->pen());
                                nellipse->setRect(ellipse->rect());
                                ellipseLayer->addToLayer(nellipse, 0);
                                break;
                            }
                            case GraphicsMeshImageItem::Type:
                            {
                                GraphicsMeshImageItem * mesh = qgraphicsitem_cast<GraphicsMeshImageItem*>(item2);
                                GraphicsMeshImageItem * nmesh = new GraphicsMeshImageItem;
                                nmesh->setTableName(mesh->tableName());
                                meshLayer->addToLayer(nmesh, 0);
                                break;
                            }
                            case GraphicsIconItem::Type:
                            {
                                GraphicsIconItem * icon = qgraphicsitem_cast<GraphicsIconItem*>(item2);
                                GraphicsIconItem * nicon = new GraphicsIconItem;
                                nicon->setIconDef(icon->iconDef());
                                nicon->setPos(icon->pos());
                                nicon->setRotation(icon->rotation());
                                nicon->setDate(icon->date());
                                iconLayer->addToLayer(nicon, 0);
                                break;
                            }
                            }
                        }
                    }
                }

                pmlItem = &map;
            }

            // Define the count of items to record
            _size += pmlItem->layersItemsCount();

            // Writing layers ...
            foreach(QGraphicsItem * item, pmlItem->childItems()){

                if(item->type() == GraphicsMapLayer::Type){
                    GraphicsMapLayer * layerItem = qgraphicsitem_cast<GraphicsMapLayer*>(item);

                    // Creates dom node
                    QDomElement layer = doc.createElement("layer");
                    root.appendChild(layer);

                    layer.setAttribute("name", (QString) layerItem->name());
                    layer.setAttribute("elevation", (double) layerItem->zValue());
                    layer.setAttribute("opacity", (double) layerItem->opacity());
                    layer.setAttribute("visibility", (int) layerItem->isVisible());

                    writeLayer(doc, layer, item, filepath);
                }
            }

            // Record the definitions of icons and boats
            foreach(QString icondefname, pmlItem->iconDefs()){
                GraphicsMapIconDef * icon = pmlItem->iconDefItem(icondefname);

                if(icon){

                    // Creates dom node
                    QDomElement icondef = doc.createElement("icondef");
                    root.appendChild(icondef);

                    icondef.setAttribute("center-x", (double) icon->center().x());
                    icondef.setAttribute("center-y", (double) icon->center().y());
                    icondef.setAttribute("name", (QString) icon->name());
                    icondef.setAttribute("selection-color", (QString) icon->selectionColor().name());

                    writeLayer(doc, icondef, icon, filepath);
                }
            }

            // Record the definitions of boats
            foreach(QString boatdefname, pmlItem->boatDefs()){
                GraphicsMapBoatDef * boat = pmlItem->boatDefItem(boatdefname);

                if(boat){

                    // Creates dom node
                    QDomElement boatdef = doc.createElement("boatdef");
                    root.appendChild(boatdef);

                    boatdef.setAttribute("center-x", (double) boat->center().x());
                    boatdef.setAttribute("center-y", (double) boat->center().y());
                    boatdef.setAttribute("name", (QString) boat->name());

                    writeLayer(doc, boatdef, boat, filepath);
                }
            }

            emit levelUpdated(100);

            // Saves the document
            emit processNameUpdated(PROCESS20);
            QFile file(filepath);
            if(!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) throw CubException(BRIEF06, TEXT01 + filepath, "PmlWriter::start");
            QTextStream out(&file);
            out << doc.toString();
            out.flush();
            file.close();
        }
    }
    catch(CubException & e){
        emit exceptionLaunched(e);
    }
}

void PmlWriter::writeLayer(QDomDocument &doc, QDomElement &layer, const QGraphicsItem *layerItem, const QString filepath){

    foreach(QGraphicsItem * item, layerItem->childItems()){

        switch(item->type()){

        case GraphicsPointXYItem::Type:
        {
            GraphicsPointXYItem * pointItem = qgraphicsitem_cast<GraphicsPointXYItem*>(item);

            QDomElement pointXY = doc.createElement("pointXY");
            layer.appendChild(pointXY);
            writePoint(pointXY, pointItem->pos());
            writeFontAttributes(pointXY, pointItem->font());
            writePenAttributes(pointXY, pointItem->pen());
            writeBrushAttributes(pointXY, pointItem->brush());

            pointXY.setAttribute("position", pointItem->positionToString());
            pointXY.setAttribute("coordinates", pointItem->typeCoordsToString());
            break;
        }
        case QGraphicsLineItem::Type:
        {
            QGraphicsLineItem * lineItem = qgraphicsitem_cast<QGraphicsLineItem*>(item);

            QDomElement line = doc.createElement("line");
            layer.appendChild(line);
            writePenAttributes(line, lineItem->pen());

            QDomElement p1 = doc.createElement("p1");
            writePoint(p1, lineItem->line().p1());
            line.appendChild(p1);

            QDomElement p2 = doc.createElement("p2");
            writePoint(p2, lineItem->line().p2());
            line.appendChild(p2);
            break;
        }

        case GraphicsHatchItem::Type:
        {
            GraphicsHatchItem * hatchItem = qgraphicsitem_cast<GraphicsHatchItem*>(item);

            QDomElement hatch = doc.createElement("hatch");
            layer.appendChild(hatch);
            writePenAttributes(hatch, hatchItem->pen());
            writeBrushAttributes(hatch, hatchItem->brush());
            QPainterPath path = hatchItem->path();

            foreach(QPolygonF polygon, path.toFillPolygons()){
                QDomElement dpolygon = doc.createElement("polygon");
                hatch.appendChild(dpolygon);

                foreach(QPointF point, polygon){
                    QDomElement dpoint = doc.createElement("point");
                    dpolygon.appendChild(dpoint);

                    writePoint(dpoint, point);
                }
            }
            break;
        }

        case GraphicsPolylineItem::Type:
        {
            GraphicsPolylineItem * polylineItem = qgraphicsitem_cast<GraphicsPolylineItem*>(item);

            QDomElement polyline = doc.createElement("polyline");
            layer.appendChild(polyline);
            writePenAttributes(polyline, polylineItem->pen());
            polyline.setAttribute("closed", polylineItem->isClosed());

            foreach(QPointF point, polylineItem->points()){
                QDomElement dpoint = doc.createElement("point");
                polyline.appendChild(dpoint);

                writePoint(dpoint, point);
            }
            break;
        }

        case GraphicsTextItem::Type:
        {
            GraphicsTextItem * textItem = qgraphicsitem_cast<GraphicsTextItem*>(item);

            QDomElement text = doc.createElement("text");
            layer.appendChild(text);

            text.setAttribute("data", (QString) textItem->text());
            text.setAttribute("angle", (double) textItem->rotation());
            text.setAttribute("color", (QString) textItem->brush().color().name());

            QDomElement point = doc.createElement("point");
            text.appendChild(point);
            writePoint(point, textItem->pos());

            writeFontAttributes(text, textItem->font());
            break;
        }

        case QGraphicsEllipseItem::Type:
        {
            QGraphicsEllipseItem * ellipseItem = qgraphicsitem_cast<QGraphicsEllipseItem*>(item);

            QDomElement ellipse = doc.createElement("ellipse");
            layer.appendChild(ellipse);

            writePenAttributes(ellipse, ellipseItem->pen());

            QDomElement rect = doc.createElement("rect");
            ellipse.appendChild(rect);

            writeRect(rect, ellipseItem->rect());
            break;
        }

        case GraphicsPictureItem::Type:
        {
            GraphicsPictureItem * pictureItem = qgraphicsitem_cast<GraphicsPictureItem*>(item);
            QDomElement picture = doc.createElement("picture");
            layer.appendChild(picture);

            QString pictureFilepath = (QString) pictureItem->filepath();
            if(compareFilepaths(filepath, pictureFilepath)) {
                pictureFilepath = filenameFromFilepath(pictureFilepath);
            }
            picture.setAttribute("filepath", pictureFilepath);
            picture.setAttribute("sCenter-x", (double) pictureItem->sceneCenter().x());
            picture.setAttribute("sCenter-y", (double) pictureItem->sceneCenter().y());
            picture.setAttribute("width", (int) pictureItem->pixmapWidth());
            picture.setAttribute("rotation", (double) pictureItem->rotation());
            picture.setAttribute("fasx", (double) pictureItem->firstAnchorScenePos().x());
            picture.setAttribute("fasy", (double) pictureItem->firstAnchorScenePos().y());
            picture.setAttribute("lasx", (double) pictureItem->lastAnchorScenePos().x());
            picture.setAttribute("lasy", (double) pictureItem->lastAnchorScenePos().y());
            break;
        }

        case GraphicsMeshImageItem::Type:
        {
            GraphicsMeshImageItem * meshItem = qgraphicsitem_cast<GraphicsMeshImageItem*>(item);

            QDomElement mesh = doc.createElement("mesh");
            layer.appendChild(mesh);

            mesh.setAttribute("table", (QString) meshItem->tableName());
            break;
        }

        case GraphicsIconItem::Type:
        {
            GraphicsIconItem * iconItem = qgraphicsitem_cast<GraphicsIconItem*>(item);

            QDomElement icon = doc.createElement("icon");
            layer.appendChild(icon);

            icon.setAttribute("x", (double) iconItem->pos().x());
            icon.setAttribute("y", (double) iconItem->pos().y());
            icon.setAttribute("name", (QString) iconItem->iconDef()->name());
            icon.setAttribute("angle", (double) iconItem->rotation());
            icon.setAttribute("date", (QString) iconItem->date());
            break;
        }

        case GraphicsVolumeItem::Type:
        {
            GraphicsVolumeItem * volumeItem = qgraphicsitem_cast<GraphicsVolumeItem*>(item);

            QDomElement volume = doc.createElement("volume");
            layer.appendChild(volume);

            // Writing polyline points
            foreach(QPointF point, volumeItem->points()){
                QDomElement dpoint = doc.createElement("point");
                volume.appendChild(dpoint);
                writePoint(dpoint, point);
            }

            volume.setAttribute("surface", volumeItem->surface());
            volume.setAttribute("volume", volumeItem->volume());
            volume.setAttribute("mesh_color", volumeItem->meshColor().name());
            volume.setAttribute("text_color", volumeItem->textColor().name());

            writeFontAttributes(volume, volumeItem->font());
            writePenAttributes(volume, volumeItem->pen());

            volume.setAttribute("text_visible", volumeItem->textVisible());
            volume.setAttribute("mesh_visible", volumeItem->meshVisible());
        }

        }

        _cpt++;
        emit levelUpdated(_cpt * 100 / _size);
    }
}

void PmlWriter::writePoint(QDomElement &element, const QPointF &point){
    element.setAttribute("x", (double) point.x());
    element.setAttribute("y", (double) point.y());
}

void PmlWriter::writeRect(QDomElement &element, const QRectF &rect){
    element.setAttribute("x", (double) rect.x());
    element.setAttribute("y", (double) rect.y());
    element.setAttribute("width", (double) rect.width());
    element.setAttribute("height", (double) rect.height());
}

void PmlWriter::writeRect(QDomElement &element, const QRect &rect){
    element.setAttribute("x", (int) rect.x());
    element.setAttribute("y", (int) rect.y());
    element.setAttribute("width", (int) rect.width());
    element.setAttribute("height", (int) rect.height());
}

void PmlWriter::writePenAttributes(QDomElement &element, const QPen &pen){
    element.setAttribute("pen_color", (QString) pen.color().name());
    element.setAttribute("pen_weight", (int) pen.width());
    element.setAttribute("qt_pen_style", (int) pen.style());
}

void PmlWriter::writeBrushAttributes(QDomElement &element, const QBrush &brush){
    element.setAttribute("brush_color", (QString) brush.color().name());
}

void PmlWriter::writeFontAttributes(QDomElement &element, const QFont &font){
    element.setAttribute("font", (QString) font.toString());
}

bool PmlWriter::compareFilepaths(const QString filepath1, const QString filepath2) {
    QFileInfo fileinfo1(filepath1);
    QFileInfo fileinfo2(filepath2);

    return fileinfo1.absolutePath() == fileinfo2.absolutePath();
}

QString PmlWriter::filenameFromFilepath(const QString filepath) {
    QFileInfo fileinfo(filepath);
    return fileinfo.fileName();
}
