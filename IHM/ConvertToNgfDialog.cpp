#include "ConvertToNgfDialog.h"
#include "ui_ConvertToNgfDialog.h"

// CUBATOR
#include <Data.h>
#include <VerticesReaderProcess.h>
#include <ConvertToNgfProcess.h>
#include <DataWriterProcess.h>

ConvertToNgfDialog::ConvertToNgfDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConvertToNgfDialog)
{
    ui->setupUi(this);

    // Loads the list of tables
    Data * data = Data::getInstance();
    QStringList slTables = data->tables();

    ui->cbSourceTable->addItems(slTables);
    ui->cbDestinationTable->addItems(slTables);

    // Hides the process widgets
    ui->lProcessName->hide();
    ui->progressBar->hide();

    // Initializes the attributes
    _process = &ConvertToNgfDialog::loadSourceVerticesList;
}

ConvertToNgfDialog::~ConvertToNgfDialog()
{
    delete ui;
}

void ConvertToNgfDialog::launchNextProcess(){

    if(_process == &ConvertToNgfDialog::loadSourceVerticesList){
        ui->pbCalculate->setEnabled(0);
        ui->cbSourceTable->setEnabled(0);
        ui->cbDestinationTable->setEnabled(0);
        ui->buttonBox->setEnabled(0);
        ui->lProcessName->show();
        ui->progressBar->show();
    }

    (this->*_process)();
}

void ConvertToNgfDialog::finishProcess(){
    ui->pbCalculate->setEnabled(1);
    ui->cbSourceTable->setEnabled(1);
    ui->cbDestinationTable->setEnabled(1);
    ui->buttonBox->setEnabled(1);
    ui->lProcessName->setText(PROCESS00);
}

void ConvertToNgfDialog::loadSourceVerticesList(){

    _process = &ConvertToNgfDialog::convertToNgf;

    VerticesReaderProcess * reader = new VerticesReaderProcess();
    //QThread *thread = new QThread();

    reader->setVerticesList(_sourceList);
    reader->setFilename(Data::vectorFileName(ui->cbSourceTable->currentText()));

    //reader->connectToThread(thread);

    connect(reader, SIGNAL(processNameUpdated(QString)), ui->lProcessName, SLOT(setText(QString)));
    connect(reader, SIGNAL(levelUpdated(int)), ui->progressBar, SLOT(setValue(int)));
    connect(reader, SIGNAL(finished()), this, SLOT(launchNextProcess()));

    //reader->moveToThread(thread);
    //thread->start();
    reader->start();
}

void ConvertToNgfDialog::convertToNgf(){

    _process = &ConvertToNgfDialog::saveDestinationVerticesList;

    ConvertToNgfProcess * converter = new ConvertToNgfProcess();
    //QThread *thread = new QThread();

    converter->setSourceVerticesList(_sourceList);
    converter->setDestinationVerticesList(_destinationList);
    converter->setHeightOfTheWater(ui->dsHeight->value());

    //converter->connectToThread(thread);

    connect(converter, SIGNAL(processNameUpdated(QString)), ui->lProcessName, SLOT(setText(QString)));
    connect(converter, SIGNAL(levelUpdated(int)), ui->progressBar, SLOT(setValue(int)));
    connect(converter, SIGNAL(finished()), this, SLOT(launchNextProcess()));

    //converter->moveToThread(thread);
    //thread->start();
    converter->start();
}

void ConvertToNgfDialog::saveDestinationVerticesList(){

    VectorsWriterProcess * writer = new VectorsWriterProcess();
    //QThread * thread = new QThread();

    writer->setVerticesList(_destinationList);
    writer->setFilename(Data::vectorFileName(ui->cbDestinationTable->currentText()));

    //writer->connectToThread(thread);

    connect(writer, SIGNAL(processNameUpdated(QString)), ui->lProcessName, SLOT(setText(QString)));
    connect(writer, SIGNAL(levelUpdated(int)), ui->progressBar, SLOT(setValue(int)));
    connect(writer, SIGNAL(finished()), this, SLOT(finishProcess()));

    //writer->moveToThread(thread);
    //thread->start();
    writer->start();
}
