#include "DbTableEditDialog.h"
#include "ui_DbTableEditDialog.h"

extern QString defaultConnection;

DbTableEditDialog::DbTableEditDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DbTableEditDialog)
{
    ui->setupUi(this);
}

DbTableEditDialog::~DbTableEditDialog()
{
    delete ui;
}

bool DbTableEditDialog::init(){

    try{
        Data* data = Data::getInstance();
        _tablesList = data->tables();
    }
    catch(CubException const &e){
        ErrorDialog::errorDialog(this, e.what(), e.error(), e.method());
    }

    ui->listWidget->addItems(_tablesList);
    ui->listWidget->setCurrentRow(0);
    if(_tablesList.isEmpty()) ui->buttonDelete->setEnabled(0);

    return 1;
}

void DbTableEditDialog::onButtonCreate(){

    DbCreateTableDialog dialog(this);
    if(dialog.exec()){
        QString name = dialog.name();
        QString comments = dialog.comments();

        try{

            Data* data = Data::getInstance();

            // Création du fichier de vecteurs
            QFile file(Data::vectorFileName(name));
            if(!file.exists()){
                if(!file.open(QIODevice::ReadWrite)) throw CubException(BRIEF05, TEXT12 + Data::vectorFileName(name)    , "DbTableEditDialog::onButtonCreate");
            }

            data->addTable(name, QDate::currentDate(), comments);
            data->save();

            //Update tables list widget
            _tablesList = data->tables();
            ui->listWidget->addItem(name);
            ui->listWidget->setCurrentRow(ui->listWidget->count()-1);
            ui->buttonDelete->setEnabled(1);
        }
        catch(const CubException &e){
            ErrorDialog::errorDialog(this, e.what(), e.error(), e.method());
            return;
        }
    }
}

void DbTableEditDialog::onButtonDelete(){

    try{    
        Data* data = Data::getInstance();
        QListWidgetItem* item = ui->listWidget->selectedItems().takeFirst();
        QString table = item->text();
        if(QMessageBox::question(this, TITLE01, QUESTION02, QMessageBox::Yes, QMessageBox::No) == QMessageBox::No){
            return;
        }

        data->removeTable(table);
        data->save();

        // Remove the data files
        QFile::remove(Data::vectorFileName(table));
        QFile::remove(Data::triangleFilename(table));
        QFile::remove(Data::gridFilename(table));
        QFile::remove(Data::imageFilename(table));

        /* Update the tables list widget */
        int rowItemDeleted = ui->listWidget->row(item);
        if(rowItemDeleted > 0) rowItemDeleted--;
        ui->listWidget->clear();
        ui->listWidget->addItems(data->tables());
        ui->listWidget->setCurrentRow(rowItemDeleted);

        /* If the table list is empty, disable the delete button */
        if(_tablesList.isEmpty()) ui->buttonDelete->setEnabled(0);
    }
    catch(const CubException &e){
        ErrorDialog::errorDialog(this, e.what(), e.error(), e.method());
    }
}

void DbTableEditDialog::onTableSelectionChanged(QString table){

    if(table.isEmpty()){
        ui->labelDate->setText(TEXT11 + "---");
        ui->labelComments->setText(TEXT13 + "---");
        return;
    }

    ui->buttonDelete->setEnabled(1);

    try{
        Data* data = Data::getInstance();

        ui->labelDate->setText(TEXT11 + data->date(table).toString("dd-MM-yyyy"));
        ui->labelComments->setText(TEXT13 + data->comments(table));
    }
    catch(const CubException &e){
        ErrorDialog::errorDialog(this, e.what(), e.error(), e.method());
    }
}
