#ifndef GRAPHICSMESHIMAGEITEM_H
#define GRAPHICSMESHIMAGEITEM_H

// QT
#include <QtGui>

// CUBATOR
#include <GraphicsTypes.h>
#include <Data.h>
#include <DVertexList.h>
#include <VerticesReader.h>
#include <TrianglesReader.h>
#include <GridReader.h>

class GraphicsMeshImageItem : public QGraphicsItem
{
public:
    GraphicsMeshImageItem(QGraphicsItem * parent = 0, const QString & tableName = "");

    enum { Type = GRAPHICS_MESH_IMAGE_TYPE };

    int type() const;

    void setTableName(const QString & tableName);
    QString tableName() const;

    bool depthAt(const QPointF & pos, double & depth);
    double depthAt(const QPointF & pos); // returns DBL_MAX constant if the point is not in mesh area.
    bool depthGridAt(const QPointF & pos, double &depth);
    double depthGridAt(const QPointF &pos);

    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    void loadVertices();
    void loadTriangles();
    void loadGrid();
    void loadImage();

protected:
    QGraphicsPixmapItem *_px;
    QString _tableName;
    DVertexList _mesh;
    //bool _loadImage; //indique à la fonction paint que l'image est à chargée (un pixmap doit être utilisé à partir du fil principal)
};

#endif // GRAPHICSMESHIMAGEITEM_H
