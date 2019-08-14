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
    maincontent/control/bannawidget.cpp \
    maincontent/control/cylinderwidget.cpp

HEADERS  += mainwindow.h \
    globaldef.hpp \
    titlebar/maintitlebar.h \
    titlebar/titlebar.h \
    maincontent/controltreewidget.h \
    maincontent/controltabwidget.h \
    maincontent/control/bannawidget.h \
    maincontent/control/cylinderwidget.h

FORMS    += mainwindow.ui \
    titlebar/maintitlebar.ui \
    maincontent/controltreewidget.ui \
    maincontent/controltabwidget.ui \
    maincontent/control/bannawidget.ui \
    maincontent/control/cylinderwidget.ui

RESOURCES += \
    res.qrc

RC_FILE += myapp.rc
