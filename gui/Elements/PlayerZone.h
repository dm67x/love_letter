#ifndef PLAYERZONE_H
#define PLAYERZONE_H

#include "Object.h"
#include "Hand.h"
#include "core/player.h"
#include "DebugBounds.h"

class PlayerZone : public Object
{

private:
    Hand * hand;
    Core::Player * player;
    sf::Text player_name;
    sf::Font font;
    sf::Text score_number;
    sf::FloatRect bounds;

    bool mask;

    // Debug
    DebugBounds * debug;

public:
    PlayerZone(Core::Player * player, sf::FloatRect bounds);
    ~PlayerZone();

    inline Hand * getHand() const { return hand; }
    inline Core::Player * getPlayer() const { return player; }
    inline sf::FloatRect getBounds() const { return bounds; }
    inline bool isMasked() const { return mask; }

    void clear();
    void setMask(bool value);

    void input(sf::Event evt, sf::Transform transform);
    void update(float dt, sf::Transform transform);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;

};

#endif // PLAYERZONE_H
