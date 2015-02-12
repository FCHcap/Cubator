#ifndef DTGRID_H
#define DTGRID_H

// QT
#include <QList>
#include <QRect>

// Cubator
#include <DTypes.h>

struct DTGridItem{
    QRect _bounds;
    QList<DTriangleId> _triangles;
};

class DTGrid : public QList<DTGridItem>{
public:
    void setBounds(const QRect &rect);
    QRect bounds() const;

protected:
    QRect _bounds;
};

#endif // DTGRID_H
