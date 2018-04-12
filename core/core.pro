TEMPLATE = lib
CONFIG += staticlib static

HEADERS += \
    cards/all.h \
    cards/baron.h \
    cards/countess.h \
    cards/guard.h \
    cards/handmaid.h \
    cards/king.h \
    cards/priest.h \
    cards/prince.h \
    cards/princess.h \
    action.h \
    card.h \
    deck.h \
    game.h \
    ia.h \
    player.h \
    utils.h

SOURCES += \
    cards/baron.cpp \
    cards/countess.cpp \
    cards/guard.cpp \
    cards/handmaid.cpp \
    cards/king.cpp \
    cards/priest.cpp \
    cards/prince.cpp \
    cards/princess.cpp \
    action.cpp \
    card.cpp \
    deck.cpp \
    game.cpp \
    ia.cpp \
    player.cpp \
    utils.cpp
