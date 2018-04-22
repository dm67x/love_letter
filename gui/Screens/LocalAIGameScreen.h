#ifndef LOCALAIGAMESCREEN_H
#define LOCALAIGAMESCREEN_H

#include "Screen.h"
#include "core/game.h"
#include "Board.h"
#include "IA/ia_intel.h"


class LocalAIGameScreen : public Screen
{

private:
    Core::Game * game;
    Board * board;

    // AI
    IA::IA_intel * ia;

    // Target & Guess
    int playing_card(int index, Core::Card * card);
    Core::Player * target_player;

    // Zones
    PlayerZone * current_zone;
    int current_zone_index;

    // Next turn
    void nextPlayerTurn();

    void playing_card_AI(int index, Core::Card *card);

public:
    LocalAIGameScreen();
    ~LocalAIGameScreen();

    void loadContent();
    void unloadContent();
    void input(sf::Event evt);
    void update(float dt);
    void draw(sf::RenderWindow &window);

};

#endif // LOCALAIGAMESCREEN_H
