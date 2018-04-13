# CORE LIBRARY
unix: LIBS += -L$$OUT_PWD/../core/ -lcore

INCLUDEPATH += $$PWD/../core
DEPENDPATH += $$PWD/../core

unix: PRE_TARGETDEPS += $$OUT_PWD/../core/libcore.a

TEMPLATE = lib
CONFIG += -std=c++11

HEADERS += \
    server/server_multiple_connections.h \
    src/socket.h \
    src/TCPClient.h \
    src/TCPServer.h \
    multiplayergame.h

SOURCES += \
    client/client.cpp \
    server/server.cpp \
    server/server_multiple_connections.cpp \
    src/TCPClient.cpp \
    src/TCPServer.cpp \
    multiplayergame.cpp \
    getting_ip_example.cpp




