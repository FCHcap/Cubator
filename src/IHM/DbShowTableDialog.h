#ifndef DbShowTableDialog_H
#define DbShowTableDialog_H

// QT
#include <QDialog>
#include <QtSql>
#include <QMessageBox>

// STL
#include <exception>

// CUBATOR
#include <Data.h>
#include <VerticesReaderProcess.h>
#include <DataWriterProcess.h>
#include <ProgressDialog.h>
#include <ErrorDialog.h>
#include <DVertexList.h>
#include <Messages.h>


namespace Ui {
    class DbShowTableDialog;
}

class CubDbController;

class DbShowTableDialog : public QDialog
{
    Q_OBJECT


public:
    explicit DbShowTableDialog(QWidget *parent = 0);
    ~DbShowTableDialog();

    bool init();

protected slots:
    void onComboTablesNamesChanged(QString table);
    void allowChanges(bool allow);
    void load();
    void addVertex(DVertex vertex);
    void setRowCount(int rows);
    void exit();

protected:
    void save(QString table, bool connectToLoad = 0);

private:
    Ui::DbShowTableDialog *ui;
    QString _lastTable;
    int _cptRow;
    DVertexList _vList; // Used for save the vertices
};

#endif // DbShowTableDialog_H
