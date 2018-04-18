QMAKE_CXXFLAGS += -std=c++11

HEADERS += \
    core/game.h \
    core/card.h \
    core/action.h \
    core/cards/guard.h \
    core/cards/priest.h \
    core/player.h \
    core/cards/baron.h \
    test/test.h \
    core/cards/handmaid.h \
    core/cards/prince.h \
    core/cards/king.h \
    core/cards/countess.h \
    core/cards/princess.h \
    core/utils.h \
    core/deck.h \
    core/cards/all.h \
    core/ia_dummy.h \
    core/ia.h

SOURCES += \
    core/game.cpp \
    core/card.cpp \
    core/action.cpp \
    core/cards/guard.cpp \
    core/cards/priest.cpp \
    core/player.cpp \
    core/cards/baron.cpp \
    test/test.cpp \
    core/cards/handmaid.cpp \
    core/cards/prince.cpp \
    core/cards/king.cpp \
    core/cards/countess.cpp \
    core/cards/princess.cpp \
    core/utils.cpp \
    core/deck.cpp \
    core/ia_dummy.cpp \
    core/ia.cpp
