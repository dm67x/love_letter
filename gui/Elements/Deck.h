#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <vector>
#include "core/deck.h"

class Deck
{

private:
    std::vector<Card *> cards;
    sf::Vector2f position;
    Core::Deck * deck;

public:
    Deck(Core::Deck * deck, sf::Vector2f position);

    Card * pickCard(); // pick card from top of deck
    void draw(sf::RenderWindow & window);

};

#endif // DECK_H
