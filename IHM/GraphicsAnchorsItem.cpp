#include "GraphicsAnchorsItem.h"

// CUBATOR
#include <GraphicsAnchorItem.h>
#include <GraphicsPictureItem.h>

GraphicsAnchorsItem::GraphicsAnchorsItem(QGraphicsItem * parent):
    QGraphicsItem(parent)
{
    // initialise les 4 ancres
    for(int i=0; i<4; i++){
        _anchors[i] = new GraphicsAnchorItem(this);
        _anchors[i]->setPos(0,0);
        _anchors[i]->setRect(0, 0, SIZE_ANCHOR, SIZE_ANCHOR);
    }

    // applique une rotation sur les ancres pour qu'elles se positionnent sur l'image
    _anchors[1]->setRotation(90);
    _anchors[2]->setRotation(180);
    _anchors[3]->setRotation(-90);

    // définit les curseurs
    _anchors[0]->setCursor(Qt::SizeFDiagCursor);
    _anchors[1]->setCursor(Qt::SizeBDiagCursor);
    _anchors[2]->setCursor(Qt::SizeFDiagCursor);
    _anchors[3]->setCursor(Qt::SizeBDiagCursor);

    _parent = parent;
    _ratioEnabled = 0;
    _pictureIsMovable = 0;
    _offsetx = 0;
    _size.setWidth(SIZE_ANCHOR);
    _size.setHeight(SIZE_ANCHOR);

    setFlag(QGraphicsItem::ItemIsMovable, false);
}

int GraphicsAnchorsItem::type() const{
    return Type;
}

void GraphicsAnchorsItem::setRect(QRectF rect){
    _anchors[0]->setPos(rect.topLeft());
    _anchors[1]->setPos(rect.topRight());
    _anchors[2]->setPos(rect.bottomRight());
    _anchors[3]->setPos(rect.bottomLeft());
}

void GraphicsAnchorsItem::anchorUpdated(GraphicsAnchorItem * sender){

    if(!sender) return;

    qreal w = 0; // nouvelle largeur d'image

    // repositionne les 3 autres ancres
    GraphicsPictureItem::Anchor anchor;
    if(sender == _anchors[0]){
        w = _anchors[1]->x() - sender->x() + _offsetx;
        _offsetx = sender->x();
        anchor = GraphicsPictureItem::TOP_LEFT_ANCHOR;
    }
    else if(sender == _anchors[1]){
        w = sender->x() - _anchors[0]->x();
        anchor = GraphicsPictureItem::TOP_RIGHT_ANCHOR;
    }
    else if(sender == _anchors[2]){
        w = sender->x() - _anchors[3]->x();
        anchor = GraphicsPictureItem::BOTTOM_RIGHT_ANCHOR;
    }
    else{
        w = _anchors[2]->x() - sender->x() + _offsetx;
        _offsetx = sender->x();
        anchor = GraphicsPictureItem::BOTTOM_LEFT_ANCHOR;
    }

    // met à jour l'image
    if(_parent){
        if(_parent->type() == GRAPHICS_PICTURE_TYPE){
            GraphicsPictureItem * picture = qgraphicsitem_cast<GraphicsPictureItem*> (_parent);
            picture->anchorsUpdated((int) w, anchor);
        }
    }
}

void GraphicsAnchorsItem::resetOffset(){
    _offsetx = 0;
}

bool GraphicsAnchorsItem::anchorSelected() const{
    for(int i=0; i<4; i++){
        if(_anchors[i]->isSelected()) return true;
    }
    return false;
}

void GraphicsAnchorsItem::setRatioEnable(bool enable){
    _ratioEnabled = enable;
}

void GraphicsAnchorsItem::setRotation(qreal angle){
    _anchors[0]->setRotation(angle);
    _anchors[1]->setRotation(90+angle);
    _anchors[2]->setRotation(180+angle);
    _anchors[3]->setRotation(-90+angle);
    prepareGeometryChange();
}

QRectF GraphicsAnchorsItem::boundingRect() const{
    QRectF rect;
    rect.setTopLeft(_anchors[0]->pos());
    rect.setTopRight(_anchors[1]->pos());
    rect.setBottomRight(_anchors[2]->pos());
    rect.setBottomLeft(_anchors[3]->pos());
    return rect;
}

void GraphicsAnchorsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    Q_UNUSED(painter)
    Q_UNUSED(option)
    Q_UNUSED(widget)
}

QList<QRectF> GraphicsAnchorsItem::anchorBounds() const{
    QList<QRectF> list;
    for(int i=0; i<4; i++){
        list.append(_anchors[i]->boundingRect());
    }
    return list;
}
