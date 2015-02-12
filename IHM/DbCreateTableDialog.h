#ifndef DBCREATETABLEDIALOG_H
#define DBCREATETABLEDIALOG_H

#include <QDialog>
#include <Data.h>

namespace Ui {
    class DbCreateTableDialog;
}

class DbCreateTableDialog : public QDialog
{
    Q_OBJECT

public:

    explicit DbCreateTableDialog(QWidget *parent = 0);
    ~DbCreateTableDialog();

    QString name();
    QString comments();

private:
    Ui::DbCreateTableDialog *ui;
};

#endif // DBCREATETABLEDIALOG_H
