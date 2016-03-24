#ifndef ICONAUTOWIDGET_H
#define ICONAUTOWIDGET_H

#include <QWidget>

namespace Ui {
class IconAutoWidget;
}

class IconAutoWidget : public QWidget
{
    Q_OBJECT

public:
    explicit IconAutoWidget(QWidget *parent = 0);
    ~IconAutoWidget();

signals:
    void iconAutoAdded();

private:
    Ui::IconAutoWidget *ui;
};

#endif // ICONAUTOWIDGET_H
