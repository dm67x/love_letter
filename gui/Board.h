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
    sf::Transform transform;
    sf::Vector2f position;
    PlayerZone * current_player_zone;
    unsigned int current_zone;

public:
    Board(Core::Game * game, sf::Vector2f position);
    ~Board();

    void addPlayer(PlayerZone * player);
    void clear();
    void nextTurn();

    void update(float dt);
    void draw(sf::RenderWindow & window);

};

#endif // BOARD_H
