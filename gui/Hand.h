#ifndef HAND_H
#define HAND_H

#include <list>
#include <SFML/Graphics.hpp>
#include "Card.h"

class Hand
{

private:
    sf::Vector2f position;
    float rotation;
    Card * cards[2];
    sf::Transform card_transforms[2];

public:
    Hand(sf::Vector2f position);
    Hand(sf::Vector2f position, float rotation);
    ~Hand();

    void addCard(Card * c);
    sf::Vector2f getPosition();
    Card * getCard(unsigned short index = 0);
    Card * pickCard(unsigned short index);
    sf::Vector2f freeZonePosition();

    void update(sf::RenderWindow & window, float dt);
    void draw(sf::RenderWindow & window);

};

#endif // HAND_H
