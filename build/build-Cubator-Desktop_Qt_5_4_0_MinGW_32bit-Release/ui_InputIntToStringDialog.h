/********************************************************************************
** Form generated from reading UI file 'InputIntToStringDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPUTINTTOSTRINGDIALOG_H
#define UI_INPUTINTTOSTRINGDIALOG_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_InputIntToStringDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *lLayers;
    QComboBox *cbLayers;
    QDialogButtonBox *buttonBox;
    QSpinBox *isLayers;

    void setupUi(QDialog *InputIntToStringDialog)
    {
        if (InputIntToStringDialog->objectName().isEmpty())
            InputIntToStringDialog->setObjectName(QStringLiteral("InputIntToStringDialog"));
        InputIntToStringDialog->resize(279, 93);
        InputIntToStringDialog->setMinimumSize(QSize(279, 93));
        InputIntToStringDialog->setMaximumSize(QSize(279, 93));
        InputIntToStringDialog->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        gridLayout = new QGridLayout(InputIntToStringDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lLayers = new QLabel(InputIntToStringDialog);
        lLayers->setObjectName(QStringLiteral("lLayers"));

        gridLayout->addWidget(lLayers, 0, 0, 1, 1);

        cbLayers = new QComboBox(InputIntToStringDialog);
        cbLayers->setObjectName(QStringLiteral("cbLayers"));
        cbLayers->setMinimumSize(QSize(176, 23));
        cbLayers->setMaximumSize(QSize(181, 23));

        gridLayout->addWidget(cbLayers, 1, 0, 1, 1);

        buttonBox = new QDialogButtonBox(InputIntToStringDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 0, 1, 2);

        isLayers = new QSpinBox(InputIntToStringDialog);
        isLayers->setObjectName(QStringLiteral("isLayers"));
        isLayers->setMaximum(100);

        gridLayout->addWidget(isLayers, 1, 1, 1, 1);


        retranslateUi(InputIntToStringDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), InputIntToStringDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), InputIntToStringDialog, SLOT(reject()));
        QObject::connect(cbLayers, SIGNAL(currentIndexChanged(QString)), InputIntToStringDialog, SLOT(changeLayer(QString)));

        QMetaObject::connectSlotsByName(InputIntToStringDialog);
    } // setupUi

    void retranslateUi(QDialog *InputIntToStringDialog)
    {
        InputIntToStringDialog->setWindowTitle(QApplication::translate("InputIntToStringDialog", "Elevation layers", 0));
        lLayers->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class InputIntToStringDialog: public Ui_InputIntToStringDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUTINTTOSTRINGDIALOG_H
