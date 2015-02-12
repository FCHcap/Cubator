#include "CheckItemsDialog.h"
#include "ui_CheckItemsDialog.h"

CheckItemsDialog::CheckItemsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CheckItemsDialog)
{
    ui->setupUi(this);
}

CheckItemsDialog::~CheckItemsDialog()
{
    delete ui;
}

void CheckItemsDialog::setItems(QMap<QString, bool> hash){
    QMapIterator<QString, bool> i(hash);
    while(i.hasNext()){
        i.next();
        QListWidgetItem * item = new QListWidgetItem(ui->listWidget);
        item->setText(i.key());
        if(i.value()) item->setCheckState(Qt::Checked);
        else item->setCheckState(Qt::Unchecked);
    }
}

QMap<QString, bool> CheckItemsDialog::items(){

    QMap<QString, bool> hash;

    for(int i=0; i < ui->listWidget->count(); i++){
        QListWidgetItem * item = ui->listWidget->item(i);
        bool checked = 0;
        if(item->checkState() == Qt::Checked) checked = 1;
        hash.insert(item->text(), checked);
    }
    return hash;
}
