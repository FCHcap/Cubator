#ifndef DATEDIALOG_H
#define DATEDIALOG_H

// QT
#include <QDialog>
#include <QDate>

namespace Ui {
    class DateDialog;
}

class DateDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DateDialog(QWidget *parent = 0, QDate date = QDate());
    ~DateDialog();

    void setDate(const QDate &date);
    QDate date() const;

private:
    Ui::DateDialog *ui;
};

#endif // DATEDIALOG_H
