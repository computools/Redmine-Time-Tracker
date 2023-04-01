#include "actionfactory.h"
#include <QMenu>
#include <QAction>

static ActionFactory *instance = nullptr;

ActionFactory::ActionFactory() {}

void ActionFactory::initialize(QObject *parent) {
    static bool initialized = false;
    if (!initialized) {
        instance = new ActionFactory;
        instance->setParent(parent);
        initialized = true;
    }
}

QAction *ActionFactory::actionShow() {
    static QAction *action = new QAction("Show", instance);
    return action;
}

QAction *ActionFactory::actionSettings() {
    static QAction *action = new QAction("Settings", instance);
    return action;
}

QMenu *ActionFactory::defaultMenu() {
    static QMenu *menu = new QMenu(nullptr);
    return menu;
}

QAction *ActionFactory::actionExit() {
    static QAction *action = new QAction("Exit", instance);
    return action;
}

QAction *ActionFactory::actionStart() {
    static QAction *action = new QAction("Start", instance);
    return action;
}

QAction *ActionFactory::actionStop() {
    static QAction *action = new QAction("Stop", instance);
    return action;
}

QAction *ActionFactory::actionPause() {
    static QAction *action = new QAction("Pause", instance);
    return action;
}
