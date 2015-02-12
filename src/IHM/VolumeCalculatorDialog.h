#ifndef VOLUMECALCULATORDIALOG_H
#define VOLUMECALCULATORDIALOG_H

// QT
#include <QDialog>
#include <QThread>

// CUBATOR
#include <Data.h>
#include <VolumeCalculatorProcess.h>
#include <ProgressDialog.h>
#include <GraphicsVolumeItem.h>
#include <CubException.h>

namespace Ui {
class VolumeCalculatorDialog;
}

class VolumeCalculatorDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit VolumeCalculatorDialog(QWidget *parent = 0);
    ~VolumeCalculatorDialog();

    void setVolumeItem(GraphicsVolumeItem * item);

    bool error() const;
    bool calculated() const;

protected slots:
    void calculates();
    void showError(CubException e);
    void showWarning(CubException e);
    void setSurface(qreal surface);
    void setVolume(qreal volume);
    void finish();
    
private:
    Ui::VolumeCalculatorDialog *ui;
    GraphicsVolumeItem * _volumeItem;
    bool _error;
    bool _calculated;
};

#endif // VOLUMECALCULATORDIALOG_H
