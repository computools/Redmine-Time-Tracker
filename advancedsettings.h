#ifndef ADVANCEDSETTINGS_H
#define ADVANCEDSETTINGS_H

#include <QWidget>
#include "view/clockview.h"

class QSettings;

namespace Ui {
  class AdvancedSettings;
}

class AdvancedSettings : public QWidget
{
  Q_OBJECT

public:
  explicit AdvancedSettings(QWidget *parent = 0);
  ~AdvancedSettings();
    void loadSettings();
    void saveSettings();

signals:
  void signalSizeChanged(int,int);
  void signalColorChange(ClockState,QColor);

private slots:
  void on_comboBox_currentIndexChanged(int index);
  void slotSizeChanged();
  void on_btnClockWorkColor_clicked();
  void on_btnClockPauseColor_clicked();
  void on_btnClockBreakColor_clicked();

private:
  Ui::AdvancedSettings *ui;
  QSettings *settings;
};

#endif // ADVANCEDSETTINGS_H
