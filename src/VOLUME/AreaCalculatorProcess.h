#ifndef AREACALCULATORPROCESS_H
#define AREACALCULATORPROCESS_H

// CUBATOR
#include <DefaultProcess.h>
#include <GraphicsAreaItem.h>
#include <GraphicsPolylineItem.h>
#include <Defines.h>

class AreaCalculatorProcess : public DefaultProcess
{
    Q_OBJECT

public:
    AreaCalculatorProcess();
    void setAreaItem(GraphicsAreaItem *item);

signals:
    void surfaceUpdated(qreal);

public slots:
    virtual void run();

private:
    GraphicsAreaItem *_item;
    GraphicsPolylineItem _polyline;
};

#endif // AREACALCULATORPROCESS_H
