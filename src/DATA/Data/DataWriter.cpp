#include "DataWriter.h"

DataWriter::DataWriter()
{
    _stream.setDevice(&_file);
}

DataWriter::DataWriter(const QString &filename, bool append) throw (CubException){

    _stream.setDevice(&_file);

    try{
        open(filename, append);
    }
    catch(const CubException &e){
        throw e;
    }
}

DataWriter::~DataWriter(){
    _file.close();
}

void DataWriter::open(const QString &filename, bool append) throw (CubException){

    // Check if table is unlock

    // Open file
    _file.setFileName(filename);
    QIODevice::OpenMode mode = QIODevice::WriteOnly;
    if(append) mode = QIODevice::Append;
    if(!_file.open(mode)){
        throw CubException(BRIEF06, TEXT01 + filename, "DataWriter::open");
    }
}

void DataWriter::close(){

    _file.close();
}

void VectorsWriter::writeVertex(const DVertex &v){

    _stream << v.x() << v.y() << v.z();
}

void TrianglesWriter::writeTriangle(const DTriangle &t){

    _stream << t.v1() << t.v2() << t.v3();
}

void GridWriter::writeBounds(const QRect &r){
    _stream << r.x() << r.y() << r.width() << r.height();
}

void GridWriter::writeGridItem(const DTGridItem &gi){

    _stream << gi._bounds.x() << gi._bounds.y() << gi._bounds.width() << gi._bounds.height();
    _stream << gi._triangles.count();
    foreach(DTriangleId id, gi._triangles){
        _stream << id;
    }
}
