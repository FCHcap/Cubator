/********************************************************************************
** Form generated from reading UI file 'SettingsDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSDIALOG_H
#define UI_SETTINGSDIALOG_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsDialog
{
public:
    QGridLayout *gridLayout_5;
    QDialogButtonBox *buttonBox;
    QTabWidget *tabWidget;
    QWidget *wMaps;
    QGridLayout *gridLayout_6;
    QGridLayout *glMaps;
    QListWidget *lMaps;
    QPushButton *pbMapRemove;
    QSpacerItem *sMaps;
    QPushButton *pbMapAdd;
    QCheckBox *cbMapsCenteringGps;
    QCheckBox *cbMapsEnableChanges;
    QLabel *lMapsDefault;
    QComboBox *cbMapsDefault;
    QSpacerItem *hsMaps1;
    QCheckBox *cbMapsCenterView;
    QLabel *lMapsCenterViewX;
    QLineEdit *leMapsCenterViewX;
    QSpacerItem *hsMaps2;
    QLabel *lMapsCenterViewY;
    QLineEdit *leMapsCenterViewY;
    QWidget *wBoats;
    QGridLayout *gridLayout_7;
    QListWidget *lBoats;
    QPushButton *pbBoatAdd;
    QPushButton *pbBoatRemove;
    QSpacerItem *verticalSpacer;
    QWidget *wDevices;
    QGridLayout *gridLayout;
    QGroupBox *gbDevicesSonar;
    QGridLayout *gridLayout_4;
    QLabel *lDevicesSonarStopBit;
    QLabel *lDevicesSonarParity;
    QComboBox *cbDevicesSonarDataBits;
    QLabel *lDevicesSonarFlowControl;
    QLabel *lDevicesSonarName;
    QLabel *lDevicesSonarBauds;
    QComboBox *cbDevicesSonarBauds;
    QLabel *lDevicesSonarDataBits;
    QCheckBox *cbDevicesSonarEnable;
    QLineEdit *leDevicesSonarName;
    QComboBox *cbDevicesSonarStopBit;
    QComboBox *cbDevicesSonarParity;
    QComboBox *cbDevicesSonarFlowControl;
    QGroupBox *gbDevicesGps;
    QGridLayout *gridLayout_2;
    QLabel *lDevicesGpsDataBits;
    QLabel *lDevicesGpsParity;
    QComboBox *cbDevicesGpsDataBits;
    QLabel *lDevicesGpsName;
    QLineEdit *leDevicesGpsName;
    QCheckBox *cbDevicesGpsEnable;
    QLabel *lDevicesGpsStopBit;
    QLabel *lDevicesGpsBauds;
    QLabel *lDevicesGpsFlowControl;
    QComboBox *cbDevicesGpsBauds;
    QComboBox *cbDevicesGpsStopBit;
    QComboBox *cbDevicesGpsParity;
    QComboBox *cbDevicesGpsFlowControl;
    QSpacerItem *vsDevices;
    QComboBox *cbDevicesProjectionSystem;
    QLabel *lDevicesProjection;
    QWidget *wEllipsoides;
    QGridLayout *gridLayout_28;
    QGroupBox *gbEllNames;
    QGridLayout *gridLayout_9;
    QListWidget *lwEllNames;
    QLabel *lEllSemiMajorAxis;
    QDoubleSpinBox *dsEllSemiMajorAxis;
    QSpacerItem *hsEll;
    QLabel *lEllSemiMinorAxis;
    QDoubleSpinBox *dsEllSemiMinorAxis;
    QSpacerItem *vsEll;
    QWidget *wDatums;
    QGridLayout *gridLayout_3;
    QLabel *lDatEll;
    QComboBox *cbDatEll;
    QGroupBox *lDatTranslation;
    QGridLayout *gridLayout_24;
    QLabel *lDatTranslationX;
    QLabel *lDatTranslationY;
    QLabel *lDatTranslationZ;
    QSpinBox *spDatTranslationX;
    QSpinBox *spDatTranslationY;
    QSpinBox *spDatTranslationZ;
    QGroupBox *lDatRotation;
    QGridLayout *gridLayout_25;
    QLabel *lDatRotationX;
    QLabel *lDatRotationY;
    QLabel *lDatRotationZ;
    QSpinBox *spDatRotationX;
    QSpinBox *spDatRotationY;
    QSpinBox *spDatRotationZ;
    QGroupBox *lDatNames;
    QGridLayout *gridLayout_26;
    QListWidget *lwDatNames;
    QLabel *lDatSf;
    QSpinBox *spDatSf;
    QWidget *wProjections;
    QGridLayout *gridLayout_10;
    QGroupBox *gbProNames;
    QGridLayout *gridLayout_14;
    QListWidget *lwProNames;
    QLabel *lProDatum;
    QComboBox *cbProDatum;
    QLabel *lProN;
    QDoubleSpinBox *dsProN;
    QSpacerItem *hsPro;
    QLabel *lProC;
    QDoubleSpinBox *dsProC;
    QLabel *lProL0;
    QDoubleSpinBox *dsProL0;
    QGroupBox *gbProCoor0;
    QGridLayout *gridLayout_15;
    QLabel *lProXs;
    QDoubleSpinBox *dsProXs;
    QLabel *lProYs;
    QDoubleSpinBox *dsProYs;
    QSpacerItem *vsPro;
    QWidget *wStatus;
    QGridLayout *gridLayout_8;
    QLabel *lStatusProjection;
    QComboBox *cbStatusProjection;
    QSpacerItem *hsStatus;
    QLabel *lStatusFormatGps;
    QComboBox *cbStatusFormatGps;
    QSpacerItem *vsStatus;

    void setupUi(QDialog *SettingsDialog)
    {
        if (SettingsDialog->objectName().isEmpty())
            SettingsDialog->setObjectName(QStringLiteral("SettingsDialog"));
        SettingsDialog->resize(522, 494);
        SettingsDialog->setMinimumSize(QSize(522, 494));
        SettingsDialog->setMaximumSize(QSize(522, 494));
        SettingsDialog->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        gridLayout_5 = new QGridLayout(SettingsDialog);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        buttonBox = new QDialogButtonBox(SettingsDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_5->addWidget(buttonBox, 2, 0, 1, 1);

        tabWidget = new QTabWidget(SettingsDialog);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        wMaps = new QWidget();
        wMaps->setObjectName(QStringLiteral("wMaps"));
        gridLayout_6 = new QGridLayout(wMaps);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        glMaps = new QGridLayout();
        glMaps->setObjectName(QStringLiteral("glMaps"));
        lMaps = new QListWidget(wMaps);
        lMaps->setObjectName(QStringLiteral("lMaps"));

        glMaps->addWidget(lMaps, 0, 0, 3, 1);

        pbMapRemove = new QPushButton(wMaps);
        pbMapRemove->setObjectName(QStringLiteral("pbMapRemove"));

        glMaps->addWidget(pbMapRemove, 1, 1, 1, 1);

        sMaps = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        glMaps->addItem(sMaps, 2, 1, 1, 1);

        pbMapAdd = new QPushButton(wMaps);
        pbMapAdd->setObjectName(QStringLiteral("pbMapAdd"));

        glMaps->addWidget(pbMapAdd, 0, 1, 1, 1);


        gridLayout_6->addLayout(glMaps, 0, 0, 1, 4);

        cbMapsCenteringGps = new QCheckBox(wMaps);
        cbMapsCenteringGps->setObjectName(QStringLiteral("cbMapsCenteringGps"));

        gridLayout_6->addWidget(cbMapsCenteringGps, 1, 0, 1, 2);

        cbMapsEnableChanges = new QCheckBox(wMaps);
        cbMapsEnableChanges->setObjectName(QStringLiteral("cbMapsEnableChanges"));

        gridLayout_6->addWidget(cbMapsEnableChanges, 2, 0, 1, 2);

        lMapsDefault = new QLabel(wMaps);
        lMapsDefault->setObjectName(QStringLiteral("lMapsDefault"));

        gridLayout_6->addWidget(lMapsDefault, 3, 0, 1, 2);

        cbMapsDefault = new QComboBox(wMaps);
        cbMapsDefault->setObjectName(QStringLiteral("cbMapsDefault"));
        cbMapsDefault->setMinimumSize(QSize(150, 0));

        gridLayout_6->addWidget(cbMapsDefault, 3, 2, 1, 1);

        hsMaps1 = new QSpacerItem(58, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(hsMaps1, 3, 3, 1, 1);

        cbMapsCenterView = new QCheckBox(wMaps);
        cbMapsCenterView->setObjectName(QStringLiteral("cbMapsCenterView"));

        gridLayout_6->addWidget(cbMapsCenterView, 4, 0, 1, 2);

        lMapsCenterViewX = new QLabel(wMaps);
        lMapsCenterViewX->setObjectName(QStringLiteral("lMapsCenterViewX"));

        gridLayout_6->addWidget(lMapsCenterViewX, 5, 0, 1, 1);

        leMapsCenterViewX = new QLineEdit(wMaps);
        leMapsCenterViewX->setObjectName(QStringLiteral("leMapsCenterViewX"));

        gridLayout_6->addWidget(leMapsCenterViewX, 5, 1, 1, 1);

        hsMaps2 = new QSpacerItem(220, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(hsMaps2, 5, 2, 1, 2);

        lMapsCenterViewY = new QLabel(wMaps);
        lMapsCenterViewY->setObjectName(QStringLiteral("lMapsCenterViewY"));

        gridLayout_6->addWidget(lMapsCenterViewY, 6, 0, 1, 1);

        leMapsCenterViewY = new QLineEdit(wMaps);
        leMapsCenterViewY->setObjectName(QStringLiteral("leMapsCenterViewY"));

        gridLayout_6->addWidget(leMapsCenterViewY, 6, 1, 1, 1);

        tabWidget->addTab(wMaps, QString());
        wBoats = new QWidget();
        wBoats->setObjectName(QStringLiteral("wBoats"));
        gridLayout_7 = new QGridLayout(wBoats);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        lBoats = new QListWidget(wBoats);
        lBoats->setObjectName(QStringLiteral("lBoats"));

        gridLayout_7->addWidget(lBoats, 0, 0, 3, 1);

        pbBoatAdd = new QPushButton(wBoats);
        pbBoatAdd->setObjectName(QStringLiteral("pbBoatAdd"));

        gridLayout_7->addWidget(pbBoatAdd, 0, 1, 1, 1);

        pbBoatRemove = new QPushButton(wBoats);
        pbBoatRemove->setObjectName(QStringLiteral("pbBoatRemove"));

        gridLayout_7->addWidget(pbBoatRemove, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 323, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_7->addItem(verticalSpacer, 2, 1, 1, 1);

        tabWidget->addTab(wBoats, QString());
        wDevices = new QWidget();
        wDevices->setObjectName(QStringLiteral("wDevices"));
        gridLayout = new QGridLayout(wDevices);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gbDevicesSonar = new QGroupBox(wDevices);
        gbDevicesSonar->setObjectName(QStringLiteral("gbDevicesSonar"));
        gbDevicesSonar->setEnabled(false);
        gridLayout_4 = new QGridLayout(gbDevicesSonar);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        lDevicesSonarStopBit = new QLabel(gbDevicesSonar);
        lDevicesSonarStopBit->setObjectName(QStringLiteral("lDevicesSonarStopBit"));

        gridLayout_4->addWidget(lDevicesSonarStopBit, 3, 0, 1, 1);

        lDevicesSonarParity = new QLabel(gbDevicesSonar);
        lDevicesSonarParity->setObjectName(QStringLiteral("lDevicesSonarParity"));

        gridLayout_4->addWidget(lDevicesSonarParity, 4, 0, 1, 1);

        cbDevicesSonarDataBits = new QComboBox(gbDevicesSonar);
        cbDevicesSonarDataBits->setObjectName(QStringLiteral("cbDevicesSonarDataBits"));

        gridLayout_4->addWidget(cbDevicesSonarDataBits, 2, 1, 1, 1);

        lDevicesSonarFlowControl = new QLabel(gbDevicesSonar);
        lDevicesSonarFlowControl->setObjectName(QStringLiteral("lDevicesSonarFlowControl"));

        gridLayout_4->addWidget(lDevicesSonarFlowControl, 5, 0, 1, 1);

        lDevicesSonarName = new QLabel(gbDevicesSonar);
        lDevicesSonarName->setObjectName(QStringLiteral("lDevicesSonarName"));

        gridLayout_4->addWidget(lDevicesSonarName, 0, 0, 1, 1);

        lDevicesSonarBauds = new QLabel(gbDevicesSonar);
        lDevicesSonarBauds->setObjectName(QStringLiteral("lDevicesSonarBauds"));

        gridLayout_4->addWidget(lDevicesSonarBauds, 1, 0, 1, 1);

        cbDevicesSonarBauds = new QComboBox(gbDevicesSonar);
        cbDevicesSonarBauds->setObjectName(QStringLiteral("cbDevicesSonarBauds"));
        cbDevicesSonarBauds->setMinimumSize(QSize(100, 0));

        gridLayout_4->addWidget(cbDevicesSonarBauds, 1, 1, 1, 1);

        lDevicesSonarDataBits = new QLabel(gbDevicesSonar);
        lDevicesSonarDataBits->setObjectName(QStringLiteral("lDevicesSonarDataBits"));

        gridLayout_4->addWidget(lDevicesSonarDataBits, 2, 0, 1, 1);

        cbDevicesSonarEnable = new QCheckBox(gbDevicesSonar);
        cbDevicesSonarEnable->setObjectName(QStringLiteral("cbDevicesSonarEnable"));

        gridLayout_4->addWidget(cbDevicesSonarEnable, 6, 0, 1, 2);

        leDevicesSonarName = new QLineEdit(gbDevicesSonar);
        leDevicesSonarName->setObjectName(QStringLiteral("leDevicesSonarName"));

        gridLayout_4->addWidget(leDevicesSonarName, 0, 1, 1, 1);

        cbDevicesSonarStopBit = new QComboBox(gbDevicesSonar);
        cbDevicesSonarStopBit->setObjectName(QStringLiteral("cbDevicesSonarStopBit"));

        gridLayout_4->addWidget(cbDevicesSonarStopBit, 3, 1, 1, 1);

        cbDevicesSonarParity = new QComboBox(gbDevicesSonar);
        cbDevicesSonarParity->setObjectName(QStringLiteral("cbDevicesSonarParity"));

        gridLayout_4->addWidget(cbDevicesSonarParity, 4, 1, 1, 1);

        cbDevicesSonarFlowControl = new QComboBox(gbDevicesSonar);
        cbDevicesSonarFlowControl->setObjectName(QStringLiteral("cbDevicesSonarFlowControl"));

        gridLayout_4->addWidget(cbDevicesSonarFlowControl, 5, 1, 1, 1);


        gridLayout->addWidget(gbDevicesSonar, 0, 2, 1, 1);

        gbDevicesGps = new QGroupBox(wDevices);
        gbDevicesGps->setObjectName(QStringLiteral("gbDevicesGps"));
        gridLayout_2 = new QGridLayout(gbDevicesGps);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        lDevicesGpsDataBits = new QLabel(gbDevicesGps);
        lDevicesGpsDataBits->setObjectName(QStringLiteral("lDevicesGpsDataBits"));

        gridLayout_2->addWidget(lDevicesGpsDataBits, 2, 0, 1, 1);

        lDevicesGpsParity = new QLabel(gbDevicesGps);
        lDevicesGpsParity->setObjectName(QStringLiteral("lDevicesGpsParity"));

        gridLayout_2->addWidget(lDevicesGpsParity, 4, 0, 1, 1);

        cbDevicesGpsDataBits = new QComboBox(gbDevicesGps);
        cbDevicesGpsDataBits->setObjectName(QStringLiteral("cbDevicesGpsDataBits"));

        gridLayout_2->addWidget(cbDevicesGpsDataBits, 2, 1, 1, 1);

        lDevicesGpsName = new QLabel(gbDevicesGps);
        lDevicesGpsName->setObjectName(QStringLiteral("lDevicesGpsName"));

        gridLayout_2->addWidget(lDevicesGpsName, 0, 0, 1, 1);

        leDevicesGpsName = new QLineEdit(gbDevicesGps);
        leDevicesGpsName->setObjectName(QStringLiteral("leDevicesGpsName"));

        gridLayout_2->addWidget(leDevicesGpsName, 0, 1, 1, 1);

        cbDevicesGpsEnable = new QCheckBox(gbDevicesGps);
        cbDevicesGpsEnable->setObjectName(QStringLiteral("cbDevicesGpsEnable"));

        gridLayout_2->addWidget(cbDevicesGpsEnable, 6, 0, 1, 2);

        lDevicesGpsStopBit = new QLabel(gbDevicesGps);
        lDevicesGpsStopBit->setObjectName(QStringLiteral("lDevicesGpsStopBit"));

        gridLayout_2->addWidget(lDevicesGpsStopBit, 3, 0, 1, 1);

        lDevicesGpsBauds = new QLabel(gbDevicesGps);
        lDevicesGpsBauds->setObjectName(QStringLiteral("lDevicesGpsBauds"));

        gridLayout_2->addWidget(lDevicesGpsBauds, 1, 0, 1, 1);

        lDevicesGpsFlowControl = new QLabel(gbDevicesGps);
        lDevicesGpsFlowControl->setObjectName(QStringLiteral("lDevicesGpsFlowControl"));

        gridLayout_2->addWidget(lDevicesGpsFlowControl, 5, 0, 1, 1);

        cbDevicesGpsBauds = new QComboBox(gbDevicesGps);
        cbDevicesGpsBauds->setObjectName(QStringLiteral("cbDevicesGpsBauds"));
        cbDevicesGpsBauds->setMinimumSize(QSize(100, 0));

        gridLayout_2->addWidget(cbDevicesGpsBauds, 1, 1, 1, 1);

        cbDevicesGpsStopBit = new QComboBox(gbDevicesGps);
        cbDevicesGpsStopBit->setObjectName(QStringLiteral("cbDevicesGpsStopBit"));

        gridLayout_2->addWidget(cbDevicesGpsStopBit, 3, 1, 1, 1);

        cbDevicesGpsParity = new QComboBox(gbDevicesGps);
        cbDevicesGpsParity->setObjectName(QStringLiteral("cbDevicesGpsParity"));

        gridLayout_2->addWidget(cbDevicesGpsParity, 4, 1, 1, 1);

        cbDevicesGpsFlowControl = new QComboBox(gbDevicesGps);
        cbDevicesGpsFlowControl->setObjectName(QStringLiteral("cbDevicesGpsFlowControl"));

        gridLayout_2->addWidget(cbDevicesGpsFlowControl, 5, 1, 1, 1);


        gridLayout->addWidget(gbDevicesGps, 0, 0, 1, 2);

        vsDevices = new QSpacerItem(20, 2, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(vsDevices, 2, 2, 1, 1);

        cbDevicesProjectionSystem = new QComboBox(wDevices);
        cbDevicesProjectionSystem->setObjectName(QStringLiteral("cbDevicesProjectionSystem"));

        gridLayout->addWidget(cbDevicesProjectionSystem, 1, 1, 1, 1);

        lDevicesProjection = new QLabel(wDevices);
        lDevicesProjection->setObjectName(QStringLiteral("lDevicesProjection"));

        gridLayout->addWidget(lDevicesProjection, 1, 0, 1, 1);

        tabWidget->addTab(wDevices, QString());
        wEllipsoides = new QWidget();
        wEllipsoides->setObjectName(QStringLiteral("wEllipsoides"));
        gridLayout_28 = new QGridLayout(wEllipsoides);
        gridLayout_28->setObjectName(QStringLiteral("gridLayout_28"));
        gbEllNames = new QGroupBox(wEllipsoides);
        gbEllNames->setObjectName(QStringLiteral("gbEllNames"));
        gbEllNames->setMaximumSize(QSize(16777215, 240));
        gridLayout_9 = new QGridLayout(gbEllNames);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        lwEllNames = new QListWidget(gbEllNames);
        lwEllNames->setObjectName(QStringLiteral("lwEllNames"));

        gridLayout_9->addWidget(lwEllNames, 0, 0, 2, 1);


        gridLayout_28->addWidget(gbEllNames, 0, 0, 1, 4);

        lEllSemiMajorAxis = new QLabel(wEllipsoides);
        lEllSemiMajorAxis->setObjectName(QStringLiteral("lEllSemiMajorAxis"));

        gridLayout_28->addWidget(lEllSemiMajorAxis, 1, 0, 1, 2);

        dsEllSemiMajorAxis = new QDoubleSpinBox(wEllipsoides);
        dsEllSemiMajorAxis->setObjectName(QStringLiteral("dsEllSemiMajorAxis"));
        dsEllSemiMajorAxis->setMinimumSize(QSize(180, 0));
        dsEllSemiMajorAxis->setDecimals(4);
        dsEllSemiMajorAxis->setMinimum(-1e+08);
        dsEllSemiMajorAxis->setMaximum(1e+08);

        gridLayout_28->addWidget(dsEllSemiMajorAxis, 1, 2, 1, 1);

        hsEll = new QSpacerItem(124, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_28->addItem(hsEll, 1, 3, 1, 1);

        lEllSemiMinorAxis = new QLabel(wEllipsoides);
        lEllSemiMinorAxis->setObjectName(QStringLiteral("lEllSemiMinorAxis"));

        gridLayout_28->addWidget(lEllSemiMinorAxis, 2, 0, 1, 1);

        dsEllSemiMinorAxis = new QDoubleSpinBox(wEllipsoides);
        dsEllSemiMinorAxis->setObjectName(QStringLiteral("dsEllSemiMinorAxis"));
        dsEllSemiMinorAxis->setDecimals(4);
        dsEllSemiMinorAxis->setMinimum(-1e+08);
        dsEllSemiMinorAxis->setMaximum(1e+08);

        gridLayout_28->addWidget(dsEllSemiMinorAxis, 2, 2, 1, 1);

        vsEll = new QSpacerItem(20, 3, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_28->addItem(vsEll, 3, 2, 1, 1);

        tabWidget->addTab(wEllipsoides, QString());
        wDatums = new QWidget();
        wDatums->setObjectName(QStringLiteral("wDatums"));
        gridLayout_3 = new QGridLayout(wDatums);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        lDatEll = new QLabel(wDatums);
        lDatEll->setObjectName(QStringLiteral("lDatEll"));

        gridLayout_3->addWidget(lDatEll, 1, 0, 1, 2);

        cbDatEll = new QComboBox(wDatums);
        cbDatEll->setObjectName(QStringLiteral("cbDatEll"));
        cbDatEll->setMinimumSize(QSize(180, 0));

        gridLayout_3->addWidget(cbDatEll, 1, 2, 1, 1);

        lDatTranslation = new QGroupBox(wDatums);
        lDatTranslation->setObjectName(QStringLiteral("lDatTranslation"));
        lDatTranslation->setMinimumSize(QSize(140, 0));
        lDatTranslation->setMaximumSize(QSize(140, 16777215));
        gridLayout_24 = new QGridLayout(lDatTranslation);
        gridLayout_24->setObjectName(QStringLiteral("gridLayout_24"));
        lDatTranslationX = new QLabel(lDatTranslation);
        lDatTranslationX->setObjectName(QStringLiteral("lDatTranslationX"));

        gridLayout_24->addWidget(lDatTranslationX, 0, 0, 1, 1);

        lDatTranslationY = new QLabel(lDatTranslation);
        lDatTranslationY->setObjectName(QStringLiteral("lDatTranslationY"));

        gridLayout_24->addWidget(lDatTranslationY, 1, 0, 1, 1);

        lDatTranslationZ = new QLabel(lDatTranslation);
        lDatTranslationZ->setObjectName(QStringLiteral("lDatTranslationZ"));

        gridLayout_24->addWidget(lDatTranslationZ, 2, 0, 1, 1);

        spDatTranslationX = new QSpinBox(lDatTranslation);
        spDatTranslationX->setObjectName(QStringLiteral("spDatTranslationX"));
        spDatTranslationX->setMinimum(-10000);
        spDatTranslationX->setMaximum(10000);

        gridLayout_24->addWidget(spDatTranslationX, 0, 1, 1, 1);

        spDatTranslationY = new QSpinBox(lDatTranslation);
        spDatTranslationY->setObjectName(QStringLiteral("spDatTranslationY"));
        spDatTranslationY->setMinimum(-10000);
        spDatTranslationY->setMaximum(10000);

        gridLayout_24->addWidget(spDatTranslationY, 1, 1, 1, 1);

        spDatTranslationZ = new QSpinBox(lDatTranslation);
        spDatTranslationZ->setObjectName(QStringLiteral("spDatTranslationZ"));
        spDatTranslationZ->setMinimum(-10000);
        spDatTranslationZ->setMaximum(10000);

        gridLayout_24->addWidget(spDatTranslationZ, 2, 1, 1, 1);


        gridLayout_3->addWidget(lDatTranslation, 2, 0, 1, 2);

        lDatRotation = new QGroupBox(wDatums);
        lDatRotation->setObjectName(QStringLiteral("lDatRotation"));
        lDatRotation->setMinimumSize(QSize(140, 0));
        lDatRotation->setMaximumSize(QSize(140, 16777215));
        gridLayout_25 = new QGridLayout(lDatRotation);
        gridLayout_25->setObjectName(QStringLiteral("gridLayout_25"));
        lDatRotationX = new QLabel(lDatRotation);
        lDatRotationX->setObjectName(QStringLiteral("lDatRotationX"));

        gridLayout_25->addWidget(lDatRotationX, 0, 0, 1, 1);

        lDatRotationY = new QLabel(lDatRotation);
        lDatRotationY->setObjectName(QStringLiteral("lDatRotationY"));

        gridLayout_25->addWidget(lDatRotationY, 1, 0, 1, 1);

        lDatRotationZ = new QLabel(lDatRotation);
        lDatRotationZ->setObjectName(QStringLiteral("lDatRotationZ"));

        gridLayout_25->addWidget(lDatRotationZ, 2, 0, 1, 1);

        spDatRotationX = new QSpinBox(lDatRotation);
        spDatRotationX->setObjectName(QStringLiteral("spDatRotationX"));
        spDatRotationX->setMinimum(-10000);
        spDatRotationX->setMaximum(10000);

        gridLayout_25->addWidget(spDatRotationX, 0, 1, 1, 1);

        spDatRotationY = new QSpinBox(lDatRotation);
        spDatRotationY->setObjectName(QStringLiteral("spDatRotationY"));
        spDatRotationY->setMinimum(-10000);
        spDatRotationY->setMaximum(10000);

        gridLayout_25->addWidget(spDatRotationY, 1, 1, 1, 1);

        spDatRotationZ = new QSpinBox(lDatRotation);
        spDatRotationZ->setObjectName(QStringLiteral("spDatRotationZ"));
        spDatRotationZ->setMinimum(-10000);
        spDatRotationZ->setMaximum(10000);

        gridLayout_25->addWidget(spDatRotationZ, 2, 1, 1, 1);


        gridLayout_3->addWidget(lDatRotation, 2, 2, 1, 1);

        lDatNames = new QGroupBox(wDatums);
        lDatNames->setObjectName(QStringLiteral("lDatNames"));
        lDatNames->setMaximumSize(QSize(16777215, 240));
        gridLayout_26 = new QGridLayout(lDatNames);
        gridLayout_26->setObjectName(QStringLiteral("gridLayout_26"));
        lwDatNames = new QListWidget(lDatNames);
        lwDatNames->setObjectName(QStringLiteral("lwDatNames"));

        gridLayout_26->addWidget(lwDatNames, 0, 0, 2, 1);


        gridLayout_3->addWidget(lDatNames, 0, 0, 1, 4);

        lDatSf = new QLabel(wDatums);
        lDatSf->setObjectName(QStringLiteral("lDatSf"));

        gridLayout_3->addWidget(lDatSf, 3, 0, 1, 1);

        spDatSf = new QSpinBox(wDatums);
        spDatSf->setObjectName(QStringLiteral("spDatSf"));
        spDatSf->setMaximum(10000);
        spDatSf->setValue(0);

        gridLayout_3->addWidget(spDatSf, 3, 1, 1, 1);

        tabWidget->addTab(wDatums, QString());
        wProjections = new QWidget();
        wProjections->setObjectName(QStringLiteral("wProjections"));
        gridLayout_10 = new QGridLayout(wProjections);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        gbProNames = new QGroupBox(wProjections);
        gbProNames->setObjectName(QStringLiteral("gbProNames"));
        gridLayout_14 = new QGridLayout(gbProNames);
        gridLayout_14->setObjectName(QStringLiteral("gridLayout_14"));
        lwProNames = new QListWidget(gbProNames);
        lwProNames->setObjectName(QStringLiteral("lwProNames"));

        gridLayout_14->addWidget(lwProNames, 0, 0, 2, 1);


        gridLayout_10->addWidget(gbProNames, 0, 0, 1, 5);

        lProDatum = new QLabel(wProjections);
        lProDatum->setObjectName(QStringLiteral("lProDatum"));

        gridLayout_10->addWidget(lProDatum, 1, 0, 1, 1);

        cbProDatum = new QComboBox(wProjections);
        cbProDatum->setObjectName(QStringLiteral("cbProDatum"));
        cbProDatum->setMinimumSize(QSize(180, 0));

        gridLayout_10->addWidget(cbProDatum, 1, 1, 1, 3);

        lProN = new QLabel(wProjections);
        lProN->setObjectName(QStringLiteral("lProN"));

        gridLayout_10->addWidget(lProN, 2, 0, 1, 3);

        dsProN = new QDoubleSpinBox(wProjections);
        dsProN->setObjectName(QStringLiteral("dsProN"));
        dsProN->setMinimumSize(QSize(180, 0));
        dsProN->setDecimals(12);
        dsProN->setMinimum(-1e+08);
        dsProN->setMaximum(1e+08);

        gridLayout_10->addWidget(dsProN, 2, 3, 1, 1);

        hsPro = new QSpacerItem(132, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_10->addItem(hsPro, 2, 4, 1, 1);

        lProC = new QLabel(wProjections);
        lProC->setObjectName(QStringLiteral("lProC"));

        gridLayout_10->addWidget(lProC, 3, 0, 1, 3);

        dsProC = new QDoubleSpinBox(wProjections);
        dsProC->setObjectName(QStringLiteral("dsProC"));
        dsProC->setMinimumSize(QSize(180, 0));
        dsProC->setDecimals(12);
        dsProC->setMinimum(-1e+08);
        dsProC->setMaximum(1e+08);

        gridLayout_10->addWidget(dsProC, 3, 3, 1, 1);

        lProL0 = new QLabel(wProjections);
        lProL0->setObjectName(QStringLiteral("lProL0"));

        gridLayout_10->addWidget(lProL0, 4, 0, 1, 2);

        dsProL0 = new QDoubleSpinBox(wProjections);
        dsProL0->setObjectName(QStringLiteral("dsProL0"));
        dsProL0->setMinimumSize(QSize(180, 0));
        dsProL0->setDecimals(12);
        dsProL0->setMinimum(-1e+08);
        dsProL0->setMaximum(1e+08);

        gridLayout_10->addWidget(dsProL0, 4, 3, 1, 1);

        gbProCoor0 = new QGroupBox(wProjections);
        gbProCoor0->setObjectName(QStringLiteral("gbProCoor0"));
        gridLayout_15 = new QGridLayout(gbProCoor0);
        gridLayout_15->setObjectName(QStringLiteral("gridLayout_15"));
        lProXs = new QLabel(gbProCoor0);
        lProXs->setObjectName(QStringLiteral("lProXs"));

        gridLayout_15->addWidget(lProXs, 0, 0, 1, 1);

        dsProXs = new QDoubleSpinBox(gbProCoor0);
        dsProXs->setObjectName(QStringLiteral("dsProXs"));
        dsProXs->setMinimumSize(QSize(180, 0));
        dsProXs->setDecimals(12);
        dsProXs->setMinimum(-1e+08);
        dsProXs->setMaximum(1e+08);

        gridLayout_15->addWidget(dsProXs, 0, 1, 1, 1);

        lProYs = new QLabel(gbProCoor0);
        lProYs->setObjectName(QStringLiteral("lProYs"));

        gridLayout_15->addWidget(lProYs, 1, 0, 1, 1);

        dsProYs = new QDoubleSpinBox(gbProCoor0);
        dsProYs->setObjectName(QStringLiteral("dsProYs"));
        dsProYs->setDecimals(12);
        dsProYs->setMinimum(-1e+08);
        dsProYs->setMaximum(1e+08);

        gridLayout_15->addWidget(dsProYs, 1, 1, 1, 1);


        gridLayout_10->addWidget(gbProCoor0, 5, 0, 1, 4);

        vsPro = new QSpacerItem(20, 202, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_10->addItem(vsPro, 6, 2, 1, 1);

        tabWidget->addTab(wProjections, QString());
        wStatus = new QWidget();
        wStatus->setObjectName(QStringLiteral("wStatus"));
        gridLayout_8 = new QGridLayout(wStatus);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        lStatusProjection = new QLabel(wStatus);
        lStatusProjection->setObjectName(QStringLiteral("lStatusProjection"));

        gridLayout_8->addWidget(lStatusProjection, 0, 0, 1, 1);

        cbStatusProjection = new QComboBox(wStatus);
        cbStatusProjection->setObjectName(QStringLiteral("cbStatusProjection"));
        cbStatusProjection->setMinimumSize(QSize(120, 0));

        gridLayout_8->addWidget(cbStatusProjection, 0, 1, 1, 1);

        hsStatus = new QSpacerItem(267, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_8->addItem(hsStatus, 0, 2, 1, 1);

        lStatusFormatGps = new QLabel(wStatus);
        lStatusFormatGps->setObjectName(QStringLiteral("lStatusFormatGps"));

        gridLayout_8->addWidget(lStatusFormatGps, 1, 0, 1, 1);

        cbStatusFormatGps = new QComboBox(wStatus);
        cbStatusFormatGps->setObjectName(QStringLiteral("cbStatusFormatGps"));

        gridLayout_8->addWidget(cbStatusFormatGps, 1, 1, 1, 1);

        vsStatus = new QSpacerItem(20, 323, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_8->addItem(vsStatus, 2, 1, 1, 1);

        tabWidget->addTab(wStatus, QString());

        gridLayout_5->addWidget(tabWidget, 1, 0, 1, 1);

        QWidget::setTabOrder(lMaps, pbMapAdd);
        QWidget::setTabOrder(pbMapAdd, pbMapRemove);
        QWidget::setTabOrder(pbMapRemove, cbMapsCenteringGps);
        QWidget::setTabOrder(cbMapsCenteringGps, cbMapsEnableChanges);
        QWidget::setTabOrder(cbMapsEnableChanges, cbMapsDefault);
        QWidget::setTabOrder(cbMapsDefault, cbMapsCenterView);
        QWidget::setTabOrder(cbMapsCenterView, leMapsCenterViewX);
        QWidget::setTabOrder(leMapsCenterViewX, leMapsCenterViewY);
        QWidget::setTabOrder(leMapsCenterViewY, cbDevicesGpsBauds);
        QWidget::setTabOrder(cbDevicesGpsBauds, cbDevicesGpsEnable);
        QWidget::setTabOrder(cbDevicesGpsEnable, cbDevicesSonarBauds);
        QWidget::setTabOrder(cbDevicesSonarBauds, cbDevicesSonarEnable);
        QWidget::setTabOrder(cbDevicesSonarEnable, cbDevicesProjectionSystem);
        QWidget::setTabOrder(cbDevicesProjectionSystem, lwEllNames);
        QWidget::setTabOrder(lwEllNames, dsEllSemiMajorAxis);
        QWidget::setTabOrder(dsEllSemiMajorAxis, dsEllSemiMinorAxis);
        QWidget::setTabOrder(dsEllSemiMinorAxis, lwDatNames);
        QWidget::setTabOrder(lwDatNames, cbDatEll);
        QWidget::setTabOrder(cbDatEll, spDatTranslationX);
        QWidget::setTabOrder(spDatTranslationX, spDatTranslationY);
        QWidget::setTabOrder(spDatTranslationY, spDatTranslationZ);
        QWidget::setTabOrder(spDatTranslationZ, spDatRotationX);
        QWidget::setTabOrder(spDatRotationX, spDatRotationY);
        QWidget::setTabOrder(spDatRotationY, spDatRotationZ);
        QWidget::setTabOrder(spDatRotationZ, spDatSf);
        QWidget::setTabOrder(spDatSf, lwProNames);
        QWidget::setTabOrder(lwProNames, cbProDatum);
        QWidget::setTabOrder(cbProDatum, dsProN);
        QWidget::setTabOrder(dsProN, dsProC);
        QWidget::setTabOrder(dsProC, dsProL0);
        QWidget::setTabOrder(dsProL0, dsProXs);
        QWidget::setTabOrder(dsProXs, dsProYs);
        QWidget::setTabOrder(dsProYs, buttonBox);

        retranslateUi(SettingsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), SettingsDialog, SLOT(onAcceptEvent()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SettingsDialog, SLOT(onRejectEvent()));
        QObject::connect(pbMapAdd, SIGNAL(clicked()), SettingsDialog, SLOT(onMapAddEvent()));
        QObject::connect(cbMapsCenterView, SIGNAL(clicked(bool)), SettingsDialog, SLOT(onMapsCenterViewEvent(bool)));
        QObject::connect(pbMapRemove, SIGNAL(clicked()), SettingsDialog, SLOT(onMapRemoveEvent()));
        QObject::connect(lwProNames, SIGNAL(currentTextChanged(QString)), SettingsDialog, SLOT(onProChangeEvent()));
        QObject::connect(lwEllNames, SIGNAL(currentTextChanged(QString)), SettingsDialog, SLOT(onEllChangeEvent()));
        QObject::connect(lwDatNames, SIGNAL(currentTextChanged(QString)), SettingsDialog, SLOT(onDatChangeEvent()));
        QObject::connect(pbBoatAdd, SIGNAL(clicked()), SettingsDialog, SLOT(onBoatAddEvent()));
        QObject::connect(pbBoatRemove, SIGNAL(clicked()), SettingsDialog, SLOT(onBoatRemoveEvent()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *SettingsDialog)
    {
        SettingsDialog->setWindowTitle(QApplication::translate("SettingsDialog", "Settings", 0));
        pbMapRemove->setText(QApplication::translate("SettingsDialog", "Remove", 0));
        pbMapAdd->setText(QApplication::translate("SettingsDialog", "Add", 0));
        cbMapsCenteringGps->setText(QApplication::translate("SettingsDialog", "Centering Gps (by default)", 0));
        cbMapsEnableChanges->setText(QApplication::translate("SettingsDialog", "Enable changes (by default)", 0));
        lMapsDefault->setText(QApplication::translate("SettingsDialog", "Map selected (by default)", 0));
        cbMapsCenterView->setText(QApplication::translate("SettingsDialog", "Define Center View", 0));
        lMapsCenterViewX->setText(QApplication::translate("SettingsDialog", "X", 0));
        lMapsCenterViewY->setText(QApplication::translate("SettingsDialog", "Y", 0));
        tabWidget->setTabText(tabWidget->indexOf(wMaps), QApplication::translate("SettingsDialog", "Maps", 0));
        pbBoatAdd->setText(QApplication::translate("SettingsDialog", "Add", 0));
        pbBoatRemove->setText(QApplication::translate("SettingsDialog", "Remove", 0));
        tabWidget->setTabText(tabWidget->indexOf(wBoats), QApplication::translate("SettingsDialog", "Boats", 0));
        gbDevicesSonar->setTitle(QApplication::translate("SettingsDialog", "Sounder", 0));
        lDevicesSonarStopBit->setText(QApplication::translate("SettingsDialog", "Stop bit", 0));
        lDevicesSonarParity->setText(QApplication::translate("SettingsDialog", "Parity", 0));
        lDevicesSonarFlowControl->setText(QApplication::translate("SettingsDialog", "Flow control", 0));
        lDevicesSonarName->setText(QApplication::translate("SettingsDialog", "Name", 0));
        lDevicesSonarBauds->setText(QApplication::translate("SettingsDialog", "Baudrates", 0));
        lDevicesSonarDataBits->setText(QApplication::translate("SettingsDialog", "Data bits", 0));
        cbDevicesSonarEnable->setText(QApplication::translate("SettingsDialog", "Enable Sounder", 0));
        gbDevicesGps->setTitle(QApplication::translate("SettingsDialog", "Gps", 0));
        lDevicesGpsDataBits->setText(QApplication::translate("SettingsDialog", "Data bits", 0));
        lDevicesGpsParity->setText(QApplication::translate("SettingsDialog", "Parity", 0));
        lDevicesGpsName->setText(QApplication::translate("SettingsDialog", "Name", 0));
        cbDevicesGpsEnable->setText(QApplication::translate("SettingsDialog", "Enable GPS", 0));
        lDevicesGpsStopBit->setText(QApplication::translate("SettingsDialog", "Stop bit", 0));
        lDevicesGpsBauds->setText(QApplication::translate("SettingsDialog", "Baudrates", 0));
        lDevicesGpsFlowControl->setText(QApplication::translate("SettingsDialog", "Flow control", 0));
        lDevicesProjection->setText(QApplication::translate("SettingsDialog", "Projection :", 0));
        tabWidget->setTabText(tabWidget->indexOf(wDevices), QApplication::translate("SettingsDialog", "Devices", 0));
        gbEllNames->setTitle(QApplication::translate("SettingsDialog", "Ellipsoids names", 0));
        lEllSemiMajorAxis->setText(QApplication::translate("SettingsDialog", "Semi-major axis A(m)", 0));
        lEllSemiMinorAxis->setText(QApplication::translate("SettingsDialog", "Semi-minor axis B(m)", 0));
        tabWidget->setTabText(tabWidget->indexOf(wEllipsoides), QApplication::translate("SettingsDialog", "Ellipsoids", 0));
        lDatEll->setText(QApplication::translate("SettingsDialog", "Reference ellipsoid :", 0));
        lDatTranslation->setTitle(QApplication::translate("SettingsDialog", "Translation (WGS84)", 0));
        lDatTranslationX->setText(QApplication::translate("SettingsDialog", "X", 0));
        lDatTranslationY->setText(QApplication::translate("SettingsDialog", "Y", 0));
        lDatTranslationZ->setText(QApplication::translate("SettingsDialog", "Z", 0));
        lDatRotation->setTitle(QApplication::translate("SettingsDialog", "Rotation (WGS84)", 0));
        lDatRotationX->setText(QApplication::translate("SettingsDialog", "X", 0));
        lDatRotationY->setText(QApplication::translate("SettingsDialog", "Y", 0));
        lDatRotationZ->setText(QApplication::translate("SettingsDialog", "Z", 0));
        lDatNames->setTitle(QApplication::translate("SettingsDialog", "Datums names", 0));
        lDatSf->setText(QApplication::translate("SettingsDialog", "Scale factor :", 0));
        tabWidget->setTabText(tabWidget->indexOf(wDatums), QApplication::translate("SettingsDialog", "Datum", 0));
        gbProNames->setTitle(QApplication::translate("SettingsDialog", "Projections names", 0));
        lProDatum->setText(QApplication::translate("SettingsDialog", "Datum", 0));
        lProN->setText(QApplication::translate("SettingsDialog", "Exponent of the projection (n) :", 0));
        lProC->setText(QApplication::translate("SettingsDialog", "Constant of the projection (c)", 0));
        lProL0->setText(QApplication::translate("SettingsDialog", "Longitude origin :", 0));
        gbProCoor0->setTitle(QApplication::translate("SettingsDialog", "Coordinates of the pole projection", 0));
        lProXs->setText(QApplication::translate("SettingsDialog", "X", 0));
        lProYs->setText(QApplication::translate("SettingsDialog", "Y", 0));
        tabWidget->setTabText(tabWidget->indexOf(wProjections), QApplication::translate("SettingsDialog", "Projections", 0));
        lStatusProjection->setText(QApplication::translate("SettingsDialog", "Projection", 0));
        lStatusFormatGps->setText(QApplication::translate("SettingsDialog", "Format GPS", 0));
        tabWidget->setTabText(tabWidget->indexOf(wStatus), QApplication::translate("SettingsDialog", "Status bar", 0));
    } // retranslateUi

};

namespace Ui {
    class SettingsDialog: public Ui_SettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSDIALOG_H
