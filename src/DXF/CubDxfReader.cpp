#include "CubDxfReader.h"

// QT
#include <QString>

// LIBDXF
#include <libdxfrw.h>

// CUBATOR
#include <GraphicsMap.h>
#include <CubDxfInterface.h>
#include <InfoMap.h>

CubDxfReader::CubDxfReader()
{
}

void CubDxfReader::setFilepath(const QString &filepath){
    dxfRW::setFilepath(filepath.toUtf8().data());
}

void CubDxfReader::run(){
    GraphicsMap* item = new GraphicsMap();
    CubDxfInterface i(item);
    dxfRW::read(&i, 0);

    QString map = InfoMap::filepathToMap(QString::fromStdString(filepath));

    emit mapGenerated(map, item);
}
