#ifndef CLOCKVIEW_H
#define CLOCKVIEW_H

#include <QWidget>

namespace Ui {
  class ClockView;
}

enum ClockState{
  WORK,
  PAUSE,
  STOP
};

class ClockView : public QWidget
{
  Q_OBJECT

public:


  explicit ClockView(QWidget *parent = 0);
  ~ClockView();

signals:
    void pauseClicked();
    void startClicked();

public slots:
  void setText(const QString &text);
  void setSize(int width, int height);
  void setState(ClockState state);
  void setColor(ClockState state, QColor color);
  void showContextMenu(const QPoint &point);

protected:
  void mouseMoveEvent(QMouseEvent *event) override;
  void mousePressEvent(QMouseEvent *event) override;
  void mouseReleaseEvent(QMouseEvent *event) override;
  void mouseDoubleClickEvent(QMouseEvent *event) override;
  void keyPressEvent(QKeyEvent *e) override;

private:
  Ui::ClockView *ui;
  QPoint oldMousePosition;
  bool isMouseDrag;
  ClockState state;
  QColor colorWork;
  QColor colorPause;
  QColor colorBreak;
};

#endif // CLOCKVIEW_H
