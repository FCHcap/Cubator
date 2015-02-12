#ifndef GRIDREADER_H
#define GRIDREADER_H

// QT
#include <Qt>

// CUBATOR
#include <DataReader.h>
#include <DTGrid.h>

class GridReader : public DataReader{

public:
    GridReader(const QString &filename) : DataReader(filename){}
    QRect readBounds();
    DTGridItem readGridItem();
};
#endif // GRIDREADER_H
