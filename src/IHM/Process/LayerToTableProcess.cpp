#include "LayerToTableProcess.h"

LayerToTableProcess::LayerToTableProcess() : _appendToTable(true)
{
}

void LayerToTableProcess::setGraphicsMap(GraphicsMap *map) {
    _map = map;
}

void LayerToTableProcess::setLayerName(const QString layername) {
    _layername = layername;
}

void LayerToTableProcess::setTableName(const QString tablename) {
    _tablename = tablename;
}

void LayerToTableProcess::setAppendToTable(const bool appendToTable) {
    _appendToTable = appendToTable;
}

void LayerToTableProcess::run() {
    try {
        Data *data = Data::getInstance();

        QString tablefilename = data->vectorFileName(_tablename);
        VectorsWriter writer(tablefilename, _appendToTable);

        if(!_map->layerExists(_layername)) {
            throw CubException(BRIEF29, TEXT25 + _layername, "LayerToTableProcess::run");
        }

        GraphicsMapLayer *layer = _map->layerItem(_layername);

        emit processNameUpdated(PROCESS22);
        emit levelUpdated(0);

        for(int i=0; i<layer->childItems().size(); i++) {
            QGraphicsItem *item = layer->childItems().at(i);

            if(item->type() == GraphicsPointXYZItem::Type) {
                GraphicsPointXYZItem *xyzitem = qgraphicsitem_cast<GraphicsPointXYZItem *>(item);
                writer.writeVertex(xyzitem->vertex());
            }

            emit levelUpdated((int) (i*100 / layer->childItems().size()));
        }
        emit levelUpdated(100);
        emit processNameUpdated(PROCESS00);
        emit finished();

    } catch (const CubException & e) {
        emit exceptionLaunched(e);
    }
}
