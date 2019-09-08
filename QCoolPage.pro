#-------------------------------------------------
#
# Project created by QtCreator 2019-06-16T13:01:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QCoolPage
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    titlebar/maintitlebar.cpp \
    titlebar/titlebar.cpp \
    maincontent/controltreewidget.cpp \
    maincontent/controltabwidget.cpp \
    systemtray/systemtray.cpp \
    maincontent/controlwidget/bannacontrol/bannawidget.cpp \
    maincontent/controlwidget/cylindercontrol/cylinderwidget.cpp \
    maincontent/controlwidget/progresscontrol/progresswidget.cpp \
    maincontent/controlwidget/progresscontrol/progresscontrol.cpp

HEADERS  += mainwindow.h \
    globaldef.hpp \
    titlebar/maintitlebar.h \
    titlebar/titlebar.h \
    maincontent/controltreewidget.h \
    maincontent/controltabwidget.h \
    systemtray/systemtray.h \
    maincontent/controlwidget/bannacontrol/bannawidget.h \
    maincontent/controlwidget/cylindercontrol/cylinderwidget.h \
    maincontent/controlwidget/progresscontrol/progresswidget.h \
    maincontent/controlwidget/progresscontrol/progresscontrol.h

FORMS    += mainwindow.ui \
    titlebar/maintitlebar.ui \
    maincontent/controltreewidget.ui \
    maincontent/controltabwidget.ui \
    maincontent/controlwidget/bannacontrol/bannawidget.ui \
    maincontent/controlwidget/cylindercontrol/cylinderwidget.ui \
    maincontent/controlwidget/progresscontrol/progresswidget.ui \
    maincontent/controlwidget/progresscontrol/progresscontrol.ui

RESOURCES += \
    res.qrc

RC_FILE += myapp.rc
