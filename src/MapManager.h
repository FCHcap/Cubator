#ifndef MAPMANAGER_H
#define MAPMANAGER_H

// QT
#include <QtGui>
#include <QPointer>
#include <QThread>

// CUBATOR
#include <GraphicsScene.h>
#include <PmlSaveDialog.h>
#include <PmlWriter.h>
#include <Settings.h>
#include <CubException.h>
#include <CubDxfReader.h>
#include <PmlReader.h>
#include <InfoMap.h>
#include <GraphicsMapEventManager.h>
#include <Map.h>

class GraphicsMap;

class MapManager : public QObject
{
    Q_OBJECT

public:
    MapManager(GraphicsScene * scene = 0, QObject *parent = 0, QWidget *widget = 0);
    ~MapManager();

    void waitThreads();

    void setScene(GraphicsScene * scene);
    void setParentWidget(QWidget * widget);

    void applySettings();

    void newMap(const QString &path);
    void addMap(const QString &path);
    void removeMap(const QString &map);
    void removeAllMaps();

    void addIcon(const QString &filepath);

    void saveMap(const QString &map);
    void saveMapAs();
    void saveAllMaps();
    void saveAllMapsWithQuestion();

    void selectMap(const QString &map);
    QString mapSelected();
    QString mapSelectedWithStatusUpdate();

    QStringList maps();
    QStringList mapsWithStatusUpdate();
    QString filepath(const QString & map);
    bool mapExists(const QString & map);

    GraphicsMap * item(QString map);

signals:
    void mapManagerUpdated();
    void mapUpdated();

protected slots:
    void showError(CubException e);
    void finishIconLoader(QString icon, GraphicsMap * graphics);
    void finishMapLoader(QString map, GraphicsMap * graphics);

protected:
    GraphicsScene *_scene;
    QWidget *_widget;
    PmlWriter *_writer;
    QMap<QString, Map> _mMaps; // key : filename without the extension
    QString _mapSelected;
    GraphicsMapEventManager _eventManager;
    QList<QPointer<QThread> > _threads; // Liste des threads en cours d'exécution; utilisée par le destructeur
};

#endif // MAPMANAGER_H
