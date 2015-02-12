#ifndef GRIDREADERPROCESS_H
#define GRIDREADERPROCESS_H

// CUBATOR
#include <DefaultProcess.h>
#include <DTGrid.h>
#include <Messages.h>
#include <GridReader.h>

class GridReaderProcess : public DefaultProcess
{
public:
    GridReaderProcess(QObject * parent = 0);

    void setGrid(DTGrid & grid);
    void setFilename(const QString &filename);

    virtual void run();

protected:
    DTGrid * _grid;
    QString _filename;

};

#endif // GRIDREADERPROCESS_H
