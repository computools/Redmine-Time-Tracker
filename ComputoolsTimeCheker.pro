#-------------------------------------------------
#
# Project created by QtCreator 2014-12-23T09:59:21
#
#-------------------------------------------------

QT       += core gui
CONFIG   += C++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ComputoolsTimeCheker
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    global.cpp \
    statusindicator.cpp \
    view/clockview.cpp \
    advancedsettings.cpp \
    actionfactory.cpp

HEADERS  += mainwindow.h \
    global.h \
    statusindicator.h \
    view/clockview.h \
    advancedsettings.h \
    actionfactory.h

FORMS    += mainwindow.ui \
    statusindicator.ui \
    view/clockview.ui \
    advancedsettings.ui

RESOURCES += \
    res.qrc
