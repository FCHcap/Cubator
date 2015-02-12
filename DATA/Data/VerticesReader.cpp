#include "VerticesReader.h"

DVertex VerticesReader::readVertex() throw (CubException){
    double x = 0, y = 0, z = 0;
    _stream >> x >> y >> z;

    if(_stream.status() == QDataStream::ReadCorruptData)
        throw CubException(BRIEF04, TEXT01 + _file.fileName(), "VerticesReader::readVertex");
    return DVertex(x, y, z);
}

int VerticesReader::count() const{
    return _file.size() / (3*sizeof(qreal));
}
