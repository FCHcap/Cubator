#ifndef GRAPHICSMAPEVENTMANAGER_H
#define GRAPHICSMAPEVENTMANAGER_H

// QT
#include <QObject>
#include <QMutex>
#include <QMutexLocker>

class GraphicsMapEventManager : public QObject
{
    Q_OBJECT
public:
    explicit GraphicsMapEventManager(QObject *parent = 0);
    void updateGraphicsMap();

signals:
    void graphicsMapUpdated();

protected:
    QMutex _mutex;
};

#endif // GRAPHICSMAPEVENTMANAGER_H
