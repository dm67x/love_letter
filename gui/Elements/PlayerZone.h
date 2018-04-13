#ifndef PLAYERZONE_H
#define PLAYERZONE_H

#include "Hand.h"
#include "core/player.h"

enum ZONES { TOP, BOTTOM, LEFT, RIGHT };

class PlayerZone : public sf::Transformable, public sf::Drawable
{

private:
    Hand * hand;
    enum ZONES zone;
    sf::Transform hand_transform, name_transform;
    sf::Vector2f position;
    double rotate;
    Core::Player * player;
    sf::Text player_name;
    sf::Font font;

public:
    PlayerZone(Core::Player * player, enum ZONES zone);
    ~PlayerZone();

    inline Hand * getHand() const { return hand; }

    void update(float dt);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;

};

#endif // PLAYERZONE_H
