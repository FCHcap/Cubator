#ifndef VERTICESREADER_H
#define VERTICESREADER_H

// CUBATOR
#include <DVertexList.h>
#include <DataReader.h>

class VerticesReader : public DataReader{

public:
    VerticesReader(const QString &filename) : DataReader(filename){}
    DVertex readVertex() throw (CubException);
    int count() const;
};

#endif // VERTICESREADER_H
