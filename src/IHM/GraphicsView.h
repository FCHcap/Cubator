#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

// QT
#include <QGraphicsView>
#include <QKeyEvent>

// CUBATOR
#include <GraphicsScene.h>
#include <GraphicsMapLayer.h>
//#include <Tools.h>

class GraphicsView : public QGraphicsView
{
    Q_OBJECT

public:
    explicit GraphicsView(QWidget *parent = 0);
    void setScene(GraphicsScene * scene);
    
protected:
    void keyPressEvent(QKeyEvent *event);
    void wheelEvent(QWheelEvent *event);

    void setScale(qreal scale);
    void updateTransform();
    
public slots:
    void updatePosition(QPointF position);

protected:
    GraphicsScene * _scene;
    bool _centeringGps;
    bool _rightButtonPressed;
    QTransform _transform;
    
};

#endif // GRAPHICSVIEW_H
