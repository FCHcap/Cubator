/********************************************************************************
** Form generated from reading UI file 'ErrorDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ERRORDIALOG_H
#define UI_ERRORDIALOG_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ErrorDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *hlError;
    QLabel *icon;
    QLabel *error;
    QHBoxLayout *hlButtons;
    QDialogButtonBox *buttonBox;
    QPushButton *pbDetails;
    QTextBrowser *tbDetails;

    void setupUi(QDialog *ErrorDialog)
    {
        if (ErrorDialog->objectName().isEmpty())
            ErrorDialog->setObjectName(QStringLiteral("ErrorDialog"));
        ErrorDialog->resize(400, 285);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ErrorDialog->sizePolicy().hasHeightForWidth());
        ErrorDialog->setSizePolicy(sizePolicy);
        ErrorDialog->setMinimumSize(QSize(400, 0));
        ErrorDialog->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        ErrorDialog->setSizeGripEnabled(true);
        verticalLayout = new QVBoxLayout(ErrorDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetFixedSize);
        hlError = new QHBoxLayout();
        hlError->setObjectName(QStringLiteral("hlError"));
        hlError->setSizeConstraint(QLayout::SetFixedSize);
        icon = new QLabel(ErrorDialog);
        icon->setObjectName(QStringLiteral("icon"));
        icon->setMinimumSize(QSize(60, 0));
        icon->setMaximumSize(QSize(80, 16777215));
        icon->setSizeIncrement(QSize(0, 0));
        icon->setPixmap(QPixmap(QString::fromUtf8(":/icons/error.png")));

        hlError->addWidget(icon);

        error = new QLabel(ErrorDialog);
        error->setObjectName(QStringLiteral("error"));
        error->setMinimumSize(QSize(250, 0));
        error->setScaledContents(true);

        hlError->addWidget(error);


        verticalLayout->addLayout(hlError);

        hlButtons = new QHBoxLayout();
        hlButtons->setObjectName(QStringLiteral("hlButtons"));
        buttonBox = new QDialogButtonBox(ErrorDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);

        hlButtons->addWidget(buttonBox);

        pbDetails = new QPushButton(ErrorDialog);
        pbDetails->setObjectName(QStringLiteral("pbDetails"));
        pbDetails->setMaximumSize(QSize(71, 24));
        pbDetails->setCheckable(true);
        pbDetails->setFlat(false);

        hlButtons->addWidget(pbDetails);


        verticalLayout->addLayout(hlButtons);

        tbDetails = new QTextBrowser(ErrorDialog);
        tbDetails->setObjectName(QStringLiteral("tbDetails"));

        verticalLayout->addWidget(tbDetails);


        retranslateUi(ErrorDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ErrorDialog, SLOT(accept()));
        QObject::connect(pbDetails, SIGNAL(toggled(bool)), tbDetails, SLOT(setVisible(bool)));

        QMetaObject::connectSlotsByName(ErrorDialog);
    } // setupUi

    void retranslateUi(QDialog *ErrorDialog)
    {
        ErrorDialog->setWindowTitle(QApplication::translate("ErrorDialog", "Dialog", 0));
        icon->setText(QString());
        error->setText(QApplication::translate("ErrorDialog", "error", 0));
        pbDetails->setText(QApplication::translate("ErrorDialog", "&D\303\251tails", 0));
    } // retranslateUi

};

namespace Ui {
    class ErrorDialog: public Ui_ErrorDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ERRORDIALOG_H
