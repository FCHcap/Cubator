#include "SelectItemDialog.h"
#include "ui_SelectItemDialog.h"

SelectItemDialog::SelectItemDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectItemDialog)
{
    ui->setupUi(this);

    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
}

SelectItemDialog::~SelectItemDialog()
{
    delete ui;
}

void SelectItemDialog::setItemsList(QList<QString> items){
    ui->listWidget->clear();
    ui->listWidget->addItems(items);
}

void SelectItemDialog::setItemSelected(QString name){
    for(int i=0;i<ui->listWidget->count();i++){
        QListWidgetItem* item=ui->listWidget->item(i);
        if(item->text()==name){
            ui->listWidget->setCurrentItem(item);
        }
    }
}

QString SelectItemDialog::itemSelected(){
    return ui->listWidget->currentItem()->text();
}

void SelectItemDialog::setButtonBox(QDialogButtonBox::StandardButtons buttons){
    ui->buttonBox->setStandardButtons(buttons);
}
