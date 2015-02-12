/********************************************************************************
** Form generated from reading UI file 'CoordinatesDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COORDINATESDIALOG_H
#define UI_COORDINATESDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_CoordinatesDialog
{
public:
    QGridLayout *gridLayout_3;
    QCheckBox *cbTranfEnable;
    QComboBox *cbProjectionsSystems;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *labelCoordsA;
    QComboBox *comboCoordsA;
    QLabel *labelLg;
    QLineEdit *editLtD;
    QLabel *labelLgD;
    QLineEdit *editLtDm;
    QLabel *labelLgDm;
    QLineEdit *editLtDms;
    QLabel *labelLgDms;
    QLabel *labelLgRad;
    QSpacerItem *horizontalSpacer_4;
    QLabel *labelLt;
    QLineEdit *editLgD;
    QLabel *labelLtD;
    QLineEdit *editLgDm;
    QLabel *labelLtDm;
    QLineEdit *editLgDms;
    QLabel *labelLtDms;
    QLabel *labelLtRad;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *btCalculate;
    QSpacerItem *horizontalSpacer_5;
    QLabel *labelXCoordsB;
    QLineEdit *editXCoordB;
    QLabel *labelYCoordB;
    QLineEdit *editYCoordB;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CoordinatesDialog)
    {
        if (CoordinatesDialog->objectName().isEmpty())
            CoordinatesDialog->setObjectName(QStringLiteral("CoordinatesDialog"));
        CoordinatesDialog->resize(404, 303);
        CoordinatesDialog->setMinimumSize(QSize(404, 303));
        CoordinatesDialog->setMaximumSize(QSize(404, 303));
        QFont font;
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        CoordinatesDialog->setFont(font);
        gridLayout_3 = new QGridLayout(CoordinatesDialog);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        cbTranfEnable = new QCheckBox(CoordinatesDialog);
        cbTranfEnable->setObjectName(QStringLiteral("cbTranfEnable"));
        QFont font1;
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        cbTranfEnable->setFont(font1);

        gridLayout_3->addWidget(cbTranfEnable, 0, 0, 1, 1);

        cbProjectionsSystems = new QComboBox(CoordinatesDialog);
        cbProjectionsSystems->setObjectName(QStringLiteral("cbProjectionsSystems"));
        cbProjectionsSystems->setMinimumSize(QSize(160, 0));

        gridLayout_3->addWidget(cbProjectionsSystems, 0, 1, 1, 2);

        horizontalSpacer_3 = new QSpacerItem(158, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 0, 3, 1, 1);

        groupBox = new QGroupBox(CoordinatesDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QFont font2;
        font2.setBold(false);
        font2.setItalic(false);
        font2.setUnderline(true);
        font2.setWeight(50);
        groupBox->setFont(font2);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        labelCoordsA = new QLabel(groupBox);
        labelCoordsA->setObjectName(QStringLiteral("labelCoordsA"));
        QFont font3;
        font3.setBold(false);
        font3.setItalic(false);
        font3.setUnderline(false);
        font3.setWeight(50);
        labelCoordsA->setFont(font3);

        gridLayout->addWidget(labelCoordsA, 0, 0, 1, 2);

        comboCoordsA = new QComboBox(groupBox);
        comboCoordsA->setObjectName(QStringLiteral("comboCoordsA"));
        QFont font4;
        font4.setItalic(false);
        font4.setUnderline(false);
        comboCoordsA->setFont(font4);

        gridLayout->addWidget(comboCoordsA, 0, 2, 1, 3);

        labelLg = new QLabel(groupBox);
        labelLg->setObjectName(QStringLiteral("labelLg"));
        QFont font5;
        font5.setBold(false);
        font5.setUnderline(false);
        font5.setWeight(50);
        labelLg->setFont(font5);

        gridLayout->addWidget(labelLg, 1, 0, 1, 1);

        editLtD = new QLineEdit(groupBox);
        editLtD->setObjectName(QStringLiteral("editLtD"));
        editLtD->setFont(font4);

        gridLayout->addWidget(editLtD, 1, 1, 1, 2);

        labelLgD = new QLabel(groupBox);
        labelLgD->setObjectName(QStringLiteral("labelLgD"));
        labelLgD->setFont(font5);

        gridLayout->addWidget(labelLgD, 1, 3, 1, 1);

        editLtDm = new QLineEdit(groupBox);
        editLtDm->setObjectName(QStringLiteral("editLtDm"));
        editLtDm->setFont(font4);

        gridLayout->addWidget(editLtDm, 1, 4, 1, 1);

        labelLgDm = new QLabel(groupBox);
        labelLgDm->setObjectName(QStringLiteral("labelLgDm"));
        labelLgDm->setFont(font5);

        gridLayout->addWidget(labelLgDm, 1, 5, 1, 1);

        editLtDms = new QLineEdit(groupBox);
        editLtDms->setObjectName(QStringLiteral("editLtDms"));
        editLtDms->setFont(font4);

        gridLayout->addWidget(editLtDms, 1, 6, 1, 1);

        labelLgDms = new QLabel(groupBox);
        labelLgDms->setObjectName(QStringLiteral("labelLgDms"));
        labelLgDms->setFont(font5);

        gridLayout->addWidget(labelLgDms, 1, 7, 1, 1);

        labelLgRad = new QLabel(groupBox);
        labelLgRad->setObjectName(QStringLiteral("labelLgRad"));
        labelLgRad->setFont(font5);

        gridLayout->addWidget(labelLgRad, 1, 8, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 1, 9, 1, 1);

        labelLt = new QLabel(groupBox);
        labelLt->setObjectName(QStringLiteral("labelLt"));
        labelLt->setFont(font5);

        gridLayout->addWidget(labelLt, 2, 0, 1, 1);

        editLgD = new QLineEdit(groupBox);
        editLgD->setObjectName(QStringLiteral("editLgD"));
        editLgD->setFont(font4);

        gridLayout->addWidget(editLgD, 2, 1, 1, 2);

        labelLtD = new QLabel(groupBox);
        labelLtD->setObjectName(QStringLiteral("labelLtD"));
        labelLtD->setFont(font5);

        gridLayout->addWidget(labelLtD, 2, 3, 1, 1);

        editLgDm = new QLineEdit(groupBox);
        editLgDm->setObjectName(QStringLiteral("editLgDm"));
        editLgDm->setFont(font4);

        gridLayout->addWidget(editLgDm, 2, 4, 1, 1);

        labelLtDm = new QLabel(groupBox);
        labelLtDm->setObjectName(QStringLiteral("labelLtDm"));
        labelLtDm->setFont(font5);

        gridLayout->addWidget(labelLtDm, 2, 5, 1, 1);

        editLgDms = new QLineEdit(groupBox);
        editLgDms->setObjectName(QStringLiteral("editLgDms"));
        editLgDms->setFont(font4);

        gridLayout->addWidget(editLgDms, 2, 6, 1, 1);

        labelLtDms = new QLabel(groupBox);
        labelLtDms->setObjectName(QStringLiteral("labelLtDms"));
        labelLtDms->setFont(font5);

        gridLayout->addWidget(labelLtDms, 2, 7, 1, 1);

        labelLtRad = new QLabel(groupBox);
        labelLtRad->setObjectName(QStringLiteral("labelLtRad"));
        labelLtRad->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelLtRad->sizePolicy().hasHeightForWidth());
        labelLtRad->setSizePolicy(sizePolicy);
        labelLtRad->setFont(font5);

        gridLayout->addWidget(labelLtRad, 2, 8, 1, 1);


        gridLayout_3->addWidget(groupBox, 1, 0, 1, 4);

        horizontalSpacer_2 = new QSpacerItem(0, 112, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 1, 4, 1, 1);

        groupBox_2 = new QGroupBox(CoordinatesDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setFont(font2);
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalSpacer = new QSpacerItem(266, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 1, 1, 1);

        btCalculate = new QPushButton(groupBox_2);
        btCalculate->setObjectName(QStringLiteral("btCalculate"));
        btCalculate->setFont(font3);

        gridLayout_2->addWidget(btCalculate, 0, 2, 2, 1);

        horizontalSpacer_5 = new QSpacerItem(26, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 1, 3, 2, 1);

        labelXCoordsB = new QLabel(groupBox_2);
        labelXCoordsB->setObjectName(QStringLiteral("labelXCoordsB"));
        labelXCoordsB->setFont(font5);

        gridLayout_2->addWidget(labelXCoordsB, 2, 0, 1, 1);

        editXCoordB = new QLineEdit(groupBox_2);
        editXCoordB->setObjectName(QStringLiteral("editXCoordB"));
        editXCoordB->setFont(font4);

        gridLayout_2->addWidget(editXCoordB, 2, 1, 1, 2);

        labelYCoordB = new QLabel(groupBox_2);
        labelYCoordB->setObjectName(QStringLiteral("labelYCoordB"));
        labelYCoordB->setFont(font5);

        gridLayout_2->addWidget(labelYCoordB, 3, 0, 1, 1);

        editYCoordB = new QLineEdit(groupBox_2);
        editYCoordB->setObjectName(QStringLiteral("editYCoordB"));
        editYCoordB->setFont(font4);

        gridLayout_2->addWidget(editYCoordB, 3, 1, 1, 2);

        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 4, 1, 1, 1);


        gridLayout_3->addWidget(groupBox_2, 2, 0, 1, 4);

        buttonBox = new QDialogButtonBox(CoordinatesDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setFont(font1);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_3->addWidget(buttonBox, 3, 2, 1, 2);

#ifndef QT_NO_SHORTCUT
        labelCoordsA->setBuddy(comboCoordsA);
        labelXCoordsB->setBuddy(editXCoordB);
        labelYCoordB->setBuddy(editYCoordB);
#endif // QT_NO_SHORTCUT

        retranslateUi(CoordinatesDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), CoordinatesDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CoordinatesDialog, SLOT(reject()));
        QObject::connect(editLgD, SIGNAL(textChanged(QString)), CoordinatesDialog, SLOT(onUpdateCoordsA()));
        QObject::connect(editLgDm, SIGNAL(textChanged(QString)), CoordinatesDialog, SLOT(onUpdateCoordsA()));
        QObject::connect(editLgDms, SIGNAL(textChanged(QString)), CoordinatesDialog, SLOT(onUpdateCoordsA()));
        QObject::connect(editLtD, SIGNAL(textChanged(QString)), CoordinatesDialog, SLOT(onUpdateCoordsA()));
        QObject::connect(editLtDm, SIGNAL(textChanged(QString)), CoordinatesDialog, SLOT(onUpdateCoordsA()));
        QObject::connect(btCalculate, SIGNAL(clicked()), CoordinatesDialog, SLOT(onButtonCalculateClicked()));
        QObject::connect(cbTranfEnable, SIGNAL(clicked(bool)), CoordinatesDialog, SLOT(onTransfEnabled(bool)));
        QObject::connect(comboCoordsA, SIGNAL(currentIndexChanged(int)), CoordinatesDialog, SLOT(onSystemAUnitsChanged()));

        QMetaObject::connectSlotsByName(CoordinatesDialog);
    } // setupUi

    void retranslateUi(QDialog *CoordinatesDialog)
    {
        CoordinatesDialog->setWindowTitle(QApplication::translate("CoordinatesDialog", "Update Coordinates", 0));
        cbTranfEnable->setText(QApplication::translate("CoordinatesDialog", "Enable projection", 0));
        groupBox->setTitle(QApplication::translate("CoordinatesDialog", "System A", 0));
        labelCoordsA->setText(QApplication::translate("CoordinatesDialog", "Coordinates", 0));
        labelLg->setText(QApplication::translate("CoordinatesDialog", "Lt", 0));
        labelLgD->setText(QApplication::translate("CoordinatesDialog", "\302\260", 0));
        labelLgDm->setText(QApplication::translate("CoordinatesDialog", "'", 0));
        labelLgDms->setText(QApplication::translate("CoordinatesDialog", "''", 0));
        labelLgRad->setText(QApplication::translate("CoordinatesDialog", "Rad", 0));
        labelLt->setText(QApplication::translate("CoordinatesDialog", "Lg", 0));
        labelLtD->setText(QApplication::translate("CoordinatesDialog", "\302\260", 0));
        labelLtDm->setText(QApplication::translate("CoordinatesDialog", "'", 0));
        labelLtDms->setText(QApplication::translate("CoordinatesDialog", "''", 0));
        labelLtRad->setText(QApplication::translate("CoordinatesDialog", "Rad", 0));
        groupBox_2->setTitle(QApplication::translate("CoordinatesDialog", "System B", 0));
        btCalculate->setText(QApplication::translate("CoordinatesDialog", "Calculate", 0));
        labelXCoordsB->setText(QApplication::translate("CoordinatesDialog", "x", 0));
        labelYCoordB->setText(QApplication::translate("CoordinatesDialog", "y", 0));
    } // retranslateUi

};

namespace Ui {
    class CoordinatesDialog: public Ui_CoordinatesDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COORDINATESDIALOG_H
