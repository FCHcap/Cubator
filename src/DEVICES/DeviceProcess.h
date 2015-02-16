#ifndef DEVICEPROCESS_H
#define DEVICEPROCESS_H

// QT
#include <QObject>
#include <QTimer>
#include <QThread>
#include <QStringList>
#include <QtSerialPort/QtSerialPort>

// CUBATOR
#include <CubException.h>
#include <Settings.h>

class DeviceProcess : public QObject
{
    Q_OBJECT
public:
    explicit DeviceProcess(QObject *parent = 0);
    ~DeviceProcess();

    void connectToThread(QThread *thread);
    bool isEnabled();

    static QStringList listBaudrate();
    static QStringList listDataBits();
    static QStringList listStopBit();
    static QStringList listParity();
    static QStringList listFlowControl();

protected:
    virtual void loadSettings() = 0; // Called from 'start' method.
    void applyParameters(QSerialPort & device);
    void open();
    
signals:
    void enabled(bool);
    void started();
    void finished();
    void connected(bool);
    void timeout();
    void inconsistentData();
    void exceptionLaunched(CubException);
    
protected slots:
    void read();
    virtual void processFrame(QByteArray &frame) = 0;
    void processTimerTimeout();

public slots:
    void run();
    void quit();
    void reloadSettings();
    void setEnabled(bool enabled);

protected:
    QSerialPort * _device;
    QTimer * _timerTimeout;
    QTimer * _timerInconsistent;
    SettingsDevice *_settings;
    QByteArray _data;
    bool _enabled;
};

#endif // DEVICEPROCESS_H
