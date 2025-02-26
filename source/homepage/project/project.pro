include(../../guieplatformlibrary.pri)

DEFINES += PROJECT_LIBRARY

INCLUDEPATH += \
    $$PWD \
    $$PWD/.. \
    $$PWD/views/composites/toolbars \ #为了让.ui找到 提升类

HEADERS += \
    global_h.h \
    controller/logic/projectlogic.h \
    controller/mediators/projectmediator.h \
    models/datamodel/projectlistmodel.h \
    models/internal/deviceinfo.h \
    models/internal/projectitem.h \
    models/persistence/configfileutils.h \
    models/persistence/projectdatasaver.h \
    models/persistence/projectxmlutils.h \
    views/components/leftpanel/leftpanel.h \
    views/components/projectcard/projectcard.h \
    views/composites/galleryview/galleryview.h \
    views/composites/toolbars/searchtoolbar.h \
    views/layouts/flowlayout.h

SOURCES += \
    controller/logic/projectlogic.cpp \
    controller/mediators/projectmediator.cpp \
    models/datamodel/projectlistmodel.cpp \
    models/internal/deviceinfo.cpp \
    models/internal/projectitem.cpp \
    models/persistence/configfileutils.cpp \
    models/persistence/projectdatasaver.cpp \
    models/persistence/projectxmlutils.cpp \
    views/components/leftpanel/leftpanel.cpp \
    views/components/projectcard/projectcard.cpp \
    views/composites/galleryview/galleryview.cpp \
    views/composites/toolbars/searchtoolbar.cpp \
    views/layouts/flowlayout.cpp

FORMS += \
    views/components/leftpanel/leftpanel.ui \
    views/components/projectcard/projectcard.ui \
    views/composites/galleryview/galleryview.ui \
    views/composites/toolbars/searchtoolbar.ui

RESOURCES += \
    resources/styles.qrc
