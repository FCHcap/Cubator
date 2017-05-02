#ifndef LAYERTOTABLEPROCESS_H
#define LAYERTOTABLEPROCESS_H

// QT
#include <qgraphicsitem.h>

// CUBATOR
#include <DefaultProcess.h>
#include <GraphicsMap.h>
#include <Data.h>
#include <DataWriter.h>
#include <Messages.h>
#include <GraphicsPointXYZItem.h>
#include <Messages.h>

/* Convertir tous les éléments xyz d'un calque vers une table */
class LayerToTableProcess : public DefaultProcess
{
    Q_OBJECT

public:
    LayerToTableProcess();
    void setGraphicsMap(GraphicsMap *map);
    void setLayerName(const QString layername);
    void setTableName(const QString tablename);
    void setAppendToTable(const bool appendToTable);

public slots:
    void run();

protected:
    GraphicsMap *_map;
    QString _tablename;
    QString _layername;
    bool _appendToTable;

signals:
    void finished();
};

#endif // LAYERTOTABLEPROCESS_H
