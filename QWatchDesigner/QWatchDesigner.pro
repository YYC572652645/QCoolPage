#-------------------------------------------------
#
# Project created by QtCreator 2019-06-18T19:33:28
#
#-------------------------------------------------

QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QWatchDesigner
TEMPLATE = app


SOURCES += main.cpp\
        qwatchdesigner.cpp \
    titlebar/titlebar.cpp \
    titlebar/maintitlebar.cpp \
    xmlhandler/xmldatamodel.cpp \
    xmlhandler/xmlreadwrite.cpp \
    testdemowidget/testdemowidget.cpp

HEADERS  += qwatchdesigner.h \
    titlebar/titlebar.h \
    titlebar/maintitlebar.h \
    globaldef.hpp \
    xmlhandler/xmldatamodel.h \
    xmlhandler/xmlreadwrite.h \
    testdemowidget/testdemowidget.h \
    xmlhandler/xmldatadef.h

FORMS    += qwatchdesigner.ui \
    titlebar/maintitlebar.ui \
    testdemowidget/testdemowidget.ui

RESOURCES += \
    res.qrc

RC_FILE += myapp.rc
