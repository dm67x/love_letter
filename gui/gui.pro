TEMPLATE = app
CONFIG += window

win32: LIBS += -L$$PWD/lib/SFML/lib -lsfml-graphics -lfreetype -lsfml-window -lopengl32 -lgdi32 -lsfml-system -lwinmm

INCLUDEPATH += $$PWD/lib/SFML/include
DEPENDPATH += $$PWD/lib/SFML/include

SOURCES += \
    Board.cpp \
    Card.cpp \
    Deck.cpp \
    Hand.cpp \
    Utils.cpp \
    Animations/MoveAnimation.cpp \
    Animations/PickAnimation.cpp \
    Animations/ScaleAnimation.cpp \
    Animation.cpp \
    Main.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../core/release/ -lcore
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../core/debug/ -lcore
else:unix:!macx: LIBS += -L$$OUT_PWD/../core/ -lcore

INCLUDEPATH += $$PWD/..
DEPENDPATH += $$PWD/../core

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../core/release/libcore.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../core/debug/libcore.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../core/release/core.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../core/debug/core.lib
else:unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/../core/libcore.a

HEADERS += \
    Board.h \
    Card.h \
    Deck.h \
    Hand.h \
    Utils.h \
    Animations/MoveAnimation.h \
    Animations/PickAnimation.h \
    Animations/ScaleAnimation.h \
    Animation.h
