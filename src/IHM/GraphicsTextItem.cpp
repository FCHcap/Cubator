#include "GraphicsTextItem.h"

// QT
#include <QMenu>
#include <QColorDialog>
#include <QGraphicsScene>
#include <QFontDialog>
#include <QInputDialog>
#include <QObject>

int GraphicsTextItem::type() const{
    return Type;
}

GraphicsTextItem::GraphicsTextItem(QGraphicsItem * parent) :
    QGraphicsSimpleTextItem(parent), GraphicsItem(this)
{
    setFlag(QGraphicsItem::ItemIgnoresTransformations);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges);
}

void GraphicsTextItem::edit(QGraphicsSceneMouseEvent *event){
    GraphicsTextDialog dialog(event->widget());
    dialog.setText(text());
    dialog.move(event->screenPos());
    if(dialog.exec() == QDialog::Accepted){
        setText(dialog.text());
        update(boundingRect());
        itemEdited();
    }
}

void GraphicsTextItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event){
    edit(event);
}

void GraphicsTextItem::contextMenuEvent(QGraphicsSceneContextMenuEvent *event){

    if(!(flags() & QGraphicsItem::ItemIsMovable)) return; // n'affiche pas le menu si l'élément n'est pas marqué comme déplaçable

    if(isSelected()) setSelected(true);

    QMenu menu;
    menu.addAction(ACTION09); // Color
    menu.addAction(ACTION10); // Font
    menu.addAction(ACTION07); // Rotation
    menu.addAction(ACTION08); // Delete

    QAction * action = menu.exec(event->screenPos());

    if(!action) return;

    if(action->text() == ACTION09){
        QColor color = QColorDialog::getColor(
                    brush().color(),
                    (QWidget *) this->window()
                    );

        if(color.isValid()){
            setBrush(QBrush(color));
        }
    }

    else if(action->text() == ACTION10){
        bool ok;
        QFont font = QFontDialog::getFont(
                    &ok,
                    this->font(),
                    (QWidget *) this->window()
                    );

        if(ok == true){
            setFont(font);
        }
    }

    else if(action->text() == ACTION07){
        this->setRotation(
                    QInputDialog::getDouble(
                        (QWidget *) this->window(),
                        TITLE07,
                        TEXT10,
                        this->rotation(),
                        0.0,
                        360.0)
                    );
    }

    else if(action->text() == ACTION08){
        delete this;
    }
}

QVariant GraphicsTextItem::itemChange(GraphicsItemChange change, const QVariant &value){
    if(change == QGraphicsItem::ItemPositionChange || \
            change == QGraphicsItem::ItemRotationChange)
                itemEdited();
    return QGraphicsSimpleTextItem::itemChange(change, value);
}
