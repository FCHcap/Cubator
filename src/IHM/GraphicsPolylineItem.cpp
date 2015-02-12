#include "GraphicsPolylineItem.h"

GraphicsPolylineItem::GraphicsPolylineItem(QGraphicsItem * parent) : QGraphicsItem(parent){
    _closed = 0;
    _pointsShown = 0;
}

GraphicsPolylineItem::~GraphicsPolylineItem(){
}

int GraphicsPolylineItem::type() const{
    return Type;
}

void GraphicsPolylineItem::addPoint(const QPointF &point){

    QRectF r(point.x()-1.5, point.y()-1.5, 3, 3);

    if(_points.isEmpty()){
        _rect = r;
    }
    else
        if(!_rect.contains(point))
        _rect = _rect.united(r);

    _points.append(point);
}

GraphicsPolylineItem::GPIPOINTS GraphicsPolylineItem::points() const{
    return _points;
}

void GraphicsPolylineItem::clearPoints(){
    _points.clear();
}

QPen GraphicsPolylineItem::pen(){
    return _pen;
}

void GraphicsPolylineItem::setPen(const QPen &pen){
    _pen = pen;
    QBrush b = _pen.brush();
    b.setStyle(Qt::SolidPattern);
    _pen.setBrush(b);
}

bool GraphicsPolylineItem::isClosed(){
    return _closed;
}

void GraphicsPolylineItem::setClosed(bool closed){
    _closed = closed;
}


bool GraphicsPolylineItem::polylineContains(const QPointF &point) const{

    QLineF xLine(boundingRect().left(), point.y(), boundingRect().right(), point.y());

    int lCpt = 0;
    int rCpt = 0;

    // Draws the line
    for(int i=1; i<_points.count(); i++){
        QPointF intersectionPoint;
        int id1 = i-1; // index for the first point
        int id2 = i; // index for the second point

        test:

        QLineF line(_points.at(id1), _points.at(id2));
        if(line.intersect(xLine, &intersectionPoint) == QLineF::BoundedIntersection)
            (intersectionPoint.x() > point.x()) ? rCpt++ : lCpt++;

        if(i == _points.count()-1){
            id1 = i; id2 = 0;
            i++;
            goto test;
        }

    }

    if(lCpt&1 || rCpt&1) return true;
    return false;
}

bool GraphicsPolylineItem::polylineContains(const QRect &rect) const{
    if(polylineContains(QPointF(rect.x(), rect.y()))
            && polylineContains(QPointF(rect.x(), rect.y()+rect.height()))
            && polylineContains(QPointF(rect.x()+rect.width(), rect.y()))
            && polylineContains(QPointF(rect.x()+rect.width(), rect.y()+rect.height()))
            ) return true;
    return false;
}

void GraphicsPolylineItem::showPoints(bool show){
    _pointsShown = show;
}

QRectF GraphicsPolylineItem::boundingRect() const{
    return _rect;
}

void GraphicsPolylineItem::mousePressEvent(QGraphicsSceneMouseEvent *event){
    QGraphicsItem::mousePressEvent(event);
    setSelected(1);
}

void GraphicsPolylineItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

    Q_UNUSED(option)
    Q_UNUSED(widget)

    painter->setPen(_pen);
    painter->setBrush(QBrush(_pen.color()));

    // Draws the line
    for(int i=1; i<_points.count(); i++){
        painter->drawLine(_points.at(i-1), _points.at(i));
    }
    if(_closed && _points.size() > 2){
        painter->drawLine(_points.last(), _points.first());
    }

    // Draws the points
    if(_pointsShown || this->isSelected()){
        painter->setPen(QPen(Qt::black));
        painter->setBrush(QBrush(Qt::black));
        foreach(QPointF point, _points){
            painter->drawEllipse(point, 2, 2);
        }
    }

    if(isSelected()){
        QPen pen = QPen(Qt::black);
        pen.setStyle(Qt::DashLine);
        painter->setPen(pen);
        painter->setBrush(QBrush());
        painter->drawRect(_rect);
    }
}
