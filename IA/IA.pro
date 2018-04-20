TEMPLATE = lib

HEADERS += \
    ia.h \
    ia_dummy.h \
    utils.h

SOURCES += \
    ia.cpp \
    ia_dummy.cpp \
    utils.cpp

# CORE LIBRARY
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../core/release/ -lcore
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../core/debug/ -lcore
else:unix:!macx: LIBS += -L$$OUT_PWD/../core/ -lcore

INCLUDEPATH += $$PWD/../core
DEPENDPATH += $$PWD/../core
