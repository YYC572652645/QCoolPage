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
    titlebar/titlebar.cpp

HEADERS  += mainwindow.h \
    globaldef.hpp \
    titlebar/maintitlebar.h \
    titlebar/titlebar.h

FORMS    += mainwindow.ui \
    titlebar/maintitlebar.ui

RESOURCES += \
    res.qrc
