#include "Hand.h"

Hand::Hand(sf::Vector2f position)
{
    this->position = position;
    cards[0] = NULL;
    cards[1] = NULL;
}

Hand::~Hand()
{
    if (cards[0])
        delete cards[0];

    if (cards[1])
        delete cards[1];
}

void Hand::addCard(Card *card)
{
    if (cards[0] == NULL)
        cards[0] = card;
    else
        cards[1] = card;
}

void Hand::update(float dt)
{
    if (cards[0])
        cards[0]->update(dt);

    if (cards[1])
        cards[1]->update(dt);
}

void Hand::draw(sf::RenderWindow &window)
{
    if (cards[0])
        window.draw(*cards[0]);

    if (cards[1])
        window.draw(*cards[1]);
}
