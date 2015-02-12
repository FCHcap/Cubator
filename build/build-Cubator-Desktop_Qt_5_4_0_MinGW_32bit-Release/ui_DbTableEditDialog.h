/********************************************************************************
** Form generated from reading UI file 'DbTableEditDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DBTABLEEDITDIALOG_H
#define UI_DBTABLEEDITDIALOG_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DbTableEditDialog
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QListWidget *listWidget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *buttonCreate;
    QPushButton *buttonDelete;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout;
    QLabel *labelDate;
    QLabel *labelComments;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DbTableEditDialog)
    {
        if (DbTableEditDialog->objectName().isEmpty())
            DbTableEditDialog->setObjectName(QStringLiteral("DbTableEditDialog"));
        DbTableEditDialog->resize(340, 321);
        DbTableEditDialog->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        gridLayout = new QGridLayout(DbTableEditDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        listWidget = new QListWidget(DbTableEditDialog);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        horizontalLayout->addWidget(listWidget);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        buttonCreate = new QPushButton(DbTableEditDialog);
        buttonCreate->setObjectName(QStringLiteral("buttonCreate"));

        verticalLayout_2->addWidget(buttonCreate);

        buttonDelete = new QPushButton(DbTableEditDialog);
        buttonDelete->setObjectName(QStringLiteral("buttonDelete"));

        verticalLayout_2->addWidget(buttonDelete);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        labelDate = new QLabel(DbTableEditDialog);
        labelDate->setObjectName(QStringLiteral("labelDate"));

        verticalLayout->addWidget(labelDate);

        labelComments = new QLabel(DbTableEditDialog);
        labelComments->setObjectName(QStringLiteral("labelComments"));

        verticalLayout->addWidget(labelComments);


        verticalLayout_3->addLayout(verticalLayout);

        buttonBox = new QDialogButtonBox(DbTableEditDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Close);
        buttonBox->setCenterButtons(true);

        verticalLayout_3->addWidget(buttonBox);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);


        retranslateUi(DbTableEditDialog);
        QObject::connect(buttonBox, SIGNAL(clicked(QAbstractButton*)), DbTableEditDialog, SLOT(accept()));
        QObject::connect(listWidget, SIGNAL(currentTextChanged(QString)), DbTableEditDialog, SLOT(onTableSelectionChanged(QString)));
        QObject::connect(buttonCreate, SIGNAL(clicked()), DbTableEditDialog, SLOT(onButtonCreate()));
        QObject::connect(buttonDelete, SIGNAL(clicked()), DbTableEditDialog, SLOT(onButtonDelete()));

        QMetaObject::connectSlotsByName(DbTableEditDialog);
    } // setupUi

    void retranslateUi(QDialog *DbTableEditDialog)
    {
        DbTableEditDialog->setWindowTitle(QApplication::translate("DbTableEditDialog", "Table Edit", 0));
        DbTableEditDialog->setWindowFilePath(QApplication::translate("DbTableEditDialog", "Edit tables", 0));
        buttonCreate->setText(QApplication::translate("DbTableEditDialog", "Create table", 0));
        buttonDelete->setText(QApplication::translate("DbTableEditDialog", "Delete Table", 0));
        labelDate->setText(QApplication::translate("DbTableEditDialog", "Creation date :", 0));
        labelComments->setText(QApplication::translate("DbTableEditDialog", "Comments :", 0));
    } // retranslateUi

};

namespace Ui {
    class DbTableEditDialog: public Ui_DbTableEditDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DBTABLEEDITDIALOG_H
