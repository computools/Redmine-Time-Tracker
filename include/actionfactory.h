#ifndef ACTION_FACTORY_H
#define ACTION_FACTORY_H

#include <QObject>

class QAction;

class QMenu;

class ActionFactory :
        public QObject {
    ActionFactory();

public:
    static void initialize(QObject *parent = nullptr);

    static QAction *actionShow();

    static QAction *actionExit();

    static QAction *actionStart();

    static QAction *actionStop();

    static QAction *actionPause();

    static QAction *actionSettings();

    static QMenu *defaultMenu();
};

#endif // ACTION_FACTORY_H
