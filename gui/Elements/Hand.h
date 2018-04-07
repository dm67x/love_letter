#ifndef HAND_H
#define HAND_H

#include "Card.h"

class Hand
{

private:
    sf::Vector2f position;
    Card * cards[2];

public:
    Hand(sf::Vector2f position);
    ~Hand();

    void addCard(Card * card);
    void update(float dt);
    void draw(sf::RenderWindow & window);

};

#endif // HAND_H
