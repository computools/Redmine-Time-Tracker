#include "statusindicator.h"
#include "ui_statusindicator.h"

StatusIndicator::StatusIndicator(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::StatusIndicator)
{
  ui->setupUi(this);
  setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
  setAttribute(Qt::WA_NoSystemBackground);
  setAttribute(Qt::WA_TranslucentBackground);
}

StatusIndicator::~StatusIndicator()
{
  delete ui;
}

void StatusIndicator::setState(int state)
{
  switch (state) {
    case WORK:
      break;

    case PAUSE:
      break;

    case BREAK:
    default:
      break;
  }
}
