#ifndef VOLUMECALCULATORPROCESS_H
#define VOLUMECALCULATORPROCESS_H

// QT
#include <QtGui>

// CUBATOR
#include <DefaultProcess.h>
#include <CubException.h>
#include <Data.h>
#include <VerticesReaderProcess.h>
#include <TrianglesReaderProcess.h>
#include <GridReaderProcess.h>
#include <GraphicsVolumeItem.h>

class VolumeCalculatorProcess : public DefaultProcess
{
    Q_OBJECT

public:
    enum Surface {LEVEL, MESH};

    VolumeCalculatorProcess();

    void setUpMesh(const QString &mesh);
    void setUpLevel(const double &level);

    void setLoMesh(const QString &mesh);
    void setLoLevel(const double &level);

    void setVolumeItem(GraphicsVolumeItem * item);

signals:
    void surfaceUpdated(qreal);
    void volumeUpdated(qreal);
    void warningMessageLaunched(CubException e);
    void rectangleAdded(QRect);

public slots:
    virtual void run();

private:
    void loadVertices(const QString &table, DVertexList &vertices) throw (CubException);
    void loadTriangles(const QString &table, DTriangleList &triangles) throw (CubException);
    void loadGrid(const QString &table, DTGrid &grid) throw (CubException);
    qreal mediumHeight(DVertexList &vertices, QRect &rect) throw (CubException);

protected:
    bool _error;
    Surface _upSurface;
    Surface _loSurface;
    QString _upMesh;
    QString _loMesh;
    double _upLevel;
    double _loLevel;
    GraphicsPolylineItem _polyline;
};

#endif // VOLUMECALCULATORPROCESS_H
