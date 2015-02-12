#include "VolumeCalculatorDialog.h"
#include "ui_VolumeCalculatorDialog.h"

VolumeCalculatorDialog::VolumeCalculatorDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VolumeCalculatorDialog)
{
    ui->setupUi(this);

    Data * data = Data::getInstance();
    ui->cbUpSurfaceMesh->addItems(data->tables());
    ui->cbLoSurfaceMesh->addItems(data->tables());

    ui->lProcessName->setEnabled(0);
    ui->progressBar->setEnabled(0);
    ui->lSurface->setEnabled(0);
    ui->lVolume->setEnabled(0);

    _volumeItem = 0;
    _error = 0;
    _calculated = 0;
}

VolumeCalculatorDialog::~VolumeCalculatorDialog()
{
    delete ui;
}

void VolumeCalculatorDialog::setVolumeItem(GraphicsVolumeItem *item){
    _volumeItem = item;
}

bool VolumeCalculatorDialog::error() const{
    return _error;
}

bool VolumeCalculatorDialog::calculated() const{
    return _calculated;
}

void VolumeCalculatorDialog::calculates(){

    ui->pbCalculates->setEnabled(0);

    VolumeCalculatorProcess * process = new VolumeCalculatorProcess;
    //QThread * thread = new QThread;

    if(ui->rbUpSurfaceMesh->isChecked()){
        process->setUpMesh(ui->cbUpSurfaceMesh->currentText());
    }
    else{
        process->setUpLevel(ui->dsUpSurfacePlan->value());
    }

    if(ui->rbLoSurfaceMesh->isChecked()){
        process->setLoMesh(ui->cbLoSurfaceMesh->currentText());
    }
    else{
        process->setLoLevel(ui->dsLoSurfacePlan->value());
    }

    //process->connectToThread(thread);
    process->setVolumeItem(_volumeItem);

    connect(process, SIGNAL(exceptionLaunched(CubException)), this, SLOT(showError(CubException)));
    connect(process, SIGNAL(warningMessageLaunched(CubException)), this, SLOT(showWarning(CubException)));
    connect(process, SIGNAL(levelUpdated(int)), ui->progressBar, SLOT(setValue(int)));
    connect(process, SIGNAL(processNameUpdated(QString)), ui->lProcessName, SLOT(setText(QString)));
    connect(process, SIGNAL(surfaceUpdated(qreal)), this, SLOT(setSurface(qreal)));
    connect(process, SIGNAL(volumeUpdated(qreal)), this, SLOT(setVolume(qreal)));
    connect(process, SIGNAL(finished()), this, SLOT(finish()));

    //process->moveToThread(thread);

    ui->lProcessName->setEnabled(1);
    ui->progressBar->setEnabled(1);

    //thread->start();
    process->start();

}

void VolumeCalculatorDialog::showError(CubException e){
    ErrorDialog::errorDialog(this, e);
    _error = 1;
}

void VolumeCalculatorDialog::showWarning(CubException e){
    ErrorDialog::errorDialog(this, e);
}

void VolumeCalculatorDialog::setSurface(qreal surface){
    ui->lSurface->setText(TEXT18 + QString::number(surface) + " m2");
    ui->lSurface->setEnabled(1);
    _calculated = 1;
}

void VolumeCalculatorDialog::setVolume(qreal volume){
    ui->lVolume->setText(TEXT19 + QString::number(volume) + " m3");
    ui->lVolume->setEnabled(1);
    _calculated = 1;
}

void VolumeCalculatorDialog::finish(){
    if(!_calculated) ui->lProcessName->setText(PROCESS11);
    else ui->lProcessName->setText(PROCESS00);
    ui->progressBar->setValue(100);
    ui->lProcessName->setEnabled(0);
    ui->progressBar->setEnabled(0);
}
