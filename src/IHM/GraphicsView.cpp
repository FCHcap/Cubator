#include "GraphicsView.h"

// QT
#include <QScrollBar>

// CUBATOR
#include <Settings.h>

GraphicsView::GraphicsView(QWidget *parent) :
    QGraphicsView(parent)
{    
    setMouseTracking(1);
    setDragMode(QGraphicsView::NoDrag);

    verticalScrollBar()->installEventFilter(this);

    _scene = 0;
}

void GraphicsView::setScene(GraphicsScene *scene){
    _scene = scene;
    QGraphicsView::setScene(scene);
}

void GraphicsView::keyPressEvent(QKeyEvent *event){

    if(event->key() == Qt::Key_Plus){
        _transform.scale(1.1, 1.1);
        updateTransform();
    }
    else if(event->key() == Qt::Key_Minus){
        _transform.scale(0.9, 0.9);
        updateTransform();
    }

    QGraphicsView::keyPressEvent(event);
}

void GraphicsView::wheelEvent(QWheelEvent *event){

    if(_scene){
        QWheelEvent * wevent = static_cast<QWheelEvent*>(event);
        if(wevent->modifiers() == Qt::ControlModifier){
            (wevent->delta() > 0) ? _transform.scale(1.1, 1.1) : _transform.scale(0.9, 0.9);

            updateTransform();
            return;
        }
    }

    QGraphicsView::wheelEvent(event);
}

void GraphicsView::updateTransform(){
    QGraphicsView::setTransform(_transform * QTransform::fromScale(1.0, -1.0));
    // Sets the scale of text items (becaused the flag : ItemIgnoresTransformations)
    QGraphicsScene * scene = this->scene();
    foreach(QGraphicsItem* item, scene->items()){
        if(item->type() == GraphicsMapLayer::Type){
            GraphicsMapLayer * layer = qgraphicsitem_cast<GraphicsMapLayer*>(item);
            foreach(QGraphicsItem * item2, layer->childItems()){
                if(item->type() == GraphicsTextItem::Type)
                    item2->setTransform(_transform);
            }
        }
        else if(item->type() == GraphicsTextItem::Type)
            item->setTransform(_transform);

        else if(item->type() == GraphicsVolumeItem::Type){
            GraphicsVolumeItem * volumeItem = qgraphicsitem_cast<GraphicsVolumeItem*> (item);
            volumeItem->setTextTransform(_transform);
        }
    }
    if(_scene) _scene->setTransform(_transform);
}

void GraphicsView::updatePosition(QPointF position){
    centerOn(position);
}

void GraphicsView::updateSceneRect(const QRectF &rect) {

    QGraphicsView::updateSceneRect(rect);

    Settings * settings = Settings::getInstance();
    SettingsMaps smaps = settings->settingsMaps();

    if(smaps.enableCenterView()) {
        QPointF pos = smaps.centerView();
        this->centerOn(pos);
    }
}
