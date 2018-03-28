#include "Deck.h"
#include "Animations/PickAnimation.h"

Deck::Deck(sf::Vector2f position)
{
    this->position = position;
    core_deck = Core::Deck::getInstance();
    std::list<Core::Card *> deck_cards = core_deck->getCards();
    unsigned int i = 0;
    for (std::list<Core::Card *>::iterator it = deck_cards.begin(); it != deck_cards.end(); it++) {
        Card * c = new Card((*it), sf::Vector2f(position.x + i, position.y + i));
        c->setScale(0.35f, 0.35f);
        cards.push_back(c);
        i++;
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
