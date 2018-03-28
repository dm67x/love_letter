#ifndef DECK_CORE_H
#define DECK_CORE_H

#include <list>
#include "card.h"

namespace Core {

class Deck
{

private:
    list<Card *> cards;
    unsigned int number_of_cards;
    Deck();
    static Deck * instance;
    void shuffle_d();

public:
    static Deck * getInstance();
    Card * pickCard();
    void clear();
    unsigned int count();
    list<Card *> getCards();

};

}

#endif // DECK_CORE_H
