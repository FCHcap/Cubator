/********************************************************************************
** Form generated from reading UI file 'PmlSaveDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PMLSAVEDIALOG_H
#define UI_PMLSAVEDIALOG_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_PmlSaveDialog
{
public:
    QGridLayout *gridLayout_4;
    QGridLayout *glDialog;
    QGridLayout *glMap;
    QLabel *lMap;
    QComboBox *cbMap;
    QSpacerItem *hsMap;
    QGridLayout *glFile;
    QLabel *lFile;
    QLineEdit *leFile;
    QPushButton *pbFile;
    QSpacerItem *vsDialogTop;
    QSpacerItem *hsDialogLeft;
    QPushButton *pbSave;
    QSpacerItem *hsDialogRight;
    QSpacerItem *vsDialogBottom;
    QProgressBar *progressBar;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *PmlSaveDialog)
    {
        if (PmlSaveDialog->objectName().isEmpty())
            PmlSaveDialog->setObjectName(QStringLiteral("PmlSaveDialog"));
        PmlSaveDialog->resize(400, 162);
        PmlSaveDialog->setMinimumSize(QSize(400, 162));
        PmlSaveDialog->setMaximumSize(QSize(400, 162));
        PmlSaveDialog->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        gridLayout_4 = new QGridLayout(PmlSaveDialog);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        glDialog = new QGridLayout();
        glDialog->setObjectName(QStringLiteral("glDialog"));
        glMap = new QGridLayout();
        glMap->setObjectName(QStringLiteral("glMap"));
        lMap = new QLabel(PmlSaveDialog);
        lMap->setObjectName(QStringLiteral("lMap"));
        lMap->setMinimumSize(QSize(50, 0));
        lMap->setMaximumSize(QSize(50, 16777215));

        glMap->addWidget(lMap, 0, 0, 1, 1);

        cbMap = new QComboBox(PmlSaveDialog);
        cbMap->setObjectName(QStringLiteral("cbMap"));
        cbMap->setMinimumSize(QSize(150, 0));
        cbMap->setMaximumSize(QSize(150, 16777215));

        glMap->addWidget(cbMap, 0, 1, 1, 1);

        hsMap = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        glMap->addItem(hsMap, 0, 2, 1, 1);


        glDialog->addLayout(glMap, 0, 0, 1, 3);

        glFile = new QGridLayout();
        glFile->setObjectName(QStringLiteral("glFile"));
        lFile = new QLabel(PmlSaveDialog);
        lFile->setObjectName(QStringLiteral("lFile"));
        lFile->setMinimumSize(QSize(50, 0));
        lFile->setMaximumSize(QSize(50, 16));

        glFile->addWidget(lFile, 0, 0, 1, 1);

        leFile = new QLineEdit(PmlSaveDialog);
        leFile->setObjectName(QStringLiteral("leFile"));

        glFile->addWidget(leFile, 0, 1, 1, 1);

        pbFile = new QPushButton(PmlSaveDialog);
        pbFile->setObjectName(QStringLiteral("pbFile"));
        pbFile->setMaximumSize(QSize(21, 24));

        glFile->addWidget(pbFile, 0, 2, 1, 1);


        glDialog->addLayout(glFile, 1, 0, 1, 3);

        vsDialogTop = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        glDialog->addItem(vsDialogTop, 2, 1, 1, 1);

        hsDialogLeft = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        glDialog->addItem(hsDialogLeft, 3, 0, 1, 1);

        pbSave = new QPushButton(PmlSaveDialog);
        pbSave->setObjectName(QStringLiteral("pbSave"));

        glDialog->addWidget(pbSave, 3, 1, 1, 1);

        hsDialogRight = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        glDialog->addItem(hsDialogRight, 3, 2, 1, 1);

        vsDialogBottom = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        glDialog->addItem(vsDialogBottom, 4, 1, 1, 1);

        progressBar = new QProgressBar(PmlSaveDialog);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(24);

        glDialog->addWidget(progressBar, 5, 0, 1, 3);

        buttonBox = new QDialogButtonBox(PmlSaveDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        glDialog->addWidget(buttonBox, 6, 0, 1, 3);


        gridLayout_4->addLayout(glDialog, 0, 0, 1, 1);


        retranslateUi(PmlSaveDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), PmlSaveDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), PmlSaveDialog, SLOT(reject()));
        QObject::connect(pbSave, SIGNAL(clicked()), PmlSaveDialog, SLOT(onSave()));
        QObject::connect(pbFile, SIGNAL(clicked()), PmlSaveDialog, SLOT(onFileSelect()));

        QMetaObject::connectSlotsByName(PmlSaveDialog);
    } // setupUi

    void retranslateUi(QDialog *PmlSaveDialog)
    {
        PmlSaveDialog->setWindowTitle(QApplication::translate("PmlSaveDialog", "Dialog", 0));
        lMap->setText(QApplication::translate("PmlSaveDialog", "Map", 0));
        lFile->setText(QApplication::translate("PmlSaveDialog", "File", 0));
        pbFile->setText(QApplication::translate("PmlSaveDialog", "...", 0));
        pbSave->setText(QApplication::translate("PmlSaveDialog", "Save", 0));
    } // retranslateUi

};

namespace Ui {
    class PmlSaveDialog: public Ui_PmlSaveDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PMLSAVEDIALOG_H
