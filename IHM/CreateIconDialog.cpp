#include "CreateIconDialog.h"
#include "ui_CreateIconDialog.h"

// QT
#include <QInputDialog>

CreateIconDialog::CreateIconDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateIconDialog)
{
    ui->setupUi(this);
    ui->labelX->setText("X : Non-defini");
    ui->labelY->setText("Y : Non-defini");

    setPosition(QPointF());
    setDate(QDate::currentDate());
    setRotation(0);
}

CreateIconDialog::~CreateIconDialog()
{
    delete ui;
}

void CreateIconDialog::setPosition(QPointF position){
    _position=position;
    ui->labelX->setText("X : " + QString::number(_position.x(), 'f', 6));
    ui->labelY->setText("Y : " + QString::number(_position.y(), 'f', 6));
}

void CreateIconDialog::setRotation(int angle){
    _angle=angle;
    ui->labelRotation->setText(TEXT10 + QString::number(_angle)+QChar(0x00B0));
}

void CreateIconDialog::setDate(QDate date){
    _date=date;
    ui->labelDate->setText(TEXT11 + _date.toString("dd/MM/yyyy"));
}

void CreateIconDialog::setSystem(QString system){
    _system=system;
}

QPointF CreateIconDialog::position(){
    return _position;
}

int CreateIconDialog::rotation(){
    return _angle;
}

QDate CreateIconDialog::date(){
    return _date;
}

QString CreateIconDialog::system(){
    return _system;
}

void CreateIconDialog::onButtonCoordsEdit(){
    CoordinatesDialog dialog(this);

    if(dialog.exec() == QDialog::Accepted){
        setPosition(dialog.systemBPosition());
    }
}

void CreateIconDialog::onButtonDateEdit(){
    DateDialog dialog(this, _date);

    if(dialog.exec()==Accepted){
        setDate(dialog.date());
    }

}

void CreateIconDialog::onButtonRotationEdit(){

    _angle = QInputDialog::getInt(this, TITLE04, MESSAGE01, _angle, -360, 360);
    setRotation(_angle);
}

