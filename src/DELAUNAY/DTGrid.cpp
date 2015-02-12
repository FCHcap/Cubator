#include <DTGrid.h>

void DTGrid::setBounds(const QRect &rect){
    _bounds = rect;
}

QRect DTGrid::bounds() const{
    return _bounds;
}
