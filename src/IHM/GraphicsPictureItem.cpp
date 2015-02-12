#include "GraphicsPictureItem.h"

// CUBATOR
#include <CoordinatesDialog.h>
#include <GraphicsAnchorsItem.h>
#include <GraphicsRAnchorItem.h>
#include <GraphicsPointXYItem.h>
#include <CubException.h>
#include <Messages.h>

// QT
#include <QMenu>
#include <QAction>

GraphicsPictureItem::GraphicsPictureItem(QGraphicsItem * parent):
    QGraphicsItem(parent)
{
    this->setTransform(QTransform::fromScale(1.0, -1.0));//this->setScale(-1); // inverse l'axe y

    _pi = new QGraphicsPixmapItem(this);
    _anchors = new GraphicsAnchorsItem(this);
    _anchors->setRatioEnable(true);
    _ranchor = new GraphicsRAnchorItem(this);
    _capture = NOTHING;
    _state = NOTHING;

    // défini les éléments de position d'ancres
    QPen penBlue = QPen(Qt::blue);
    _firstAnchorItem = new GraphicsPointXYItem(this);
    _firstAnchorItem->setVisible(false); // masqué par défaut
    _firstAnchorItem->setTypeCoords(GraphicsPointXYItem::MANUAL); // coordonnées cartographiques
    _firstAnchorItem->setPosition(GraphicsPointXYItem::RIGHT); // texte à droite du point
    _firstAnchorItem->setScale(-1);
    _firstAnchorItem->setPen(penBlue);

    _lastAnchorItem = new GraphicsPointXYItem(this);
    _lastAnchorItem->setVisible(false);
    _lastAnchorItem->setTypeCoords(GraphicsPointXYItem::MANUAL);
    _lastAnchorItem->setPosition(GraphicsPointXYItem::RIGHT);
    _lastAnchorItem->setScale(-1);
    _lastAnchorItem->setPen(penBlue);

    setTransformOriginPoint(_pi->boundingRect().center()+QPointF(SIZE_RANCHOR/2, SIZE_RANCHOR/2));

    setAcceptHoverEvents(true);
}

int GraphicsPictureItem::type() const{
    return Type;
}

void GraphicsPictureItem::anchorsUpdated(int width, Anchor anchor){

    // récupère la position (scène) de l'ancre opposée à celle déplacée ...
    QPointF sPos;
    QRectF pir = _pi->boundingRect();
    switch(anchor){
    case TOP_LEFT_ANCHOR:
        sPos = mapToScene(pir.bottomRight());
        break;

    case TOP_RIGHT_ANCHOR:
        sPos = mapToScene(pir.bottomLeft());
        break;

    case BOTTOM_LEFT_ANCHOR:
        sPos = mapToScene(pir.topRight());
        break;

    case BOTTOM_RIGHT_ANCHOR:
        break;
    }

    // re-dimensionnement de l'image ...
    prepareGeometryChange();
    QPixmap px = _px.scaledToWidth(width, Qt::SmoothTransformation);
    _size = px.size(); // met à jour l'attribut contenant la taille de l'image
    _pi->setPixmap(px);
    setTransformOriginPoint(_pi->boundingRect().center()+QPointF(SIZE_RANCHOR/2, SIZE_RANCHOR/2));
    QRectF npir = _pi->boundingRect();

    // récupère la nouvelle position (scène) de l'ancre opposée à celle déplacée, et calcule le décalage avec la position précédente
    // puis déplace l'item
    QPointF sNPos;
    switch(anchor){
    case TOP_LEFT_ANCHOR:
        sNPos = mapToScene(npir.bottomRight());
        setX(x() + sPos.x() - sNPos.x());
        setY(y() + sPos.y() - sNPos.y());
        break;

    case TOP_RIGHT_ANCHOR:
        sNPos = mapToScene(npir.bottomLeft());
        setX(x() + sPos.x() - sNPos.x());
        setY(y() + sPos.y() - sNPos.y());
        break;

    case BOTTOM_LEFT_ANCHOR:
        sNPos = mapToScene(npir.topRight());
        setX(x() + sPos.x() - sNPos.x());
        setY(y() + sPos.y() - sNPos.y());
        break;

    case BOTTOM_RIGHT_ANCHOR:
        break;
    }

    _anchors->setRect(npir); // met à jour les ancres aux nouvelles dimensions
    _ranchor->setPos(npir.center()-QPointF(SIZE_RANCHOR/2, SIZE_RANCHOR/2)); // définit la position de l'ancre de rotation
}

void GraphicsPictureItem::rAnchorUpdated(qreal angle){
    prepareGeometryChange();
    setRotation(angle);
    _anchors->setRotation(angle);
}

void GraphicsPictureItem::setFilepath(const QString filepath) throw (CubException){
    _filepath = filepath;

    QImage img(_filepath, "PNG");
    bool loaded = _px.convertFromImage(img);

    // renvoie une exception si l'image n'a pas été chargée
    if(img.isNull()){
        throw CubException(BRIEF27, TEXT01 + filepath, "GraphicsPictureItem::setFilepath");
    }
    else if(!loaded){
        throw CubException(BRIEF26, TEXT01 + filepath, "GraphicsPictureItem::setFilepath");
    }

    _pi->setPixmap(_px);
    _size = _px.size();

    QRectF rect = _pi->boundingRect();

    _anchors->setRect(rect); // définit le rectangle des ancres
    _ranchor->setPos(rect.center() - QPointF(SIZE_RANCHOR/2, SIZE_RANCHOR/2)); //définit la position de l'ancre de rotation
    setTransformOriginPoint(_pi->boundingRect().center()+QPointF(SIZE_RANCHOR/2, SIZE_RANCHOR/2));
}

QString GraphicsPictureItem::filepath() const{
    return _filepath;
}

void GraphicsPictureItem::setPixmapWidth(int width){// re-dimensionnement de l'image ...
    prepareGeometryChange();
    QPixmap px = _px.scaledToWidth(width, Qt::SmoothTransformation);
    _size = px.size(); // met à jour l'attribut contenant la taille de l'image
    _pi->setPixmap(px);
    setTransformOriginPoint(_pi->boundingRect().center()+QPointF(SIZE_RANCHOR/2, SIZE_RANCHOR/2));
    _anchors->setRect(_pi->boundingRect());
    _ranchor->setPos(_pi->boundingRect().center());
}

int GraphicsPictureItem::pixmapWidth() const{
    return _size.width();
}

void GraphicsPictureItem::setSceneCenter(const QPointF pos){
    QPointF sCenter = mapToScene(boundingRect().center());
    setX(pos.x() - (sCenter.x() - x()));
    setY(pos.y() - (sCenter.y() - y()));
}

QPointF GraphicsPictureItem::sceneCenter() const{
    return mapToScene(boundingRect().center());
}

void GraphicsPictureItem::setFirstAnchorScenePos(const QPointF &pos){
    _firstAnchorItem->setManualPos(pos);
    _firstAnchorItem->setPos(_pi->mapFromScene(pos));
}

QPointF GraphicsPictureItem::firstAnchorScenePos() const{
    return _firstAnchorItem->manualPos();
}

void GraphicsPictureItem::setLastAnchorScenePos(const QPointF &pos){
    _lastAnchorItem->setManualPos(pos);
    _lastAnchorItem->setPos(_pi->mapFromScene(pos));
}

QPointF GraphicsPictureItem::lastAnchorScenePos() const{
    return _lastAnchorItem->manualPos();
}

void GraphicsPictureItem::setFont(const QFont &font){
    _firstAnchorItem->setFont(font);
    _lastAnchorItem->setFont(font);
}

QFont GraphicsPictureItem::font() const{
    return _firstAnchorItem->font();
}

QRectF GraphicsPictureItem::boundingRect() const{
    return childrenBoundingRect();
}

void GraphicsPictureItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    Q_UNUSED(option)
    Q_UNUSED(widget)

    if(isSelected() || _anchors->anchorSelected() || _ranchor->isSelected()){
        QPen pen(QColor(Qt::black));
        pen.setStyle(Qt::DashLine);
        painter->setPen(pen);
        painter->drawRect(_anchors->boundingRect());
        _anchors->setVisible(1);
        _ranchor->setVisible(1);
    }
    else{
        _anchors->setVisible(0);
        _ranchor->setVisible(0);
    }
}

void GraphicsPictureItem::contextMenuEvent(QGraphicsSceneContextMenuEvent *event){

    if(!(flags() & QGraphicsItem::ItemIsMovable)) return; // n'affiche pas le menu si l'élément n'est pas marqué comme déplaçable

    QMenu menu(event->widget());
    menu.addAction((_state == FIRST_ANCHOR) ? ACTION21 : ACTION20); // si la première ancre est définie, propose de définir la dernière sinon propose la première
    QAction * showAction = menu.addAction(ACTION22);
    showAction->setCheckable(true);
    showAction->setChecked((_firstAnchorItem->isVisible()) ? true : false);
    menu.addAction(ACTION08); // supprimer

    QAction * action = menu.exec(event->screenPos());

    if(!action){
        _capture = NOTHING;
        return;
    }
    if(action->text() == ACTION20){
        _capture = FIRST_ANCHOR;
        setCursor(Qt::CrossCursor);
        return;
    }
    if(action->text() == ACTION21){
        _capture = LAST_ANCHOR;
        setCursor(Qt::CrossCursor);
        return;
    }
    if(action->text() == ACTION22){
        if(action->isChecked()){
            _firstAnchorItem->setVisible(true);
            _lastAnchorItem->setVisible(true);
        }
        else{
            _firstAnchorItem->setVisible(false);
            _lastAnchorItem->setVisible(false);
        }
        return;
    }
    if(action->text() == ACTION08){
        delete this;
    }
}

void GraphicsPictureItem::mousePressEvent(QGraphicsSceneMouseEvent *event){

    switch(_capture){

    case FIRST_ANCHOR:
    {
        CoordinatesDialog dialog(event->widget());
        if(dialog.exec() == QDialog::Accepted){
            QPointF gpos = dialog.systemBPosition();
            QPointF pos = event->pos();
            setX(gpos.x() - pos.x());
            setY(gpos.y() + pos.y());
            _firstAnchorItem->setPos(pos);
            _firstAnchorItem->setManualPos(gpos);
            _capture = NOTHING;
            _state = FIRST_ANCHOR;
        }
        break;
    }

    case LAST_ANCHOR:
    {
        CoordinatesDialog dialog(event->widget());
        if(dialog.exec() == QDialog::Accepted){
            QPointF gpos = dialog.systemBPosition();
            QPointF pos = event->pos();

            // calcul de la nouvelle taille de l'image
            qreal lx = pos.x() - _firstAnchorItem->pos().x(); // écart sur l'axe x entre les deux points (coordonnées locales)
            qreal ly = pos.y() - _firstAnchorItem->pos().y(); // écart sur l'axe y
            qreal lz = sqrt(pow(lx, 2) + pow(ly, 2)); // écart entre les deux points (coordonnées locales)

            qreal sx = gpos.x() - _firstAnchorItem->manualPos().x(); // écart sur l'axe x entre les deux points (coordonnées scène)
            qreal sy = gpos.y() - _firstAnchorItem->manualPos().y(); // écart sur l'axe y
            qreal sz = sqrt(pow(sx, 2) + pow(sy, 2)); // écart entre les deux points (coordonnées scène)

            qreal fx = lx * sz / lz; // nouvelle largeur x entre les deux points

            qreal aw = _size.width(); // largeur actuelle de l'image
            qreal ah = _size.height(); // hauteur actuelle de l'image
            qreal fw = fx * aw / lx; // largeur future de l'image
            setPixmapWidth(fw);

            // calcul de la nouvelle position de la première ancre
            QPointF firstAnchor;
            firstAnchor.setX(_firstAnchorItem->pos().x() * fw / aw);
            firstAnchor.setY(_firstAnchorItem->pos().y() * _size.height() / ah);
            _firstAnchorItem->setPos(firstAnchor);

            // positionne la dernière ancre
            _lastAnchorItem->setPos(mapFromScene(gpos));
            _lastAnchorItem->setManualPos(gpos);

            // repositionnement de l'image
            setX(_firstAnchorItem->manualPos().x() - _firstAnchorItem->pos().x());
            setY(_firstAnchorItem->manualPos().y() + _firstAnchorItem->pos().y());

            // rotation de l'image
            qreal pa = acos(fx / sz) * 180 / M_PI;
            qreal ga = acos(sx / sz) * 180 / M_PI;
            qreal angle = ga - pa;

            setTransformOriginPoint(_firstAnchorItem->pos()); // effectue la rotation autour de la première ancre
            setRotation(angle);
            _anchors->setRotation(angle);
            _capture = NOTHING;
            _state = LAST_ANCHOR;
        }
        break;
    }
    case NOTHING:
        break;
    }

    QGraphicsItem::mousePressEvent(event);
}
