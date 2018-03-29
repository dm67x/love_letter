#ifndef DECK_CORE_H
#define DECK_CORE_H

#include <list>
#include "card.h"

namespace Core {

class Deck
{

private:
    std::list<Card *> cards;
    std::list<Card *> removed_cards;
    static Deck * instance;

    Deck();
    void shuffle_me();

public:
    inline std::list<Card *> getCards() const { return cards; }
    inline std::list<Card *> getRemovedCards() const { return removed_cards; }

    static Deck * getInstance();
    Card * pickCard();
    void removeCard();
    void clear();

};

}

#endif // DECK_CORE_H
