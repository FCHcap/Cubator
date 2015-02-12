#ifndef GRAPHICSIMAGEITEM_H
#define GRAPHICSIMAGEITEM_H

// QT
#include <QtGui>

// CUBATOR
#include <GraphicsTypes.h>

class GraphicsImageItem : public QGraphicsPixmapItem
{
public:

    enum { TYPE = GRAPHICS_IMAGE_TYPE };

    int type() const;

    GraphicsImageItem();

    void setImagePath(const QString imagePath);
    QString imagePath() const;

protected:
    QString _imagePath;
};

#endif // GRAPHICSIMAGEITEM_H
