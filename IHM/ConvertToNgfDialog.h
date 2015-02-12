#ifndef CONVERTTONGFDIALOG_H
#define CONVERTTONGFDIALOG_H

// QT
#include <QDialog>

// CUBATOR
#include <DVertexList.h>

namespace Ui {
class ConvertToNgfDialog;
}

class ConvertToNgfDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit ConvertToNgfDialog(QWidget *parent = 0);
    ~ConvertToNgfDialog();

protected slots:
    void launchNextProcess();
    void finishProcess();

protected:
    void loadSourceVerticesList();
    void convertToNgf();
    void saveDestinationVerticesList();
    
private:
    Ui::ConvertToNgfDialog *ui;
    void (ConvertToNgfDialog::* _process) (void);

    DVertexList _sourceList;
    DVertexList _destinationList;
};

#endif // CONVERTTONGFDIALOG_H
