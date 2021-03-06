TEMPLATE = app
CONFIG += window
CONFIG -= qt
DEFINES +=

win32: LIBS += -L$$PWD/../lib/SFML/windows/lib -lsfml-graphics -lfreetype -lsfml-window -lopengl32 -lgdi32 -lsfml-system -lwinmm
unix: LIBS += -L$$PWD/../lib/SFML/linux/lib -lsfml-graphics -lsfml-window -lsfml-system

INCLUDEPATH += $$PWD/../lib/SFML/include
DEPENDPATH += $$PWD/../lib/SFML/include

SOURCES += \
    Animations/MoveAnimation.cpp \
    Animations/PickAnimation.cpp \
    Animations/ScaleAnimation.cpp \
    Animation.cpp \
    main.cpp \
    MainWindow.cpp \
    Screen.cpp \
    ScreenManager.cpp \
    Screens/MenuScreen.cpp \
    Button.cpp \
    Screens/CreditsScreen.cpp \
    Elements/Card.cpp \
    Elements/Deck.cpp \
    Elements/Hand.cpp \
    Elements/PlayerZone.cpp \
    Buttons/MenuButton.cpp \
    DebugBounds.cpp \
    Board.cpp \
    Screens/MultiplayerScreen.cpp \
    Screens/SinglePlayerMenuScreen.cpp \
    Message.cpp \
    Object.cpp \
    Screens/CreateGame.cpp \
    Screens/JoinGame.cpp \
    Buttons/TextArea.cpp \
    Screens/NextPlayerMessageScreen.cpp \
    Screens/LocalGameScreen.cpp \
    DialogBox.cpp \
    Dialogs/GuessDialog.cpp \
    Screens/RulesScreen.cpp \
    Screens/SingleplayerModeChoiceScreen.cpp \
    Screens/LocalAIGameScreen.cpp

# CORE LIBRARY
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../core/release/ -lcore
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../core/debug/ -lcore
else:unix:!macx: LIBS += -L$$OUT_PWD/../core/ -lcore

# IA LIBRARY
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../IA/release/ -lIA
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../IA/debug/ -lIA
else:unix:!macx: LIBS += -L$$OUT_PWD/../IA/ -lIA

INCLUDEPATH += $$PWD/..
DEPENDPATH += \
    $$PWD/../core \
    $$PWD/../IA
QMAKE_CXXFLAGS += -std=c++11

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../core/release/libcore.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../core/debug/libcore.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../core/release/core.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../core/debug/core.lib
else:unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/../core/libcore.a

HEADERS += \
    Animations/MoveAnimation.h \
    Animations/PickAnimation.h \
    Animations/ScaleAnimation.h \
    Animation.h \
    MainWindow.h \
    Screen.h \
    ScreenManager.h \
    Screens/MenuScreen.h \
    Button.h \
    Screens/CreditsScreen.h \
    Elements/Card.h \
    Elements/Deck.h \
    Elements/Hand.h \
    Elements/PlayerZone.h \
    Board.h \
    Buttons/MenuButton.h \
    DebugBounds.h \
    Screens/MultiplayerScreen.h \
    Screens/SinglePlayerMenuScreen.h \
    Message.h \
    Object.h \
    Screens/CreateGame.h \
    Screens/JoinGame.h \
    Buttons/TextArea.h \
    Screens/NextPlayerMessageScreen.h \
    Screens/SingleplayerModeChoiceScreen.h \
    Screens/LocalAIGameScreen.h \
    Screens/LocalGameScreen.h \
    GameState.h \
    DialogBox.h \
    Dialogs/GuessDialog.h \
    Screens/RulesScreen.h

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../IA/release/ -lIA
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../IA/debug/ -lIA
else:unix:!macx: LIBS += -L$$OUT_PWD/../IA/ -lIA

INCLUDEPATH += $$PWD/../IA
DEPENDPATH += $$PWD/../IA

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../IA/release/libIA.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../IA/debug/libIA.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../IA/release/IA.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../IA/debug/IA.lib
else:unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/../IA/libIA.a
