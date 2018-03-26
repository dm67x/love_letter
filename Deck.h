#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <list>

class Deck
{

private:
    sf::Vector2f position;
    std::list<Card *> cards;

public:
    Deck(sf::Vector2f position);
    ~Deck();

    Card * pickCard();
    Card * top();
    void setPosition(sf::Vector2f position);
    sf::Vector2f getPosition();
    void draw(sf::RenderWindow & window);

};

#endif // DECK_H
