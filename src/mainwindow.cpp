#include "global.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSystemTrayIcon>
#include <QCloseEvent>
#include "statusindicator.h"
#include "view/clockview.h"
#include "advancedsettings.h"
#include "actionfactory.h"
#include <math.h>

void MainWindow::initDefaultMenu() {
  connect(ActionFactory::actionShow(),SIGNAL(triggered()),this,SLOT(show()));
  connect(ActionFactory::actionExit(),SIGNAL(triggered()),qApp,SLOT(quit()));
  auto * menu = ActionFactory::defaultMenu();
  menu->addAction(ActionFactory::actionPause());
  menu->addAction(ActionFactory::actionStart());
  menu->addAction(ActionFactory::actionStop());
  menu->addSeparator();
  menu->addAction(ActionFactory::actionSettings());
  menu->addSeparator();
  menu->addAction(ActionFactory::actionExit());
  systemTrayIcon->setContextMenu(menu);
  systemTrayIcon->show();
}

void MainWindow::initActions(){
    ActionFactory::initialize(this);
    connect(settings,SIGNAL(signalSizeChanged(int,int)),clock,SLOT(setSize(int,int)));
    connect(settings,SIGNAL(signalColorChange(ClockState,QColor)),clock,SLOT(setColor(ClockState,QColor)));
    connect(ui->actionAdvanced_Settings,SIGNAL(triggered()),ActionFactory::actionSettings(),SLOT(trigger()));
    connect(ActionFactory::actionSettings(),SIGNAL(triggered()),settings,SLOT(show()));
    connect(ActionFactory::actionStart(),SIGNAL(triggered()),SLOT(actionStart()));
    connect(ActionFactory::actionPause(),SIGNAL(triggered()),SLOT(actionPause()));
    connect(ActionFactory::actionStop(),SIGNAL(triggered()),SLOT(actionStop()));

}

MainWindow::MainWindow(QWidget *parent):
  QMainWindow(parent),
  ui(new Ui::MainWindow),
  systemTrayIcon(new QSystemTrayIcon(Default::App::icon(),this)),
  seconds(0),
  clock(new ClockView(nullptr)),
  settings(new AdvancedSettings(nullptr)),
  state(WORK){
  ui->setupUi(this);
  initActions();
  initDefaultMenu();

  setState(WORK);

  connect(settings,SIGNAL(signalColorChange(ClockState,QColor)),clock,SLOT(setColor(ClockState,QColor)));
  connect(settings,SIGNAL(signalSizeChanged(int,int)),clock,SLOT(setSize(int,int)));
  connect(clock,SIGNAL(startClicked()),SLOT(actionStart()));
  connect(clock,SIGNAL(pauseClicked()),SLOT(actionPause()));
  settings->loadSettings();
  clock->show();
  this->setWindowIcon(Default::App::icon());
  this->setWindowTitle(Default::App::title());
  startTimer(1000);
}

MainWindow::~MainWindow() {
  delete ui;
  delete systemTrayIcon;
}

void MainWindow::closeEvent(QCloseEvent *event) {
  event->ignore();
  this->hide();
}

void MainWindow::timerEvent(QTimerEvent *) {
  if(state == WORK){
      seconds++;
      const quint64 h = floor(seconds / 3600);
      const quint64 m = floor((seconds % 3600) / 60);
      const quint64 s = floor(seconds % 60);
      clock->setText(QString("%1:%2:%3").arg(h,3,10,QChar('0')).arg(m,2,10,QChar('0')).arg(s,2,10,QChar('0')));
  }
}

void MainWindow::actionStart(){
    if(state != WORK){
        setState(WORK);
    }
}

void MainWindow::actionPause(){
    setState(PAUSE);
}

void MainWindow::actionStop(){
    seconds = 0;
    clock->setText("000:00:00");
    setState(STOP);
}

void MainWindow::setState(ClockState state){
    clock->setState(state);
    this->state = state;
    switch(state){
        case WORK:
            ActionFactory::actionStart()->setVisible(false);
            ActionFactory::actionPause()->setVisible(true);
            ActionFactory::actionStop()->setVisible(true);
        break;
        case PAUSE:
            ActionFactory::actionStart()->setVisible(true);
            ActionFactory::actionPause()->setVisible(false);
            ActionFactory::actionStop()->setVisible(true);
        break;
        default:
            ActionFactory::actionStart()->setVisible(true);
            ActionFactory::actionPause()->setVisible(false);
            ActionFactory::actionStop()->setVisible(false);
        break;
    }


}


