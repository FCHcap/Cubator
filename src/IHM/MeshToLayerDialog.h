#ifndef MESHTOLAYERDIALOG_H
#define MESHTOLAYERDIALOG_H

// QT
#include <QDialog>
#include <qstringlist.h>

// CUBATOR
#include <GraphicsMap.h>
#include <Data.h>
#include <GraphicsMeshItem.h>
#include <TrianglesItemLoadingProcess.h>
#include <VerticesLoadingProcess.h>
#include <VerticesReaderProcess.h>
#include <TrianglesReaderProcess.h>

namespace Ui {
class MeshToLayerDialog;
}

class MeshToLayerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MeshToLayerDialog(QWidget *parent, GraphicsMap *map);
    ~MeshToLayerDialog();

signals:
    void startProcess();

protected slots:
    void onTransferEvent();
    void readVerticesEvent();
    void readTrianglesEvent();
    void loadVerticesEvent();
    void loadTrianglesEvent();
    void showException(CubException e);
    void setVerticesItem(QGraphicsItemGroup *group);
    void setTrianglesItem(QGraphicsItemGroup *group);
    void onFinishedEvent();

private:
    Ui::MeshToLayerDialog *ui;

    QStringList _layers;
    QStringList _tables;

    GraphicsMap *_map;
    Data *_data;
    GraphicsMeshItem *_item;
    DVertexList _vertices;
};

#endif // MESHTOLAYERDIALOG_H
