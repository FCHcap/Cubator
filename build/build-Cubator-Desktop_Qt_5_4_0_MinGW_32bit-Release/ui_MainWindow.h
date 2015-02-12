/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "GraphicsView.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionViewCenterGps;
    QAction *actionDbEditTables;
    QAction *actionDbShowTable;
    QAction *actionDevicesEnableSimulationGps;
    QAction *actionDevicesEnableGps;
    QAction *actionDevicesEnableSounder;
    QAction *actionToolsSettings;
    QAction *actionSelectTool;
    QAction *actionMoveTool;
    QAction *actionSaveTool;
    QAction *actionPointAddTool;
    QAction *actionLineAddTool;
    QAction *actionPolylineAddTool;
    QAction *actionTextAddTool;
    QAction *actionFillTool;
    QAction *actionColorSelectTool;
    QAction *actionLineWidthTool;
    QAction *actionFontTool;
    QAction *actionSettings;
    QAction *actionIconAddTool;
    QAction *actionIconXYAddTool;
    QAction *actionRecordTool;
    QAction *actionMeshTool;
    QAction *actionVolumeTool;
    QAction *actionFileExit;
    QAction *actionSaveAllTool;
    QAction *actionDevicesEnableSimulationSounder;
    QAction *actionSelect_shape;
    QAction *actionEnable;
    QAction *actionMapAdd;
    QAction *actionMapNew;
    QAction *actionMapSave;
    QAction *actionMapSaveAll;
    QAction *actionMapRemove;
    QAction *actionMapSaveAs;
    QAction *actionMapVisibility;
    QAction *actionDbAddFileXYZ;
    QAction *actionConvertMapFile;
    QAction *actionMapLayerAdd;
    QAction *actionMapLayerRemove;
    QAction *actionMapLayerVisibility;
    QAction *actionMapLayerElevation;
    QAction *actionMapLayerOpacity;
    QAction *actionMapLayerEditable;
    QAction *actionMapInsertIconDefinition;
    QAction *actionMapRemoveIconDefinition;
    QAction *actionMapInsertMesh;
    QAction *actionMapRemoveMesh;
    QAction *actionMapCenteringGps;
    QAction *actionMapInsertBoatDefinition;
    QAction *actionMapRemoveBoatDefinition;
    QAction *actionMeasureAddTool;
    QAction *actionDbConvertToNgf;
    QAction *actionPointXyzDbAddTool;
    QAction *actionPointXyAddTool;
    QAction *actionPrintInPng;
    QAction *actionMapInsertPicture;
    QAction *actionMapRemovePicture;
    QAction *actionPictureTool;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    GraphicsView *graphicsView;
    QMenuBar *menubar;
    QMenu *menuMap;
    QMenu *menuMapLayers;
    QMenu *menuMapIconsDefinitions;
    QMenu *menuMapMeshes;
    QMenu *menuDatabase;
    QMenu *menuDevices;
    QMenu *menuTools;
    QMenu *menuFiles;
    QMenu *menuShape;
    QStatusBar *statusbar;
    QToolBar *toolBar;
    QToolBar *toolBarCb;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1012, 600);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/cubator.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        actionViewCenterGps = new QAction(MainWindow);
        actionViewCenterGps->setObjectName(QStringLiteral("actionViewCenterGps"));
        actionViewCenterGps->setCheckable(true);
        actionDbEditTables = new QAction(MainWindow);
        actionDbEditTables->setObjectName(QStringLiteral("actionDbEditTables"));
        actionDbShowTable = new QAction(MainWindow);
        actionDbShowTable->setObjectName(QStringLiteral("actionDbShowTable"));
        actionDevicesEnableSimulationGps = new QAction(MainWindow);
        actionDevicesEnableSimulationGps->setObjectName(QStringLiteral("actionDevicesEnableSimulationGps"));
        actionDevicesEnableSimulationGps->setCheckable(true);
        actionDevicesEnableGps = new QAction(MainWindow);
        actionDevicesEnableGps->setObjectName(QStringLiteral("actionDevicesEnableGps"));
        actionDevicesEnableGps->setCheckable(true);
        actionDevicesEnableSounder = new QAction(MainWindow);
        actionDevicesEnableSounder->setObjectName(QStringLiteral("actionDevicesEnableSounder"));
        actionDevicesEnableSounder->setCheckable(true);
        actionToolsSettings = new QAction(MainWindow);
        actionToolsSettings->setObjectName(QStringLiteral("actionToolsSettings"));
        actionSelectTool = new QAction(MainWindow);
        actionSelectTool->setObjectName(QStringLiteral("actionSelectTool"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/select.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSelectTool->setIcon(icon1);
        actionMoveTool = new QAction(MainWindow);
        actionMoveTool->setObjectName(QStringLiteral("actionMoveTool"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/move.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionMoveTool->setIcon(icon2);
        actionSaveTool = new QAction(MainWindow);
        actionSaveTool->setObjectName(QStringLiteral("actionSaveTool"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icons/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSaveTool->setIcon(icon3);
        actionPointAddTool = new QAction(MainWindow);
        actionPointAddTool->setObjectName(QStringLiteral("actionPointAddTool"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icons/point.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPointAddTool->setIcon(icon4);
        actionLineAddTool = new QAction(MainWindow);
        actionLineAddTool->setObjectName(QStringLiteral("actionLineAddTool"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/icons/line.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLineAddTool->setIcon(icon5);
        actionPolylineAddTool = new QAction(MainWindow);
        actionPolylineAddTool->setObjectName(QStringLiteral("actionPolylineAddTool"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/icons/polyline.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPolylineAddTool->setIcon(icon6);
        actionTextAddTool = new QAction(MainWindow);
        actionTextAddTool->setObjectName(QStringLiteral("actionTextAddTool"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/icons/text.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTextAddTool->setIcon(icon7);
        actionFillTool = new QAction(MainWindow);
        actionFillTool->setObjectName(QStringLiteral("actionFillTool"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/icons/paint.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFillTool->setIcon(icon8);
        actionColorSelectTool = new QAction(MainWindow);
        actionColorSelectTool->setObjectName(QStringLiteral("actionColorSelectTool"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/icons/color.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionColorSelectTool->setIcon(icon9);
        actionLineWidthTool = new QAction(MainWindow);
        actionLineWidthTool->setObjectName(QStringLiteral("actionLineWidthTool"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/icons/pen_width.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLineWidthTool->setIcon(icon10);
        actionFontTool = new QAction(MainWindow);
        actionFontTool->setObjectName(QStringLiteral("actionFontTool"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/icons/fonts.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFontTool->setIcon(icon11);
        actionSettings = new QAction(MainWindow);
        actionSettings->setObjectName(QStringLiteral("actionSettings"));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/icons/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSettings->setIcon(icon12);
        actionIconAddTool = new QAction(MainWindow);
        actionIconAddTool->setObjectName(QStringLiteral("actionIconAddTool"));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/icons/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionIconAddTool->setIcon(icon13);
        actionIconXYAddTool = new QAction(MainWindow);
        actionIconXYAddTool->setObjectName(QStringLiteral("actionIconXYAddTool"));
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/icons/iconXY.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionIconXYAddTool->setIcon(icon14);
        actionRecordTool = new QAction(MainWindow);
        actionRecordTool->setObjectName(QStringLiteral("actionRecordTool"));
        actionRecordTool->setCheckable(true);
        QIcon icon15;
        icon15.addFile(QStringLiteral(":/icons/recordDisabled.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon15.addFile(QStringLiteral(":/icons/recordEnabled.png"), QSize(), QIcon::Normal, QIcon::On);
        actionRecordTool->setIcon(icon15);
        actionMeshTool = new QAction(MainWindow);
        actionMeshTool->setObjectName(QStringLiteral("actionMeshTool"));
        QIcon icon16;
        icon16.addFile(QStringLiteral(":/icons/mesh.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionMeshTool->setIcon(icon16);
        actionVolumeTool = new QAction(MainWindow);
        actionVolumeTool->setObjectName(QStringLiteral("actionVolumeTool"));
        QIcon icon17;
        icon17.addFile(QStringLiteral(":/icons/volume.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionVolumeTool->setIcon(icon17);
        actionFileExit = new QAction(MainWindow);
        actionFileExit->setObjectName(QStringLiteral("actionFileExit"));
        actionSaveAllTool = new QAction(MainWindow);
        actionSaveAllTool->setObjectName(QStringLiteral("actionSaveAllTool"));
        QIcon icon18;
        icon18.addFile(QStringLiteral(":/icons/saveAll.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSaveAllTool->setIcon(icon18);
        actionDevicesEnableSimulationSounder = new QAction(MainWindow);
        actionDevicesEnableSimulationSounder->setObjectName(QStringLiteral("actionDevicesEnableSimulationSounder"));
        actionDevicesEnableSimulationSounder->setCheckable(true);
        actionSelect_shape = new QAction(MainWindow);
        actionSelect_shape->setObjectName(QStringLiteral("actionSelect_shape"));
        actionEnable = new QAction(MainWindow);
        actionEnable->setObjectName(QStringLiteral("actionEnable"));
        actionEnable->setCheckable(true);
        actionMapAdd = new QAction(MainWindow);
        actionMapAdd->setObjectName(QStringLiteral("actionMapAdd"));
        actionMapNew = new QAction(MainWindow);
        actionMapNew->setObjectName(QStringLiteral("actionMapNew"));
        actionMapSave = new QAction(MainWindow);
        actionMapSave->setObjectName(QStringLiteral("actionMapSave"));
        actionMapSaveAll = new QAction(MainWindow);
        actionMapSaveAll->setObjectName(QStringLiteral("actionMapSaveAll"));
        actionMapRemove = new QAction(MainWindow);
        actionMapRemove->setObjectName(QStringLiteral("actionMapRemove"));
        actionMapSaveAs = new QAction(MainWindow);
        actionMapSaveAs->setObjectName(QStringLiteral("actionMapSaveAs"));
        actionMapVisibility = new QAction(MainWindow);
        actionMapVisibility->setObjectName(QStringLiteral("actionMapVisibility"));
        actionDbAddFileXYZ = new QAction(MainWindow);
        actionDbAddFileXYZ->setObjectName(QStringLiteral("actionDbAddFileXYZ"));
        actionConvertMapFile = new QAction(MainWindow);
        actionConvertMapFile->setObjectName(QStringLiteral("actionConvertMapFile"));
        actionMapLayerAdd = new QAction(MainWindow);
        actionMapLayerAdd->setObjectName(QStringLiteral("actionMapLayerAdd"));
        actionMapLayerRemove = new QAction(MainWindow);
        actionMapLayerRemove->setObjectName(QStringLiteral("actionMapLayerRemove"));
        actionMapLayerVisibility = new QAction(MainWindow);
        actionMapLayerVisibility->setObjectName(QStringLiteral("actionMapLayerVisibility"));
        actionMapLayerElevation = new QAction(MainWindow);
        actionMapLayerElevation->setObjectName(QStringLiteral("actionMapLayerElevation"));
        actionMapLayerOpacity = new QAction(MainWindow);
        actionMapLayerOpacity->setObjectName(QStringLiteral("actionMapLayerOpacity"));
        actionMapLayerEditable = new QAction(MainWindow);
        actionMapLayerEditable->setObjectName(QStringLiteral("actionMapLayerEditable"));
        actionMapInsertIconDefinition = new QAction(MainWindow);
        actionMapInsertIconDefinition->setObjectName(QStringLiteral("actionMapInsertIconDefinition"));
        actionMapRemoveIconDefinition = new QAction(MainWindow);
        actionMapRemoveIconDefinition->setObjectName(QStringLiteral("actionMapRemoveIconDefinition"));
        actionMapInsertMesh = new QAction(MainWindow);
        actionMapInsertMesh->setObjectName(QStringLiteral("actionMapInsertMesh"));
        actionMapRemoveMesh = new QAction(MainWindow);
        actionMapRemoveMesh->setObjectName(QStringLiteral("actionMapRemoveMesh"));
        actionMapCenteringGps = new QAction(MainWindow);
        actionMapCenteringGps->setObjectName(QStringLiteral("actionMapCenteringGps"));
        actionMapCenteringGps->setCheckable(true);
        actionMapInsertBoatDefinition = new QAction(MainWindow);
        actionMapInsertBoatDefinition->setObjectName(QStringLiteral("actionMapInsertBoatDefinition"));
        actionMapRemoveBoatDefinition = new QAction(MainWindow);
        actionMapRemoveBoatDefinition->setObjectName(QStringLiteral("actionMapRemoveBoatDefinition"));
        actionMeasureAddTool = new QAction(MainWindow);
        actionMeasureAddTool->setObjectName(QStringLiteral("actionMeasureAddTool"));
        QIcon icon19;
        icon19.addFile(QStringLiteral(":/icons/measure.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionMeasureAddTool->setIcon(icon19);
        actionDbConvertToNgf = new QAction(MainWindow);
        actionDbConvertToNgf->setObjectName(QStringLiteral("actionDbConvertToNgf"));
        actionPointXyzDbAddTool = new QAction(MainWindow);
        actionPointXyzDbAddTool->setObjectName(QStringLiteral("actionPointXyzDbAddTool"));
        QIcon icon20;
        icon20.addFile(QStringLiteral(":/icons/pointXYZDb.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPointXyzDbAddTool->setIcon(icon20);
        actionPointXyAddTool = new QAction(MainWindow);
        actionPointXyAddTool->setObjectName(QStringLiteral("actionPointXyAddTool"));
        QIcon icon21;
        icon21.addFile(QStringLiteral(":/icons/pointXYZ.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPointXyAddTool->setIcon(icon21);
        actionPrintInPng = new QAction(MainWindow);
        actionPrintInPng->setObjectName(QStringLiteral("actionPrintInPng"));
        QIcon icon22;
        icon22.addFile(QStringLiteral(":/icons/png.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPrintInPng->setIcon(icon22);
        actionMapInsertPicture = new QAction(MainWindow);
        actionMapInsertPicture->setObjectName(QStringLiteral("actionMapInsertPicture"));
        actionMapRemovePicture = new QAction(MainWindow);
        actionMapRemovePicture->setObjectName(QStringLiteral("actionMapRemovePicture"));
        actionPictureTool = new QAction(MainWindow);
        actionPictureTool->setObjectName(QStringLiteral("actionPictureTool"));
        QIcon icon23;
        icon23.addFile(QStringLiteral(":/icons/picture.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPictureTool->setIcon(icon23);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        graphicsView = new GraphicsView(centralwidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setAutoFillBackground(false);
        graphicsView->setInteractive(true);
        graphicsView->setRenderHints(QPainter::Antialiasing|QPainter::HighQualityAntialiasing|QPainter::SmoothPixmapTransform|QPainter::TextAntialiasing);
        graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);
        graphicsView->setCacheMode(QGraphicsView::CacheBackground);
        graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

        gridLayout->addWidget(graphicsView, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1012, 21));
        menuMap = new QMenu(menubar);
        menuMap->setObjectName(QStringLiteral("menuMap"));
        menuMapLayers = new QMenu(menuMap);
        menuMapLayers->setObjectName(QStringLiteral("menuMapLayers"));
        menuMapIconsDefinitions = new QMenu(menuMap);
        menuMapIconsDefinitions->setObjectName(QStringLiteral("menuMapIconsDefinitions"));
        menuMapMeshes = new QMenu(menuMap);
        menuMapMeshes->setObjectName(QStringLiteral("menuMapMeshes"));
        menuDatabase = new QMenu(menubar);
        menuDatabase->setObjectName(QStringLiteral("menuDatabase"));
        menuDevices = new QMenu(menubar);
        menuDevices->setObjectName(QStringLiteral("menuDevices"));
        menuTools = new QMenu(menubar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        menuFiles = new QMenu(menubar);
        menuFiles->setObjectName(QStringLiteral("menuFiles"));
        menuShape = new QMenu(menubar);
        menuShape->setObjectName(QStringLiteral("menuShape"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setIconSize(QSize(24, 24));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        toolBarCb = new QToolBar(MainWindow);
        toolBarCb->setObjectName(QStringLiteral("toolBarCb"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBarCb);
        MainWindow->insertToolBarBreak(toolBarCb);

        menubar->addAction(menuFiles->menuAction());
        menubar->addAction(menuMap->menuAction());
        menubar->addAction(menuShape->menuAction());
        menubar->addAction(menuDatabase->menuAction());
        menubar->addAction(menuDevices->menuAction());
        menubar->addAction(menuTools->menuAction());
        menuMap->addAction(actionMapNew);
        menuMap->addAction(actionMapAdd);
        menuMap->addAction(actionMapRemove);
        menuMap->addAction(actionMapSave);
        menuMap->addAction(actionMapSaveAs);
        menuMap->addAction(actionMapSaveAll);
        menuMap->addAction(actionMapVisibility);
        menuMap->addAction(menuMapLayers->menuAction());
        menuMap->addAction(menuMapIconsDefinitions->menuAction());
        menuMap->addAction(menuMapMeshes->menuAction());
        menuMap->addAction(actionMapCenteringGps);
        menuMapLayers->addAction(actionMapLayerAdd);
        menuMapLayers->addAction(actionMapLayerRemove);
        menuMapLayers->addAction(actionMapLayerVisibility);
        menuMapLayers->addAction(actionMapLayerElevation);
        menuMapLayers->addAction(actionMapLayerOpacity);
        menuMapLayers->addAction(actionMapLayerEditable);
        menuMapIconsDefinitions->addAction(actionMapInsertIconDefinition);
        menuMapIconsDefinitions->addAction(actionMapRemoveIconDefinition);
        menuMapMeshes->addAction(actionMapInsertMesh);
        menuMapMeshes->addAction(actionMapRemoveMesh);
        menuDatabase->addAction(actionDbEditTables);
        menuDatabase->addAction(actionDbShowTable);
        menuDatabase->addAction(actionDbAddFileXYZ);
        menuDatabase->addAction(actionDbConvertToNgf);
        menuDevices->addAction(actionDevicesEnableGps);
        menuDevices->addAction(actionDevicesEnableSounder);
        menuTools->addAction(actionToolsSettings);
        menuTools->addAction(actionConvertMapFile);
        menuFiles->addAction(actionFileExit);
        menuShape->addAction(actionSelect_shape);
        menuShape->addAction(actionEnable);
        toolBar->addAction(actionSelectTool);
        toolBar->addAction(actionMoveTool);
        toolBar->addAction(actionSaveTool);
        toolBar->addAction(actionSaveAllTool);
        toolBar->addAction(actionPointAddTool);
        toolBar->addAction(actionPointXyAddTool);
        toolBar->addAction(actionLineAddTool);
        toolBar->addAction(actionPolylineAddTool);
        toolBar->addAction(actionTextAddTool);
        toolBar->addAction(actionPictureTool);
        toolBar->addAction(actionMeasureAddTool);
        toolBar->addAction(actionFillTool);
        toolBar->addAction(actionColorSelectTool);
        toolBar->addAction(actionLineWidthTool);
        toolBar->addAction(actionFontTool);
        toolBar->addAction(actionSettings);
        toolBar->addSeparator();
        toolBar->addAction(actionIconAddTool);
        toolBar->addAction(actionIconXYAddTool);
        toolBar->addSeparator();
        toolBar->addAction(actionRecordTool);
        toolBar->addAction(actionMeshTool);
        toolBar->addAction(actionVolumeTool);
        toolBar->addAction(actionPointXyzDbAddTool);
        toolBar->addSeparator();
        toolBar->addAction(actionPrintInPng);

        retranslateUi(MainWindow);
        QObject::connect(toolBar, SIGNAL(actionTriggered(QAction*)), MainWindow, SLOT(onToolTriggered(QAction*)));
        QObject::connect(menubar, SIGNAL(triggered(QAction*)), MainWindow, SLOT(onMenuTriggered(QAction*)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Cubator", 0));
        actionViewCenterGps->setText(QApplication::translate("MainWindow", "CenteringGPS", 0));
#ifndef QT_NO_TOOLTIP
        actionViewCenterGps->setToolTip(QApplication::translate("MainWindow", "Centering map with GPS position.", 0));
#endif // QT_NO_TOOLTIP
        actionDbEditTables->setText(QApplication::translate("MainWindow", "Edit tables", 0));
#ifndef QT_NO_TOOLTIP
        actionDbEditTables->setToolTip(QApplication::translate("MainWindow", "Edit tables.", 0));
#endif // QT_NO_TOOLTIP
        actionDbShowTable->setText(QApplication::translate("MainWindow", "Show table", 0));
#ifndef QT_NO_TOOLTIP
        actionDbShowTable->setToolTip(QApplication::translate("MainWindow", "Edit tables contents.", 0));
#endif // QT_NO_TOOLTIP
        actionDevicesEnableSimulationGps->setText(QApplication::translate("MainWindow", "SimulateGps", 0));
#ifndef QT_NO_TOOLTIP
        actionDevicesEnableSimulationGps->setToolTip(QApplication::translate("MainWindow", "Simulate gps", 0));
#endif // QT_NO_TOOLTIP
        actionDevicesEnableGps->setText(QApplication::translate("MainWindow", "EnableGps", 0));
#ifndef QT_NO_TOOLTIP
        actionDevicesEnableGps->setToolTip(QApplication::translate("MainWindow", "Enable gps.", 0));
#endif // QT_NO_TOOLTIP
        actionDevicesEnableSounder->setText(QApplication::translate("MainWindow", "EnableSounder", 0));
        actionToolsSettings->setText(QApplication::translate("MainWindow", "Settings", 0));
#ifndef QT_NO_TOOLTIP
        actionToolsSettings->setToolTip(QApplication::translate("MainWindow", "Settings.", 0));
#endif // QT_NO_TOOLTIP
        actionSelectTool->setText(QApplication::translate("MainWindow", "SelectTool", 0));
        actionMoveTool->setText(QApplication::translate("MainWindow", "MoveTool", 0));
        actionSaveTool->setText(QApplication::translate("MainWindow", "SaveTool", 0));
        actionPointAddTool->setText(QApplication::translate("MainWindow", "PointAddTool", 0));
        actionLineAddTool->setText(QApplication::translate("MainWindow", "LineAddTool", 0));
        actionPolylineAddTool->setText(QApplication::translate("MainWindow", "PolylineAddTool", 0));
        actionTextAddTool->setText(QApplication::translate("MainWindow", "TextAddTool", 0));
        actionFillTool->setText(QApplication::translate("MainWindow", "FillTool", 0));
        actionColorSelectTool->setText(QApplication::translate("MainWindow", "ColorSelectTool", 0));
        actionLineWidthTool->setText(QApplication::translate("MainWindow", "LineWidthTool", 0));
        actionFontTool->setText(QApplication::translate("MainWindow", "FontTool", 0));
        actionSettings->setText(QApplication::translate("MainWindow", "SettingsTool", 0));
        actionIconAddTool->setText(QApplication::translate("MainWindow", "IconAddTool", 0));
        actionIconXYAddTool->setText(QApplication::translate("MainWindow", "IconXYAddTool", 0));
        actionRecordTool->setText(QApplication::translate("MainWindow", "RecordTool", 0));
        actionMeshTool->setText(QApplication::translate("MainWindow", "MeshTool", 0));
        actionVolumeTool->setText(QApplication::translate("MainWindow", "VolumeTool", 0));
        actionFileExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        actionSaveAllTool->setText(QApplication::translate("MainWindow", "actionSaveAllTool", 0));
        actionDevicesEnableSimulationSounder->setText(QApplication::translate("MainWindow", "Simulate Sounder", 0));
        actionSelect_shape->setText(QApplication::translate("MainWindow", "Select Table", 0));
        actionEnable->setText(QApplication::translate("MainWindow", "Enable", 0));
        actionMapAdd->setText(QApplication::translate("MainWindow", "Add file", 0));
        actionMapNew->setText(QApplication::translate("MainWindow", "New file", 0));
        actionMapSave->setText(QApplication::translate("MainWindow", "Save map", 0));
        actionMapSaveAll->setText(QApplication::translate("MainWindow", "Save all files", 0));
        actionMapRemove->setText(QApplication::translate("MainWindow", "Remove file", 0));
        actionMapSaveAs->setText(QApplication::translate("MainWindow", "Save map as", 0));
        actionMapVisibility->setText(QApplication::translate("MainWindow", "Select maps visible", 0));
        actionDbAddFileXYZ->setText(QApplication::translate("MainWindow", "Add File XYZ", 0));
        actionConvertMapFile->setText(QApplication::translate("MainWindow", "Convert map file", 0));
        actionMapLayerAdd->setText(QApplication::translate("MainWindow", "Add layer", 0));
        actionMapLayerRemove->setText(QApplication::translate("MainWindow", "Remove layer", 0));
        actionMapLayerVisibility->setText(QApplication::translate("MainWindow", "Visibility", 0));
        actionMapLayerElevation->setText(QApplication::translate("MainWindow", "Elevation", 0));
        actionMapLayerOpacity->setText(QApplication::translate("MainWindow", "Opacity", 0));
        actionMapLayerEditable->setText(QApplication::translate("MainWindow", "Editable", 0));
        actionMapInsertIconDefinition->setText(QApplication::translate("MainWindow", "Insert definition", 0));
        actionMapRemoveIconDefinition->setText(QApplication::translate("MainWindow", "Remove definition", 0));
        actionMapInsertMesh->setText(QApplication::translate("MainWindow", "Insert mesh", 0));
        actionMapRemoveMesh->setText(QApplication::translate("MainWindow", "Remove mesh", 0));
        actionMapCenteringGps->setText(QApplication::translate("MainWindow", "Centering Gps", 0));
        actionMapInsertBoatDefinition->setText(QApplication::translate("MainWindow", "Insert definition", 0));
        actionMapRemoveBoatDefinition->setText(QApplication::translate("MainWindow", "Remove definition", 0));
        actionMeasureAddTool->setText(QApplication::translate("MainWindow", "MeasureAddTool", 0));
#ifndef QT_NO_TOOLTIP
        actionMeasureAddTool->setToolTip(QApplication::translate("MainWindow", "Add measure", 0));
#endif // QT_NO_TOOLTIP
        actionDbConvertToNgf->setText(QApplication::translate("MainWindow", "Convert to NGF", 0));
        actionPointXyzDbAddTool->setText(QApplication::translate("MainWindow", "Add point XYZ", 0));
        actionPointXyAddTool->setText(QApplication::translate("MainWindow", "Add point XY", 0));
#ifndef QT_NO_TOOLTIP
        actionPointXyAddTool->setToolTip(QApplication::translate("MainWindow", "Add point XY", 0));
#endif // QT_NO_TOOLTIP
        actionPrintInPng->setText(QApplication::translate("MainWindow", "Print in a picture (PNG)", 0));
#ifndef QT_NO_TOOLTIP
        actionPrintInPng->setToolTip(QApplication::translate("MainWindow", "Print in a picture (PNG)", 0));
#endif // QT_NO_TOOLTIP
        actionMapInsertPicture->setText(QApplication::translate("MainWindow", "Insert picture", 0));
        actionMapRemovePicture->setText(QApplication::translate("MainWindow", "Remove picture", 0));
        actionPictureTool->setText(QApplication::translate("MainWindow", "actionPictureTool", 0));
#ifndef QT_NO_TOOLTIP
        actionPictureTool->setToolTip(QApplication::translate("MainWindow", "Add a picture", 0));
#endif // QT_NO_TOOLTIP
        menuMap->setTitle(QApplication::translate("MainWindow", "Map", 0));
        menuMapLayers->setTitle(QApplication::translate("MainWindow", "Layers", 0));
        menuMapIconsDefinitions->setTitle(QApplication::translate("MainWindow", "Definitions of icons", 0));
        menuMapMeshes->setTitle(QApplication::translate("MainWindow", "Meshes", 0));
        menuDatabase->setTitle(QApplication::translate("MainWindow", "Database", 0));
        menuDevices->setTitle(QApplication::translate("MainWindow", "Devices", 0));
        menuTools->setTitle(QApplication::translate("MainWindow", "Tools", 0));
        menuFiles->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuShape->setTitle(QApplication::translate("MainWindow", "AutoDepth", 0));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
        toolBarCb->setWindowTitle(QApplication::translate("MainWindow", "toolBar_2", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
