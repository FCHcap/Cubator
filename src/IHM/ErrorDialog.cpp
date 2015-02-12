#include "ErrorDialog.h"
#include "ui_ErrorDialog.h"

ErrorDialog::ErrorDialog(QWidget *parent, const QString &brief, const QString &details, const QString &method) :
    QDialog(parent),
    ui(new Ui::ErrorDialog)
{
    ui->setupUi(this);
    ui->error->setText(brief);
    ui->tbDetails->append("<p><b>" + TEXT14 + "</b>" + details + "</p>");
    ui->tbDetails->append("<p><b>" + TEXT15 + "</b>" + method + "</p>");
    ui->tbDetails->hide();

    setWindowTitle(TITLE05);
}

ErrorDialog::~ErrorDialog()
{
    delete ui;
}

void ErrorDialog::errorDialog(QWidget *parent, const QString &brief, const QString &details, const QString &method){
    ErrorDialog dialog(parent, brief, details, method);
    dialog.exec();
}

void ErrorDialog::errorDialog(QWidget *parent, const std::string &brief, const std::string &details, const std::string &method){
    errorDialog(parent, QString::fromStdString(brief), QString::fromStdString(details), QString::fromStdString(method));
}

void ErrorDialog::errorDialog(QWidget *parent, const CubException &e){
    errorDialog(parent, e.brief(), e.error(), e.method());
}
