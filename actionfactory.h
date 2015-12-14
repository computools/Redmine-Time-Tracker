#ifndef ACTIONFACTORY_H
#define ACTIONFACTORY_H
#include <QObject>

class QAction;
class QMenu;

class ActionFactory:
        public QObject
{
    ActionFactory();
public:
    static void initialize(QObject *parent);
    static QAction* actionShow();
    static QAction* actionExit();
    static QAction *actionStart();
    static QAction *actionStop();
    static QAction *actionPause();
    static QAction *actionSettings();
    static QMenu* defaultMenu();
};

#endif // ACTIONFACTORY_H
