TEMPLATE = lib
CONFIG += staticlib static
QMAKE_CXXFLAGS += -std=c++11

HEADERS += \
    ia_dummy.h \
    utils.h \
    ia_intel.h

SOURCES += \
    ia_dummy.cpp \
    utils.cpp \
    ia_intel.cpp

# CORE LIBRARY
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../core/release/ -lcore
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../core/debug/ -lcore
else:unix:!macx: LIBS += -L$$OUT_PWD/../core/ -lcore

INCLUDEPATH += $$PWD/../core
DEPENDPATH += $$PWD/../core
