#ifndef PMLREADER_H
#define PMLREADER_H

// QT
#include <QtXml>
#include <QtGui>

// CUBATOR
#include <GraphicsMapIconDef.h>
#include <GraphicsMapBoatDef.h>
#include <GraphicsVolumeItem.h>
#include <GraphicsPointXYItem.h>
#include <GraphicsPointXYZItem.h>
#include <GraphicsMeshItem.h>
#include <DefaultProcess.h>
#include <InfoMap.h>
#include <Messages.h>
#include <DVertexList.h>

class PmlReader : public LoaderMapProcess
{

public:
    PmlReader(const QString &filepath = "");

    void setFilepath(const QString &filepath);
    QString filepath() const;

public slots:
    void run();

protected:
    QLineF readingLine(QDomElement & element);
    QPointF readingPoint(QDomElement & element);
    DVertex readingVertex(QDomElement & element);
    QRectF readingRectf(QDomElement & element);
    QRect readingRect(QDomElement & element);
    QPen readingPenAttributes(QDomElement & element);
    QBrush readingBrushAttributes(QDomElement & element);
    QFont readingFontAttributes(QDomElement & element);
    QString convertRelativePathToAbsolute(const QString filepath);

    QString normalizeFilepath(const QString filepath) const;


protected:
    QString _filepath;
};

#endif // PMLREADER_H
