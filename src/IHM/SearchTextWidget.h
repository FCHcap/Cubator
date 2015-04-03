#ifndef SEARCHTEXTWIDGET_H
#define SEARCHTEXTWIDGET_H

#include <QWidget>

#include <GraphicsTextItem.h>
#include <GraphicsView.h>

#include <qdockwidget.h>
#include <qobject.h>
#include <qlist.h>
#include <qcolor.h>

#define MESSAGE_RESULT "result : "

namespace Ui {
class SearchTextWidget;
}

class SearchTextWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SearchTextWidget(QWidget *parent, GraphicsView* view);
    ~SearchTextWidget();

private slots:
    void on_searchButton_clicked();
    void on_backButton_clicked();
    void on_nextButton_clicked();

private:
    QList<GraphicsTextItem*> extractTextItems(QGraphicsScene *scene);
    QRegExp regularExpressionSearched();
    void selectItem(GraphicsTextItem *item);
    void scrollView();
    void resetVisibility();
    void updateButtonsState();
    void updateMessageResult();

    QGraphicsScene * scene() const;

private:
    Ui::SearchTextWidget *ui;
    GraphicsView *_view;
    QList<GraphicsTextItem*> _searchedItems;
    QList<GraphicsTextItem*>::iterator _iterator;
    GraphicsTextItem _item;
};

#endif // SEARCHTEXTWIDGET_H
