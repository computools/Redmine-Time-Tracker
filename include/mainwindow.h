#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "view/clockview.h"

class QSystemTrayIcon;
class ClockView;
class AdvancedSettings;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT
public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

  void initDefaultMenu();
  void initActions();

protected:
  void closeEvent(QCloseEvent *event);
  void timerEvent(QTimerEvent *);

private slots:
  void actionStart();
  void actionPause();
  void actionStop();
  void setState(ClockState state);

private:
  Ui::MainWindow *ui;
  QSystemTrayIcon *systemTrayIcon;
  quint64 seconds;
  ClockView *clock;
  AdvancedSettings *settings;
  ClockState state;
};

#endif // MAINWINDOW_H
