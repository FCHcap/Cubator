#include "GpsInfoWidget.h"
#include "ui_GpsInfoWidget.h"

GpsInfoWidget::GpsInfoWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GpsInfoWidget)
{
    ui->setupUi(this);
    this->setVisible(false);
}

void GpsInfoWidget::enable(bool value) {
    this->setVisible(value);
}

void GpsInfoWidget::updateData(GpsData data) {
    QString sColor = "#00FF00";
    QString sX = QString("<font color = \"%1\">X : %2</font>").arg(sColor).arg(data.position.x(), 0, 'f', 4);
    QString sY = QString("<font color = \"%1\">Y : %2</font>").arg(sColor).arg(data.position.y(), 0, 'f', 4);
    QString sSat= QString("<font color = \"%1\">Satellites : %2</font>").arg(sColor).arg(data.satellites);
    QString sDgps = QString("<font color = \"%1\">DGPS : %2</font>").arg(sColor).arg((data.dgps == true) ? "OUI" : "NON");
    QString sAlt = QString("<font color = \"%1\">Altitude : %2</font>").arg(sColor).arg(data.altitude, 0, 'f', 4);

    this->ui->xLabel->setText(sX);
    this->ui->yLabel->setText(sY);
    this->ui->satellitesLabel->setText(sSat);
    this->ui->dgpsLabel->setText(sDgps);
    this->ui->altitudeLabel->setText(sAlt);
}

void GpsInfoWidget::connect(bool connected) {
    setVisible(connected);
}

void GpsInfoWidget::timeout() {
    QString sX = "<font color = \"#FF0000\">X : "+TEXT16+"</font>";
    QString sY = "<font color = \"#FF0000\">Y : "+TEXT16+"</font>";
    QString sAlt = "<font color = \"#FF0000\">Altitude : "+TEXT16+"</font>";
    QString sSat = "<font color = \"#FF0000\">Satellites : "+TEXT16+"</font>";
    QString sDgps = "<font color = \"#FF0000\">DGPS : "+TEXT16+"</font>";

    this->ui->xLabel->setText(sX);
    this->ui->yLabel->setText(sY);
    this->ui->satellitesLabel->setText(sSat);
    this->ui->dgpsLabel->setText(sDgps);
    this->ui->altitudeLabel->setText(sAlt);
}

void GpsInfoWidget::inconsistentData() {
    QString sX = "<font color = \"#FF6600\">X : "+TEXT17+"</font>";
    QString sY = "<font color = \"#FF6600\">Y : "+TEXT17+"</font>";
    QString sAlt = "<font color = \"#FF6600\">Altitude : "+TEXT17+"</font>";
    QString sSat = "<font color = \"#FF6600\">Satellites : "+TEXT17+"</font>";
    QString sDgps = "<font color = \"#FF6600\">DGPS : "+TEXT17+"</font>";

    this->ui->xLabel->setText(sX);
    this->ui->yLabel->setText(sY);
    this->ui->satellitesLabel->setText(sSat);
    this->ui->dgpsLabel->setText(sDgps);
    this->ui->altitudeLabel->setText(sAlt);
}

GpsInfoWidget::~GpsInfoWidget()
{
    delete ui;
}
