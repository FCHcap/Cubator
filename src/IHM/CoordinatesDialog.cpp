#include "CoordinatesDialog.h"
#include "ui_CoordinatesDialog.h"

CoordinatesDialog::CoordinatesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CoordinatesDialog)
{
    ui->setupUi(this);

    ui->comboCoordsA->addItem("Deg Min Sec");
    ui->comboCoordsA->addItem("Deg Min");
    ui->comboCoordsA->addItem("Deg");
    ui->comboCoordsA->addItem("Radian");

    ui->cbTranfEnable->setChecked(0);
    onTransfEnabled(0);

    ui->cbProjectionsSystems->addItems(GeoConvers::listProjections());
}

CoordinatesDialog::~CoordinatesDialog()
{
    delete ui;
}

void CoordinatesDialog::checkToEnableCalculate(){

    if(ui->comboCoordsA->currentText()=="Deg Min Sec" && !ui->editLtD->text().isEmpty() && !ui->editLtDm->text().isEmpty() && !ui->editLtDms->text().isEmpty() &&
                                                      !ui->editLgD->text().isEmpty() && !ui->editLgDm->text().isEmpty() && !ui->editLgDms->text().isEmpty()){
        ui->btCalculate->setEnabled(1);
    }
    else if(ui->comboCoordsA->currentText()=="Deg Min" && !ui->editLtD->text().isEmpty() && !ui->editLtDm->text().isEmpty() &&
                                                       !ui->editLgD->text().isEmpty() && !ui->editLgDm->text().isEmpty()){
        ui->btCalculate->setEnabled(1);
    }
    else if((ui->comboCoordsA->currentText()=="Deg" || ui->comboCoordsA->currentText()=="Rad") && !ui->editLtD->text().isEmpty() && !ui->editLgD->text().isEmpty()){

        ui->btCalculate->setEnabled(1);
    }
    else{
        ui->btCalculate->setEnabled(0);
    }
}

void CoordinatesDialog::setSystemBPosition(QPointF position){
    ui->editXCoordB->setText(QString("%1").arg(position.x(),0,'f',6));
    ui->editYCoordB->setText(QString("%1").arg(position.y(),0,'f',6));
}

QPointF CoordinatesDialog::systemBPosition(){
    QPointF position(ui->editXCoordB->text().toDouble(), ui->editYCoordB->text().toDouble());
    return position;
}

void CoordinatesDialog::onSystemAUnitsChanged(){

    if(ui->comboCoordsA->currentText()=="Deg Min Sec"){
        ui->labelLtD->setVisible(1);
        ui->labelLtDm->setVisible(1);
        ui->labelLtDms->setVisible(1);
        ui->labelLtRad->setVisible(0);
        ui->labelLgD->setVisible(1);
        ui->labelLgDm->setVisible(1);
        ui->labelLgDms->setVisible(1);
        ui->labelLgRad->setVisible(0);
        ui->editLtD->setVisible(1);
        ui->editLtDm->setVisible(1);
        ui->editLtDms->setVisible(1);
        ui->editLgD->setVisible(1);
        ui->editLgDm->setVisible(1);
        ui->editLgDms->setVisible(1);
    }
    else if(ui->comboCoordsA->currentText()=="Deg Min"){
        ui->labelLtD->setVisible(1);
        ui->labelLtDm->setVisible(1);
        ui->labelLtDms->setVisible(0);
        ui->labelLtRad->setVisible(0);
        ui->labelLgD->setVisible(1);
        ui->labelLgDm->setVisible(1);
        ui->labelLgDms->setVisible(0);
        ui->labelLgRad->setVisible(0);
        ui->editLtD->setVisible(1);
        ui->editLtDm->setVisible(1);
        ui->editLtDms->setVisible(0);
        ui->editLgD->setVisible(1);
        ui->editLgDm->setVisible(1);
        ui->editLgDms->setVisible(0);
    }
    else if(ui->comboCoordsA->currentText()=="Deg"){
        ui->labelLtD->setVisible(1);
        ui->labelLtDm->setVisible(0);
        ui->labelLtDms->setVisible(0);
        ui->labelLtRad->setVisible(0);
        ui->labelLgD->setVisible(1);
        ui->labelLgDm->setVisible(0);
        ui->labelLgDms->setVisible(0);
        ui->labelLgRad->setVisible(0);
        ui->editLtD->setVisible(1);
        ui->editLtDm->setVisible(0);
        ui->editLtDms->setVisible(0);
        ui->editLgD->setVisible(1);
        ui->editLgDm->setVisible(0);
        ui->editLgDms->setVisible(0);
    }
    else{
        ui->labelLtD->setVisible(0);
        ui->labelLtDm->setVisible(0);
        ui->labelLtDms->setVisible(0);
        ui->labelLtRad->setVisible(1);
        ui->labelLgD->setVisible(0);
        ui->labelLgDm->setVisible(0);
        ui->labelLgDms->setVisible(0);
        ui->labelLgRad->setVisible(1);
        ui->editLtD->setVisible(1);
        ui->editLtDm->setVisible(0);
        ui->editLtDms->setVisible(0);
        ui->editLgD->setVisible(1);
        ui->editLgDm->setVisible(0);
        ui->editLgDms->setVisible(0);
    }

    checkToEnableCalculate();
}

void CoordinatesDialog::onTransfEnabled(bool enable){
    if(enable){
        ui->cbProjectionsSystems->setEnabled(1);
        ui->labelCoordsA->setEnabled(1);
        ui->comboCoordsA->setEnabled(1);
        ui->labelLtD->setEnabled(1);
        ui->labelLtDm->setEnabled(1);
        ui->labelLtDms->setEnabled(1);
        ui->labelLtRad->setEnabled(1);
        ui->editLtD->setEnabled(1);
        ui->editLtDm->setEnabled(1);
        ui->editLtDms->setEnabled(1);
        ui->labelLgD->setEnabled(1);
        ui->labelLgDm->setEnabled(1);
        ui->labelLgDms->setEnabled(1);
        ui->labelLgRad->setEnabled(1);
        ui->editLgD->setEnabled(1);
        ui->editLgDm->setEnabled(1);
        ui->editLgDms->setEnabled(1);
        ui->editXCoordB->setEnabled(0);
        ui->editYCoordB->setEnabled(0);
    }
    else{
        ui->cbProjectionsSystems->setEnabled(0);
        ui->labelCoordsA->setEnabled(0);
        ui->comboCoordsA->setEnabled(0);
        ui->labelLtD->setEnabled(0);
        ui->labelLtDm->setEnabled(0);
        ui->labelLtDms->setEnabled(0);
        ui->labelLtRad->setEnabled(0);
        ui->editLtD->setEnabled(0);
        ui->editLtDm->setEnabled(0);
        ui->editLtDms->setEnabled(0);
        ui->labelLgD->setEnabled(0);
        ui->labelLgDm->setEnabled(0);
        ui->labelLgDms->setEnabled(0);
        ui->labelLgRad->setEnabled(0);
        ui->editLgD->setEnabled(0);
        ui->editLgDm->setEnabled(0);
        ui->editLgDms->setEnabled(0);
        ui->editXCoordB->setEnabled(1);
        ui->editYCoordB->setEnabled(1);
    }
    checkToEnableCalculate();
}

void CoordinatesDialog::onTextDegChanged(){
    checkToEnableCalculate();
}

void CoordinatesDialog::onTextMinChanged(){
    checkToEnableCalculate();
}

void CoordinatesDialog::onTextSecChanged(){
    checkToEnableCalculate();
}

void CoordinatesDialog::onUpdateCoordsA(){
    checkToEnableCalculate();
}

void CoordinatesDialog::onButtonCalculateClicked(){

    CubGeo geo;

    QString proj = ui->cbProjectionsSystems->currentText();

    GeoData coordsA;
    GeoVecteur vector;

    if(ui->comboCoordsA->currentText()=="Deg Min Sec"){
        int lgd = ui->editLgD->text().toInt();
        int lgdm = ui->editLgDm->text().toInt();
        qreal lgdms = ui->editLgDms->text().toDouble();
        int ltd = ui->editLtD->text().toInt();
        int ltdm = ui->editLtDm->text().toInt();
        qreal ltdms = ui->editLtDms->text().toDouble();

        GeoData coords(ltd, ltdm, ltdms, lgd, lgdm, lgdms);
        coordsA = coords.toRad();
    }
    else if(ui->comboCoordsA->currentText()=="Deg Min"){
        int lgd = ui->editLgD->text().toInt();
        qreal lgdm = ui->editLgDm->text().toDouble();
        int ltd = ui->editLtD->text().toInt();
        qreal ltdm = ui->editLtDm->text().toDouble();

        GeoData coords(ltd, ltdm, lgd, lgdm);
        coordsA = coords.toRad();
    }
    else if(ui->comboCoordsA->currentText()=="Deg"){
        qreal lgd = ui->editLgD->text().toDouble();
        qreal ltd = ui->editLtD->text().toDouble();

        GeoData coords(ltd, lgd);
        coordsA = coords.toRad();
    }
    else{
        qreal lgd = ui->editLgD->text().toDouble();
        qreal ltd = ui->editLtD->text().toDouble();

        coordsA.setCoord(ltd, lgd);
    }
    try{
        vector = geo.WGS84GeoToLambert(coordsA, proj);
    }
    catch (GeoException e){
        ErrorDialog::errorDialog(this, BRIEF13, e.concatenate(), "CoordinatesDialog::onButtonCalculateClicked");
        return;
    }

    setSystemBPosition(QPointF(vector.x(), vector.y()));
}
