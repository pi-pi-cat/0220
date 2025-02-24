TEMPLATE = lib
CONFIG += shared dll
include(../guie.pri)

DESTDIR = $$GUIE_LIBRARY_PATH_GUIE

contains(QT_CONFIG, reduce_exports): CONFIG += hide_symbols

target.path = $$INSTALL_PREFIX/$$GUIE_LIBRARY_PATH/guie

INSTALLS += target
