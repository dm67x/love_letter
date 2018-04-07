#ifndef PLAYERZONE_H
#define PLAYERZONE_H

#include "Hand.h"
#include "core/player.h"

class PlayerZone
{

private:
    Hand * hand;
    sf::Vector2f position;
    Core::Player * player;
    sf::Text player_name;
    sf::Font font;

public:
    PlayerZone(Core::Player * player, sf::Vector2f position);
    ~PlayerZone();

    void update(float dt);
    void draw(sf::RenderWindow & window);

};

#endif // PLAYERZONE_H
