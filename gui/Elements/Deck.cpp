#include "Deck.h"

Deck::Deck(Core::Deck * deck, sf::Vector2f position)
    : sf::Drawable()
{
    this->position = position;
    this->deck = deck;

    // Cards
    std::list<Core::Card *> core_cards = deck->getCards();
    unsigned int i = 0;
    for (std::list<Core::Card *>::iterator it = core_cards.begin();
         it != core_cards.end(); it++) {
        Card * card = new Card(*it);
        card->setPosition(position.x + i, position.y + i);
        card->setScale(0.5f, 0.5f);
        cards.push_back(card);
        i++;
    }
}

Card *Deck::pickCard()
{
    Card * top = cards.back();
    //deck->pickCard(); // remove card from core deck too
    cards.pop_back();
    return top;
}

void Deck::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for (int i = 0; i < cards.size(); i++) {
        target.draw(*cards[i], states);
    }
}
