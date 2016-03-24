#ifndef BOATMANAGER_H
#define BOATMANAGER_H

// QT
#include <QObject>
#include <QWidget>

// CUBATOR
#include <GraphicsScene.h>
#include <CubException.h>
#include <PmlReader.h>
#include <GraphicsMapBoatDef.h>
#include <GraphicsBoatItem.h>
#include <Gps.h>

class BoatManager : public QObject
{
    Q_OBJECT

protected:
    typedef QMap<QString, GraphicsMapBoatDef*> Boats; // <Name of boat, definition pointer>

public:
    BoatManager(GraphicsScene * scene = 0, QObject *parent = 0, QWidget *widget = 0);
    ~BoatManager();

    void setScene(GraphicsScene * scene);
    void setParentWidget(QWidget * widget);

    void applySettings();

    void addBoatFile(const QString &filepath);
    void removeBoatFile(const QString &boatName);
    void removeAllBoatsFiles();

    void selectBoat(const QString &boat);
    QString boatSelected() const;

    QStringList boats();

    void connectToGps(Gps * gps);

signals:
    void boatManagerUpdated();

protected slots:
    void showError(CubException e);
    void finishBoatLoader(QString boatFile, GraphicsMap * graphics);
    void updateGpsPosition(QPointF);
    void updateDisplaying(bool);

protected:
    GraphicsScene *_scene;
    QWidget *_widget;
    QMap<QString, Boats> _mBoatsDefs; // <File name without extension, Boats>
    GraphicsBoatItem _boatItem;
};

#endif // BOATMANAGER_H
