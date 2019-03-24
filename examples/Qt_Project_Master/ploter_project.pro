#-------------------------------------------------
#
# Project created by QtCreator 2018-06-30T23:40:47
#
#-------------------------------------------------

QT       += core gui network serialport  quickwidgets widgets

CONFIG += c++11
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = ploter_project
TEMPLATE = app
LIBS += -lwiringPi

target.path = /opt
INSTALLS += target

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    qcustomplot.cpp \
    qcgaugewidget.cpp \
    slidinggraph.cpp \
    geometryengine.cpp \
    mainwidget.cpp \
    spi_telemetry.cpp

HEADERS += \
        mainwindow.h \
    qcustomplot.h \
    qcgaugewidget.h \
    slidinggraph.h \
    geometryengine.h \
    mainwidget.h \
    spi_telemetry.h

FORMS += \
        mainwindow.ui

RESOURCES += \
    shaders.qrc \
    textures.qrc
