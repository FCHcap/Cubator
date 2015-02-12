#include "DateDialog.h"
#include "ui_DateDialog.h"

DateDialog::DateDialog(QWidget *parent, QDate date) :
    QDialog(parent),
    ui(new Ui::DateDialog)
{
    ui->setupUi(this);
    ui->calendarWidget->setSelectedDate(date);
}

DateDialog::~DateDialog()
{
    delete ui;
}

void DateDialog::setDate(const QDate &date){
    ui->calendarWidget->setSelectedDate(date);
}

QDate DateDialog::date() const{
    return ui->calendarWidget->selectedDate();
}
