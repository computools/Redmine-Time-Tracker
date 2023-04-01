#ifndef STATUS_INDICATOR_H
#define STATUS_INDICATOR_H

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

#endif // STATUS_INDICATOR_H
