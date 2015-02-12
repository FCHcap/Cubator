#include "TrianglesReader.h"

DTriangle TrianglesReader::readTriangle() throw (CubException){
    int v1 = 0, v2 = 0, v3 = 0;
    _stream >> v1 >> v2 >> v3;

    if(_stream.status() == QDataStream::ReadCorruptData)
        throw CubException(BRIEF04, TEXT01 + _file.fileName(), "TrianglesReader::readTriangle");
    return DTriangle(v1, v2, v3);
}

int TrianglesReader::count() const{
    return _file.size() /(3*sizeof(int));
}
