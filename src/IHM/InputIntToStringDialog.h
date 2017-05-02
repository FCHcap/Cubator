#ifndef INPUTINTTOSTRINGDIALOG_H
#define INPUTINTTOSTRINGDIALOG_H

// QT
#include <QDialog>
#include <QMap>

namespace Ui {
    class InputIntToStringDialog;
}

class InputIntToStringDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InputIntToStringDialog(QWidget *parent = 0);
    ~InputIntToStringDialog();

    void setLayers(const QMap<QString, int> & layers);
    QMap<QString, int> layers() const;

    void setDescription(const QString & description);
    void setRange(const int &min, const int &max);
    void setStep(const int &step);

protected:
    void accept();

protected slots:
    void changeLayer(QString layer);

private:
    Ui::InputIntToStringDialog *ui;
    QMap<QString, int> _layers;
    QString _lastLayer;
};

#endif // INPUTINTTOSTRINGDIALOG_H
