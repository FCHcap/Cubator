#include "GraphicsTextDialog.h"

GraphicsTextDialog::GraphicsTextDialog(QWidget *parent) :
    QDialog(parent)
{
    setWindowFlags(Qt::Popup);
    setMouseTracking(true);

    _lineEdit = new QLineEdit(this);
    _lineEdit->setMinimumSize(200, 30);
    _lineEdit->setFocus();
}

void GraphicsTextDialog::setText(QString text){
    _lineEdit->setText(text);
}

QString GraphicsTextDialog::text(){
    return _lineEdit->text();
}

void GraphicsTextDialog::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Return){
        accept();
    }

    else if(event->key() == Qt::Key_Escape){
        reject();
    }
}

bool GraphicsTextDialog::eventFilter(QObject * obj, QEvent * event){

    if(event->type() == QEvent::KeyPress){
        QKeyEvent *kevent = static_cast<QKeyEvent*>(event);
        if(kevent->key() == Qt::Key_Return){
            done(0);
            return true;
        }
    }

    return obj->eventFilter(obj, event);
}
