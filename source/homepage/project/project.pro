include(../../guieplatformlibrary.pri)

DEFINES += PROJECT_LIBRARY

INCLUDEPATH += \
    $$PWD \
    $$PWD/.. \
    $$PWD/views/composites/toolbars \ #为了让.ui找到 提升类

HEADERS += \
    controller/eventbus/eventbus.h \
    controller/logic/devicelogic.h \
    controller/mediators/devicemediator.h \
    global_h.h \
    controller/logic/projectlogic.h \
    controller/mediators/projectmediator.h \
    models/datamodel/devicelistmodel.h \
    models/datamodel/projectlistmodel.h \
    models/internal/deviceinfo.h \
    models/internal/projectitem.h \
    models/persistence/configfileutils.h \
    models/persistence/projectdatasaver.h \
    models/persistence/projectxmlutils.h \
    views/components/devicecard/devicecard.h \
    views/components/projectcard/projectcard.h \
    views/composites/devicegallery/devicegalleryview.h \
    views/composites/projectgallery/projectgalleryview.h \
    views/layouts/flowlayout.h

SOURCES += \
    controller/eventbus/eventbus.cpp \
    controller/logic/devicelogic.cpp \
    controller/logic/projectlogic.cpp \
    controller/mediators/devicemediator.cpp \
    controller/mediators/projectmediator.cpp \
    models/datamodel/devicelistmodel.cpp \
    models/datamodel/projectlistmodel.cpp \
    models/internal/deviceinfo.cpp \
    models/internal/projectitem.cpp \
    models/persistence/configfileutils.cpp \
    models/persistence/projectdatasaver.cpp \
    models/persistence/projectxmlutils.cpp \
    views/components/devicecard/devicecard.cpp \
    views/components/projectcard/projectcard.cpp \
    views/composites/devicegallery/devicegalleryview.cpp \
    views/composites/projectgallery/projectgalleryview.cpp \
    views/layouts/flowlayout.cpp

FORMS += \
    views/components/projectcard/projectcard.ui \

RESOURCES += \
    resources/styles.qrc
