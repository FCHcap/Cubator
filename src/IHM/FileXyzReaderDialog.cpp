#include "FileXyzReaderDialog.h"
#include "ui_FileXyzReaderDialog.h"

#include <QFileDialog>
#include <QMessageBox>

FileXyzReaderDialog::FileXyzReaderDialog(QWidget *parent) :
    QDialog(parent), ui(new Ui::FileXyzReaderDialog)
{
    ui->setupUi(this);
    ui->progressBar->setEnabled(0);
    _reader = 0;
}

FileXyzReaderDialog::~FileXyzReaderDialog()
{
    delete ui;
}

bool FileXyzReaderDialog::init(){

    ui->cbDelimitor->addItem(".");
    ui->cbDelimitor->addItem(",");
    ui->cbDelimitor->addItem(" ");

    Data * data = Data::getInstance();
    QStringList tables = data->tables();

    ui->cbTable->addItems(tables);
    return 1;
}

void FileXyzReaderDialog::reject(){
    if(_reader){
        _reader->stop();
        _reader->wait();
        if(_reader->isRunning()) _reader->terminate();
        delete _reader;
        _reader = 0;
    }
    QDialog::reject();
}

void FileXyzReaderDialog::import(){

    if(_reader) return;

    _reader = new XyzFileReader(this);
    connect(_reader, SIGNAL(levelUpdated(int)), this, SLOT(updateLevel(int)));
    connect(_reader, SIGNAL(operationNameUpdated(QString)), this, SLOT(updateOperationName(QString)));
    connect(_reader, SIGNAL(finished()), this, SLOT(finish()));

    ui->pbImport->setEnabled(0);
    ui->progressBar->setEnabled(1);

    _reader->process(ui->leFile->text(), ui->cbDelimitor->currentText()[0], ui->cbTable->currentText());
}

void FileXyzReaderDialog::selectFile(){
    QString file = QFileDialog::getOpenFileName(this, TITLE06, getUserDocumentsLocation());
    if(!file.isNull()){
        ui->leFile->setText(file);
        ui->pbImport->setEnabled(1);
    }
}

void FileXyzReaderDialog::updateLevel(int level){
    ui->progressBar->setValue(level);
}

void FileXyzReaderDialog::updateOperationName(QString name){
    ui->lOperationName->setText(name);
}

void FileXyzReaderDialog::finish(){

    if(!_reader) return;
    if(!_reader->isFinished()) return;

    CubException *e = _reader->exception();

    if(e){
        ErrorDialog::errorDialog(this, e->what(), e->error(), e->method());
    }

    ui->progressBar->setEnabled(0);
    ui->pbImport->setEnabled(1);
    ui->lOperationName->setText("");

    if(_reader){
        delete _reader;
        _reader = 0;
    }
}
