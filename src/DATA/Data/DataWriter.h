#ifndef DATAWRITER_H
#define DATAWRITER_H

// QT
#include <QFile>
#include <QDataStream>
#include <QString>
#include <QObject>
#include <QVariant>
#include <QCoreApplication>

// CUBATOR
#include <DVertexList.h>
#include <CubException.h>
#include <DTGrid.h>

class DataWriter{

    Q_DECLARE_TR_FUNCTIONS(DataWriter)

public:
    DataWriter();
    DataWriter(const QString &filename, bool append = 0) throw(CubException);
    ~DataWriter();

    void open(const QString &filename, bool append) throw(CubException);
    void close();

protected:
    QFile _file;
    QDataStream _stream;
};

class VectorsWriter : public DataWriter{

public:
    VectorsWriter(const QString &filename, bool append = 0) : DataWriter(filename, append){}
    void writeVertex(const DVertex & v);
};

class TrianglesWriter : public DataWriter{

public:
    TrianglesWriter(const QString &filename, bool append = 0) : DataWriter(filename, append){}
    void writeTriangle(const DTriangle & t);
};

class GridWriter : public DataWriter{

public:
    GridWriter(const QString &filename, bool append = 0) : DataWriter(filename, append){}
    void writeBounds(const QRect &r);
    void writeGridItem(const DTGridItem &gi);
};

#endif // DATAWRITER_H
