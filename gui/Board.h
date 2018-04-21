#ifndef BOARD_H
#define BOARD_H

#include "Object.h"
#include "Elements/PlayerZone.h"
#include "Elements/Deck.h"
#include "core/game.h"
#include <vector>
#include "IA/ia_intel.h"

enum ZONE { LEFT, RIGHT, BOTTOM, TOP };

class Board : public Object
{

private:
    Core::Game * game;
    IA::IA_intel * ia;
    Deck * deck;
    sf::FloatRect bounds;

    // zones
    std::vector<PlayerZone *> zones;
    bool top, left, right, bottom;

public:
    Board(Core::Game * game, sf::FloatRect bounds);
    ~Board();

    inline sf::FloatRect getBounds() const { return bounds; }
    inline std::vector<PlayerZone *> getZones() const { return zones; }
    inline Deck * getDeck() const { return deck; }

    int playing(int index, Core::Card *card);

    void addPlayer(Core::Player * player, enum ZONE where);
    void nextTurn();

    void update(float dt);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;

};

#endif // BOARD_H
