include(../guieplatform.pri)

TARGET = testdevice

QT += core gui widgets
CONFIG += c++11

DEFINES += PLATFORM

SOURCES += \
    main.cpp \

include(../use_guie.pri)
INCLUDEPATH += $(ENGINE_HOME)/include
