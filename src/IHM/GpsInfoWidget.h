#ifndef GPSINFOWIDGET_H
#define GPSINFOWIDGET_H

// QT
#include <QWidget>
#include <QtGui>
#include <QLabel>

// CUBATOR
#include <Messages.h>
#include <Gps.h>

namespace Ui {
class GpsInfoWidget;
}

class GpsInfoWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GpsInfoWidget(QWidget *parent = 0);
    ~GpsInfoWidget();

public slots:
    void enable(bool value);
    void updateData(GpsData data);
    void connect(bool connected);
    void timeout();
    void inconsistentData();

private:
    Ui::GpsInfoWidget *ui;
};

#endif // GPSINFOWIDGET_H
