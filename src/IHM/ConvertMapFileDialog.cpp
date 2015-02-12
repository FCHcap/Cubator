#include "ConvertMapFileDialog.h"
#include "ui_ConvertMapFileDialog.h"

// CUBATOR
#include <InfoMap.h>
#include <ProgressDialog.h>
#include <CubDxfReader.h>
#include <Messages.h>
#include <PmlReader.h>
#include <PmlWriter.h>
#include <ErrorDialog.h>

ConvertMapFileDialog::ConvertMapFileDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConvertMapFileDialog)
{
    ui->setupUi(this);
    _item = 0;

    ui->pbConvert->setEnabled(0);
}

ConvertMapFileDialog::~ConvertMapFileDialog()
{
    delete ui;
}

void ConvertMapFileDialog::onConvert(){

    ui->pbConvert->setEnabled(0);

    QString extension = InfoMap::filenameToExtension(ui->leSourceFile->text());

    //QThread * thread = new QThread;
    ProgressDialog * dialog = new ProgressDialog(this);

    if(extension == "dxf"){
        CubDxfReader * reader = new CubDxfReader;
        reader->setFilepath(ui->leSourceFile->text());

        //reader->connectToThread(thread);
        reader->connectToProgressDialog(dialog);

        connect(reader, SIGNAL(exceptionLaunched(CubException)), this, SLOT(showError(CubException)));
        connect(reader, SIGNAL(mapGenerated(QString, GraphicsMap*)), this, SLOT(setGpil(QString, GraphicsMap*)));
        reader->start();
        //reader->moveToThread(thread);
    }
    else if(extension == "pml"){
        PmlReader * reader = new PmlReader;
        reader->setFilepath(ui->leSourceFile->text());

        //reader->connectToThread(thread);
        reader->connectToProgressDialog(dialog);

        connect(reader, SIGNAL(exceptionLaunched(CubException)), this, SLOT(showError(CubException)));
        connect(reader, SIGNAL(mapGenerated(QString, GraphicsMap*)), this, SLOT(setGpil(QString, GraphicsMap*)));
        reader->start();
        //reader->moveToThread(thread);
    }

    //thread->start();
}

void ConvertMapFileDialog::onSfBrowse(){

    QString filepath = QFileDialog::getOpenFileName(this, TITLE03, getUserDocumentsLocation(), TEXT09 + "(*.dxf *.pml)");
    ui->leSourceFile->setText(filepath);
}

void ConvertMapFileDialog::onDfBrowse(){

    ui->leDestinationFile->setText(QFileDialog::getSaveFileName(this, TITLE03, getUserDocumentsLocation(), TEXT09 + "(*.pml)"));
}

void ConvertMapFileDialog::onLeChanged(){

    (!ui->leSourceFile->text().isEmpty() && !ui->leDestinationFile->text().isEmpty()) ? ui->pbConvert->setEnabled(1) : ui->pbConvert->setEnabled(0);
}

void ConvertMapFileDialog::setGpil(QString map, GraphicsMap *item){

    Q_UNUSED(map)

    _item = item;

    PmlWriter * writer = new PmlWriter;
    //QThread * thread = new QThread;
    ProgressDialog * dialog = new ProgressDialog(this);

    QMap<QString, GraphicsMap*> hMaps;
    hMaps.insert(ui->leDestinationFile->text(), _item);

    writer->setList(hMaps);
    writer->sortByType(ui->cbSortByType->isEnabled());

    //writer->connectToThread(thread);
    writer->connectToProgressDialog(dialog);

    connect(writer, SIGNAL(exceptionLaunched(CubException)), this, SLOT(showError(CubException)));
    connect(writer, SIGNAL(finished()), this, SLOT(finishProcess()));

    //writer->moveToThread(thread);
    //thread->start();
    writer->start();
}

void ConvertMapFileDialog::finishProcess(){

    if(_item){
        delete _item;
        _item = 0;
    }

    ui->pbConvert->setEnabled(1);
}

void ConvertMapFileDialog::showError(CubException e){
    ErrorDialog::errorDialog(this, e);
}
