#ifndef GPSWIDGET_H
#define GPSWIDGET_H

// QT
#include <QWidget>
#include <QtGui>
#include <QLabel>

// CUBATOR
#include <Messages.h>

class GpsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GpsWidget(QWidget *parent = 0);
    
public slots:
    void updatePosition(QPointF position);
    void connect(bool connected);
    void timeout();
    void inconsistentData();

protected:
    QLabel * _lX;
    QLabel * _lY;
};

#endif // GPSWIDGET_H
