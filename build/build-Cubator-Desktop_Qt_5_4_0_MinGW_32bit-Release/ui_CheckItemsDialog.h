/********************************************************************************
** Form generated from reading UI file 'CheckItemsDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKITEMSDIALOG_H
#define UI_CHECKITEMSDIALOG_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>

QT_BEGIN_NAMESPACE

class Ui_CheckItemsDialog
{
public:
    QGridLayout *gridLayout;
    QListWidget *listWidget;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CheckItemsDialog)
    {
        if (CheckItemsDialog->objectName().isEmpty())
            CheckItemsDialog->setObjectName(QStringLiteral("CheckItemsDialog"));
        CheckItemsDialog->resize(400, 300);
        CheckItemsDialog->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        gridLayout = new QGridLayout(CheckItemsDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        listWidget = new QListWidget(CheckItemsDialog);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        gridLayout->addWidget(listWidget, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(CheckItemsDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close);
        buttonBox->setCenterButtons(true);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(CheckItemsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), CheckItemsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CheckItemsDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(CheckItemsDialog);
    } // setupUi

    void retranslateUi(QDialog *CheckItemsDialog)
    {
        CheckItemsDialog->setWindowTitle(QApplication::translate("CheckItemsDialog", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class CheckItemsDialog: public Ui_CheckItemsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKITEMSDIALOG_H
