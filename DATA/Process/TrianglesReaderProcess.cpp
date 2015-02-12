#include "TrianglesReaderProcess.h"

TrianglesReaderProcess::TrianglesReaderProcess(QString filename){
    _filename = filename;
    _triangles = 0;
}

void TrianglesReaderProcess::setFilename(QString filename){
    _filename = filename;
}

void TrianglesReaderProcess::setTrianglesList(DTriangleList &t){
    _triangles = &t;
}

void TrianglesReaderProcess::run(){

    try{
        if(!_triangles) throw CubException(BRIEF00, ERROR08, "TrianglesReaderProcess::start");

        TrianglesReader reader(_filename);
        int size = reader.count();

        emit processNameUpdated(PROCESS16);

        for(int i=0; i< size; i++){
            _triangles->append(reader.readTriangle());
            emit levelUpdated(i * 100 / size);
        }
        emit levelUpdated(100);
    }
    catch(const CubException &e){
        emit exceptionLaunched(e);
    }
}
