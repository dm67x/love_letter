HEADERS += \
    test.h

SOURCES += \
    main.cpp

QMAKE_CXXFLAGS += -std=c++11
CONFIG += -std=c++11

TEMPLATE = app

# CORE LIBRARY
unix:!macx: LIBS += -L$$OUT_PWD/../core/ -lcore

INCLUDEPATH += $$PWD/../core
DEPENDPATH += $$PWD/../core

unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/../core/libcore.a

# NETWORK LIBRARY
unix:!macx: LIBS += -L$$OUT_PWD/../network/ -lnetwork

INCLUDEPATH += $$PWD/../network
DEPENDPATH += $$PWD/../network
