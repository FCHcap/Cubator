#include "DbCreateTableDialog.h"
#include "ui_DbCreateTableDialog.h"

DbCreateTableDialog::DbCreateTableDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DbCreateTableDialog)
{
    ui->setupUi(this);
}

DbCreateTableDialog::~DbCreateTableDialog()
{
    delete ui;
}

QString DbCreateTableDialog::name(){
    return ui->editName->text();
}

QString DbCreateTableDialog::comments(){
    return ui->editComments->text();
}
