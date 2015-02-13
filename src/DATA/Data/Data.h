#ifndef DATA_H
#define DATA_H

// QT
#include <QStringList>
#include <QDate>
#include <QMap>
#include <QDir>
#include <QFile>
#include <QCoreApplication>
#include <QDesktopServices>

// STL
#include <string>

// CUBATOR
#include <CubException.h>
#include <Messages.h>
#include <Defines.h>

#define TABLE_FILENAME "databases/tables.bin"

class Data{

    Q_DECLARE_TR_FUNCTIONS(Data)

    typedef struct Table{
        QDate date;
        QString comments;
    } Table;

public:
    static Data * getInstance();
    static void kill();

    void addTable(const QString &table, const QDate &date, const QString &comments) throw(CubException);
    void removeTable(const QString &table) throw(CubException);
    static void initTable(const QString &table) throw(CubException);

    QStringList tables() const;
    QDate date(const QString &table) const throw(CubException);
    QString comments(const QString &name) const throw(CubException);

    void save() throw(CubException);

    static QString vectorFileName(const QString &table);
    static QString triangleFilename(const QString &table);
    static QString imageFilename(const QString &table);
    static QString gridFilename(const QString &table);

    void tableExists(const QString &table, const QString method = "", const QString brief = "") const throw(CubException);

private:
    Data() throw (CubException);
    ~Data() throw(CubException);

protected:
    QMap<QString, Table> _tables;
    static Data *_data;

};

#endif // DATA_H
