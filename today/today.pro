#-------------------------------------------------
#
# Project created by QtCreator 2020-05-16T10:26:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = today
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    mainwindow.cpp

HEADERS  += widget.h \
    mainwindow.h

FORMS    += widget.ui \
    mainwindow.ui

DISTFILES += \
    ../../5.13/final/1.jpg

RESOURCES += \
    smarthome.qrc
