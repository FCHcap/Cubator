#include <InfoMap.h>

QString InfoMap::filepathToFilename(const QString & filepath){
    QRegExp rx("([\\w '-]+[.]\\w{3})$");
    rx.indexIn(filepath);

    return rx.cap(1);
}

QString InfoMap::filenameToMap(const QString & filename){
    QRegExp rx("([\\w '-]+)[.]\\w{3}$");
    rx.indexIn(filename);

    return rx.cap(1);
}

QString InfoMap::filenameToExtension(const QString & filename){
    QRegExp rx("[\\w '-]+[.](\\w{3})$");
    rx.indexIn(filename);

    return rx.cap(1);
}

QString InfoMap::filepathToMap(const QString & filepath){
    QRegExp rx("([\\w '-]+)[.]\\w{3}$");
    rx.indexIn(filepath);

    return rx.cap(1);
}

QString InfoMap::filepathToExtension(const QString & filepath){
    QRegExp rx("[.](\\w{3})$");
    rx.indexIn(filepath);

    return rx.cap(1);
}
