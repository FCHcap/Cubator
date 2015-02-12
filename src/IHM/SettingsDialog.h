#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

// QT
#include <QDialog>
#include <QListWidget>
#include <QFileDialog>

// CUBATOR
#include <Settings.h>
#include <GeoEllipsoid.h>
#include <GeoDatum.h>
#include <GeoProjection.h>
#include <InfoMap.h>
#include <DeviceProcess.h>
#include <Defines.h>

namespace Ui{
    class SettingsDialog;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT
public:
    explicit SettingsDialog(QWidget *parent = 0);
    ~SettingsDialog();

    bool mapsUpdated();
    bool iconsUpdated();
    bool boatsUpdated();
    bool databaseUpdated();
    bool devicesUpdated();
    bool statusBarUpdated();

protected slots:
    void onMapAddEvent();
    void onMapRemoveEvent();
    void onMapsCenterViewEvent(bool);

    void onBoatAddEvent();
    void onBoatRemoveEvent();

    void onEllChangeEvent();
    void onDatChangeEvent();
    void onProChangeEvent();

    void onAcceptEvent();
    void onRejectEvent();

    void updateDevice();
    void updateStatusBar();

protected:
    void loadSettings();
    void writeSettings();
    void saveLastEllipsoid();
    void saveLastDatum();
    void saveLastProjection();
    void updateMapDefault(QString map="");
    void updateDatabaseTablesDefault();

private:
    Ui::SettingsDialog *ui;
    QMap<QString,QString> _mMaps;
    QMap<QString,QString> _mBoats;
    QStringList _bauds;
    QStringList _com;
    GeoEllipsoids _ellipsoids;
    GeoDatums _datums;
    GeoProjections _projections;

    bool _mapsUpdated;
    bool _iconsUpdated;
    bool _boatsUpdated;
    bool _databaseUpdated;
    bool _devicesUpdated;
    bool _statusBarUpdated;

    QListWidgetItem *_lastEllItem;
    QListWidgetItem *_lastDatItem;
    QListWidgetItem *_lastProItem;
    
};

#endif // SETTINGSDIALOG_H
