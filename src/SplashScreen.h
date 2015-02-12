#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

// QT
#include <QDialog>
#include <QPixmap>
#include <QtGui>

class SplashScreen : public QDialog
{
    Q_OBJECT

public:
    SplashScreen(QPixmap &pixmap);
};

#endif // SPLASHSCREEN_H
