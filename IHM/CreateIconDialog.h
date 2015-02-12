#ifndef CREATEICONDIALOG_H
#define CREATEICONDIALOG_H

// QT
#include <Qt>
#include <QtGui>

// CUBATOR
#include <CoordinatesDialog.h>
#include <DateDialog.h>

namespace Ui {
    class CreateIconDialog;
}

class CreateIconDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CreateIconDialog(QWidget *parent = 0);
    ~CreateIconDialog();

    void setPosition(QPointF position);
    void setRotation(int angle);
    void setDate(QDate date);
    void setSystem(QString system);

    QPointF position();
    int rotation();
    QDate date();
    QString system();

protected slots:
    void onButtonCoordsEdit();
    void onButtonRotationEdit();
    void onButtonDateEdit();

private:
    Ui::CreateIconDialog *ui;
    QPointF _position;
    int _angle;
    QDate _date;
    QString _system;
};

#endif // CREATEICONDIALOG_H
