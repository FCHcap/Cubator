#include "GraphicsBoatItem.h"

int GraphicsBoatItem::type() const{
    return Type;
}

GraphicsBoatItem::GraphicsBoatItem(QGraphicsItem *parent) : QGraphicsItem(parent){
    _boatDef = 0;
}

void GraphicsBoatItem::setBoatDef(GraphicsMapBoatDef *boatDef){
    _boatDef = boatDef;
}

GraphicsMapBoatDef * GraphicsBoatItem::boatDef() const{
    return _boatDef;
}

QRectF GraphicsBoatItem::boundingRect() const{
    if(_boatDef){
        QPointF center = (QPointF) _boatDef->center();
        QRectF rect = _boatDef->childrenBoundingRect();
        rect.translate(-center);
        return rect;
    }
    return QRectF();
}

void GraphicsBoatItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

    Q_UNUSED(option)
    Q_UNUSED(widget)

    if(_boatDef){

        QTransform transform=painter->transform();
        transform.translate(-_boatDef->center().x(), -_boatDef->center().y());
        painter->setTransform(transform);

        QGraphicsItem* item = 0;

        foreach (item, _boatDef->childItems()){

            if(item->type() == QGraphicsEllipseItem::Type){
                QGraphicsEllipseItem* ellipseItem = qgraphicsitem_cast<QGraphicsEllipseItem*>(item);
                QPen pen = ellipseItem->pen();
                painter->setPen(pen);
                painter->drawEllipse(ellipseItem->rect());
                continue;
            }

            if(item->type() == QGraphicsLineItem::Type){
                QGraphicsLineItem* lineItem = qgraphicsitem_cast<QGraphicsLineItem*>(item);
                QPen pen = lineItem->pen();
                painter->setPen(pen);
                painter->drawLine(lineItem->line());
                continue;
            }

            if(item->type() == GraphicsPolylineItem::Type){
                GraphicsPolylineItem * polylineItem = qgraphicsitem_cast<GraphicsPolylineItem*>(item);
                QPen pen = polylineItem->pen();
                painter->setPen(pen);
                GraphicsPolylineItem::GPIPOINTS points = polylineItem->points();
                for(int i=0; i<points.size(); i++){
                    QPointF p1 = points[i];
                    QPointF p2;
                    (i+1 >= points.size()) ? p2 = points[0] : p2 = points[i+1];
                    painter->drawLine(p1, p2);
                }
                continue;
            }

            if(item->type() == QGraphicsPolygonItem::Type){
                QGraphicsPolygonItem* polygonItem = qgraphicsitem_cast<QGraphicsPolygonItem*>(item);
                QPolygonF p=polygonItem->polygon();
                QPen pen = polygonItem->pen();
                painter->setPen(pen);
                painter->drawPolygon(p);
                continue;
            }

            if(item->type() == QGraphicsSimpleTextItem::Type){
                QGraphicsSimpleTextItem* textItem = qgraphicsitem_cast<QGraphicsSimpleTextItem*>(item);
                painter->drawText(textItem->pos(), textItem->text());
                continue;
            }
        }
    }
}
