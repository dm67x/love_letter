#ifndef SINGLEPLAYERSCREEN_H
#define SINGLEPLAYERSCREEN_H

#include "Screen.h"
#include "core/game.h"
#include "Board.h"
#include "IA/ia_intel.h"

class SingleplayerScreen : public Screen
{

private:
    Core::Game * game;
    Board * board;
    IA::IA_intel * ia;

public:
    SingleplayerScreen();
    ~SingleplayerScreen();

    void loadContent();
    void input(sf::Event evt);
    void update(float dt);
    void draw(sf::RenderWindow &window);

};

#endif // SINGLEPLAYERSCREEN_H
