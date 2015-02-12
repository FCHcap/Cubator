#ifndef ERRORDIALOG_H
#define ERRORDIALOG_H

#include <QDialog>
#include <QVBoxLayout>
#include <string>

#include <CubException.h>

namespace Ui {
class ErrorDialog;
}

class ErrorDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit ErrorDialog(QWidget *parent = 0, const QString &brief = "", const QString &details = "", const QString &method = "");
    ~ErrorDialog();

    static void errorDialog(QWidget *parent = 0, const QString &brief = "", const QString &details = "", const QString &method = "");
    static void errorDialog(QWidget *parent = 0, const std::string &brief = "", const std::string &details = "", const std::string &method = "");
    static void errorDialog(QWidget *parent = 0, const CubException &e = CubException());
    
private:
    Ui::ErrorDialog *ui;
};

#endif // ERRORDIALOG_H
