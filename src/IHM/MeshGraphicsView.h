#ifndef MESHGRAPHICSVIEW_H
#define MESHGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QKeyEvent>

class MeshGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit MeshGraphicsView(QWidget *parent = 0);
    bool isMousePressed();
    void zoomIn();
    void zoomOut();
    void setScale(qreal scale);

signals:
    void spacePressed();
    void scenePositionUpdated(QPointF);

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void dragLeaveEvent(QDragLeaveEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void wheelEvent(QWheelEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

protected:
    bool _kCtrlPressed;
    bool _mousePressed;
};

#endif // MESHGRAPHICSVIEW_H
