#ifndef DBTABLEWIDGET_H
#define DBTABLEWIDGET_H

// QT
#include <QTableWidget>
#include <QtGui>

// CUBATOR
#include <Messages.h>

class DbTableWidget : public QTableWidget
{
    Q_OBJECT
public:
    explicit DbTableWidget(QWidget *parent = 0);
    void allowChanges(bool allow);
    
protected:
    void contextMenuEvent(QContextMenuEvent *event);

protected:
    bool _allowChanges;
    
};

#endif // DBTABLEWIDGET_H
