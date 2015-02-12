#include "GraphicsScene.h"

// CUBATOR

GraphicsScene::GraphicsScene(QObject *parent) :
    QGraphicsScene(parent)
{
    _map = 0;
    _lineItem = 0;
    _polylineItem = 0;
    _pHatchItem = 0;
    _iconItem = 0;
    _measureItem = 0;
    _volumeItem = 0;

    _pen.setWidth(1);

    addItem(&_boatItem);
}

void GraphicsScene::selectTool(Tool tool){

    if(_toolSelected == TICON && tool != TICON){
        delete _iconItem;
        _iconItem = 0;
    }

    if(_toolSelected == TMOVE){
    }

    if(_lineItem){
        delete _lineItem;
        _lineItem = 0;
    }

    if(_polylineItem){
        GraphicsMapLayer * layer = _map->layerItem(_map->layerSelected());
        layer->setFlags(_polylineItem);
        _polylineItem->showPoints(0);
        _polylineItem = 0;
    }

    if(_pHatchItem){
        GraphicsMapLayer * layer = _map->layerItem(_map->layerSelected());
        GraphicsHatchItem * hatchItem = new GraphicsHatchItem;
        QPainterPath path;
        QPolygonF polygon(_pHatchItem->points());
        path.addPolygon(polygon);
        hatchItem->setPath(path);
        hatchItem->setPen(_pHatchItem->pen());
        hatchItem->setBrush(QBrush(_pHatchItem->pen().color()));
        layer->addToLayer(hatchItem);
        delete _pHatchItem;
        _pHatchItem = 0;

    }

    if(_volumeItem){
        if(tool == TVOLUME){
            GraphicsMapLayer * layer = _map->layerItem(_map->layerSelected());
            layer->setFlags(_volumeItem);
            _volumeItem->showPoints(0);
            _volumeItem->setClosed(1);
            emit(volumeShapeDefined(_volumeItem));
        }
        else delete _volumeItem;
        _volumeItem = 0;
    }

    if(_measureItem){
        delete _measureItem;
        _measureItem = 0;
    }

    if(_map){
        GraphicsMapLayer * layer = _map->layerItem(_map->layerSelected());

        if(tool == TICON){
            // load the icon definition
            GraphicsMapIconDef * icondef = _map->iconDefItem(_icon);
            GraphicsIconItem * iconItem = new GraphicsIconItem();
            iconItem->setIconDef(icondef);
            iconItem->setDate(QDate::currentDate().toString("dd/MM/yyyy"));
            layer->addToLayer(iconItem); // add the icon to layer

            _iconItem = iconItem;
        }
    }

    _toolSelected = tool;
}

Tool GraphicsScene::toolSelected(){return _toolSelected;}

void GraphicsScene::setPen(QPen pen){_pen = pen;}

QPen GraphicsScene::pen(){return _pen;}

void GraphicsScene::setMap(const GraphicsMap *map){_map = (GraphicsMap *) map;}

GraphicsMap * GraphicsScene::map() const{return _map;}

void GraphicsScene::setIcon(const QString &icon){_icon = icon;}

QString GraphicsScene::icon() const{return _icon;}

GraphicsBoatItem * GraphicsScene::boatItem() {return &_boatItem;}

void GraphicsScene::setPaintColor(QColor color){_pen.setColor(color);}

QColor GraphicsScene::paintColor(){return _pen.color();}

void GraphicsScene::setLineWidth(int lineWidth){_pen.setWidth(lineWidth);}

int GraphicsScene::lineWidth(){return _pen.width();}

void GraphicsScene::setFont(QFont font){_font = font;}

QFont GraphicsScene::font(){return _font;}

void GraphicsScene::setTransform(QTransform transform){_transform = transform;}

void GraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event){

    if(_toolSelected == THEIGHT){
        processMeshDepth(event);
    }

    else if(_toolSelected == TLINE){
        if(_lineItem != 0) {
            QLineF newLine(_lineItem->line().p1(), event->scenePos());
            _lineItem->setLine(newLine);
        }
    }

    else if(_toolSelected == TICON){
        if(_iconItem){
            _iconItem->setPos(event->scenePos());
        }
    }

    else if(_toolSelected == TMEASURE){
       if(_measureItem){
           _measureItem->setP2(event->scenePos());
       }
    }

    emit mousePositionUpdated(event->scenePos());

    processMeshDepth(event);
    QGraphicsScene::mouseMoveEvent(event);
}

void GraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event){

    if(!_map) return QGraphicsScene::mousePressEvent(event);

    GraphicsMapLayer * layer = _map->layerItem(_map->layerSelected());

   if(_toolSelected == TPOINT){
        QGraphicsEllipseItem * ellipseItem = new QGraphicsEllipseItem;
        QPointF pos = event->scenePos();
        ellipseItem->setRect((qreal) (pos.x() - 1), (qreal) (pos.y() - 1), 2, 2);
        ellipseItem->setPen(_pen);
        QBrush b;
        b.setColor(_pen.color());
        b.setStyle(Qt::SolidPattern);
        ellipseItem->setBrush(b);
        layer->addToLayer(ellipseItem);
    }

    else if(_toolSelected == TPOINTXY){
       if(event->button() == Qt::LeftButton){
           GraphicsPointXYItem * pointItem = new GraphicsPointXYItem;
           QPointF pos = event->scenePos();
           pointItem->setPen(_pen);
           pointItem->setBrush(QBrush(_pen.color()));
           pointItem->setPos(pos);
           pointItem->setFont(_font);
           layer->addToLayer(pointItem);
       }
   }

    else if(_toolSelected == TLINE){
        if(_lineItem){
            QLineF line(_lineItem->line().p1(), event->scenePos());
            layer->setFlags(_lineItem);
            _lineItem->setLine(line);
            _lineItem = 0;
            _map->update();
        }
        else{
            _lineItem = new QGraphicsLineItem;
            _lineItem->setPen(_pen);
            layer->addToLayer(_lineItem);
            _lineItem->setLine(QLineF(event->scenePos(), event->scenePos()));
            _lineItem->setFlag(QGraphicsItem::ItemIsMovable, 0);
        }
    }

    else if(_toolSelected == TPOLYLINE){
        if(event->button() == Qt::RightButton){
            selectTool(TPOLYLINE);
        }
        else{
            if(!_polylineItem){
                _polylineItem = new GraphicsPolylineItem;
                _polylineItem->setPen(_pen);
                _polylineItem->showPoints(1);
                layer->addToLayer(_polylineItem);
                _polylineItem->setFlag(QGraphicsItem::ItemIsMovable, 0);
            }
            _polylineItem->addPoint(event->scenePos());
            _polylineItem->update(_polylineItem->boundingRect());
        }
    }

    else if(_toolSelected == TPAINT){
        if(event->button() == Qt::RightButton){
            selectTool(TPAINT);
        }
        else{
            if(!_pHatchItem){
                _pHatchItem = new GraphicsPolylineItem;
                _pHatchItem->setPen(_pen);
                _pHatchItem->showPoints(1);
                layer->addToLayer(_pHatchItem);
                _pHatchItem->setFlag(QGraphicsItem::ItemIsMovable, 0);
            }
            _pHatchItem->addPoint(event->scenePos());
            _pHatchItem->update(_pHatchItem->boundingRect());
        }
    }

    else if(_toolSelected == TVOLUME){
       if(event->button() == Qt::RightButton){
           selectTool(TVOLUME);
           event->setButton(Qt::LeftButton);
       }
       else{
           if(!_volumeItem){
               _volumeItem = new GraphicsVolumeItem;
               _volumeItem->setFont(_font);
               _volumeItem->setMeshColor(QColor(0, 150, 0));
               _volumeItem->setTextColor(_pen.color());
               _volumeItem->showPoints(1);
               layer->addToLayer(_volumeItem);
               _volumeItem->setFlag(QGraphicsItem::ItemIsMovable, 0);
           }
           _volumeItem->addPoint(event->scenePos());
           _volumeItem->update(_volumeItem->boundingRect());
       }
   }

    else if(_toolSelected == TTEXT){
        if(event->button() == Qt::LeftButton){
            GraphicsTextItem * textItem = new GraphicsTextItem;
            textItem->setPos(event->scenePos());
            textItem->setFont(_font);
            textItem->setBrush(QBrush(_pen.color()));
            textItem->setTransform(_transform);
            layer->addToLayer(textItem);
            textItem->edit(event);
            layer->setFlags(textItem);
        }
    }

    else if(_toolSelected == TMEASURE){
        if(event->button() == Qt::LeftButton){
            if(!_measureItem){
                _measureItem = new GraphicsMeasureItem;
                _measureItem->setP1(event->scenePos());
                addItem(_measureItem);
            }
            else{
                delete _measureItem;
                _measureItem = 0;

                QGraphicsEllipseItem * ellipseItem = new QGraphicsEllipseItem;
                QPointF pos = event->scenePos();
                ellipseItem->setRect((qreal) (pos.x() - 1), (qreal) (pos.y() - 1), 2, 2);
                ellipseItem->setPen(_pen);
                ellipseItem->setBrush(QBrush(_pen.color()));
                layer->addToLayer(ellipseItem);
            }
        }
        else if(event->button() == Qt::RightButton){
            delete _measureItem;
            _measureItem = 0;
        }
    }

    else if(_toolSelected == TICON){
        if(event->button() == Qt::LeftButton){
            if(_iconItem){
                _iconItem->enableContextMenuEvent(1);
                layer->setFlags(_iconItem);
                selectTool(TICON);
            }

        }
    }

   else if(_toolSelected == TPOINTXYZ){
       if(event->button() == Qt::LeftButton){
           emit pointXYZAdded(event->scenePos());
       }
   }

    QGraphicsScene::mousePressEvent(event);
}

void GraphicsScene::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event){
    if(_toolSelected == TMOVE) return;

    QGraphicsScene::mouseDoubleClickEvent(event);
}

void GraphicsScene::contextMenuEvent(QGraphicsSceneContextMenuEvent *event){
    if(_toolSelected == TVOLUME) return;

    QGraphicsScene::contextMenuEvent(event);
}

void GraphicsScene::wheelEvent(QGraphicsSceneWheelEvent *event){

    if(_toolSelected == TICON){
        if(_iconItem){
            //(event->delta() > 0) ? _iconItem->rotate(-2) : _iconItem->rotate(2);
            (event->delta() > 0) ? _iconItem->setRotation(-2) : _iconItem->setRotation(2);
        }
    }

    QGraphicsScene::wheelEvent(event);
}

void GraphicsScene::keyPressEvent(QKeyEvent *event){

    if(event->key() == Qt::Key_Delete){
        QList<QGraphicsItem*> list = selectedItems();
        QGraphicsItem * item = 0;

        foreach(item, list){
            if(item->type() == GRAPHICS_ANCHORS_TYPE ||
                    item->type() == GRAPHICS_ANCHOR_TYPE ||
                    item->type() == GRAPHICS_RANCHOR_TYPE) return;
            delete item;
        }
    }
    else if(event->key() == Qt::Key_Escape){
        clearSelection();
    }
    QGraphicsScene::keyPressEvent(event);
}

void GraphicsScene::processMeshDepth(QGraphicsSceneMouseEvent *event){

    QList<QGraphicsItem*> list = items(event->scenePos());
    emit mouseMeshDepthNotFound();
    foreach(QGraphicsItem * item, list){
        if(item->type() == GRAPHICS_MESH_IMAGE_TYPE){
            GraphicsMeshImageItem * imageItem = qgraphicsitem_cast<GraphicsMeshImageItem*>(item);
            if(imageItem->contains(event->scenePos())){
                double depth=0;
                if(imageItem->depthGridAt(event->scenePos(), depth)){
                    emit mouseMeshDepthAdded(imageItem->tableName(), depth);
                }
            }
        }
    }
}

void GraphicsScene::updateGpsPosition(const QPointF &position){
    _boatItem.setPos(position);
}
