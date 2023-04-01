#include "advancedsettings.h"
#include "ui_advancedsettings.h"
#include <QColorDialog>
#include <QDebug>
#include <QSettings>

AdvancedSettings::AdvancedSettings(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::AdvancedSettings),
        settings(new QSettings(QSettings::IniFormat, QSettings::UserScope, "Computools", "Timer", this)) {
    ui->setupUi(this);
}

AdvancedSettings::~AdvancedSettings() {
    delete ui;
}

void AdvancedSettings::loadSettings() {
    const QColor work = settings->value("colors/work", QColor(150, 255, 150)).value<QColor>();
    const QColor pause = settings->value("colors/pause", QColor(255, 255, 120)).value<QColor>();
    const QColor stop = settings->value("colors/stop", QColor(255, 100, 100)).value<QColor>();
    signalColorChange(ClockState::WORK, work);
    signalColorChange(ClockState::PAUSE, pause);
    signalColorChange(ClockState::STOP, stop);
    const int width = settings->value("size/width", 124).toInt();
    const int height = settings->value("size/height", 28).toInt();
    signalSizeChanged(width, height);
    {
        QPalette pal = ui->btnClockWorkColor->palette();
        pal.setColor(QPalette::Button, work);
        ui->btnClockWorkColor->setAutoFillBackground(true);
        ui->btnClockWorkColor->setPalette(pal);
        ui->btnClockWorkColor->update();
    }
    {
        QPalette pal = ui->btnClockPauseColor->palette();
        pal.setColor(QPalette::Button, pause);
        ui->btnClockPauseColor->setAutoFillBackground(true);
        ui->btnClockPauseColor->setPalette(pal);
        ui->btnClockPauseColor->update();
    }
    {
        QPalette pal = ui->btnClockBreakColor->palette();
        pal.setColor(QPalette::Button, stop);
        ui->btnClockBreakColor->setAutoFillBackground(true);
        ui->btnClockBreakColor->setPalette(pal);
        ui->btnClockBreakColor->update();
    }
}

void AdvancedSettings::saveSettings() {

}

void AdvancedSettings::on_comboBox_currentIndexChanged(int index) {
    int width = 128;
    int height = 28;
    switch (index) {
        case 0:
            width = 100;
            height = 24;
            break;
        case 2:
            width = 134;
            height = 34;
            break;
        case 1:
        default:
            width = 124;
            height = 28;
            break;
    };
    settings->setValue("size/width", width);
    settings->setValue("size/height", height);
    settings->sync();
    signalSizeChanged(width, height);
}

void AdvancedSettings::slotSizeChanged() {
    signalSizeChanged(ui->boxWidth->value(), ui->boxHeight->value());
}

void AdvancedSettings::on_btnClockWorkColor_clicked() {
    const QColor color = QColorDialog::getColor(QColor(150, 255, 150));
    signalColorChange(WORK, color);
    settings->setValue("colors/work", color);
    settings->sync();
    QPalette pal = ui->btnClockWorkColor->palette();
    pal.setColor(QPalette::Button, color);
    ui->btnClockWorkColor->setAutoFillBackground(true);
    ui->btnClockWorkColor->setPalette(pal);
    ui->btnClockWorkColor->update();
}

void AdvancedSettings::on_btnClockPauseColor_clicked() {
    const QColor color = QColorDialog::getColor(QColor(255, 255, 120));
    signalColorChange(PAUSE, color);
    settings->setValue("colors/pause", color);
    settings->sync();
    QPalette pal = ui->btnClockPauseColor->palette();
    pal.setColor(QPalette::Button, color);
    ui->btnClockPauseColor->setAutoFillBackground(true);
    ui->btnClockPauseColor->setPalette(pal);
    ui->btnClockPauseColor->update();
}

void AdvancedSettings::on_btnClockBreakColor_clicked() {
    const QColor color = QColorDialog::getColor(QColor(255, 100, 100));
    signalColorChange(STOP, color);
    settings->setValue("colors/stop", color);
    settings->sync();
    QPalette pal = ui->btnClockBreakColor->palette();
    pal.setColor(QPalette::Button, color);
    ui->btnClockBreakColor->setAutoFillBackground(true);
    ui->btnClockBreakColor->setPalette(pal);
    ui->btnClockBreakColor->update();
}
