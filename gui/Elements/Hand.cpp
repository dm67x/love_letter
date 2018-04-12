#include "Hand.h"

Hand::Hand()
    : sf::Transformable(), sf::Drawable()
{
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
    //card->setPosition(getPosition());
    card->setScale(0.5f, 0.5f);
    card->reveal();
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

void Hand::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    if (cards[0])
        target.draw(*cards[0], states);
    if (cards[1])
        target.draw(*cards[1], states);
}
