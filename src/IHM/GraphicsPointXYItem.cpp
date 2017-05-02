#include "GraphicsPointXYItem.h"

// QT
#include <QMenu>
#include <QColorDialog>
#include <QGraphicsScene>
#include <QFontDialog>

int GraphicsPointXYItem::type() const{
    return Type;
}

GraphicsPointXYItem::GraphicsPointXYItem(QGraphicsItem *parent) :
    QGraphicsEllipseItem(parent),
    _text(this)
{
    setAcceptDrops(1);
    _text.setTransform(QTransform::fromScale(1.0, -1.0));
    _tCoords = GPS;
    _tPos = RIGHT;
}

void GraphicsPointXYItem::setFont(const QFont &font){
    _text.setFont(font);
}

QFont GraphicsPointXYItem::font() const{
    return _text.font();
}

void GraphicsPointXYItem::setPen(const QPen &pen){
    QGraphicsEllipseItem::setPen(pen);
    QPen p = pen;
    p.setWidth(1);
    _text.setPen(p);
}

QPen GraphicsPointXYItem::pen() const{
    return QGraphicsEllipseItem::pen();
}

void GraphicsPointXYItem::setBrush(const QBrush &brush){
    QBrush b = brush;
    b.setStyle(Qt::SolidPattern);
    QGraphicsEllipseItem::setBrush(b);
    _text.setBrush(b);
}

QBrush GraphicsPointXYItem::brush() const{
    return QGraphicsEllipseItem::brush();
}

void GraphicsPointXYItem::setTransform(const QTransform &matrix, bool combine){

    QGraphicsEllipseItem::setTransform(matrix, combine);
    _text.setTransform(matrix * QTransform::fromScale(1.0, -1.0));
    updateTextItem();
}

void GraphicsPointXYItem::setPos(const QPointF &pos){
    QGraphicsEllipseItem::setPos(pos); // Positionne l'élément
    QGraphicsEllipseItem::setRect(-1, -1, 2, 2); // Définit la taille du point
    updateTextItem();
}

QPointF GraphicsPointXYItem::pos() const{
    return QGraphicsEllipseItem::pos();
}

void GraphicsPointXYItem::setPosition(Position position){
    _tPos = position;
    updateTextItem();
}

GraphicsPointXYItem::Position GraphicsPointXYItem::position() const{
    return _tPos;
}

void GraphicsPointXYItem::setManualPos(QPointF position){
    _mPos = position;
    updateTextItem();
}

QPointF GraphicsPointXYItem::manualPos() const{
    return _mPos;
}

void GraphicsPointXYItem::setPositionFromString(QString position){
    if(position == SLEFT) _tPos = LEFT;
    else _tPos = RIGHT;
    updateTextItem();
}

QString GraphicsPointXYItem::positionToString() const{
    if(_tPos == LEFT) return SLEFT;
    return SRIGHT;
}

void GraphicsPointXYItem::setTypeCoords(TCoords coords){
    _tCoords = coords;
    updateTextItem();
}

GraphicsPointXYItem::TCoords GraphicsPointXYItem::typeCoords() const{
    return _tCoords;
}

void GraphicsPointXYItem::setTypeCoordsFromString(QString coords){
    if(coords == SGPS) _tCoords = GPS;
    else _tCoords = CART;
    updateTextItem();
}

QString GraphicsPointXYItem::typeCoordsToString() const{
    if(_tCoords == GPS) return SGPS;
    return SCART;
}

QRectF GraphicsPointXYItem::boundingRect() const{
    return childrenBoundingRect().united(QGraphicsEllipseItem::boundingRect());
}

void GraphicsPointXYItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    Q_UNUSED(option)
    Q_UNUSED(widget)

    if(isSelected()){
        QPen pen = QPen(Qt::black);
        pen.setStyle(Qt::DashLine);
        painter->setPen(pen);
        painter->setBrush(QBrush());
        painter->drawRect(boundingRect());
    }

    QGraphicsEllipseItem::paint(painter, option, widget);
}

void GraphicsPointXYItem::contextMenuEvent(QGraphicsSceneContextMenuEvent *event){

    QMenu menu;
    QAction *aShowText = menu.addAction(ACTION11); // Afficher texte
    menu.addAction(ACTION09); // Sélectionner couleur
    menu.addAction(ACTION10); // Sélectionner police
    if(_tPos == RIGHT)
        menu.addAction(ACTION16); // Déplacer à gauche
    else
        menu.addAction(ACTION17); // Déplacer à droite
    if(_tCoords == GPS)
        menu.addAction(ACTION18); // Convertir en coordonnées carto
    else
        menu.addAction(ACTION19); // Convertir en coordonnées GPS
    menu.addAction(ACTION08); // Supprimer

    aShowText->setCheckable(1);
    aShowText->setChecked(_text.isVisible());

    QAction * action = menu.exec(event->screenPos());

    if(action == aShowText){
        _text.setVisible(action->isChecked());
    }
    else if(action->text() == ACTION09){
        QColor color = QColorDialog::getColor(
                    pen().color(),
                    (QWidget*) this->window(),
                    MESSAGE08
                    );

        // Paramètre le crayon
        QPen p = pen();
        p.setColor(color);
        setPen(p);

        // Paramètre le pinceau
        QBrush brush(color);
        setBrush(brush);
    }
    else if(action->text() == ACTION10){
        bool ok = 0;
        QFont f = QFontDialog::getFont(
                    &ok,
                    font(),
                    (QWidget*) this->window()
                    );
        if(ok) {
            setFont(f);
        }
    }
    else if(action->text() == ACTION16){
        _tPos = LEFT;
        updateTextItem();
    }
    else if(action->text() == ACTION17){
        _tPos = RIGHT;
        updateTextItem();
    }
    else if(action->text() == ACTION18){
        _tCoords = CART;
        updateTextItem();
    }
    else if(action->text() == ACTION19){
        _tCoords = GPS;
        updateTextItem();
    }
    else if(action->text() == ACTION08){
        delete this;
    }
}

void GraphicsPointXYItem::updateCoordsGPS(){
    try{
        Settings * settings = Settings::getInstance();
        SettingsStatusBar ssb = settings->settingsStatusBar();

        CubGeo geo;
        GeoData data = geo.lambertToWGS84Geo(GeoVecteur(pos().x(), pos().y(), 0), ssb.projection());
        data=data.toFormat(ssb.gpsFormat());

        _tGPS="Lt : " + data.getLatitude() + '\n' + "Lg : " + data.getLongitude();
    }
    catch(GeoException e){
        qDebug() << e.concatenate();
    }
}

void GraphicsPointXYItem::updateCoordsCart(){
    _tCart="X : " + QString::number(pos().x(), 'f', 4) + '\n' + "Y : " + QString::number(pos().y(), 'f', 4);
}

void GraphicsPointXYItem::updateCoordsManual(){
    _tMan="X : " + QString::number(_mPos.x(), 'f', 4) + '\n' + "Y : " + QString::number(_mPos.y(), 'f', 4);
}

void GraphicsPointXYItem::updateTextItem(){

    switch(_tCoords){
    case GPS:
        updateCoordsGPS();
        _text.setText(_tGPS);
        break;
    case CART:
        updateCoordsCart();
        _text.setText(_tCart);
        break;
    case MANUAL:
        updateCoordsManual();
        _text.setText(_tMan);
        break;
    }

    QRectF r = _text.boundingRect();
    switch(_tPos){
    case RIGHT:
        _text.setPos(QPointF(7, 0));
        break;
    case LEFT:
        _text.setPos(QPointF(-r.width()-7, 0));
        break;
    }
}

void GraphicsPointXYItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    QGraphicsEllipseItem::mouseMoveEvent(event);

    if(event->buttons() | Qt::LeftButton){
        updateTextItem();

        // Signale au calque qu'il y a eu une modification
        QGraphicsItem * parent = parentItem();
        if(!parent) return;
        if(parent->type() == GraphicsMapLayer::Type){
            GraphicsMapLayer * layer = qgraphicsitem_cast<GraphicsMapLayer*>(parent);
            layer->itemEdited();
        }
    }
}
