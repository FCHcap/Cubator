#ifndef DBTABLEEDITDIALOG_H
#define DBTABLEEDITDIALOG_H

// QT
#include <QDialog>
#include <QtSql>
#include <QMessageBox>
#include <QDate>
#include <QDir>

// STL
#include <exception>

// CUBATOR
#include <DbCreateTableDialog.h>
#include <Data.h>
#include <ErrorDialog.h>

namespace Ui {
    class DbTableEditDialog;
}

class CubDbController;

class DbTableEditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DbTableEditDialog(QWidget *parent = 0);
    ~DbTableEditDialog();

    bool init();

private slots:
    void onButtonCreate();
    void onButtonDelete();
    void onTableSelectionChanged(QString table);

private:
    Ui::DbTableEditDialog *ui;
    QStringList _tablesList;

};

#endif // DBTABLEEDITDIALOG_H
