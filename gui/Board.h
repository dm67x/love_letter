#ifndef BOARD_H
#define BOARD_H

#include "Elements/PlayerZone.h"
#include "Elements/Deck.h"
#include "core/game.h"
#include <vector>

class Board
{

private:
    Core::Game * game;
    std::vector<PlayerZone *> zones;
    Deck * deck;

public:
    Board(Core::Game * game, sf::Vector2f position);
    ~Board();

    void addPlayer(PlayerZone * player);
    void clear();
    void rotate();

    void update(float dt);
    void draw(sf::RenderWindow & window);

};

#endif // BOARD_H
