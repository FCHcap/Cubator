#ifndef TABLETOLAYERDIALOG_H
#define TABLETOLAYERDIALOG_H

// QT
#include <QDialog>
#include <QGraphicsItemGroup>

// CUBATOR
#include <GraphicsMap.h>
#include <Data.h>
#include <VerticesReaderProcess.h>
#include <VerticesLoadingProcess.h>
#include <ErrorDialog.h>
#include <DVertexList.h>
#include <Messages.h>

namespace Ui {
class TableToLayerDialog;
}

class TableToLayerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TableToLayerDialog(QWidget *parent = 0, GraphicsMap *map = 0);
    ~TableToLayerDialog();

    void setGraphicsMap(GraphicsMap *map);
    GraphicsMap * graphicsMap();

private:
    Ui::TableToLayerDialog *ui;

    QStringList _layers;
    QStringList _tables;
    DVertexList _vertices;

    GraphicsMap * _map;
    Data * _data;

protected:
    void loadTable();

protected slots:
    void onConvertEvent();
    void generateGraphicsEvent();
    void graphicsGeneratedEvent(QGraphicsItemGroup *verticesItem);

signals:
    void generateGraphics();

};

#endif // TABLETOLAYERDIALOG_H
