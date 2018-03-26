#include "Hand.h"

Hand::Hand(sf::Vector2f position)
    : Hand(position, 0)
{
}

Hand::Hand(sf::Vector2f position, float rotation)
{
    this->rotation = rotation;
    this->position = position;

    cards[0] = NULL;
    cards[1] = NULL;

    card_transforms[0].rotate(rotation, position);
    card_transforms[0].translate(-80, 0);

    card_transforms[1].rotate(rotation, position);
    card_transforms[1].translate(80, 0);
}

Hand::~Hand()
{
}

void Hand::addCard(Card * c)
{
    if (cards[0])
        cards[1] = c;
    else
        cards[0] = c;
}

sf::Vector2f Hand::getPosition()
{
    return position;
}

Card * Hand::getCard(unsigned short index)
{
    return cards[index];
}

void Hand::update(sf::RenderWindow &window, float dt)
{
    if (cards[0])
        cards[0]->update(dt);
    if (cards[1])
        cards[1]->update(dt);
}

void Hand::draw(sf::RenderWindow &window)
{
    if (cards[0])
        window.draw(*cards[0], card_transforms[0]);
    if (cards[1])
        window.draw(*cards[1], card_transforms[1]);
}
