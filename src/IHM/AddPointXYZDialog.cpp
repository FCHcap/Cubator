#include "AddPointXYZDialog.h"
#include "ui_AddPointXYZDialog.h"

AddPointXYZDialog::AddPointXYZDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddPointXYZDialog)
{
    ui->setupUi(this);
    ui->dsDepth->setFocus();
    ui->dsDepth->selectAll();
}

AddPointXYZDialog::~AddPointXYZDialog()
{
    delete ui;
}

double AddPointXYZDialog::getDepth() {
    return ui->dsDepth->value();
}
