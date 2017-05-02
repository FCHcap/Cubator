#include "AreaCalculatorProcess.h"

AreaCalculatorProcess::AreaCalculatorProcess() : _item(NULL)
{
}

void AreaCalculatorProcess::setAreaItem(GraphicsAreaItem *item) {
    _item = item;
}

void AreaCalculatorProcess::run() {
    try {
        foreach(QPointF point, _item->points()) {
            _polyline.addPoint(point);
        }

        QRectF rectf = _polyline.boundingRect();
        QRect rect(rectf.topLeft().toPoint(), rectf.bottomRight().toPoint());

        qreal surface;
        int size = rect.width() * rect.height();
        int cpt = 0;

        emit processNameUpdated(PROCESS23);
        emit levelUpdated(0);

        for(int i=rect.x(); i<rect.right(); i++) {
            for(int j=rect.y(); j<rect.bottom(); j++) {
                QRect r(QPoint(i, j), QSize(1, 1));
                if(_polyline.polylineContains(r)) {
                    surface ++;
                }
                cpt ++;
                emit levelUpdated(cpt * 100 / size);
            }
        }

        emit surfaceUpdated(surface);


    } catch(CubException &e) {
        emit exceptionLaunched(e);
    }
}
