#ifndef XYZFILEREADER_H
#define XYZFILEREADER_H

#include <QThread>
#include <QFile>
#include <QVector3D>
#include <QByteArray>

#include <cmath>
#include <exception>

#include <Data.h>
#include <DataWriter.h>
#include <DVertexList.h>
#include <ErrorDialog.h>

#define PROXIMITY_VECTORS_DELTA 1

class XyzFileReader : public QThread
{
    Q_OBJECT

public:

    explicit XyzFileReader(QObject *parent=0);
    ~XyzFileReader();

    void process(const QString &filepath, const QChar &delimitor, const QString &table);
    CubException *exception();

    void stop();

protected:
    void run();
    DVertex processLine(QByteArray line);
    
signals:
    void levelUpdated(int);
    void operationNameUpdated(QString);

protected:
    QString _filepath;
    QChar _delimitor;
    QString _table;
    CubException *_exception;
    bool _stop;
};

#endif // XYZFILEREADER_H
