#ifndef COORDINATESDIALOG_H
#define COORDINATESDIALOG_H

// QT
#include <QDialog>
#include <QtGui>

// CUBATOR
#include <CubGeo.h>
#include <CubException.h>
#include <ErrorDialog.h>

namespace Ui {
    class CoordinatesDialog;
}

class CoordinatesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CoordinatesDialog(QWidget *parent = 0);
    ~CoordinatesDialog();

    void checkToEnableCalculate();
    void setSystemBPosition(QPointF position);

    QPointF systemBPosition();

private slots:
    void onSystemAUnitsChanged();
    void onTransfEnabled(bool enable);
    void onTextDegChanged();
    void onTextMinChanged();
    void onTextSecChanged();
    void onUpdateCoordsA();
    void onButtonCalculateClicked();

private:
    Ui::CoordinatesDialog *ui;
    QStringList _systemsB;
};

#endif // COORDINATESDIALOG_H
