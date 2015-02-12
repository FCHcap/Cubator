#ifndef GRIDCALCULATORPROCESS_H
#define GRIDCALCULATORPROCESS_H

// CUBATOR
#include <DefaultProcess.h>
#include <DTGrid.h>
#include <DVertexList.h>
#include <Messages.h>

#define STITCH 20

class GridCalculatorProcess : public DefaultProcess
{
public:
    GridCalculatorProcess(QObject * parent = 0);
    ~GridCalculatorProcess();

    void setVertexList(DVertexList &list);

    virtual void run();

protected:
    DVertexList * _verticesList;
};

#endif // GRIDCALCULATORPROCESS_H
