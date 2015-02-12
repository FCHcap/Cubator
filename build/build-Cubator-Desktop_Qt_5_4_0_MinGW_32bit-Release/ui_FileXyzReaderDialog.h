/********************************************************************************
** Form generated from reading UI file 'FileXyzReaderDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEXYZREADERDIALOG_H
#define UI_FILEXYZREADERDIALOG_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_FileXyzReaderDialog
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *hlFile;
    QLabel *lFile;
    QLineEdit *leFile;
    QPushButton *pbFile;
    QHBoxLayout *hlDelimitor;
    QLabel *lDelimitor;
    QComboBox *cbDelimitor;
    QHBoxLayout *hlTable;
    QLabel *lTable;
    QComboBox *cbTable;
    QHBoxLayout *hlCalculate;
    QSpacerItem *hsCalculateLeft;
    QPushButton *pbImport;
    QSpacerItem *hlCalculateRight;
    QLabel *lOperationName;
    QProgressBar *progressBar;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *FileXyzReaderDialog)
    {
        if (FileXyzReaderDialog->objectName().isEmpty())
            FileXyzReaderDialog->setObjectName(QStringLiteral("FileXyzReaderDialog"));
        FileXyzReaderDialog->resize(476, 228);
        FileXyzReaderDialog->setMinimumSize(QSize(476, 228));
        FileXyzReaderDialog->setMaximumSize(QSize(476, 228));
        FileXyzReaderDialog->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        gridLayout = new QGridLayout(FileXyzReaderDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        hlFile = new QHBoxLayout();
        hlFile->setObjectName(QStringLiteral("hlFile"));
        lFile = new QLabel(FileXyzReaderDialog);
        lFile->setObjectName(QStringLiteral("lFile"));

        hlFile->addWidget(lFile);

        leFile = new QLineEdit(FileXyzReaderDialog);
        leFile->setObjectName(QStringLiteral("leFile"));

        hlFile->addWidget(leFile);

        pbFile = new QPushButton(FileXyzReaderDialog);
        pbFile->setObjectName(QStringLiteral("pbFile"));

        hlFile->addWidget(pbFile);


        gridLayout->addLayout(hlFile, 0, 0, 1, 1);

        hlDelimitor = new QHBoxLayout();
        hlDelimitor->setObjectName(QStringLiteral("hlDelimitor"));
        lDelimitor = new QLabel(FileXyzReaderDialog);
        lDelimitor->setObjectName(QStringLiteral("lDelimitor"));

        hlDelimitor->addWidget(lDelimitor);

        cbDelimitor = new QComboBox(FileXyzReaderDialog);
        cbDelimitor->setObjectName(QStringLiteral("cbDelimitor"));

        hlDelimitor->addWidget(cbDelimitor);


        gridLayout->addLayout(hlDelimitor, 1, 0, 1, 1);

        hlTable = new QHBoxLayout();
        hlTable->setObjectName(QStringLiteral("hlTable"));
        lTable = new QLabel(FileXyzReaderDialog);
        lTable->setObjectName(QStringLiteral("lTable"));

        hlTable->addWidget(lTable);

        cbTable = new QComboBox(FileXyzReaderDialog);
        cbTable->setObjectName(QStringLiteral("cbTable"));

        hlTable->addWidget(cbTable);


        gridLayout->addLayout(hlTable, 2, 0, 1, 1);

        hlCalculate = new QHBoxLayout();
        hlCalculate->setObjectName(QStringLiteral("hlCalculate"));
        hsCalculateLeft = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hlCalculate->addItem(hsCalculateLeft);

        pbImport = new QPushButton(FileXyzReaderDialog);
        pbImport->setObjectName(QStringLiteral("pbImport"));

        hlCalculate->addWidget(pbImport);

        hlCalculateRight = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hlCalculate->addItem(hlCalculateRight);


        gridLayout->addLayout(hlCalculate, 3, 0, 1, 1);

        lOperationName = new QLabel(FileXyzReaderDialog);
        lOperationName->setObjectName(QStringLiteral("lOperationName"));

        gridLayout->addWidget(lOperationName, 4, 0, 1, 1);

        progressBar = new QProgressBar(FileXyzReaderDialog);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);

        gridLayout->addWidget(progressBar, 5, 0, 1, 1);

        buttonBox = new QDialogButtonBox(FileXyzReaderDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setMaximumSize(QSize(468, 25));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close);

        gridLayout->addWidget(buttonBox, 6, 0, 1, 1);


        retranslateUi(FileXyzReaderDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), FileXyzReaderDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), FileXyzReaderDialog, SLOT(reject()));
        QObject::connect(pbFile, SIGNAL(clicked()), FileXyzReaderDialog, SLOT(selectFile()));
        QObject::connect(pbImport, SIGNAL(clicked()), FileXyzReaderDialog, SLOT(import()));

        QMetaObject::connectSlotsByName(FileXyzReaderDialog);
    } // setupUi

    void retranslateUi(QDialog *FileXyzReaderDialog)
    {
        FileXyzReaderDialog->setWindowTitle(QApplication::translate("FileXyzReaderDialog", "File XYZ converter", 0));
        lFile->setText(QApplication::translate("FileXyzReaderDialog", "File", 0));
        pbFile->setText(QApplication::translate("FileXyzReaderDialog", "...", 0));
        lDelimitor->setText(QApplication::translate("FileXyzReaderDialog", "Delimitor caracter", 0));
        lTable->setText(QApplication::translate("FileXyzReaderDialog", "Table", 0));
        pbImport->setText(QApplication::translate("FileXyzReaderDialog", "Import", 0));
        lOperationName->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FileXyzReaderDialog: public Ui_FileXyzReaderDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEXYZREADERDIALOG_H
