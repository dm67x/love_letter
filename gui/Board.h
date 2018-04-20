#ifndef BOARD_H
#define BOARD_H

#include "Object.h"
#include "Elements/PlayerZone.h"
#include "Elements/Deck.h"
#include "core/game.h"
#include <vector>

class Board : public Object
{

private:
    Core::Game * game;
    std::vector<PlayerZone *> zones;
    Deck * deck;
    sf::FloatRect board_rect;
    PlayerZone * current_player_zone;
    unsigned int current_zone;

    int playing(int index, Core::Card * card);

    Core::Player * target_player;
    sf::Transform transform;

public:
    Board(Core::Game * game, sf::FloatRect board_rect);
    ~Board();

    void addPlayer(PlayerZone * player);
    void clear();
    void nextTurn();

    void input(sf::Event evt);
    void update(float dt);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;

};

#endif // BOARD_H
