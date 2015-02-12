#include "XyzFileReader.h"

XyzFileReader::XyzFileReader(QObject *parent) :
    QThread(parent)
{
    _stop = 0;
    _exception = 0;
}

XyzFileReader::~XyzFileReader(){
    delete _exception;
}

void XyzFileReader::process(const QString &filepath, const QChar &delimitor, const QString &table){

    _filepath = filepath;
    _delimitor = delimitor;
    _table = table;

    start();
}

CubException *XyzFileReader::exception(){
    return _exception;
}

void XyzFileReader::stop(){
    _stop = 1;
}

void XyzFileReader::run(){

    try{
        Data * data = Data::getInstance();
        data->tableExists(_table, "XyzFileReader::run");

        // Open the file
        QFile file(_filepath);
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
            throw CubException(BRIEF06, TEXT01 + _filepath, "XyzFileReader::run");

        QString wfn = Data::vectorFileName(_table);
        VectorsWriter writer(wfn);

        // Import file
        emit operationNameUpdated(PROCESS18);

        while(!file.atEnd()){
            QByteArray bytes = file.readLine();
            DVertex vector = processLine(bytes);
            writer.writeVertex(vector);

            int level = file.pos() * 100 / file.size();
            emit levelUpdated(level);

            if(_stop) return;
        }
        emit levelUpdated(100);

        // Close the file
        file.close();
    }
    catch(const CubException &e){
        _exception = new CubException(e);
        return;
    }
}

DVertex XyzFileReader::processLine(QByteArray line){

    QString sLine(line);
    QString sX = sLine.section(_delimitor, 0, 0);
    QString sY = sLine.section(_delimitor, 1, 1);
    QString sZ = sLine.section(_delimitor, 2, 2);
    return DVertex(sX.toDouble(), sY.toDouble(), sZ.toDouble());
}
