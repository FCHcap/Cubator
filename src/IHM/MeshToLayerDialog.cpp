#include "MeshToLayerDialog.h"
#include "ui_MeshToLayerDialog.h"

MeshToLayerDialog::MeshToLayerDialog(QWidget *parent, GraphicsMap *map) :
    QDialog(parent),
    ui(new Ui::MeshToLayerDialog)
{
    ui->setupUi(this);
    ui->progressBar->setVisible(false);
    ui->lProcess->setVisible(false);

    _map = map;
    _layers = _map->layers();

    _data = Data::getInstance();
    _tables = _data->tables();

    if(!_layers.length() || !_tables.length()) {
        ui->pbTransfer->setEnabled(false);
    }

    ui->cbLayer->addItems(_layers);
    ui->cbMesh->addItems(_tables);

    connect(ui->pbTransfer, SIGNAL(clicked()), this, SLOT(onTransferEvent()));
    connect(this, SIGNAL(startProcess()), this, SLOT(readVerticesEvent()));
}

MeshToLayerDialog::~MeshToLayerDialog()
{
    delete ui;
}

void MeshToLayerDialog::onTransferEvent() {
    ui->pbTransfer->setEnabled(false);
    ui->lProcess->setVisible(true);
    ui->progressBar->setVisible(true);

    GraphicsMapLayer *layer = _map->layerItem(ui->cbLayer->currentText());
    _item = new GraphicsMeshItem(layer);

    emit startProcess();
}

void MeshToLayerDialog::readVerticesEvent() {
    VerticesReaderProcess *proc = new VerticesReaderProcess;
    proc->setFilename(Data::vectorFileName(ui->cbMesh->currentText()));
    proc->setVerticesList(_vertices);
    proc->connectToProgressBar(ui->progressBar);

    connect(proc, SIGNAL(processNameUpdated(QString)), ui->lProcess, SLOT(setText(QString)));
    connect(proc, SIGNAL(exceptionLaunched(CubException)), this, SLOT(showException(CubException)));
    connect(proc, SIGNAL(finished()), this, SLOT(readTrianglesEvent()));

    proc->start();
}

void MeshToLayerDialog::readTrianglesEvent() {
    TrianglesReaderProcess *proc = new TrianglesReaderProcess;
    proc->setFilename(Data::triangleFilename(ui->cbMesh->currentText()));
    proc->setTrianglesList(*_vertices.triangles());
    proc->connectToProgressBar(ui->progressBar);

    connect(proc, SIGNAL(processNameUpdated(QString)), ui->lProcess, SLOT(setText(QString)));
    connect(proc, SIGNAL(exceptionLaunched(CubException)), this, SLOT(showException(CubException)));
    connect(proc, SIGNAL(finished()), this, SLOT(loadVerticesEvent()));

    proc->start();
}

void MeshToLayerDialog::loadVerticesEvent() {
    VerticesLoadingProcess *proc = new VerticesLoadingProcess;
    proc->setVertices(_vertices, false);
    proc->connectToProgressBar(ui->progressBar);

    connect(proc, SIGNAL(processNameUpdated(QString)), ui->lProcess, SLOT(setText(QString)));
    connect(proc, SIGNAL(exceptionLaunched(CubException)), this, SLOT(showException(CubException)));
    connect(proc, SIGNAL(verticesItemUpdated(QGraphicsItemGroup*)), this, SLOT(setVerticesItem(QGraphicsItemGroup*)));
    connect(proc, SIGNAL(finished()), this, SLOT(loadTrianglesEvent()));

    proc->start();
}

void MeshToLayerDialog::loadTrianglesEvent() {
    TrianglesItemLoadingProcess *proc = new TrianglesItemLoadingProcess;
    proc->setVertices(_vertices);
    proc->connectToProgressBar(ui->progressBar);

    connect(proc, SIGNAL(processNameUpdated(QString)), ui->lProcess, SLOT(setText(QString)));
    connect(proc, SIGNAL(exceptionLaunched(CubException)), this, SLOT(showException(CubException)));
    connect(proc, SIGNAL(trianglesItemUpdated(QGraphicsItemGroup*)), this, SLOT(setTrianglesItem(QGraphicsItemGroup*)));
    connect(proc, SIGNAL(finished()), this, SLOT(onFinishedEvent()));

    proc->start();
}

void MeshToLayerDialog::showException(CubException e){
    ErrorDialog::errorDialog(this, e);
}

void MeshToLayerDialog::setVerticesItem(QGraphicsItemGroup *group) {
    _item->setVertices(group);
}

void MeshToLayerDialog::setTrianglesItem(QGraphicsItemGroup *group) {
    _item->setTriangles(group);
}

void MeshToLayerDialog::onFinishedEvent() {
    ui->pbTransfer->setEnabled(true);
    ui->lProcess->setText(PROCESS00);
    _map->setEdited(true);
}
