/********************************************************************************
** Form generated from reading UI file 'ProgressDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROGRESSDIALOG_H
#define UI_PROGRESSDIALOG_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>

QT_BEGIN_NAMESPACE

class Ui_ProgressDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QProgressBar *progressBar;

    void setupUi(QDialog *ProgressDialog)
    {
        if (ProgressDialog->objectName().isEmpty())
            ProgressDialog->setObjectName(QStringLiteral("ProgressDialog"));
        ProgressDialog->resize(410, 71);
        ProgressDialog->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        gridLayout = new QGridLayout(ProgressDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(ProgressDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(392, 22));
        label->setMaximumSize(QSize(392, 22));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        progressBar = new QProgressBar(ProgressDialog);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(24);

        gridLayout->addWidget(progressBar, 1, 0, 1, 1);


        retranslateUi(ProgressDialog);

        QMetaObject::connectSlotsByName(ProgressDialog);
    } // setupUi

    void retranslateUi(QDialog *ProgressDialog)
    {
        ProgressDialog->setWindowTitle(QApplication::translate("ProgressDialog", "Cubator - process", 0));
        label->setText(QApplication::translate("ProgressDialog", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class ProgressDialog: public Ui_ProgressDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROGRESSDIALOG_H
