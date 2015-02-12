#ifndef PMLSAVEDIALOG_H
#define PMLSAVEDIALOG_H

// QT
#include <QDialog>
#include <QMap>
#include <QString>
#include <QFileDialog>

// CUBATOR
#include <PmlWriter.h>
#include <CubException.h>
#include <ErrorDialog.h>
#include <Map.h>
#include <Defines.h>

namespace Ui {
class PmlSaveDialog;
}

class PmlSaveDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit PmlSaveDialog(QMap<QString, Map> hMaps, QWidget *parent = 0);
    ~PmlSaveDialog();
    QStringList mapSaved();

protected slots:
    void showException(CubException e);
    void onSave();
    void onFileSelect();
    void updateLevel(int level);
    void finish();
    
private:
    Ui::PmlSaveDialog *ui;
    QMap<QString, Map> _mMaps;
    QStringList _mapSaved;
};

#endif // PMLSAVEDIALOG_H
