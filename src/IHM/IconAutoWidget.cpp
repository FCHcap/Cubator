#include "IconAutoWidget.h"
#include "ui_IconAutoWidget.h"

IconAutoWidget::IconAutoWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IconAutoWidget)
{
    ui->setupUi(this);

    connect(ui->addButton, SIGNAL(clicked(bool)), this, SIGNAL(iconAutoAdded()));
}

IconAutoWidget::~IconAutoWidget()
{
    delete ui;
}
