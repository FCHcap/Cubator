#include "DataReader.h"

DataReader::DataReader()
{
    _stream.setDevice(&_file);
}

DataReader::DataReader(const QString &filename) throw (CubException){

    _stream.setDevice(&_file);

    try{
        open(filename);
    }
    catch(const CubException &e){
        throw e;
    }
}

DataReader::~DataReader(){
}

void DataReader::open(const QString &filename) throw (CubException){

    // Check if filename is unlock

    // Open file
    _file.setFileName(filename);
    if(!_file.open(QIODevice::ReadOnly)){
        throw CubException(BRIEF06, TEXT01 + filename, "DataReader::open");
    }
}

void DataReader::close(){
    _file.close();
}

bool DataReader::atEnd(){

    return _file.atEnd();
}

int DataReader::pos() const{
    return _file.pos();
}

int DataReader::size() const{
    return _file.size();
}
