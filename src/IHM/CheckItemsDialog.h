#ifndef CHECKITEMSDIALOG_H
#define CHECKITEMSDIALOG_H

// QT
#include <QDialog>
#include <QMap>

namespace Ui {
class CheckItemsDialog;
}

class CheckItemsDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit CheckItemsDialog(QWidget *parent = 0);
    ~CheckItemsDialog();

    void setItems(QMap<QString, bool> hash);
    QMap<QString, bool> items();
    
private:
    Ui::CheckItemsDialog *ui;
};

#endif // CHECKITEMSDIALOG_H
