#include "GraphicsIconItem.h"

// QT
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QToolTip>
#include <QGraphicsSceneHoverEvent>
#include <QMenu>
#include <QAction>
#include <QInputDialog>

int GraphicsIconItem::type() const{
    return Type;
}

GraphicsIconItem::GraphicsIconItem(QGraphicsItem * parent, GraphicsMapIconDef * iconDef): QGraphicsItem(parent){
    setAcceptHoverEvents(1);
    _iconDef = iconDef;

    _cmv = 0;

    setFlags(QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);

}

void GraphicsIconItem::setIconDef(const GraphicsMapIconDef *iconDef){
    _iconDef = (GraphicsMapIconDef*) iconDef;
    if(_iconDef) _name = _iconDef->name();
}

GraphicsMapIconDef * GraphicsIconItem::iconDef() const{
    return _iconDef;
}

void GraphicsIconItem::setDate(QString date){
    _date = date;
}

QString GraphicsIconItem::date(){
    return _date;
}

void GraphicsIconItem::setName(const QString &name){
    _name = name;
}

QString GraphicsIconItem::name() const{
    return _name;
}

void GraphicsIconItem::enableContextMenuEvent(bool cmv){
    _cmv = cmv;
}

QRectF GraphicsIconItem::boundingRect() const{

    if(_iconDef){
        QPointF center = (QPointF) _iconDef->center();
        QRectF rect = _iconDef->childrenBoundingRect();
        rect.translate(-center);
        return rect;
    }
    return QRectF();
}

void GraphicsIconItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

    Q_UNUSED(option)
    Q_UNUSED(widget)

    if(_iconDef){

        bool autoColor=0;

        if(isUnderMouse() || isSelected()){
            autoColor=1;
            QPen pen(_iconDef->selectionColor());
            painter->setPen(pen);
        }

        QTransform transform=painter->transform();
        transform.translate(-_iconDef->center().x(), -_iconDef->center().y());
        painter->setTransform(transform);

        QGraphicsItem* item = 0;

        foreach (item, _iconDef->childItems()){

            if(item->type() == QGraphicsEllipseItem::Type){
                QGraphicsEllipseItem* ellipseItem = qgraphicsitem_cast<QGraphicsEllipseItem*>(item);
                QPen pen = ellipseItem->pen();
                QBrush brush = ellipseItem->brush();

                if(autoColor) pen.setColor(_iconDef->selectionColor());

                painter->setPen(pen);
                painter->setBrush(brush);
                painter->drawEllipse(ellipseItem->rect());
                continue;
            }

            if(item->type() == QGraphicsLineItem::Type){
                QGraphicsLineItem* lineItem = qgraphicsitem_cast<QGraphicsLineItem*>(item);
                if(!autoColor) painter->setPen(lineItem->pen());
                else{
                    QPen pen=painter->pen();
                    pen.setWidth(lineItem->pen().width());
                    painter->setPen(pen);
                }
                painter->drawLine(lineItem->line());
                continue;
            }

            if(item->type() == QGraphicsPolygonItem::Type){
                QGraphicsPolygonItem* polygonItem = qgraphicsitem_cast<QGraphicsPolygonItem*>(item);
                QPolygonF p=polygonItem->polygon();
                if(!autoColor) painter->setPen(polygonItem->pen());
                else{
                    QPen pen=painter->pen();
                    pen.setWidth(polygonItem->pen().width());
                    painter->setPen(pen);
                }
                painter->drawPolygon(p);
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

            if(item->type() == QGraphicsSimpleTextItem::Type){
                QGraphicsSimpleTextItem* textItem = qgraphicsitem_cast<QGraphicsSimpleTextItem*>(item);
                painter->drawText(textItem->pos(), textItem->text());
                continue;
            }
        }

        if(isSelected()){
            QPen pen;
            pen.setStyle(Qt::DashLine);
            painter->setPen(pen);
            QRectF rect = _iconDef->childrenBoundingRect();

            painter->drawRect(rect);
        }
    }
}

void GraphicsIconItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    QList<QGraphicsView*> views=scene()->views();
    QToolTip::showText(event->screenPos(),_date, views.first());
    update();
    QGraphicsItem::hoverEnterEvent(event);
}

void GraphicsIconItem::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    QToolTip::hideText();
    update();
    QGraphicsItem::hoverLeaveEvent(event);
}

void GraphicsIconItem::contextMenuEvent(QGraphicsSceneContextMenuEvent *event){

    if(!(flags() & QGraphicsItem::ItemIsMovable)) return; // n'affiche pas le menu si l'élément n'est pas marqué comme déplaçable

    QMenu menu;
    menu.addAction(ACTION05); // Position
    menu.addAction(ACTION06); // Date
    menu.addAction(ACTION07); // Rotation
    menu.addAction(ACTION08); // Delete
    QAction * action = menu.exec(event->screenPos());

    if(!action) return;

    if(action->text() == ACTION05){
        CoordinatesDialog dialog(static_cast<QWidget*> (scene()->views().at(0)));
        dialog.setSystemBPosition(pos());
        if(dialog.exec() == QDialog::Accepted){
            setPos(dialog.systemBPosition());
        }
    }
    else if(action->text() == ACTION06){
        DateDialog dialog(static_cast<QWidget*> (scene()->views().at(0)));
        dialog.setDate(QDate::fromString(date(), "dd/MM/yyyy"));
        if(dialog.exec() == QDialog::Accepted){
            setDate(dialog.date().toString("dd/MM/yyyy"));
        }
    }
    else if(action->text() == ACTION07){
        this->setRotation(QInputDialog::getDouble(this->scene()->views().at(0), TITLE04, TEXT10, this->rotation(), 0.0, 360.0));
    }
    else if(action->text() == ACTION08){
        delete this;
    }
}
