/********************************************************************************
** Form generated from reading UI file 'MeshDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESHDIALOG_H
#define UI_MESHDIALOG_H

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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include "MeshGraphicsView.h"

QT_BEGIN_NAMESPACE

class Ui_MeshDialog
{
public:
    QGridLayout *gridLayout_5;
    QHBoxLayout *horizontalLayout;
    QLabel *lVertex;
    QComboBox *cbTable;
    QPushButton *pbCalculate;
    QSpacerItem *hlLeftPbCalculate;
    QPushButton *pbWritingImage;
    MeshGraphicsView *graphicsView;
    QVBoxLayout *verticalLayout;
    QLabel *lX;
    QLabel *lY;
    QLabel *lZ;
    QCheckBox *cbShowVertex;
    QCheckBox *cbShowTriangles;
    QCheckBox *cbShowImage;
    QGroupBox *gbA;
    QGridLayout *gridLayout;
    QLabel *lAX;
    QLabel *lAY;
    QLabel *lAZ;
    QLabel *lAIndex;
    QGroupBox *gbB;
    QGridLayout *gridLayout_2;
    QLabel *lBX;
    QLabel *lBY;
    QLabel *lBZ;
    QLabel *lBIndex;
    QGroupBox *gbC;
    QGridLayout *gridLayout_3;
    QLabel *lCX;
    QLabel *lCY;
    QLabel *lCZ;
    QLabel *lCIndex;
    QGroupBox *gbTriangle;
    QGridLayout *gridLayout_4;
    QLabel *lTIndex;
    QSpacerItem *verticalSpacer;
    QLabel *lProcessName;
    QProgressBar *progressBar;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *MeshDialog)
    {
        if (MeshDialog->objectName().isEmpty())
            MeshDialog->setObjectName(QStringLiteral("MeshDialog"));
        MeshDialog->resize(932, 738);
        MeshDialog->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        gridLayout_5 = new QGridLayout(MeshDialog);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lVertex = new QLabel(MeshDialog);
        lVertex->setObjectName(QStringLiteral("lVertex"));
        QFont font;
        font.setUnderline(false);
        lVertex->setFont(font);

        horizontalLayout->addWidget(lVertex);

        cbTable = new QComboBox(MeshDialog);
        cbTable->setObjectName(QStringLiteral("cbTable"));
        cbTable->setMinimumSize(QSize(200, 0));
        cbTable->setFont(font);

        horizontalLayout->addWidget(cbTable);

        pbCalculate = new QPushButton(MeshDialog);
        pbCalculate->setObjectName(QStringLiteral("pbCalculate"));
        pbCalculate->setMinimumSize(QSize(0, 25));
        pbCalculate->setMaximumSize(QSize(200, 20));

        horizontalLayout->addWidget(pbCalculate);

        hlLeftPbCalculate = new QSpacerItem(58, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(hlLeftPbCalculate);

        pbWritingImage = new QPushButton(MeshDialog);
        pbWritingImage->setObjectName(QStringLiteral("pbWritingImage"));

        horizontalLayout->addWidget(pbWritingImage);


        gridLayout_5->addLayout(horizontalLayout, 0, 0, 1, 2);

        graphicsView = new MeshGraphicsView(MeshDialog);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setRenderHints(QPainter::Antialiasing|QPainter::HighQualityAntialiasing|QPainter::NonCosmeticDefaultPen|QPainter::SmoothPixmapTransform|QPainter::TextAntialiasing);
        graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

        gridLayout_5->addWidget(graphicsView, 4, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        lX = new QLabel(MeshDialog);
        lX->setObjectName(QStringLiteral("lX"));
        lX->setMinimumSize(QSize(170, 0));

        verticalLayout->addWidget(lX);

        lY = new QLabel(MeshDialog);
        lY->setObjectName(QStringLiteral("lY"));
        lY->setMinimumSize(QSize(150, 0));

        verticalLayout->addWidget(lY);

        lZ = new QLabel(MeshDialog);
        lZ->setObjectName(QStringLiteral("lZ"));
        lZ->setMinimumSize(QSize(150, 0));

        verticalLayout->addWidget(lZ);

        cbShowVertex = new QCheckBox(MeshDialog);
        cbShowVertex->setObjectName(QStringLiteral("cbShowVertex"));
        cbShowVertex->setChecked(false);

        verticalLayout->addWidget(cbShowVertex);

        cbShowTriangles = new QCheckBox(MeshDialog);
        cbShowTriangles->setObjectName(QStringLiteral("cbShowTriangles"));
        cbShowTriangles->setChecked(false);

        verticalLayout->addWidget(cbShowTriangles);

        cbShowImage = new QCheckBox(MeshDialog);
        cbShowImage->setObjectName(QStringLiteral("cbShowImage"));

        verticalLayout->addWidget(cbShowImage);

        gbA = new QGroupBox(MeshDialog);
        gbA->setObjectName(QStringLiteral("gbA"));
        gridLayout = new QGridLayout(gbA);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lAX = new QLabel(gbA);
        lAX->setObjectName(QStringLiteral("lAX"));
        lAX->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(lAX, 0, 0, 1, 1);

        lAY = new QLabel(gbA);
        lAY->setObjectName(QStringLiteral("lAY"));
        lAY->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(lAY, 1, 0, 1, 1);

        lAZ = new QLabel(gbA);
        lAZ->setObjectName(QStringLiteral("lAZ"));
        lAZ->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(lAZ, 2, 0, 1, 1);

        lAIndex = new QLabel(gbA);
        lAIndex->setObjectName(QStringLiteral("lAIndex"));

        gridLayout->addWidget(lAIndex, 3, 0, 1, 1);


        verticalLayout->addWidget(gbA);

        gbB = new QGroupBox(MeshDialog);
        gbB->setObjectName(QStringLiteral("gbB"));
        gridLayout_2 = new QGridLayout(gbB);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        lBX = new QLabel(gbB);
        lBX->setObjectName(QStringLiteral("lBX"));
        lBX->setMinimumSize(QSize(150, 0));

        gridLayout_2->addWidget(lBX, 0, 0, 1, 1);

        lBY = new QLabel(gbB);
        lBY->setObjectName(QStringLiteral("lBY"));
        lBY->setMinimumSize(QSize(150, 0));

        gridLayout_2->addWidget(lBY, 1, 0, 1, 1);

        lBZ = new QLabel(gbB);
        lBZ->setObjectName(QStringLiteral("lBZ"));
        lBZ->setMinimumSize(QSize(150, 0));

        gridLayout_2->addWidget(lBZ, 2, 0, 1, 1);

        lBIndex = new QLabel(gbB);
        lBIndex->setObjectName(QStringLiteral("lBIndex"));

        gridLayout_2->addWidget(lBIndex, 3, 0, 1, 1);


        verticalLayout->addWidget(gbB);

        gbC = new QGroupBox(MeshDialog);
        gbC->setObjectName(QStringLiteral("gbC"));
        gridLayout_3 = new QGridLayout(gbC);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        lCX = new QLabel(gbC);
        lCX->setObjectName(QStringLiteral("lCX"));
        lCX->setMinimumSize(QSize(150, 0));

        gridLayout_3->addWidget(lCX, 0, 0, 1, 1);

        lCY = new QLabel(gbC);
        lCY->setObjectName(QStringLiteral("lCY"));
        lCY->setMinimumSize(QSize(150, 0));

        gridLayout_3->addWidget(lCY, 1, 0, 1, 1);

        lCZ = new QLabel(gbC);
        lCZ->setObjectName(QStringLiteral("lCZ"));
        lCZ->setMinimumSize(QSize(150, 0));

        gridLayout_3->addWidget(lCZ, 2, 0, 1, 1);

        lCIndex = new QLabel(gbC);
        lCIndex->setObjectName(QStringLiteral("lCIndex"));

        gridLayout_3->addWidget(lCIndex, 3, 0, 1, 1);


        verticalLayout->addWidget(gbC);

        gbTriangle = new QGroupBox(MeshDialog);
        gbTriangle->setObjectName(QStringLiteral("gbTriangle"));
        gridLayout_4 = new QGridLayout(gbTriangle);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        lTIndex = new QLabel(gbTriangle);
        lTIndex->setObjectName(QStringLiteral("lTIndex"));

        gridLayout_4->addWidget(lTIndex, 0, 0, 1, 1);


        verticalLayout->addWidget(gbTriangle);

        verticalSpacer = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout_5->addLayout(verticalLayout, 4, 1, 1, 1);

        lProcessName = new QLabel(MeshDialog);
        lProcessName->setObjectName(QStringLiteral("lProcessName"));

        gridLayout_5->addWidget(lProcessName, 2, 0, 1, 1);

        progressBar = new QProgressBar(MeshDialog);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);

        gridLayout_5->addWidget(progressBar, 3, 0, 1, 2);

        buttonBox = new QDialogButtonBox(MeshDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        buttonBox->setStandardButtons(QDialogButtonBox::Close);
        buttonBox->setCenterButtons(true);

        gridLayout_5->addWidget(buttonBox, 5, 0, 1, 2);


        retranslateUi(MeshDialog);
        QObject::connect(buttonBox, SIGNAL(clicked(QAbstractButton*)), MeshDialog, SLOT(close()));
        QObject::connect(cbTable, SIGNAL(currentIndexChanged(QString)), MeshDialog, SLOT(selectTable(QString)));
        QObject::connect(cbShowVertex, SIGNAL(toggled(bool)), MeshDialog, SLOT(showVertex(bool)));
        QObject::connect(cbShowTriangles, SIGNAL(toggled(bool)), MeshDialog, SLOT(showTriangles(bool)));
        QObject::connect(cbShowImage, SIGNAL(toggled(bool)), MeshDialog, SLOT(showImage(bool)));
        QObject::connect(pbCalculate, SIGNAL(clicked()), MeshDialog, SLOT(onPbCalculate()));
        QObject::connect(pbWritingImage, SIGNAL(clicked()), MeshDialog, SLOT(onPbWriteImage()));

        QMetaObject::connectSlotsByName(MeshDialog);
    } // setupUi

    void retranslateUi(QDialog *MeshDialog)
    {
        MeshDialog->setWindowTitle(QApplication::translate("MeshDialog", "Dialog", 0));
        lVertex->setText(QApplication::translate("MeshDialog", "Table", 0));
        pbCalculate->setText(QApplication::translate("MeshDialog", "Calculate", 0));
        pbWritingImage->setText(QApplication::translate("MeshDialog", "Write image", 0));
        lX->setText(QApplication::translate("MeshDialog", "X : ", 0));
        lY->setText(QApplication::translate("MeshDialog", "Y : ", 0));
        lZ->setText(QApplication::translate("MeshDialog", "Z:", 0));
        cbShowVertex->setText(QApplication::translate("MeshDialog", "Show vertex", 0));
        cbShowTriangles->setText(QApplication::translate("MeshDialog", "Show triangles", 0));
        cbShowImage->setText(QApplication::translate("MeshDialog", "Show image", 0));
        gbA->setTitle(QApplication::translate("MeshDialog", "Point A", 0));
        lAX->setText(QApplication::translate("MeshDialog", "X : ", 0));
        lAY->setText(QApplication::translate("MeshDialog", "Y : ", 0));
        lAZ->setText(QApplication::translate("MeshDialog", "Z:", 0));
        lAIndex->setText(QApplication::translate("MeshDialog", "Index :", 0));
        gbB->setTitle(QApplication::translate("MeshDialog", "Point B", 0));
        lBX->setText(QApplication::translate("MeshDialog", "X : ", 0));
        lBY->setText(QApplication::translate("MeshDialog", "Y : ", 0));
        lBZ->setText(QApplication::translate("MeshDialog", "Z:", 0));
        lBIndex->setText(QApplication::translate("MeshDialog", "Index :", 0));
        gbC->setTitle(QApplication::translate("MeshDialog", "Point C", 0));
        lCX->setText(QApplication::translate("MeshDialog", "X : ", 0));
        lCY->setText(QApplication::translate("MeshDialog", "Y : ", 0));
        lCZ->setText(QApplication::translate("MeshDialog", "Z:", 0));
        lCIndex->setText(QApplication::translate("MeshDialog", "Index :", 0));
        gbTriangle->setTitle(QApplication::translate("MeshDialog", "Triangle", 0));
        lTIndex->setText(QApplication::translate("MeshDialog", "Index :", 0));
        lProcessName->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MeshDialog: public Ui_MeshDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESHDIALOG_H
