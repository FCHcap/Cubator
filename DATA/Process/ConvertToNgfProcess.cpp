#include "ConvertToNgfProcess.h"

ConvertToNgfProcess::ConvertToNgfProcess(QObject * parent) : DefaultProcess(parent)
{
    _sourceList = 0;
    _destinationList = 0;
    _height = 0;
}

void ConvertToNgfProcess::run(){
    CubException e;
    e.setMethod(QString("ConvertToNgfProcess::run"));

    emit processNameUpdated(PROCESS01);

    try{
        if(!_sourceList || !_destinationList){
            e.setBrief(BRIEF00);
            e.setError(ERROR08);
            throw e;
        }

        int cpt = 0;
        foreach(DVertex v, *_sourceList){
            DVertex v2;
            v2.setX(v.x());
            v2.setY(v.y());
            v2.setZ(_height + v.z());
            _destinationList->append(v2);

            // Updates the progressbar
            cpt++;
            emit levelUpdated(cpt * 100 / _sourceList->count());
        }
    }
    catch(CubException e){
        emit exceptionLaunched(e);
    }

}

void ConvertToNgfProcess::setSourceVerticesList(DVertexList &list){
    _sourceList = &list;
}

void ConvertToNgfProcess::setDestinationVerticesList(DVertexList &list){
    _destinationList = &list;
}

void ConvertToNgfProcess::setHeightOfTheWater(const double &height){
    _height = height;
}
