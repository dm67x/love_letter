LIBS += -Llib/SFML/lib
LIBS += \
    -lsfml-graphics \
    -lfreetype \
    -lsfml-window \
    -lopengl32 \
    -lgdi32 \
    -lsfml-system \
    -lwinmm

INCLUDEPATH += lib/SFML/include
DEPENDPATH += lib/SFML/include

HEADERS += \
    Animation.h \
    Card.h \
    Animations/PickAnimation.h

SOURCES += \
    Animation.cpp \
    Card.cpp \
    Main.cpp \
    Animations/PickAnimation.cpp
