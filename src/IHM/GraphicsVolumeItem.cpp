#include "GraphicsVolumeItem.h"

// QT
#include <QMenu>
#include <QGraphicsSceneContextMenuEvent>
#include <QColorDialog>
#include <QGraphicsScene>
#include <QInputDialog>
#include <QFontDialog>

GraphicsVolumeItem::GraphicsVolumeItem(QGraphicsItem * parent) : GraphicsPolylineItem(parent)
{
    _surface = DBL_MIN;
    _volume = DBL_MIN;

    _meshColor.setRgb(0, 0, 0);

    _textItem.setParentItem(this);
    _textItem.setFlag(QGraphicsItem::ItemIgnoresTransformations);
    _textItem.setVisible(0);

    _meshVisible = 0;

    _pen.setStyle(Qt::DashDotLine);
    _pen.setColor(QColor(255,0,127));
    _pen.setWidth(3);

    QFont font = _textItem.font();
    font.setPointSize(4);
    _textItem.setFont(font);
    _textItem.setDefaultTextColor(QColor(255,0,127));
}

GraphicsVolumeItem::~GraphicsVolumeItem(){

}

int GraphicsVolumeItem::type() const{
    return Type;
}

QList<QRect> GraphicsVolumeItem::rects() const{
    return _rectangles;
}

qreal GraphicsVolumeItem::surface() const{
    return _surface;
}

qreal GraphicsVolumeItem::volume() const{
    return _volume;
}

void GraphicsVolumeItem::setFont(const QFont &font){
    _textItem.setFont(font);
    updateTextItem();
}

QFont GraphicsVolumeItem::font() const{
    return _textItem.font();
}

void GraphicsVolumeItem::setPen(const QPen &pen){
    _pen = pen;
    _pen.setStyle(Qt::DashDotLine);
}

void GraphicsVolumeItem::setMeshColor(const QColor &color){
    _meshColor = color;
    _pen.setColor(_meshColor);
}

QColor GraphicsVolumeItem::meshColor() const{
    return _meshColor;
}

void GraphicsVolumeItem::setTextColor(const QColor &color){
    _textItem.setDefaultTextColor(color);
}

QColor GraphicsVolumeItem::textColor() const{
    return _textItem.defaultTextColor();
}

void GraphicsVolumeItem::setMeshVisible(bool visible){
    _meshVisible = visible;
}

bool GraphicsVolumeItem::meshVisible() const{
    return _meshVisible;
}

void GraphicsVolumeItem::setTextVisible(bool visible){
    _textItem.setVisible(visible);
}

bool GraphicsVolumeItem::textVisible() const{
    return _textItem.isVisible();
}

void GraphicsVolumeItem::setTextTransform(const QTransform &transform){
    _textItem.setTransform(transform);
}

QTransform GraphicsVolumeItem::textTransform() const{
    return _textItem.transform();
}

void GraphicsVolumeItem::updateRects(){

    _rectangles.clear();

    QRectF rectf = boundingRect();
    QRect rect(rectf.topLeft().toPoint(), rectf.bottomRight().toPoint());

    for(int i=rect.x(), ii=0; ii<rect.width(); i++, ii++){
        for(int j=rect.y(), jj=0; jj<rect.height(); j++, jj++){
            QRect r(QPoint(i, j), QSize(1, 1));
            if(this->polylineContains(r)) _rectangles.append(r);
        }
    }
    updateTextItem();
}

void GraphicsVolumeItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

    if(_meshVisible){
        QPen pen = _pen;
        pen.setColor(_meshColor);
        pen.setWidthF(0.1);
        painter->setPen(pen);
        painter->setBrush(Qt::NoBrush);
        foreach(QRect rect, _rectangles){
            painter->drawRect(rect);
        }
    }

    GraphicsPolylineItem::paint(painter, option, widget);
}

void GraphicsVolumeItem::contextMenuEvent(QGraphicsSceneContextMenuEvent *event){

    if(!(flags() & QGraphicsItem::ItemIsSelectable)) return; // n'affiche pas le menu si l'élément n'est pas marqué comme sélectionnable

    QMenu menu;
    QAction * aShowText = menu.addAction(ACTION11); // Show text
    QAction * aShowMesh = menu.addAction(ACTION12); // Show mesh
    menu.addAction(ACTION13); // Color text
    menu.addAction(ACTION14); // Color mesh
    menu.addAction(ACTION15); // Line thickness
    menu.addAction(ACTION10); // Select font
    menu.addAction(ACTION08); // Delete

    aShowText->setCheckable(1);
    aShowText->setChecked(_textItem.isVisible());

    aShowMesh->setCheckable(1);
    aShowMesh->setChecked(_meshVisible);

    QAction * action = menu.exec(event->screenPos());
    if(!action) return;

    if(action->text() == ACTION11){
        _textItem.setVisible(aShowText->isChecked());
    }
    else if(action->text() == ACTION12){
        if(!_meshVisible) updateRects();
        _meshVisible = aShowMesh->isChecked();
    }
    else if(action->text() == ACTION13){
        _textItem.setDefaultTextColor(
                    QColorDialog::getColor(
                        _textItem.defaultTextColor(),
                        (QWidget *) this->window(),
                        //static_cast<QWidget*> (scene()->views().at(0)),
                        MESSAGE08
                        )
                    );
    }
    else if(action->text() == ACTION14){
        _meshColor = QColorDialog::getColor(
                    _meshColor,
                    (QWidget *) this->window(),
                    //static_cast<QWidget*> (scene()->views().at(0)),
                    MESSAGE09
                    );
        _pen.setColor(_meshColor);
    }
    else if(action->text() == ACTION15){
        _pen.setWidth(
                    QInputDialog::getInt(
                        (QWidget *) this->window(),
                        //static_cast<QWidget*> (scene()->views().at(0)),
                        MESSAGE10, TEXT13,
                        _pen.width(),
                        1,
                        10
                        )
                    );
    }
    else if(action->text() == ACTION10){
        bool ok = 0;
        QFont font = QFontDialog::getFont(
                    &ok,
                    _textItem.font(),
                    (QWidget *) this->window()
                    //static_cast<QWidget*> (scene()->views().at(0))
                    );
        if(ok) {
            _textItem.setFont(font);
            emit updateTextItem();
        }
    }
    else if(action->text() == ACTION08){
        delete this;
        return;
    }

    update(boundingRect().united(childrenBoundingRect()));
}

void GraphicsVolumeItem::updateTextItem(){
    QString text;
    text.append(TEXT18 + QString::number(_surface, 'f', 4) + " m2");
    if(_volume > DBL_MIN)
        text.append("<br />" + TEXT19 + QString::number(_volume, 'f', 4) + " m3");
    _textItem.setHtml(text);

    QRectF rect = boundingRect();
    _textItem.adjustSize();
    _textItem.setPos(rect.center().x() - _textItem.boundingRect().width()/2, rect.center().y() + _textItem.boundingRect().height()/2);
}

void GraphicsVolumeItem::addRect(const QRect &rect){
    if(!_rect.contains(rect)){
        _rect = _rect.united(rect);
    }
    _rectangles.append(rect);
    update(boundingRect());
}

void GraphicsVolumeItem::addPoint(const QPointF &point){
    GraphicsPolylineItem::addPoint(point);
    update(boundingRect());
}

void GraphicsVolumeItem::setSurface(qreal surface){
    _surface = surface;
    _textItem.setVisible(1);
    updateTextItem();
}

void GraphicsVolumeItem::setVolume(qreal volume){
    _volume = volume;
    _textItem.setVisible(1);
    updateTextItem();
}
