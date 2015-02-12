#ifndef TRIANGLESREADER_H
#define TRIANGLESREADER_H

// CUBATOR
#include <DataReader.h>
#include <DVertexList.h>

class TrianglesReader : public DataReader{

public:
    TrianglesReader(const QString &filename) : DataReader(filename){}
    DTriangle readTriangle() throw (CubException);
    int count() const;
};

#endif // TRIANGLESREADER_H
