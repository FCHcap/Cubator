#ifndef GRAPHICSTEXTDIALOG_H
#define GRAPHICSTEXTDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QEvent>
#include <QKeyEvent>

class GraphicsTextDialog : public QDialog
{
    Q_OBJECT
public:
    explicit GraphicsTextDialog(QWidget *parent = 0);

    void setText(QString text);
    QString text();

protected:
    void keyPressEvent(QKeyEvent * event);
    bool eventFilter(QObject *, QEvent *);

protected:
    QLineEdit *_lineEdit;
    
};

#endif // GRAPHICSTEXTDIALOG_H
