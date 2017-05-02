#ifndef LAYERTOTABLEDIALOG_H
#define LAYERTOTABLEDIALOG_H

// QT
#include <QDialog>
#include <QGraphicsItemGroup>

// CUBATOR
#include <GraphicsMap.h>
#include <ErrorDialog.h>
#include <Messages.h>
#include <LayerToTableProcess.h>
#include <Data.h>

namespace Ui {
class LayerToTableDialog;
}

class LayerToTableDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LayerToTableDialog(QWidget *parent = 0, GraphicsMap *map = 0);
    ~LayerToTableDialog();

    void setGraphicsMap(GraphicsMap *map);
    GraphicsMap * graphicsMap();

private:
    Ui::LayerToTableDialog *ui;

    QStringList _layers;
    QStringList _tables;

    GraphicsMap *_map;
    Data *_data;

protected:
    void loadTable();

protected slots:
    void onConvertEvent();
    void onFinishedEvent();
};

#endif // LAYERTOTABLEDIALOG_H
