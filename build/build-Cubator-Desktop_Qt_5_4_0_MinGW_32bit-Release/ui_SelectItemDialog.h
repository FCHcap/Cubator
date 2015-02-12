/********************************************************************************
** Form generated from reading UI file 'SelectItemDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTITEMDIALOG_H
#define UI_SELECTITEMDIALOG_H

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

class Ui_SelectItemDialog
{
public:
    QGridLayout *gridLayout;
    QListWidget *listWidget;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SelectItemDialog)
    {
        if (SelectItemDialog->objectName().isEmpty())
            SelectItemDialog->setObjectName(QStringLiteral("SelectItemDialog"));
        SelectItemDialog->setWindowModality(Qt::ApplicationModal);
        SelectItemDialog->resize(400, 300);
        SelectItemDialog->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        gridLayout = new QGridLayout(SelectItemDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        listWidget = new QListWidget(SelectItemDialog);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        gridLayout->addWidget(listWidget, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(SelectItemDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close);
        buttonBox->setCenterButtons(true);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(SelectItemDialog);
        QObject::connect(buttonBox, SIGNAL(clicked(QAbstractButton*)), SelectItemDialog, SLOT(accept()));

        QMetaObject::connectSlotsByName(SelectItemDialog);
    } // setupUi

    void retranslateUi(QDialog *SelectItemDialog)
    {
        SelectItemDialog->setWindowTitle(QApplication::translate("SelectItemDialog", "Select Item", 0));
    } // retranslateUi

};

namespace Ui {
    class SelectItemDialog: public Ui_SelectItemDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTITEMDIALOG_H
