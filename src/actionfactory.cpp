#include "actionfactory.h"
#include <QMenu>
#include <QAction>

QT_USE_NAMESPACE

static ActionFactory *instance = nullptr;

ActionFactory::ActionFactory() = default;

void ActionFactory::initialize(QObject *parent) {
    static bool initialized = false;
    if (!initialized) {
        instance = new ActionFactory;
        instance->setParent(parent);
        initialized = true;
    }
}

QAction *ActionFactory::actionShow() {
    static auto *action = new QAction(tr("Show"), instance);
    return action;
}

QAction *ActionFactory::actionSettings() {
    static auto *action = new QAction(tr("Settings"), instance);
    return action;
}

QMenu *ActionFactory::defaultMenu() {
    static auto *menu = new QMenu(nullptr);
    return menu;
}

QAction *ActionFactory::actionExit() {
    static auto *action = new QAction(tr("Exit"), instance);
    return action;
}

QAction *ActionFactory::actionStart() {
    static auto *action = new QAction(tr("Start"), instance);
    return action;
}

QAction *ActionFactory::actionStop() {
    static auto *action = new QAction(tr("Stop"), instance);
    return action;
}

QAction *ActionFactory::actionPause() {
    static auto *action = new QAction(tr("Pause"), instance);
    return action;
}
