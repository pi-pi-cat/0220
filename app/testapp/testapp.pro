include(../guieplatform.pri)

TARGET = testapp

QT += core gui widgets
CONFIG += c++11

DEFINES += PLATFORM

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

include(../use_guie.pri)
INCLUDEPATH += $(ENGINE_HOME)/include
