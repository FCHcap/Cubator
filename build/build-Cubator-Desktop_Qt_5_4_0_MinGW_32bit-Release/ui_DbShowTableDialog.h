/********************************************************************************
** Form generated from reading UI file 'DbShowTableDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DBSHOWTABLEDIALOG_H
#define UI_DBSHOWTABLEDIALOG_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include "DbTableWidget.h"

QT_BEGIN_NAMESPACE

class Ui_DbShowTableDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QCheckBox *cbAllowChanges;
    DbTableWidget *tableWidget;
    QComboBox *comboTablesNames;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DbShowTableDialog)
    {
        if (DbShowTableDialog->objectName().isEmpty())
            DbShowTableDialog->setObjectName(QStringLiteral("DbShowTableDialog"));
        DbShowTableDialog->resize(640, 490);
        DbShowTableDialog->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        gridLayout = new QGridLayout(DbShowTableDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(DbShowTableDialog);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(487, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        cbAllowChanges = new QCheckBox(DbShowTableDialog);
        cbAllowChanges->setObjectName(QStringLiteral("cbAllowChanges"));

        gridLayout->addWidget(cbAllowChanges, 2, 0, 1, 2);

        tableWidget = new DbTableWidget(DbShowTableDialog);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        gridLayout->addWidget(tableWidget, 1, 0, 1, 3);

        comboTablesNames = new QComboBox(DbShowTableDialog);
        comboTablesNames->setObjectName(QStringLiteral("comboTablesNames"));

        gridLayout->addWidget(comboTablesNames, 0, 1, 1, 1);

        buttonBox = new QDialogButtonBox(DbShowTableDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setLayoutDirection(Qt::LeftToRight);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close);
        buttonBox->setCenterButtons(true);

        gridLayout->addWidget(buttonBox, 3, 0, 1, 3);


        retranslateUi(DbShowTableDialog);
        QObject::connect(buttonBox, SIGNAL(rejected()), DbShowTableDialog, SLOT(exit()));
        QObject::connect(comboTablesNames, SIGNAL(currentIndexChanged(QString)), DbShowTableDialog, SLOT(onComboTablesNamesChanged(QString)));
        QObject::connect(cbAllowChanges, SIGNAL(toggled(bool)), DbShowTableDialog, SLOT(allowChanges(bool)));

        QMetaObject::connectSlotsByName(DbShowTableDialog);
    } // setupUi

    void retranslateUi(QDialog *DbShowTableDialog)
    {
        DbShowTableDialog->setWindowTitle(QApplication::translate("DbShowTableDialog", "Data Viewer", 0));
        label->setText(QApplication::translate("DbShowTableDialog", "Table", 0));
        cbAllowChanges->setText(QApplication::translate("DbShowTableDialog", "Allow changes", 0));
    } // retranslateUi

};

namespace Ui {
    class DbShowTableDialog: public Ui_DbShowTableDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DBSHOWTABLEDIALOG_H
