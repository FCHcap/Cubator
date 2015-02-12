/********************************************************************************
** Form generated from reading UI file 'DbCreateTableDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DBCREATETABLEDIALOG_H
#define UI_DBCREATETABLEDIALOG_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_DbCreateTableDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *labelName;
    QLineEdit *editName;
    QLabel *labelComments;
    QLineEdit *editComments;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DbCreateTableDialog)
    {
        if (DbCreateTableDialog->objectName().isEmpty())
            DbCreateTableDialog->setObjectName(QStringLiteral("DbCreateTableDialog"));
        DbCreateTableDialog->resize(309, 149);
        DbCreateTableDialog->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        gridLayout = new QGridLayout(DbCreateTableDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        labelName = new QLabel(DbCreateTableDialog);
        labelName->setObjectName(QStringLiteral("labelName"));

        gridLayout->addWidget(labelName, 0, 0, 1, 1);

        editName = new QLineEdit(DbCreateTableDialog);
        editName->setObjectName(QStringLiteral("editName"));

        gridLayout->addWidget(editName, 0, 1, 1, 2);

        labelComments = new QLabel(DbCreateTableDialog);
        labelComments->setObjectName(QStringLiteral("labelComments"));

        gridLayout->addWidget(labelComments, 1, 0, 1, 2);

        editComments = new QLineEdit(DbCreateTableDialog);
        editComments->setObjectName(QStringLiteral("editComments"));

        gridLayout->addWidget(editComments, 1, 2, 1, 1);

        buttonBox = new QDialogButtonBox(DbCreateTableDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);

        gridLayout->addWidget(buttonBox, 2, 0, 1, 3);


        retranslateUi(DbCreateTableDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), DbCreateTableDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DbCreateTableDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(DbCreateTableDialog);
    } // setupUi

    void retranslateUi(QDialog *DbCreateTableDialog)
    {
        DbCreateTableDialog->setWindowTitle(QApplication::translate("DbCreateTableDialog", "Create table", 0));
        labelName->setText(QApplication::translate("DbCreateTableDialog", "Name", 0));
        labelComments->setText(QApplication::translate("DbCreateTableDialog", "Comments", 0));
    } // retranslateUi

};

namespace Ui {
    class DbCreateTableDialog: public Ui_DbCreateTableDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DBCREATETABLEDIALOG_H
