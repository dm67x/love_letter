#ifndef PLAYERZONE_H
#define PLAYERZONE_H

#include "Hand.h"
#include "core/player.h"
#include "DebugBounds.h"

class PlayerZone : public sf::Transformable, public sf::Drawable
{

private:
    Hand * hand;
    Core::Player * player;
    sf::Text player_name;
    sf::Font font;

    // Debug
    DebugBounds * debug;

public:
    PlayerZone(Core::Player * player, sf::FloatRect bounds);
    ~PlayerZone();

    inline Hand * getHand() const { return hand; }

    void update(float dt);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;

};

#endif // PLAYERZONE_H
