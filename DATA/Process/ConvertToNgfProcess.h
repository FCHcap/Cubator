#ifndef CONVERTTONGFPROCESS_H
#define CONVERTTONGFPROCESS_H

// CUBATOR
#include <DefaultProcess.h>
#include <Messages.h>

class ConvertToNgfProcess : public DefaultProcess
{
public:
    ConvertToNgfProcess(QObject * parent = 0);

    virtual void run();

    void setSourceVerticesList(DVertexList & list);
    void setDestinationVerticesList(DVertexList & list);
    void setHeightOfTheWater(const double & height);

protected:
    DVertexList * _sourceList;
    DVertexList * _destinationList;
    double _height;
};

#endif // CONVERTTONGFPROCESS_H
