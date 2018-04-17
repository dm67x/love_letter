#ifndef BOARD_H
#define BOARD_H

#include "Elements/PlayerZone.h"
#include "Elements/Deck.h"
#include "core/game.h"
#include <vector>

class Board : public sf::Transformable, public sf::Drawable
{

private:
    Core::Game * game;
    std::vector<PlayerZone *> zones;
    Deck * deck;
    sf::Transform zone_transforms[4];
    sf::FloatRect board_rect;
    PlayerZone * current_player_zone;
    unsigned int current_zone;

    static void played(int index, Core::Card * card);
    static void target_func();
    static void guess_func();

public:
    Board(Core::Game * game, sf::FloatRect board_rect);
    ~Board();

    void addPlayer(PlayerZone * player);
    void clear();
    void nextTurn();

    void update(float dt);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;

};

#endif // BOARD_H
