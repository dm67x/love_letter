#ifndef SINGLEPLAYERSCREEN_H
#define SINGLEPLAYERSCREEN_H

#include "Screen.h"
#include "core/game.h"
#include "Board.h"

class SingleplayerScreen : public Screen
{

private:
    Core::Game * game;
    Board * board;

public:
    SingleplayerScreen();
    ~SingleplayerScreen();

    void loadContent();
    void update(sf::Event evt, float dt);
    void draw(sf::RenderWindow &window);

};

#endif // SINGLEPLAYERSCREEN_H
