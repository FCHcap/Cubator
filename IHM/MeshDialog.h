#ifndef MESHDIALOG_H
#define MESHDIALOG_H

// QT
#include <QDialog>
#include <QPicture>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsItemGroup>
#include <QInputDialog>

// CUBATOR
#include <Delaunay.h>
#include <ErrorDialog.h>
#include <VerticesReader.h>
#include <TrianglesReader.h>
#include <GridReader.h>
#include <DataWriterProcess.h>
#include <VerticesLoadingProcess.h>
#include <TrianglesItemLoadingProcess.h>
#include <GridCalculatorProcess.h>
#include <GridWriterProcess.h>
#include <Messages.h>

namespace Ui {
class MeshDialog;
}

class MeshDialog : public QDialog
{
    Q_OBJECT

    typedef struct ENode{
        DVertexId id;
        ENode *next;
    } ENode;

    typedef struct GTriangle{
        QGraphicsLineItem *ab;
        QGraphicsLineItem *bc;
        QGraphicsLineItem *ca;
    } GTriangle;
    
public:
    explicit MeshDialog(QWidget *parent = 0);
    ~MeshDialog();

    bool init();

protected:

    void removeItems();
    void loadVertices();
    void loadTriangles();
    void loadGrid();
    void triangulate();
    void createGrid();
    void writeTriangles();
    void writeImage();
    void writeGrid();
    void enableTools(bool enable = 1);
    void enableTools();

protected slots:
    void launchProcess();

    void onPbCalculate();
    void onPbWriteImage();
    void updateImage();
    void showException(CubException e);
    void setVerticesItem(QGraphicsItemGroup *);
    void setTrianglesItem(QGraphicsItemGroup *);
    void updateScenePosition(QPointF position);
    void selectTable(QString table);
    void showVertex(bool show);
    void showTriangles(bool show);
    void showImage(bool show);
    
private:
    Ui::MeshDialog *ui;

protected:
    QGraphicsScene *_scene;
    TrianglesWriterProcess *_twp;
    ImageWriterProcess *_iwp;
    VerticesLoadingProcess *_vlp;
    TrianglesItemLoadingProcess *_tlp;
    QGraphicsPixmapItem *_vpxItem;
    QGraphicsItemGroup *_verticesItem;
    QGraphicsItemGroup *_trianglesItem;
    QGraphicsLineItem *_triangleSelected[3];
    DVertexList _vertex;
    bool _completeProcess;
    QList<void (MeshDialog::*)()> _processList;
};

#endif // MESHDIALOG_H
