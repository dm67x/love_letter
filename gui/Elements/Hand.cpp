#include "Hand.h"

Hand::Hand()
    : sf::Transformable(), sf::Drawable()
{
    cards[0] = NULL;
    cards[1] = NULL;

    transforms[0].translate(-80.0f, 0.0f);
    transforms[1].translate(80.0f, 0.0f);
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
    card->setScale(0.5f, 0.5f);
    if (!cards[0])
        cards[0] = card;
    else
        cards[1] = card;
}

void Hand::reveal()
{
    if (cards[0])
        cards[0]->reveal();
    if (cards[1])
        cards[1]->reveal();
}

void Hand::mask()
{
    if (cards[0])
        cards[0]->mask();
    if (cards[1])
        cards[1]->mask();
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
    if (cards[0]) {
        sf::RenderStates cards_zero_states = states;
        cards_zero_states.transform *= transforms[0];
        target.draw(*cards[0], cards_zero_states);
    }

    if (cards[1]) {
        sf::RenderStates cards_one_states = states;
        cards_one_states.transform *= transforms[1];
        target.draw(*cards[1], cards_one_states);
    }
}
