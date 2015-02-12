#include "GpsWidget.h"

// QT
#include <QVBoxLayout>

GpsWidget::GpsWidget(QWidget *parent) :
    QWidget(parent)
{
    QVBoxLayout * layout = new QVBoxLayout(this);
    _lX = new QLabel(this);
    _lY = new QLabel(this);

    layout->addWidget(_lX);
    layout->addWidget(_lY);
}

void GpsWidget::updatePosition(QPointF position){

    QString sColor = "#00FF00";
    QString sx = QString("<font color = \"%1\">X : %2</font>").arg(sColor).arg(position.x(), 0, 'f', 4);
    QString sy = QString("<font color = \"%1\">Y : %2</font>").arg(sColor).arg(position.y(), 0, 'f', 4);
    _lX->setText(sx);
    _lY->setText(sy);
}

void GpsWidget::connect(bool connected){
    setVisible(connected);
}

void GpsWidget::timeout(){
    QString sx = "<font color = \"#FF0000\">X : "+TEXT16+"</font>";
    QString sy = "<font color = \"#FF0000\">Y : "+TEXT16+"</font>";
    _lX->setText(sx);
    _lY->setText(sy);
}

void GpsWidget::inconsistentData(){
    QString sx = "<font color = \"#FF6600\">X : "+TEXT17+"</font>";
    QString sy = "<font color = \"#FF6600\">Y : "+TEXT17+"</font>";
    _lX->setText(sx);
    _lY->setText(sy);
}
