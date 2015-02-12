#include "GraphicsView.h"

// QT
#include <QScrollBar>

GraphicsView::GraphicsView(QWidget *parent) :
    QGraphicsView(parent)
{    
    setMouseTracking(1);
    setRenderHint(QPainter::Antialiasing,true);
    setDragMode(QGraphicsView::NoDrag);

    verticalScrollBar()->installEventFilter(this);

    _toolSelected = NO;
    _scene = 0;
    _centeringGps = 0;
}

void GraphicsView::setScene(GraphicsScene *scene){
    _scene = scene;
    QGraphicsView::setScene(scene);
}

void GraphicsView::setTool(Tool tool){
    _toolSelected = tool;
}

void GraphicsView::mousePressEvent(QMouseEvent *event){

    if(_toolSelected == TMOVE){
        setDragMode(QGraphicsView::ScrollHandDrag);
        setCursor(Qt::ClosedHandCursor);
    }
    else setDragMode(QGraphicsView::NoDrag);

    QGraphicsView::mousePressEvent(event);
}

void GraphicsView::mouseReleaseEvent(QMouseEvent *event){

    if(_toolSelected == TMOVE){
        setDragMode(QGraphicsView::NoDrag);
        setCursor(Qt::OpenHandCursor);
    }
    QGraphicsView::mouseReleaseEvent(event);
}

void GraphicsView::mouseMoveEvent(QMouseEvent *event){
    if(_toolSelected == TMOVE){
        setCursor(Qt::OpenHandCursor);
    }
    else{
        setCursor(Qt::CrossCursor);
    }
    QGraphicsView::mouseMoveEvent(event);
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

        /*else if(item->type() == GraphicsPointXYItem::Type){
            GraphicsPointXYItem * pointItem = qgraphicsitem_cast<GraphicsPointXYItem*> (item);
            pointItem->setTextTransform(_transform);
        }*/
    }
    if(_scene) _scene->setTransform(_transform);
}

void GraphicsView::updatePosition(QPointF position){
    centerOn(position);
}
