#include "ProgressDialog.h"
#include "ui_ProgressDialog.h"

#include <qwidget.h>

ProgressDialog::ProgressDialog(QWidget *parent) :
    QDialog(parent, Qt::Dialog | Qt::WindowTitleHint),
    ui(new Ui::ProgressDialog)
{
    ui->setupUi(this);
    ui->label->setText("");
    ui->progressBar->setValue(0);
}

ProgressDialog::~ProgressDialog()
{
    delete ui;
}

void ProgressDialog::updateLevel(int level){
    ui->progressBar->setValue(level);
}

void ProgressDialog::updateProcessName(QString processName){
    ui->label->setText(processName);
}
