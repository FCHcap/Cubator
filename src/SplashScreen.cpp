#include "SplashScreen.h"

// QT
#include <QVBoxLayout>
#include <QLabel>

SplashScreen::SplashScreen(QPixmap &pixmap) : QDialog(0, Qt::SplashScreen)
{
    QVBoxLayout * layout = new QVBoxLayout;
    QLabel * image = new QLabel(this);
    image->setPixmap(pixmap);
    layout->addWidget(image);
    this->setLayout(layout);

    this->setAttribute(Qt::WA_TranslucentBackground);
}
