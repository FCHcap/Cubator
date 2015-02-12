#include "GraphicsMapEventManager.h"

GraphicsMapEventManager::GraphicsMapEventManager(QObject *parent) :
    QObject(parent)
{
}

void GraphicsMapEventManager::updateGraphicsMap(){
    QMutexLocker locker(&_mutex);
    Q_UNUSED(locker)

    emit graphicsMapUpdated();
}
