#include "InputIntToStringDialog.h"
#include "ui_InputIntToStringDialog.h"

InputIntToStringDialog::InputIntToStringDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InputIntToStringDialog)
{
    ui->setupUi(this);
}

InputIntToStringDialog::~InputIntToStringDialog()
{
    delete ui;
}

void InputIntToStringDialog::setLayers(const QMap<QString, int> &layers){
    _layers = layers;
    ui->cbLayers->addItems(layers.keys());
    ui->cbLayers->setCurrentIndex(0);
}

QMap<QString, int> InputIntToStringDialog::layers() const{
    return _layers;
}

void InputIntToStringDialog::setDescription(const QString &description){
    ui->lLayers->setText(description);
}

void InputIntToStringDialog::setRange(const int &min, const int &max){
    ui->isLayers->setRange(min, max);
}

void InputIntToStringDialog::setStep(const int &step) {
    ui->isLayers->setSingleStep(10);
}

void InputIntToStringDialog::accept(){
    _layers.insert(ui->cbLayers->currentText(), ui->isLayers->value());
    QDialog::accept();
}

void InputIntToStringDialog::changeLayer(QString layer){
    if(!_lastLayer.isEmpty()){
        _layers.insert(_lastLayer, ui->isLayers->value());
    }
    ui->isLayers->setValue(_layers.value(layer));
    _lastLayer = layer;
}


