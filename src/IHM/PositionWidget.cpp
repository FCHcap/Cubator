#include "PositionWidget.h"
#include "ui_PositionWidget.h"

PositionWidget::PositionWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PositionWidget)
{
    ui->setupUi(this);
}

PositionWidget::~PositionWidget()
{
    delete ui;
}

void PositionWidget::onPositionUpdated(const QPointF position) {
    ui->x->setText(QString("X : %1").arg(position.x(), 0, 'f', 4));
    ui->y->setText(QString("Y : %1").arg(position.y(), 0, 'f', 4));
}
