/********************************************************************************
** Form generated from reading UI file 'VolumeCalculatorDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VOLUMECALCULATORDIALOG_H
#define UI_VOLUMECALCULATORDIALOG_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_VolumeCalculatorDialog
{
public:
    QGridLayout *gridLayout;
    QGridLayout *glUpSurface;
    QLabel *lUpSurface;
    QRadioButton *rbUpSurfaceMesh;
    QComboBox *cbUpSurfaceMesh;
    QRadioButton *rbUpSurfacePlan;
    QDoubleSpinBox *dsUpSurfacePlan;
    QGridLayout *glLoSurface;
    QLabel *lLoSurface;
    QRadioButton *rbLoSurfaceMesh;
    QComboBox *cbLoSurfaceMesh;
    QRadioButton *rbLoSurfacePlan;
    QDoubleSpinBox *dsLoSurfacePlan;
    QHBoxLayout *hlCalculatesVolume;
    QSpacerItem *hsCalculatesLeft;
    QPushButton *pbCalculates;
    QSpacerItem *hsCalculatesRight;
    QLabel *lProcessName;
    QProgressBar *progressBar;
    QGridLayout *glResults;
    QLabel *lSurface;
    QLabel *lVolume;
    QDialogButtonBox *buttonBox;
    QButtonGroup *bgLoSurface;
    QButtonGroup *bgUpSurface;

    void setupUi(QDialog *VolumeCalculatorDialog)
    {
        if (VolumeCalculatorDialog->objectName().isEmpty())
            VolumeCalculatorDialog->setObjectName(QStringLiteral("VolumeCalculatorDialog"));
        VolumeCalculatorDialog->resize(497, 295);
        VolumeCalculatorDialog->setMaximumSize(QSize(497, 295));
        VolumeCalculatorDialog->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        gridLayout = new QGridLayout(VolumeCalculatorDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        glUpSurface = new QGridLayout();
        glUpSurface->setObjectName(QStringLiteral("glUpSurface"));
        lUpSurface = new QLabel(VolumeCalculatorDialog);
        lUpSurface->setObjectName(QStringLiteral("lUpSurface"));
        lUpSurface->setMaximumSize(QSize(120, 16777215));

        glUpSurface->addWidget(lUpSurface, 0, 0, 1, 1);

        rbUpSurfaceMesh = new QRadioButton(VolumeCalculatorDialog);
        bgUpSurface = new QButtonGroup(VolumeCalculatorDialog);
        bgUpSurface->setObjectName(QStringLiteral("bgUpSurface"));
        bgUpSurface->addButton(rbUpSurfaceMesh);
        rbUpSurfaceMesh->setObjectName(QStringLiteral("rbUpSurfaceMesh"));
        rbUpSurfaceMesh->setMaximumSize(QSize(80, 16777215));
        rbUpSurfaceMesh->setChecked(true);
        rbUpSurfaceMesh->setAutoExclusive(true);

        glUpSurface->addWidget(rbUpSurfaceMesh, 0, 1, 1, 1);

        cbUpSurfaceMesh = new QComboBox(VolumeCalculatorDialog);
        cbUpSurfaceMesh->setObjectName(QStringLiteral("cbUpSurfaceMesh"));

        glUpSurface->addWidget(cbUpSurfaceMesh, 0, 2, 1, 1);

        rbUpSurfacePlan = new QRadioButton(VolumeCalculatorDialog);
        bgUpSurface->addButton(rbUpSurfacePlan);
        rbUpSurfacePlan->setObjectName(QStringLiteral("rbUpSurfacePlan"));
        rbUpSurfacePlan->setMaximumSize(QSize(80, 16777215));
        rbUpSurfacePlan->setAutoExclusive(true);

        glUpSurface->addWidget(rbUpSurfacePlan, 1, 1, 1, 1);

        dsUpSurfacePlan = new QDoubleSpinBox(VolumeCalculatorDialog);
        dsUpSurfacePlan->setObjectName(QStringLiteral("dsUpSurfacePlan"));
        dsUpSurfacePlan->setMinimum(-10000);
        dsUpSurfacePlan->setMaximum(10000);

        glUpSurface->addWidget(dsUpSurfacePlan, 1, 2, 1, 1);


        gridLayout->addLayout(glUpSurface, 0, 0, 1, 1);

        glLoSurface = new QGridLayout();
        glLoSurface->setObjectName(QStringLiteral("glLoSurface"));
        lLoSurface = new QLabel(VolumeCalculatorDialog);
        lLoSurface->setObjectName(QStringLiteral("lLoSurface"));
        lLoSurface->setMaximumSize(QSize(120, 16777215));

        glLoSurface->addWidget(lLoSurface, 0, 0, 1, 1);

        rbLoSurfaceMesh = new QRadioButton(VolumeCalculatorDialog);
        bgLoSurface = new QButtonGroup(VolumeCalculatorDialog);
        bgLoSurface->setObjectName(QStringLiteral("bgLoSurface"));
        bgLoSurface->addButton(rbLoSurfaceMesh);
        rbLoSurfaceMesh->setObjectName(QStringLiteral("rbLoSurfaceMesh"));
        rbLoSurfaceMesh->setMaximumSize(QSize(80, 16777215));
        rbLoSurfaceMesh->setLocale(QLocale(QLocale::French, QLocale::France));
        rbLoSurfaceMesh->setChecked(true);
        rbLoSurfaceMesh->setAutoExclusive(true);

        glLoSurface->addWidget(rbLoSurfaceMesh, 0, 1, 1, 1);

        cbLoSurfaceMesh = new QComboBox(VolumeCalculatorDialog);
        cbLoSurfaceMesh->setObjectName(QStringLiteral("cbLoSurfaceMesh"));

        glLoSurface->addWidget(cbLoSurfaceMesh, 0, 2, 1, 1);

        rbLoSurfacePlan = new QRadioButton(VolumeCalculatorDialog);
        bgLoSurface->addButton(rbLoSurfacePlan);
        rbLoSurfacePlan->setObjectName(QStringLiteral("rbLoSurfacePlan"));
        rbLoSurfacePlan->setMaximumSize(QSize(80, 16777215));

        glLoSurface->addWidget(rbLoSurfacePlan, 1, 1, 1, 1);

        dsLoSurfacePlan = new QDoubleSpinBox(VolumeCalculatorDialog);
        dsLoSurfacePlan->setObjectName(QStringLiteral("dsLoSurfacePlan"));
        dsLoSurfacePlan->setMinimum(-10000);
        dsLoSurfacePlan->setMaximum(10000);

        glLoSurface->addWidget(dsLoSurfacePlan, 1, 2, 1, 1);


        gridLayout->addLayout(glLoSurface, 1, 0, 1, 1);

        hlCalculatesVolume = new QHBoxLayout();
        hlCalculatesVolume->setObjectName(QStringLiteral("hlCalculatesVolume"));
        hsCalculatesLeft = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hlCalculatesVolume->addItem(hsCalculatesLeft);

        pbCalculates = new QPushButton(VolumeCalculatorDialog);
        pbCalculates->setObjectName(QStringLiteral("pbCalculates"));

        hlCalculatesVolume->addWidget(pbCalculates);

        hsCalculatesRight = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hlCalculatesVolume->addItem(hsCalculatesRight);


        gridLayout->addLayout(hlCalculatesVolume, 2, 0, 1, 1);

        lProcessName = new QLabel(VolumeCalculatorDialog);
        lProcessName->setObjectName(QStringLiteral("lProcessName"));

        gridLayout->addWidget(lProcessName, 3, 0, 1, 1);

        progressBar = new QProgressBar(VolumeCalculatorDialog);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);

        gridLayout->addWidget(progressBar, 4, 0, 1, 1);

        glResults = new QGridLayout();
        glResults->setObjectName(QStringLiteral("glResults"));
        lSurface = new QLabel(VolumeCalculatorDialog);
        lSurface->setObjectName(QStringLiteral("lSurface"));

        glResults->addWidget(lSurface, 0, 0, 1, 1);

        lVolume = new QLabel(VolumeCalculatorDialog);
        lVolume->setObjectName(QStringLiteral("lVolume"));

        glResults->addWidget(lVolume, 0, 1, 1, 1);


        gridLayout->addLayout(glResults, 5, 0, 1, 1);

        buttonBox = new QDialogButtonBox(VolumeCalculatorDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close);

        gridLayout->addWidget(buttonBox, 6, 0, 1, 1);


        retranslateUi(VolumeCalculatorDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), VolumeCalculatorDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), VolumeCalculatorDialog, SLOT(reject()));
        QObject::connect(rbUpSurfaceMesh, SIGNAL(toggled(bool)), cbUpSurfaceMesh, SLOT(setEnabled(bool)));
        QObject::connect(rbUpSurfacePlan, SIGNAL(toggled(bool)), dsUpSurfacePlan, SLOT(setEnabled(bool)));
        QObject::connect(rbLoSurfaceMesh, SIGNAL(toggled(bool)), cbLoSurfaceMesh, SLOT(setEnabled(bool)));
        QObject::connect(rbLoSurfacePlan, SIGNAL(toggled(bool)), dsLoSurfacePlan, SLOT(setEnabled(bool)));
        QObject::connect(pbCalculates, SIGNAL(clicked()), VolumeCalculatorDialog, SLOT(calculates()));

        QMetaObject::connectSlotsByName(VolumeCalculatorDialog);
    } // setupUi

    void retranslateUi(QDialog *VolumeCalculatorDialog)
    {
        VolumeCalculatorDialog->setWindowTitle(QApplication::translate("VolumeCalculatorDialog", "Dialog", 0));
        lUpSurface->setText(QApplication::translate("VolumeCalculatorDialog", "Upper surface", 0));
        rbUpSurfaceMesh->setText(QApplication::translate("VolumeCalculatorDialog", "Mesh", 0));
        rbUpSurfacePlan->setText(QApplication::translate("VolumeCalculatorDialog", "Plan", 0));
        lLoSurface->setText(QApplication::translate("VolumeCalculatorDialog", "Lower surface", 0));
        rbLoSurfaceMesh->setText(QApplication::translate("VolumeCalculatorDialog", "Mesh", 0));
        rbLoSurfacePlan->setText(QApplication::translate("VolumeCalculatorDialog", "Plan", 0));
        pbCalculates->setText(QApplication::translate("VolumeCalculatorDialog", "Calculates volume", 0));
        lProcessName->setText(QString());
        lSurface->setText(QApplication::translate("VolumeCalculatorDialog", "Surface :", 0));
        lVolume->setText(QApplication::translate("VolumeCalculatorDialog", "Volume :", 0));
    } // retranslateUi

};

namespace Ui {
    class VolumeCalculatorDialog: public Ui_VolumeCalculatorDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VOLUMECALCULATORDIALOG_H
