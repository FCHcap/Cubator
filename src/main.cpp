// QT
#include <QApplication>
#include <QTranslator>
#include <QSplashScreen>

// STL
#include <exception>
#include <iostream>

// CUBATOR
#include <Messages.h>
#include <MainWindow.h>
#include <Settings.h>
#include <ErrorDialog.h>
#include <SplashScreen.h>
#include <CubException.h>

#define SPLASH_PICTURE ":/pictures/splashscreen.png"
#define CUBATORFR_QM "cubator_fr.qm"

#define QTFR_QM "qt_"+QLocale::system().name(), QLibraryInfo::location(QLibraryInfo::TranslationsPath)
#define QTFR_QM_L "qt_fr.qm"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setApplicationName("Cubator");
    app.setOrganizationName("Fch");

    // Affiche l'écran splash si l'image est trouvée
    QPixmap pixmap(SPLASH_PICTURE);

    if(!pixmap.isNull()) {
        SplashScreen splash(pixmap);
        QTimer::singleShot(2000, &splash, SLOT(accept()));
        splash.exec();
    }

    // Charge la traduction de Cubator
    QTranslator cubTranslator;
    if(!cubTranslator.load(CUBATORFR_QM)){
        QMessageBox::warning(0, TITLE05, ERROR22 + '\n' + TEXT01 + QString(CUBATORFR_QM));
    }
    else
        app.installTranslator(&cubTranslator);

    // Charge la traduction de QT
    QTranslator qtTranslator;
    if(!qtTranslator.load(QTFR_QM)){
        if(!qtTranslator.load(QTFR_QM_L))
            QMessageBox::warning(0, TITLE05, ERROR22 + '\n' + TEXT01 + QString(QTFR_QM_L));
    }
    else
        app.installTranslator(&qtTranslator);

    // Charge et affiche la fenêtre principale
    MainWindow * window = MainWindow::getInstance();
    window->setWindowState(Qt::WindowMaximized);
    window->show();

    int code = app.exec(); // Lance la boucle d'évènements

    // Détruit les objets
    try{
        Data::kill();
        MainWindow::kill();
        Settings::kill();
    }
    catch(CubException &e){
        ErrorDialog::errorDialog(NULL, e);
    }

    return code;
}
