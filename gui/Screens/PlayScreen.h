#ifndef PLAYSCREEN_H
#define PLAYSCREEN_H

#include "Screen.h"

class PlayScreen : public Screen
{

private:

public:
    PlayScreen();
    ~PlayScreen();

    void loadContent();
    void update(float dt);
    void draw(sf::RenderWindow &window);

};

#endif // PLAYSCREEN_H
