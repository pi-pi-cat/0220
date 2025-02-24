GUIE_SOURCE_TREE = $$PWD
#isEmpty(GUIE_BUILD_TREE) {
#    subdir = $$_PRO_FILE_PWD_
#    subdir ~= s,^$$re_escape($$PWD),,
#    GUIE_BUILD_TREE = $$OUT_PWD
#    GUIE_BUILD_TREE ~= s,^$$re_escape($$subdir),,
#}
GUIE_BUILD_TREE = C:\Users\yuexiaofeng\Documents\build-0222-Desktop_Qt_5_12_12_MinGW_64_bit-Debug
GUIE_LIBRARY_BASENAME = lib
GUIE_APP_PATH = $$GUIE_BUILD_TREE/bin/guie
GUIE_LIBRARY_PATH = $$GUIE_BUILD_TREE/$$GUIE_LIBRARY_BASENAME
GUIE_LIBRARY_PATH_GUIE = $$GUIE_LIBRARY_PATH/guie
GUIE_PLUGIN_PATH = $$GUIE_LIBRARY_PATH_GUIE/plugins
INSTALL_INC=$$INSTALL_PREFIX/include/guie

INCLUDEPATH += \
    $$GUIE_SOURCE_TREE/source \
    $$GUIE_SOURCE_TREE/source/homepage \
    $$GUIE_SOURCE_TREE/source/homepage/project \

CONFIG += depend_includepath
LIBS += -L$$GUIE_LIBRARY_PATH
LIBS += -L$$GUIE_LIBRARY_PATH_GUIE
LIBS += -L$$GUIE_PLUGIN_PATH

QT += core gui xml widgets concurrent
QMAKE_CXXFLAGS += -std=c++11
QMAKE_CXXFLAGS += -Wno-unused-parameter
DISTFILES += $$PWD/app/guieplatform.pri
