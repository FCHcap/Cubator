#ifndef GRIDWRITERPROCESS_H
#define GRIDWRITERPROCESS_H

// CUBATOR
#include <DefaultProcess.h>
#include <DTGrid.h>
#include <Messages.h>
#include <DataWriter.h>

class GridWriterProcess : public DefaultProcess
{
public:
    GridWriterProcess(QObject * parent = 0);
    ~GridWriterProcess();

    void setGrid(DTGrid & grid);
    void setFilename(const QString &filename);

    virtual void run();

protected:
    DTGrid * _grid;
    QString _filename;
};

#endif // GRIDWRITERPROCESS_H
