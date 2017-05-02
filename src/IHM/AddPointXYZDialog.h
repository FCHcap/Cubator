#ifndef ADDPOINTXYZDIALOG_H
#define ADDPOINTXYZDIALOG_H

#include <QDialog>

namespace Ui {
class AddPointXYZDialog;
}

class AddPointXYZDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddPointXYZDialog(QWidget *parent = 0);
    ~AddPointXYZDialog();

    double getDepth();

private:
    Ui::AddPointXYZDialog *ui;
};

#endif // ADDPOINTXYZDIALOG_H
