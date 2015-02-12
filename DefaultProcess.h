#ifndef DEFAULTPROCESS_H
#define DEFAULTPROCESS_H

// QT
#include <QThread>

// CUBATOR
#include <CubException.h>
#include <ProgressDialog.h>
#include <GraphicsMap.h>
#include <InfoMap.h>

class DefaultProcess : public QThread
{
    Q_OBJECT

public:
    DefaultProcess(QObject *parent = 0);
    ~DefaultProcess();
    void connectToProgressDialog(const ProgressDialog * dialog);
    CubException * lastException(); // returns the last exception launched else returns null

public slots:
    virtual void run() = 0;
    void saveException(CubException);

signals:
    void levelUpdated(int);
    void processNameUpdated(QString);
    void exceptionLaunched(CubException e);

protected:
    CubException *_lastException;
};

class LoaderMapProcess : public DefaultProcess
{
    Q_OBJECT

public:
    LoaderMapProcess(QObject * parent = 0) : DefaultProcess(parent){}
    ~LoaderMapProcess(){}

public slots:
    virtual void run() = 0;

signals:
    void mapGenerated(QString, GraphicsMap *); // Key : name of map (without extension and path)
};

#endif // DEFAULTPROCESS_H
