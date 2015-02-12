#include "GridReaderProcess.h"

GridReaderProcess::GridReaderProcess(QObject * parent) : DefaultProcess(parent)
{
    _grid = 0;
}

void GridReaderProcess::setGrid(DTGrid &grid){
    _grid = &grid;
}

void GridReaderProcess::setFilename(const QString &filename){
    _filename = filename;
}

void GridReaderProcess::run(){
    try{
        CubException e;
        e.setMethod("GridReaderProcess::run");

        if(!_grid){
            e.setBrief(BRIEF00);
            e.setError(ERROR08);
            throw e;
        }

        GridReader reader(_filename);

        emit processNameUpdated(PROCESS04);

        _grid->setBounds(reader.readBounds());

        while(!reader.atEnd()){
            _grid->append(reader.readGridItem());
            emit levelUpdated(reader.pos() * 100 / reader.size());
        }
        emit levelUpdated(100);
    }
    catch(CubException &e){
        emit exceptionLaunched(e);
    }
}
