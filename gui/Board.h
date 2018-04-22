#ifndef BOARD_H
#define BOARD_H

#include "Object.h"
#include "Elements/PlayerZone.h"
#include "Elements/Deck.h"
#include "core/game.h"
#include <vector>

enum ZONE { LEFT, RIGHT, BOTTOM, TOP };

class Board : public Object
{

private:
    Core::Game * game;
    Deck * deck;
    sf::FloatRect bounds;

    sf::Sprite board_bg;
    sf::Texture board_bg_texture;

    // zones
    std::vector<PlayerZone *> zones;

public:
    Board(Core::Game * game, sf::FloatRect bounds);
    ~Board();

    inline sf::FloatRect getBounds() const { return bounds; }
    inline std::vector<PlayerZone *> getZones() const { return zones; }
    inline Deck * getDeck() const { return deck; }

    int playing(int index, Core::Card *card);

    void resetDeck();
    void addPlayer(Core::Player * player, enum ZONE where);
    void nextTurn();

    void update(float dt);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;

};

#endif // BOARD_H
