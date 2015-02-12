#ifndef PMLWRITER_H
#define PMLWRITER_H

// QT
#include <QString>
#include <QDomElement>
#include <QMap>

// CUBATOR
#include <DefaultProcess.h>
#include <GraphicsMap.h>
#include <GraphicsImageItem.h>
#include <GraphicsVolumeItem.h>
#include <GraphicsPointXYItem.h>
#include <PmlElements.h>

class PmlWriter : public DefaultProcess
{
    Q_OBJECT

public:
    PmlWriter(QObject * parent = 0);
    void setList(QMap<QString, GraphicsMap*> list);
    void sortByType(bool sortByType);

public slots:
    void run();

protected:
    void writeLayer(QDomDocument &doc, QDomElement &layer, const QGraphicsItem * item);
    void writeLine(QDomElement & element, const QLineF & color);
    void writePoint(QDomElement & element, const QPointF & point);
    void writeRect(QDomElement & element, const QRectF & rect);
    void writeRect(QDomElement & element, const QRect & rect);
    void writePenAttributes(QDomElement & element, const QPen & pen);
    void writeBrushAttributes(QDomElement & element, const QBrush & brush);
    void writeFontAttributes(QDomElement & element, const QFont & font);

protected:
    QMap<QString, GraphicsMap*> _list; // Key : filepath
    bool _sortByType;
    int _cpt;
    int _size;
};

#endif // PMLWRITER_H
