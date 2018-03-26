#include "Deck.h"
#include "Animations/PickAnimation.h"

Deck::Deck(sf::Vector2f position)
{
    this->position = position;
    for (int i = 0; i < 16; i++) {
        Card * c = new Card(sf::Vector2f(position.x + i * 1, position.y + i * 1));
        c->setScale(0.35f, 0.35f);
        cards.push_back(c);
    }
}

Deck::~Deck()
{
}

Card * Deck::pickCard()
{
    Card * c = top();
    cards.pop_back();
    return c;
}

Card * Deck::top()
{
    return cards.back();
}

void Deck::setPosition(sf::Vector2f position)
{
    this->position = position;
    for (std::list<Card *>::iterator it = cards.begin(); it != cards.end(); it++)
        (*it)->setPosition(position);
}

sf::Vector2f Deck::getPosition()
{
    return position;
}

void Deck::draw(sf::RenderWindow & window)
{
    for (std::list<Card *>::iterator it = cards.begin(); it != cards.end(); it++)
        window.draw(*(*it));
}
