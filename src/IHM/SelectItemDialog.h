#ifndef SELECTITEMDIALOG_H
#define SELECTITEMDIALOG_H

#include <QDialog>
#include <QDialogButtonBox>

namespace Ui {
    class SelectItemDialog;
}

class SelectItemDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SelectItemDialog(QWidget *parent = 0);
    ~SelectItemDialog();

    void setItemsList(QList<QString> items);
    void setItemSelected(QString name);
    QString itemSelected();

    void setButtonBox(QDialogButtonBox::StandardButtons buttons);

private:
    Ui::SelectItemDialog *ui;
};

#endif // SELECTITEMDIALOG_H
