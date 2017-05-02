#include "LayerToTableDialog.h"
#include "ui_LayerToTableDialog.h"

LayerToTableDialog::LayerToTableDialog(QWidget *parent, GraphicsMap *map) :
    QDialog(parent),
    ui(new Ui::LayerToTableDialog)
{
    ui->setupUi(this);
    ui->progressBar->setVisible(false);
    ui->lProcess->setVisible(false);

    this->_data = Data::getInstance();
    this->_map = map;
    this->_layers = this->_map->layers();
    this->_tables = this->_data->tables();

    if(!this->_layers.length() || !this->_tables.length()) {
        ui->pbConvert->setEnabled(false);
    }

    ui->cbLayer->addItems(this->_layers);
    ui->cbTable->addItems(this->_tables);

    connect(ui->pbConvert, SIGNAL(clicked()), this, SLOT(onConvertEvent()));
}

LayerToTableDialog::~LayerToTableDialog()
{
    delete ui;
}

void LayerToTableDialog::setGraphicsMap(GraphicsMap *map) {
    this->_map = map;
}

GraphicsMap * LayerToTableDialog::graphicsMap() {
    return this->_map;
}

void LayerToTableDialog::onConvertEvent() {
    ui->pbConvert->setEnabled(false);

    try {
        LayerToTableProcess *proc = new LayerToTableProcess();
        proc->setGraphicsMap(_map);
        proc->setLayerName(this->ui->cbLayer->currentText());
        proc->setTableName(this->ui->cbTable->currentText());
        proc->setAppendToTable(this->ui->cbAppendToTable->isChecked());

        proc->connectToProgressBar(ui->progressBar);

        connect(proc, SIGNAL(processNameUpdated(QString)), this->ui->lProcess, SLOT(setText(QString)));
        connect(proc, SIGNAL(finished()), this, SLOT(onFinishedEvent()));

        proc->start();
    } catch (const CubException &e) {
        ErrorDialog::errorDialog(this, e);
    }
}

void LayerToTableDialog::onFinishedEvent() {
    ui->pbConvert->setEnabled(true);
}

