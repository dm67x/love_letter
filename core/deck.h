#ifndef DECK_H
#define DECK_H

#include <list>
#include "card.h"

class Deck
{

private:
    list<Card *> cards;
    unsigned int number_of_cards;
    Deck();
    static Deck * instance;

public:
    static Deck * getInstance();
    Card * pickCard();
    void clear();
    unsigned int count();

};

#endif // DECK_H
