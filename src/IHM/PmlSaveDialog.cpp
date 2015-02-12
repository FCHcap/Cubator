#include "PmlSaveDialog.h"
#include "ui_PmlSaveDialog.h"

PmlSaveDialog::PmlSaveDialog(QMap<QString, Map> hMaps, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PmlSaveDialog)
{
    ui->setupUi(this);
    _mMaps = hMaps;

    QStringList keys = _mMaps.keys();
    ui->cbMap->addItems(keys);

    ui->progressBar->setValue(0);
}

PmlSaveDialog::~PmlSaveDialog()
{
    delete ui;
}

QStringList PmlSaveDialog::mapSaved(){
    return _mapSaved;
}

void PmlSaveDialog::showException(CubException e){
    ErrorDialog::errorDialog(this, e);
}

void PmlSaveDialog::onFileSelect(){
    QString filename = QFileDialog::getSaveFileName(this, TITLE19, getUserDocumentsLocation(), TEXT09+"(*.pml)");

    if(!filename.isEmpty()){
        ui->leFile->setText(filename);
    }
}

void PmlSaveDialog::onSave(){

    ui->pbSave->setEnabled(0);

    PmlWriter * writer = new PmlWriter;
    //QThread * thread = new QThread;
    QMap<QString, GraphicsMap*> hash;
    hash.insert(ui->leFile->text(), _mMaps[ui->cbMap->currentText()].item);
    writer->setList(hash);
    //writer->connectToThread(thread);
    connect(writer, SIGNAL(levelUpdated(int)), this, SLOT(updateLevel(int)));
    connect(writer, SIGNAL(finished()), this, SLOT(finish()));
    //writer->moveToThread(thread);
    //thread->start();
    writer->start();
}

void PmlSaveDialog::updateLevel(int level){
    ui->progressBar->setValue(level);
}

void PmlSaveDialog::finish(){
    close();
}
