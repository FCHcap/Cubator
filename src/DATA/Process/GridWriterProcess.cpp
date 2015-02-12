#include "GridWriterProcess.h"

GridWriterProcess::GridWriterProcess(QObject * parent) : DefaultProcess(parent)
{
    _grid = 0;
}

GridWriterProcess::~GridWriterProcess(){

}

void GridWriterProcess::setGrid(DTGrid &grid){
    _grid = &grid;
}

void GridWriterProcess::setFilename(const QString &filename){
    _filename = filename;
}

void GridWriterProcess::run(){
    try{
        CubException e;
        e.setMethod("GridWriterProcess::run");

        if(!_grid){
            e.setBrief(BRIEF00);
            e.setError(ERROR08);
            throw e;
        }

        emit processNameUpdated(PROCESS03);

        GridWriter writer(_filename);
        writer.writeBounds(_grid->bounds());
        for(int i=0; i<_grid->size();i++){
            writer.writeGridItem(_grid->at(i));
            emit levelUpdated(i*100/_grid->size());
        }
    }
    catch(CubException &e){
        emit exceptionLaunched(e);
    }
}
