/********************************************************************************
** Form generated from reading UI file 'CreateIconDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEICONDIALOG_H
#define UI_CREATEICONDIALOG_H

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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CreateIconDialog
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *labelX;
    QLabel *labelY;
    QSpacerItem *horizontalSpacer;
    QPushButton *buttonCoords;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelDate;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *buttonDate;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelRotation;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *buttonRotation;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CreateIconDialog)
    {
        if (CreateIconDialog->objectName().isEmpty())
            CreateIconDialog->setObjectName(QStringLiteral("CreateIconDialog"));
        CreateIconDialog->resize(301, 180);
        CreateIconDialog->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        gridLayout = new QGridLayout(CreateIconDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        labelX = new QLabel(CreateIconDialog);
        labelX->setObjectName(QStringLiteral("labelX"));

        verticalLayout->addWidget(labelX);

        labelY = new QLabel(CreateIconDialog);
        labelY->setObjectName(QStringLiteral("labelY"));

        verticalLayout->addWidget(labelY);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        buttonCoords = new QPushButton(CreateIconDialog);
        buttonCoords->setObjectName(QStringLiteral("buttonCoords"));

        horizontalLayout->addWidget(buttonCoords);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        labelDate = new QLabel(CreateIconDialog);
        labelDate->setObjectName(QStringLiteral("labelDate"));

        horizontalLayout_2->addWidget(labelDate);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        buttonDate = new QPushButton(CreateIconDialog);
        buttonDate->setObjectName(QStringLiteral("buttonDate"));

        horizontalLayout_2->addWidget(buttonDate);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        labelRotation = new QLabel(CreateIconDialog);
        labelRotation->setObjectName(QStringLiteral("labelRotation"));

        horizontalLayout_3->addWidget(labelRotation);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        buttonRotation = new QPushButton(CreateIconDialog);
        buttonRotation->setObjectName(QStringLiteral("buttonRotation"));

        horizontalLayout_3->addWidget(buttonRotation);


        verticalLayout_2->addLayout(horizontalLayout_3);

        buttonBox = new QDialogButtonBox(CreateIconDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);

        QWidget::setTabOrder(buttonCoords, buttonDate);
        QWidget::setTabOrder(buttonDate, buttonRotation);
        QWidget::setTabOrder(buttonRotation, buttonBox);

        retranslateUi(CreateIconDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), CreateIconDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CreateIconDialog, SLOT(reject()));
        QObject::connect(buttonCoords, SIGNAL(clicked()), CreateIconDialog, SLOT(onButtonCoordsEdit()));
        QObject::connect(buttonDate, SIGNAL(clicked()), CreateIconDialog, SLOT(onButtonDateEdit()));
        QObject::connect(buttonRotation, SIGNAL(clicked()), CreateIconDialog, SLOT(onButtonRotationEdit()));

        QMetaObject::connectSlotsByName(CreateIconDialog);
    } // setupUi

    void retranslateUi(QDialog *CreateIconDialog)
    {
        CreateIconDialog->setWindowTitle(QApplication::translate("CreateIconDialog", "Icon", 0));
        labelX->setText(QApplication::translate("CreateIconDialog", "X :", 0));
        labelY->setText(QApplication::translate("CreateIconDialog", "Y :", 0));
        buttonCoords->setText(QApplication::translate("CreateIconDialog", "Change", 0));
        labelDate->setText(QApplication::translate("CreateIconDialog", "Date : ", 0));
        buttonDate->setText(QApplication::translate("CreateIconDialog", "Change", 0));
        labelRotation->setText(QApplication::translate("CreateIconDialog", "Rotation : ", 0));
        buttonRotation->setText(QApplication::translate("CreateIconDialog", "Change", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateIconDialog: public Ui_CreateIconDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEICONDIALOG_H
