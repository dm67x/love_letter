#ifndef LOCALGAMESCREEN_H
#define LOCALGAMESCREEN_H

#include "Screen.h"
#include "core/game.h"
#include "Board.h"

class LocalGameScreen : public Screen
{

private:
    Core::Game * game;
    Board * board;

    // Target & Guess
    int playing_card(int index, Core::Card * card);
    Core::Player * target_player;

    // Zones
    PlayerZone * current_zone;

    // Next turn
    void nextPlayerTurn();
    PlayerZone * getCurrentZone(Core::Player * p);

public:
    LocalGameScreen();
    ~LocalGameScreen();

    void loadContent();
    void unloadContent();
    void input(sf::Event evt);
    void update(float dt);
    void draw(sf::RenderWindow &window);

};

#endif // LOCALGAMESCREEN_H
