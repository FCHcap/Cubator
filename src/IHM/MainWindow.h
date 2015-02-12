#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// QT
#include <QMainWindow>
#include <QLabel>
#include <QComboBox>
#include <QThread>
#include <QColorDialog>
#include <QFontDialog>

// CUBATOR
#include <GraphicsView.h>
#include <GraphicsScene.h>
#include <SettingsDialog.h>
#include <SelectItemDialog.h>
#include <CheckItemsDialog.h>
#include <FileXyzReaderDialog.h>
#include <DbTableEditDialog.h>
#include <DbShowTableDialog.h>
#include <MeshDialog.h>
#include <ConvertMapFileDialog.h>
#include <InputIntToStringDialog.h>
#include <CreateIconDialog.h>
#include <ConvertToNgfDialog.h>
#include <GpsWidget.h>
#include <GraphicsBoatItem.h>
#include <VolumeCalculatorDialog.h>
#include <VolumeCalculatorProcess.h>
#include <MapManager.h>
#include <BoatManager.h>
#include <Settings.h>
#include <Gps.h>
#include <Messages.h>
#include <Defines.h>
#include <CubException.h>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    explicit MainWindow();
    ~MainWindow();

public:
    static MainWindow* getInstance();
    static void kill();

protected:
    void initCbToolBar();
    void selectTool(QAction* action);

signals:
    void reloadDevicesSettings();
    void enableGps(bool);
    void enableSonar(bool);

protected slots:
    void updateMapCb();
    void updateLayerCb();
    void updateIconCb();
    void updateBoatCb();
    void updateTableCb();
    void updateToolbarsMenus();
    void showSettingsDialog();
    void showError(CubException exception);
    void onToolTriggered(QAction* action);
    void onMenuTriggered(QAction* action);
    void cbMapsIndexChanged(QString map);
    void cbLayersIndexChanged(const QString &layer);
    void cbIconsIndexChanged(const QString &icon);
    void cbBoatsIndexChanged(const QString &boat);
    void updateMousePosition(QPointF position);
    void addMouseMeshDepth(QString tableName, double depth); // if the variable depth is positive then it is ignored
    void clearMeshDepth();
    void closeEvent(QCloseEvent *);
    void calculateVolume(GraphicsVolumeItem * item);
    void addPointXYZ(QPointF position);

protected:
    GraphicsScene * _scene;
    MapManager _mapManager;
    BoatManager _boatManager;
    Ui::MainWindow * ui;
    QStringList _lastMapsItems; // Used for checking the maps combobox
    QStringList _lastLayersItems; // Used for checking the layers combobox

    static MainWindow * _window;

    QComboBox * _cbMaps;
    QComboBox * _cbLayers;
    QComboBox * _cbIcons;
    QComboBox * _cbBoats;
    QComboBox * _cbTables;
    QAction * _actionSelected;

    QLabel _statusPos;
    QLabel _statusDepth;
    QLabel _statusPosGeo;

    Gps * _gps;
    CubGeo _geo;

    QString _sbPro;
    QString _sbGpsFrm;
};

#endif // MAINWINDOW_H
