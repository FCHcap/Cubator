/*
 * Credit to Nicoptere (http://en.nicoptere.net/) for the original code.
*/

// QT
#include <QList>

// STL
#include <cmath>
#include <cassert>

// CUBATOR
#include "DEdge.h"
#include "DTriangleList.h"
#include "DVertexList.h"
#include <CubException.h>
#include <DefaultProcess.h>
#include <Messages.h>

/**
  * @author Emmanuel Olive
*/

#ifndef DELAUNAY_H
#define DELAUNAY_H

#define PROXIMITY_DELTA 1

class Delaunay : public DefaultProcess
{
    Q_OBJECT

public:
    Delaunay(QObject * parent = 0);

    void setVertices(DVertexList &vertices);

public slots:
    void run();

protected:
    bool inCircle(const DTriangle &t, const DVertex &v) const;

protected:
    DVertexList *_vertices;
};

#endif // DELAUNAY_H
