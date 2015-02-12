#include "VerticesReaderProcess.h"

VerticesReaderProcess::VerticesReaderProcess(QString filename){
    _filename = filename;
    _vertices = 0;
}

void VerticesReaderProcess::setFilename(QString filename){
    _filename = filename;
}

void VerticesReaderProcess::setVerticesList(DVertexList &v){
    _vertices = &v;
}

void VerticesReaderProcess::run(){

    try{
        VerticesReader reader(_filename);
        int size = reader.count();

        emit processNameUpdated(PROCESS15);
        emit rowCountUpdated(size);

        for(int i=0; i<size; i++){
            if(_vertices) _vertices->append(reader.readVertex());
            else emit vertexRead(reader.readVertex());
            emit levelUpdated(i * 100 /size);
        }
        emit levelUpdated(100);
    }
    catch(const CubException &e){
        emit exceptionLaunched(e);
    }
}
