/********************************************************************************
** Form generated from reading UI file 'ConvertMapFileDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONVERTMAPFILEDIALOG_H
#define UI_CONVERTMAPFILEDIALOG_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_ConvertMapFileDialog
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *lSourceFile;
    QPushButton *pbSourceFile;
    QLabel *lDestinationFile;
    QLineEdit *leDestinationFile;
    QPushButton *pbDestinationFile;
    QLineEdit *leSourceFile;
    QSpacerItem *hsConvertLeft;
    QPushButton *pbConvert;
    QSpacerItem *hsConvertRight;
    QDialogButtonBox *buttonBox;
    QCheckBox *cbSortByType;

    void setupUi(QDialog *ConvertMapFileDialog)
    {
        if (ConvertMapFileDialog->objectName().isEmpty())
            ConvertMapFileDialog->setObjectName(QStringLiteral("ConvertMapFileDialog"));
        ConvertMapFileDialog->resize(445, 164);
        ConvertMapFileDialog->setMinimumSize(QSize(422, 145));
        ConvertMapFileDialog->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        gridLayout_2 = new QGridLayout(ConvertMapFileDialog);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lSourceFile = new QLabel(ConvertMapFileDialog);
        lSourceFile->setObjectName(QStringLiteral("lSourceFile"));

        gridLayout->addWidget(lSourceFile, 0, 0, 1, 1);

        pbSourceFile = new QPushButton(ConvertMapFileDialog);
        pbSourceFile->setObjectName(QStringLiteral("pbSourceFile"));

        gridLayout->addWidget(pbSourceFile, 0, 2, 1, 1);

        lDestinationFile = new QLabel(ConvertMapFileDialog);
        lDestinationFile->setObjectName(QStringLiteral("lDestinationFile"));

        gridLayout->addWidget(lDestinationFile, 1, 0, 1, 1);

        leDestinationFile = new QLineEdit(ConvertMapFileDialog);
        leDestinationFile->setObjectName(QStringLiteral("leDestinationFile"));

        gridLayout->addWidget(leDestinationFile, 1, 1, 1, 1);

        pbDestinationFile = new QPushButton(ConvertMapFileDialog);
        pbDestinationFile->setObjectName(QStringLiteral("pbDestinationFile"));

        gridLayout->addWidget(pbDestinationFile, 1, 2, 1, 1);

        leSourceFile = new QLineEdit(ConvertMapFileDialog);
        leSourceFile->setObjectName(QStringLiteral("leSourceFile"));

        gridLayout->addWidget(leSourceFile, 0, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 3);

        hsConvertLeft = new QSpacerItem(166, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(hsConvertLeft, 2, 0, 1, 1);

        pbConvert = new QPushButton(ConvertMapFileDialog);
        pbConvert->setObjectName(QStringLiteral("pbConvert"));

        gridLayout_2->addWidget(pbConvert, 2, 1, 1, 1);

        hsConvertRight = new QSpacerItem(165, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(hsConvertRight, 2, 2, 1, 1);

        buttonBox = new QDialogButtonBox(ConvertMapFileDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close);

        gridLayout_2->addWidget(buttonBox, 3, 1, 1, 2);

        cbSortByType = new QCheckBox(ConvertMapFileDialog);
        cbSortByType->setObjectName(QStringLiteral("cbSortByType"));

        gridLayout_2->addWidget(cbSortByType, 1, 0, 1, 1);


        retranslateUi(ConvertMapFileDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ConvertMapFileDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ConvertMapFileDialog, SLOT(reject()));
        QObject::connect(pbConvert, SIGNAL(clicked()), ConvertMapFileDialog, SLOT(onConvert()));
        QObject::connect(pbSourceFile, SIGNAL(clicked()), ConvertMapFileDialog, SLOT(onSfBrowse()));
        QObject::connect(pbDestinationFile, SIGNAL(clicked()), ConvertMapFileDialog, SLOT(onDfBrowse()));
        QObject::connect(leDestinationFile, SIGNAL(textChanged(QString)), ConvertMapFileDialog, SLOT(onLeChanged()));
        QObject::connect(leSourceFile, SIGNAL(textChanged(QString)), ConvertMapFileDialog, SLOT(onLeChanged()));

        QMetaObject::connectSlotsByName(ConvertMapFileDialog);
    } // setupUi

    void retranslateUi(QDialog *ConvertMapFileDialog)
    {
        ConvertMapFileDialog->setWindowTitle(QApplication::translate("ConvertMapFileDialog", "Convert map file", 0));
        lSourceFile->setText(QApplication::translate("ConvertMapFileDialog", "Source file", 0));
        pbSourceFile->setText(QApplication::translate("ConvertMapFileDialog", "...", 0));
        lDestinationFile->setText(QApplication::translate("ConvertMapFileDialog", "Destination file", 0));
        pbDestinationFile->setText(QApplication::translate("ConvertMapFileDialog", "...", 0));
        pbConvert->setText(QApplication::translate("ConvertMapFileDialog", "Convert", 0));
        cbSortByType->setText(QApplication::translate("ConvertMapFileDialog", "Sort the layers by item type", 0));
    } // retranslateUi

};

namespace Ui {
    class ConvertMapFileDialog: public Ui_ConvertMapFileDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONVERTMAPFILEDIALOG_H
