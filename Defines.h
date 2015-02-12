#ifndef DEFINES_H
#define DEFINES_H

// QT
#include <QStandardPaths>

#define getDataLocation() QStandardPaths::displayName(QStandardPaths::DataLocation)
#define getUserDocumentsLocation() QStandardPaths::displayName(QStandardPaths::DocumentsLocation)
#define getUserPicturesLocation() QStandardPaths::displayName(QStandardPaths::PicturesLocation)

#endif // DEFINES_H
