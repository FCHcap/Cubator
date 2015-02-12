#ifndef CONVERTMAPFILEDIALOG_H
#define CONVERTMAPFILEDIALOG_H

// QT
#include <QDialog>
#include <QFileDialog>
#include <QThread>

// CUBATOR
#include <CubException.h>

class GraphicsMap;

namespace Ui {
    class ConvertMapFileDialog;
}

class ConvertMapFileDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConvertMapFileDialog(QWidget *parent = 0);
    ~ConvertMapFileDialog();

protected slots:
    void onConvert();
    void onSfBrowse();
    void onDfBrowse();
    void onLeChanged();
    void setGpil(QString map, GraphicsMap * item);
    void finishProcess();
    void showError(CubException e);

protected:
    GraphicsMap * _item;

private:
    Ui::ConvertMapFileDialog *ui;
};

#endif // CONVERTMAPFILEDIALOG_H
