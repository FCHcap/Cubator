#ifndef GRAPHICSVOLUMEITEM_H
#define GRAPHICSVOLUMEITEM_H

// QT
#include <QtGui>
#include <QAction>

// CUBATOR
#include <GraphicsPolylineItem.h>
#include <Messages.h>

// STL
#include <climits>

class GraphicsVolumeItem : public QObject, public GraphicsPolylineItem
{
    Q_OBJECT

public:
    enum { Type = GRAPHICS_VOLUME_TYPE };

    GraphicsVolumeItem(QGraphicsItem * parent = 0);
    ~GraphicsVolumeItem();

    int type() const;

    QList<QRect> rects() const;

    qreal surface() const;

    qreal volume() const;

    void setFont(const QFont &font);
    QFont font() const;

    void setPen(const QPen &pen);

    void setMeshColor(const QColor &color);
    QColor meshColor() const;

    void setTextColor(const QColor &color);
    QColor textColor() const;

    void setMeshVisible(bool visible = 1);
    bool meshVisible() const;

    void setTextVisible(bool visible = 1);
    bool textVisible() const;

    void setTextTransform(const QTransform &transform);
    QTransform textTransform() const;

    void updateRects();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);

protected slots:
    void updateTextItem();

public slots:
    void addRect(const QRect &rect);
    void addPoint(const QPointF &point);
    void setSurface(qreal surface);
    void setVolume(qreal volume);

protected:
    QList<QRect> _rectangles;
    qreal _surface;
    qreal _volume;
    QColor _meshColor;
    QGraphicsTextItem _textItem;
    bool _meshVisible;
};

#endif // GRAPHICSVOLUMEITEM_H
