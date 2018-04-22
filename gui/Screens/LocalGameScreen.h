#ifndef LOCALGAMESCREEN_H
#define LOCALGAMESCREEN_H

#include "Screen.h"
#include "core/game.h"
#include "Board.h"
#include "GameState.h"
#include "Dialogs/GuessDialog.h"

class LocalGameScreen : public Screen
{

private:
    Core::Game * game;
    Board * board;

    // State
    enum GameState state;

    // Target & Guess
    int playing_card(int index, Core::Card * card);
    Core::Player * target_player;

    // Zones
    PlayerZone * current_zone;

    // Next turn
    void nextPlayerTurn();
    PlayerZone * getCurrentZone(Core::Player * p);

    // For guess
    GuessDialog * guess_dialog;

    // Threads (target & guess)
    void target_func(Core::Card *card);
    void guess_func(Core::Card *card);

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
