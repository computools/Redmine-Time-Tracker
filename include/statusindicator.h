#ifndef STATUSINDICATOR_H
#define STATUSINDICATOR_H

#include <QWidget>

namespace Ui {
    class StatusIndicator;
}

class StatusIndicator : public QWidget {
Q_OBJECT

public:
    enum State {
        WORK,
        PAUSE,
        BREAK
    };

    explicit StatusIndicator(QWidget *parent = nullptr);

    ~StatusIndicator() override;

public slots:

    static void setState(int state);

private:
    Ui::StatusIndicator *ui;
};

#endif // STATUSINDICATOR_H
