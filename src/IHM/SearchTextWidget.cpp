#include "SearchTextWidget.h"
#include "ui_SearchTextWidget.h"

#include <QGraphicsScene>

SearchTextWidget::SearchTextWidget(QWidget *parent, GraphicsView *view) :
    QWidget(parent),
    ui(new Ui::SearchTextWidget),
    _view(view)
{
    ui->setupUi(this);

    QGraphicsScene *scene = this->scene();
    scene->addItem(&_item);
    _item.setVisible(false);

    ui->messageLabel->setEnabled(false);
    ui->backButton->setEnabled(false);
    ui->nextButton->setEnabled(false);
}

SearchTextWidget::~SearchTextWidget()
{
    delete ui;
}

QList<GraphicsTextItem*> SearchTextWidget::extractTextItems(QGraphicsScene *scene) {
    QList<GraphicsTextItem*> textItems;
    if(scene != NULL) {
        QList<QGraphicsItem*> list = scene->items();
        QList<QGraphicsItem*>::iterator it;

        for(it = list.begin(); it != list.end(); ++it) {
            GraphicsTextItem *item = reinterpret_cast<GraphicsTextItem *>(*it);

            if(item->type() == GraphicsTextItem::Type && item->isVisible()) {
                textItems.append(item);
            }
        }
    }
    return textItems;
}

QRegExp SearchTextWidget::regularExpressionSearched() {
    QString searchedText = ui->searchEdit->text();
    QString strRe;
    QRegExp re;
    bool exact = ui->exactlyCheckBox->isChecked();

    strRe = searchedText.toUpper();

    if(exact) {
        strRe.insert(0, '^');
        strRe.append('$');
    }

    re.setPattern(strRe);
    return re;
}

void SearchTextWidget::selectItem(GraphicsTextItem *item) {
    _item.setVisible(false);
    this->resetVisibility();

    _item.setText(item->text());
    _item.setFont(item->font());
    _item.setPos(item->pos());
    _item.setZValue(item->zValue()+1);

    QBrush brush = item->brush();
    brush.setColor(Qt::red);
    _item.setBrush(brush);

    item->setVisible(false);
    _item.setVisible(true);

    this->scrollView();
}

void SearchTextWidget::scrollView() {
    _view->updatePosition(_item.pos());
}

void SearchTextWidget::resetVisibility() {
    QList<GraphicsTextItem*>::iterator it;
    for(it = _searchedItems.begin(); it != _searchedItems.end(); ++it) {
        GraphicsTextItem *item = reinterpret_cast<GraphicsTextItem*>(*it);
        item->setVisible(true);
    }
}

void SearchTextWidget::updateButtonsState() {
    ui->nextButton->setEnabled((_iterator + 1 == _searchedItems.end()) ? false : true);
    ui->backButton->setEnabled((_iterator == _searchedItems.begin()) ? false : true);
}

void SearchTextWidget::updateMessageResult() {
    QList<GraphicsTextItem*>::iterator begin = _searchedItems.begin();

    int pos = (_searchedItems.isEmpty()) ? 0 : std::distance(begin, _iterator) +1;
    int count = _searchedItems.count();

   QString message;
   QTextStream(&message) << QObject::tr(MESSAGE_RESULT) << pos << " / " << count;

    ui->messageLabel->setText(message);
}

QGraphicsScene *SearchTextWidget::scene() const {
    QGraphicsScene *scene = _view->scene();
    if(scene == NULL) throw CubException(QObject::tr("Error in loading the search text tool"), QObject::tr("The scene element is not found"), "SearchTextWidget:SearchTextWidget()");
    return scene;
}

void SearchTextWidget::on_searchButton_clicked()
{
    _searchedItems.clear();

    if(!_view) {
        qWarning() << "SearchTextDialog::onClickSearchButton : _view is null";
        return;
    }

    QGraphicsScene *scene = _view->scene();
    if(!scene) {
        qWarning() << "SearchTextDialog::onClickSearchButton : scene is null";
        return;
    }

    _item.setVisible(true);

    QList<GraphicsTextItem*> textItems = this->extractTextItems(scene);
    QList<GraphicsTextItem*>::iterator it;
    QRegExp re = this->regularExpressionSearched();

    for(it = textItems.begin(); it != textItems.end(); ++it) {
        GraphicsTextItem *item = reinterpret_cast<GraphicsTextItem*>(*it);

        if(item->text().toUpper().contains(re)) {
            _searchedItems.append(item);
        }
    }

    if(!_searchedItems.isEmpty()) {
        _iterator = _searchedItems.begin();
        selectItem(_searchedItems.first());
    }
    updateButtonsState();
    updateMessageResult();

    ui->messageLabel->setEnabled(true);
}

void SearchTextWidget::on_backButton_clicked()
{
    _iterator--;
    if(_iterator != _searchedItems.end()) {
        this->selectItem(reinterpret_cast<GraphicsTextItem*>(*_iterator));
    }
    updateButtonsState();
    updateMessageResult();
}

void SearchTextWidget::on_nextButton_clicked()
{
    _iterator++;
    if(_iterator != _searchedItems.begin()) {
        this->selectItem(reinterpret_cast<GraphicsTextItem*>(*_iterator));
    }
    updateButtonsState();
    updateMessageResult();
}
