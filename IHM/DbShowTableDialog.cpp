#include "DbShowTableDialog.h"
#include "ui_DbShowTableDialog.h"

//#include <CubDoubleDelegate.h>

extern QString defaultConnection;

DbShowTableDialog::DbShowTableDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DbShowTableDialog)
{
    ui->setupUi(this);

    QStringList headerLabels;
    headerLabels << "X" << "Y" << "Z";

    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(headerLabels);
    _cptRow = 0;

    qRegisterMetaType<DVertex>("DVertex");
}

DbShowTableDialog::~DbShowTableDialog()
{
    delete ui;
}

bool DbShowTableDialog::init(){

    Data *data = Data::getInstance();

    // Initialize la liste de tables
    try{
        ui->comboTablesNames->addItems(data->tables());
    }
    catch(std::exception e){
        QMessageBox::critical(this, tr("Cubator error"), e.what());
        return 0;
    }

    return 1;
}

void DbShowTableDialog::onComboTablesNamesChanged(QString table){

    if(!_lastTable.isEmpty() && ui->cbAllowChanges->isChecked()) save(_lastTable, 1);
    else load();
    _lastTable = table;
}

void DbShowTableDialog::allowChanges(bool allow){

    QString table = ui->comboTablesNames->currentText();
    if(QFile::exists(Data::triangleFilename(table)) && allow){
        if(QMessageBox::question(this, tr("Cubator question"), QUESTION01, QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes){

            // Supprime la triangulation, la grille et l'image
            QFile::remove(Data::triangleFilename(table));
            QFile::remove(Data::gridFilename(table));
            QFile::remove(Data::imageFilename(table));
        }
        else{
            ui->cbAllowChanges->setChecked(0);
            return;
        }
    }
    ui->tableWidget->allowChanges(allow);
}

void DbShowTableDialog::load(){

    try{
        VerticesReaderProcess * rProcess = new VerticesReaderProcess(Data::vectorFileName(ui->comboTablesNames->currentText()));
        //QThread * thread = new QThread;
        ProgressDialog * dialog = new ProgressDialog(this);

        _cptRow = 0;
        ui->cbAllowChanges->setChecked(0);

        //rProcess->connectToThread(thread);
        rProcess->connectToProgressDialog(dialog);

        connect(rProcess, SIGNAL(vertexRead(DVertex)), this, SLOT(addVertex(DVertex)));
        connect(rProcess, SIGNAL(rowCountUpdated(int)), this, SLOT(setRowCount(int)));

        //rProcess->moveToThread(thread);
        //thread->start();
        rProcess->start();
    }
    catch(const CubException &e){
        ErrorDialog::errorDialog(this, e);
    }
}

void DbShowTableDialog::addVertex(DVertex vertex){

    QTableWidgetItem *x = new QTableWidgetItem(QString::number(vertex.x(), 'f', 4));
    QTableWidgetItem *y = new QTableWidgetItem(QString::number(vertex.y(), 'f', 4));
    QTableWidgetItem *z = new QTableWidgetItem(QString::number(vertex.z(), 'f', 4));
    x->setFlags(0);
    y->setFlags(0);
    z->setFlags(0);
    ui->tableWidget->setItem(_cptRow, 0, x);
    ui->tableWidget->setItem(_cptRow, 1, y);
    ui->tableWidget->setItem(_cptRow, 2, z);
    _cptRow++;
}

void DbShowTableDialog::setRowCount(int rows){
    ui->tableWidget->setRowCount(rows);
}

void DbShowTableDialog::exit(){
    if(!ui->comboTablesNames->currentText().isEmpty() && ui->cbAllowChanges->isChecked()) save(ui->comboTablesNames->currentText());
    else QDialog::accept();
}

void DbShowTableDialog::save(QString table, bool connectToLoad){

    try{
        _vList.clear();

        for(int i=0; i<ui->tableWidget->rowCount(); i++){
            QTableWidgetItem * ix = ui->tableWidget->item(i, 0);
            QTableWidgetItem * iy = ui->tableWidget->item(i, 1);
            QTableWidgetItem * iz = ui->tableWidget->item(i, 2);

            ix->setFlags(0);
            iy->setFlags(0);
            iz->setFlags(0);

            if(!ix || !iy || !iz) continue;

            DVertex v(ix->text().toDouble(), iy->text().toDouble(), iz->text().toDouble());
            _vList.append(v);
        }

        VectorsWriterProcess * wProcess = new VectorsWriterProcess(Data::vectorFileName(table));
        //QThread * thread = new QThread;
        ProgressDialog * dialog = new ProgressDialog(this);

        wProcess->setVerticesList(_vList);

        wProcess->connectToProgressDialog(dialog);
        //wProcess->connectToThread(thread);

        if(connectToLoad) connect(wProcess, SIGNAL(finished()), this, SLOT(load()));
        else connect(wProcess, SIGNAL(finished()), this, SLOT(accept()));

        //wProcess->moveToThread(thread);
        //thread->start();
        wProcess->start();
    }
    catch(CubException e){
        ErrorDialog::errorDialog(this, e);
    }
}
