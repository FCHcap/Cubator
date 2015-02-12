/********************************************************************************
** Form generated from reading UI file 'ConvertToNgfDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONVERTTONGFDIALOG_H
#define UI_CONVERTTONGFDIALOG_H

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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_ConvertToNgfDialog
{
public:
    QGridLayout *gridLayout_2;
    QProgressBar *progressBar;
    QGridLayout *gridLayout;
    QLabel *lSourceTable;
    QComboBox *cbSourceTable;
    QLabel *lDestinationTable;
    QComboBox *cbDestinationTable;
    QLabel *lHeight;
    QDoubleSpinBox *dsHeight;
    QLabel *lProcessName;
    QDialogButtonBox *buttonBox;
    QPushButton *pbCalculate;
    QSpacerItem *hsl;
    QSpacerItem *hsr;

    void setupUi(QDialog *ConvertToNgfDialog)
    {
        if (ConvertToNgfDialog->objectName().isEmpty())
            ConvertToNgfDialog->setObjectName(QStringLiteral("ConvertToNgfDialog"));
        ConvertToNgfDialog->resize(416, 241);
        ConvertToNgfDialog->setMinimumSize(QSize(416, 241));
        ConvertToNgfDialog->setMaximumSize(QSize(416, 241));
        ConvertToNgfDialog->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        gridLayout_2 = new QGridLayout(ConvertToNgfDialog);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        progressBar = new QProgressBar(ConvertToNgfDialog);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);

        gridLayout_2->addWidget(progressBar, 3, 0, 1, 3);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lSourceTable = new QLabel(ConvertToNgfDialog);
        lSourceTable->setObjectName(QStringLiteral("lSourceTable"));

        gridLayout->addWidget(lSourceTable, 0, 0, 1, 1);

        cbSourceTable = new QComboBox(ConvertToNgfDialog);
        cbSourceTable->setObjectName(QStringLiteral("cbSourceTable"));

        gridLayout->addWidget(cbSourceTable, 0, 1, 1, 1);

        lDestinationTable = new QLabel(ConvertToNgfDialog);
        lDestinationTable->setObjectName(QStringLiteral("lDestinationTable"));

        gridLayout->addWidget(lDestinationTable, 1, 0, 1, 1);

        cbDestinationTable = new QComboBox(ConvertToNgfDialog);
        cbDestinationTable->setObjectName(QStringLiteral("cbDestinationTable"));

        gridLayout->addWidget(cbDestinationTable, 1, 1, 1, 1);

        lHeight = new QLabel(ConvertToNgfDialog);
        lHeight->setObjectName(QStringLiteral("lHeight"));

        gridLayout->addWidget(lHeight, 2, 0, 1, 1);

        dsHeight = new QDoubleSpinBox(ConvertToNgfDialog);
        dsHeight->setObjectName(QStringLiteral("dsHeight"));

        gridLayout->addWidget(dsHeight, 2, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 3);

        lProcessName = new QLabel(ConvertToNgfDialog);
        lProcessName->setObjectName(QStringLiteral("lProcessName"));

        gridLayout_2->addWidget(lProcessName, 2, 0, 1, 1);

        buttonBox = new QDialogButtonBox(ConvertToNgfDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close);

        gridLayout_2->addWidget(buttonBox, 4, 2, 1, 1);

        pbCalculate = new QPushButton(ConvertToNgfDialog);
        pbCalculate->setObjectName(QStringLiteral("pbCalculate"));

        gridLayout_2->addWidget(pbCalculate, 1, 1, 1, 1);

        hsl = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(hsl, 1, 0, 1, 1);

        hsr = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(hsr, 1, 2, 1, 1);


        retranslateUi(ConvertToNgfDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ConvertToNgfDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ConvertToNgfDialog, SLOT(reject()));
        QObject::connect(pbCalculate, SIGNAL(clicked()), ConvertToNgfDialog, SLOT(launchNextProcess()));

        QMetaObject::connectSlotsByName(ConvertToNgfDialog);
    } // setupUi

    void retranslateUi(QDialog *ConvertToNgfDialog)
    {
        ConvertToNgfDialog->setWindowTitle(QApplication::translate("ConvertToNgfDialog", "Dialog", 0));
        lSourceTable->setText(QApplication::translate("ConvertToNgfDialog", "Source table", 0));
        lDestinationTable->setText(QApplication::translate("ConvertToNgfDialog", "Destination table", 0));
        lHeight->setText(QApplication::translate("ConvertToNgfDialog", "Height of the water", 0));
        lProcessName->setText(QString());
        pbCalculate->setText(QApplication::translate("ConvertToNgfDialog", "Calculate", 0));
    } // retranslateUi

};

namespace Ui {
    class ConvertToNgfDialog: public Ui_ConvertToNgfDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONVERTTONGFDIALOG_H
