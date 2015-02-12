/********************************************************************************
** Form generated from reading UI file 'DateDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATEDIALOG_H
#define UI_DATEDIALOG_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_DateDialog
{
public:
    QGridLayout *gridLayout;
    QCalendarWidget *calendarWidget;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DateDialog)
    {
        if (DateDialog->objectName().isEmpty())
            DateDialog->setObjectName(QStringLiteral("DateDialog"));
        DateDialog->resize(386, 225);
        DateDialog->setMinimumSize(QSize(386, 225));
        DateDialog->setMaximumSize(QSize(386, 225));
        DateDialog->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        gridLayout = new QGridLayout(DateDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        calendarWidget = new QCalendarWidget(DateDialog);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));

        gridLayout->addWidget(calendarWidget, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(DateDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(DateDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), DateDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DateDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(DateDialog);
    } // setupUi

    void retranslateUi(QDialog *DateDialog)
    {
        DateDialog->setWindowTitle(QApplication::translate("DateDialog", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class DateDialog: public Ui_DateDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATEDIALOG_H
