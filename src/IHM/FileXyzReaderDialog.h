#ifndef FILEXYZREADERDIALOG_H
#define FILEXYZREADERDIALOG_H

#include <QDialog>
#include <QThread>

#include <exception>

#include <XyzFileReader.h>
#include <Data.h>
#include <ErrorDialog.h>
#include <Defines.h>

namespace Ui {
class FileXyzReaderDialog;
}

class FileXyzReaderDialog : public QDialog
{
    Q_OBJECT
    
public:

    explicit FileXyzReaderDialog(QWidget *parent = 0);
    ~FileXyzReaderDialog();

    bool init();

protected:
    void reject();

protected slots:
    void import();
    void selectFile();

    void updateLevel(int level);
    void updateOperationName(QString name);
    void finish();
    
private:
    Ui::FileXyzReaderDialog *ui;

    XyzFileReader * _reader;
};

#endif // FILEXYZREADERDIALOG_H
