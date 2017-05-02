#include "TableToLayerDialog.h"
#include "ui_TableToLayerDialog.h"

TableToLayerDialog::TableToLayerDialog(QWidget *parent, GraphicsMap *map) :
    QDialog(parent),
    ui(new Ui::TableToLayerDialog)
{
    ui->setupUi(this);
    ui->progressBar->setVisible(false);
    ui->lProcess->setVisible(false);

    this->_map = map;
    this->_layers = this->_map->layers();

    this->_data = Data::getInstance();
    this->_tables = this->_data->tables();

    if(!this->_layers.length() || !this->_tables.length()) {
        ui->pbConvert->setEnabled(false);
    }

    ui->cbLayer->addItems(this->_layers);
    ui->cbTable->addItems(this->_tables);

    connect(ui->pbConvert, SIGNAL(clicked()), this, SLOT(onConvertEvent()));
}

TableToLayerDialog::~TableToLayerDialog()
{
    delete ui;
}

void TableToLayerDialog::setGraphicsMap(GraphicsMap *map) {
    this->_map = map;
}

GraphicsMap * TableToLayerDialog::graphicsMap() {
    return this->_map;
}

void TableToLayerDialog::onConvertEvent() {
    ui->pbConvert->setEnabled(false);
    loadTable();
}

void TableToLayerDialog::loadTable  () {
    ui->progressBar->setValue(0);
    ui->lProcess->setText("");
    ui->progressBar->setVisible(true);
    ui->lProcess->setVisible(true);
    _vertices.clear();

    try {
        VerticesReaderProcess *vrproc = new VerticesReaderProcess(Data::vectorFileName(ui->cbTable->currentText()));
        vrproc->connectToProgressBar(ui->progressBar);
        vrproc->setVerticesList(_vertices);

        ui->lProcess->setText(PROCESS21);

        connect(vrproc, SIGNAL(finished()), this, SLOT(generateGraphicsEvent()));

        vrproc->start();
    } catch (const CubException &e) {
        ErrorDialog::errorDialog(this, e);
    }
}

void TableToLayerDialog::generateGraphicsEvent() {
    ui->progressBar->setValue(0);
    ui->lProcess->setText("");

    try {
        VerticesLoadingProcess *vlproc = new VerticesLoadingProcess();
        vlproc->setVertices(_vertices, true);
        vlproc->connectToProgressBar(ui->progressBar);

        connect(vlproc, SIGNAL(processNameUpdated(QString)), ui->lProcess, SLOT(setText(QString)));
        connect(vlproc, SIGNAL(verticesItemUpdated(QGraphicsItemGroup*)), this, SLOT(graphicsGeneratedEvent(QGraphicsItemGroup*)));

        vlproc->start();
    } catch (const CubException &e) {
        ErrorDialog::errorDialog(this, e);
    }
}

void TableToLayerDialog::graphicsGeneratedEvent(QGraphicsItemGroup *verticesItem) {

    GraphicsMapLayer *layer = this->_map->layerItem(ui->cbLayer->currentText());
    layer->addToLayer(verticesItem);

    ui->progressBar->setEnabled(false);
    ui->lProcess->setText("Completed");
    ui->pbConvert->setEnabled(true);
}

