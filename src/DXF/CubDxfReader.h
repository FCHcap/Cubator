#ifndef CUBDXFREADER_H
#define CUBDXFREADER_H

// QT
#include <QObject>

// LIBDXF
#include <libdxfrw.h>

// CUBATOR
#include <CubDxfInterface.h>

class CubDxfReader : public dxfRW
{
    Q_OBJECT

public:
    CubDxfReader();
    void setFilepath(const QString &filepath);

public slots:
    void run();
};

#endif // CUBDXFREADER_H
