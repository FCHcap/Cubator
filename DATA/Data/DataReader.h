#ifndef DATAREADER_H
#define DATAREADER_H

// QT
#include <QFile>
#include <QDataStream>
#include <QString>
#include <QObject>
#include <QVariant>
#include <QCoreApplication>

// CUBATOR
#include <CubException.h>
#include <DTGrid.h>

class DataReader{

    Q_DECLARE_TR_FUNCTIONS(DataReader)

public:
    DataReader();
    DataReader(const QString &filename) throw(CubException);
    ~DataReader();

    void open(const QString &filename) throw(CubException);
    void close();

    bool atEnd();

    int pos() const;
    int size() const;

protected:
    QFile _file;
    QDataStream _stream;
};

#endif // DATAREADER_H
