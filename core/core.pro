TEMPLATE = lib
CONFIG += staticlib static

HEADERS += \
    game.h \
    card.h \
    action.h \
    cards/guard.h \
    cards/priest.h \
    player.h \
    cards/baron.h \
    cards/handmaid.h \
    cards/prince.h \
    cards/king.h \
    cards/countess.h \
    cards/princess.h \
    deck.h \
    cards/all.h

SOURCES += \
    game.cpp \
    card.cpp \
    action.cpp \
    cards/guard.cpp \
    cards/priest.cpp \
    player.cpp \
    cards/baron.cpp \
    cards/handmaid.cpp \
    cards/prince.cpp \
    cards/king.cpp \
    cards/countess.cpp \
    cards/princess.cpp \
    deck.cpp
