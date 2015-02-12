#include "GridReader.h"

QRect GridReader::readBounds(){
    QRect r;
    int x=0, y=0, w=0, h=0;
    _stream >> x >> y >> w >> h;
    r.setX(x);
    r.setY(y);
    r.setWidth(w);
    r.setHeight(h);

    return r;
}

DTGridItem GridReader::readGridItem(){

    int x = 0, y = 0, width = 0, height = 0;
    _stream >> x >> y >> width >> height;

    DTGridItem item;

    item._bounds.setX(x);
    item._bounds.setY(y);
    item._bounds.setWidth(width);
    item._bounds.setHeight(height);

    int count = 0;
    _stream >> count;

    for(int i=0; i<count; i++){
        int id = 0;
        _stream >> id;
        item._triangles.append(id);
    }
    return item;
}
