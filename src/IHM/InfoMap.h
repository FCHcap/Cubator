#ifndef INFOMAP_H
#define INFOMAP_H

// QT
#include <QString>
#include <QRegExp>

class InfoMap{

public:
    static QString filepathToFilename(const QString & filepath);
    static QString filenameToMap(const QString & filename);
    static QString filenameToExtension(const QString & filename);
    static QString filepathToMap(const QString & filepath);
    static QString filepathToExtension(const QString & filepath);
};

#endif // INFOMAP_H
