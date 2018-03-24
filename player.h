#ifndef PLAYER_H
#define PLAYER_H

#include <SFML\Graphics.hpp>
#include "Animation.h"
#include "Card.h"

#include <iostream>
#include <list>

class Player
{

private:
    std::list<Card> hand;
    sf::Vector2f handPosition;

public:
    Player();
    Player(sf::Vector2f handPos);
    ~Player();

    void draw();
    void moveHand(sf::Vector2f dPosition);
};

#endif // PLAYER_H
