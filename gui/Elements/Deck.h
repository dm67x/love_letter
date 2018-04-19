#ifndef DECK_H
#define DECK_H

#include "Object.h"
#include "Card.h"
#include <vector>
#include "core/deck.h"

class Deck : public Object
{

private:
    std::vector<Card *> cards;
    Core::Deck * deck;

public:
    Deck(Core::Deck * deck);

    Card * pickCard(); // pick card from top of deck
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;

};

#endif // DECK_H
