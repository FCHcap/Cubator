#include "MeshGraphicsView.h"

MeshGraphicsView::MeshGraphicsView(QWidget *parent) :
    QGraphicsView(parent)
{
    setFocus();
    setMouseTracking(1);
    //setRenderHint(QPainter::Antialiasing,true);
    setDragMode(QGraphicsView::ScrollHandDrag);

    _kCtrlPressed = 0;
    _mousePressed = 0;
}

bool MeshGraphicsView::isMousePressed(){
    return _mousePressed;
}

void MeshGraphicsView::mousePressEvent(QMouseEvent *event){

    if(event->button() == Qt::RightButton){
        _mousePressed = 1;
        setDragMode(QGraphicsView::NoDrag);
        setCursor(Qt::CrossCursor);
        emit scenePositionUpdated(mapToScene(event->pos()));
    }

    QGraphicsView::mousePressEvent(event);
}

void MeshGraphicsView::mouseReleaseEvent(QMouseEvent *event){

    if(event->button() == Qt::RightButton){
        _mousePressed = 0;
        setDragMode(QGraphicsView::ScrollHandDrag);
    }

    QGraphicsView::mouseReleaseEvent(event);
}

void MeshGraphicsView::dragLeaveEvent(QDragLeaveEvent *event){
    if(_mousePressed){
        _mousePressed = 0;
        setDragMode(QGraphicsView::ScrollHandDrag);
    }

    QGraphicsView::dragLeaveEvent(event);
}

void MeshGraphicsView::keyPressEvent(QKeyEvent *event){

    if(event->key() == Qt::Key_Control){
        _kCtrlPressed = 1;
    }
    else if(event->key() == Qt::Key_Space){
        emit spacePressed();
    }

    QGraphicsView::keyPressEvent(event);
}

void MeshGraphicsView::keyReleaseEvent(QKeyEvent *event){

    if(event->key() == Qt::Key_Control){
        _kCtrlPressed = 0;
    }

    QGraphicsView::keyReleaseEvent(event);
}

void MeshGraphicsView::wheelEvent(QWheelEvent *event){
    if(_kCtrlPressed){
        QWheelEvent * wevent = static_cast<QWheelEvent*>(event);
        (wevent->delta() > 0) ? scale(1.2, 1.2) : scale(0.8, 0.8);
    }
}

void MeshGraphicsView::mouseMoveEvent(QMouseEvent *event){
    emit scenePositionUpdated(mapToScene(event->pos()));
    QGraphicsView::mouseMoveEvent(event);
}
