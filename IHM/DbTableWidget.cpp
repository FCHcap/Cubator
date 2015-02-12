#include "DbTableWidget.h"

// QT
#include <QMenu>
#include <QAction>
#include <QMessageBox>

DbTableWidget::DbTableWidget(QWidget *parent) :
    QTableWidget(parent)
{
    _allowChanges = 0;
}

void DbTableWidget::allowChanges(bool allow){
    _allowChanges = allow;

    for(int i=0; i<rowCount(); i++){
        for(int j=0; j<columnCount(); j++){
            if(allow) item(i, j)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled);
            else item(i, j)->setFlags(Qt::NoItemFlags);
        }
    }

}

void DbTableWidget::contextMenuEvent(QContextMenuEvent *event){

    if(!_allowChanges) return;

    QMenu menu;
    menu.addAction(ACTION02);
    menu.addAction(ACTION03);
    menu.addAction(ACTION04);

    QAction * action = menu.exec(event->globalPos());

    if(!action) return;

    if(action->text() == ACTION02){
        QTableWidgetItem * item = itemAt(event->pos());
        (item) ? insertRow(item->row()) : insertRow(0);
    }
    else if(action->text() == ACTION03){
        QList<QTableWidgetItem*> items = selectedItems();
        foreach(QTableWidgetItem * item, items) removeRow(item->row());
    }
    else if(action->text() == ACTION04){
        if(QMessageBox::question(this, TITLE01, QUESTION03, QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes){
            clear();
        }
    }
}
