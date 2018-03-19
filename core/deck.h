#ifndef DECK_H
#define DECK_H

#include <list>
#include "card.h"

class Deck
{

private:
    list<Card *> cards;
    unsigned int number_of_cards;
    Deck(unsigned int number_of_cards);
    static Deck * instance;

public:
    static Deck * getInstance(unsigned int number_of_cards);
    Card * pickCard();

};

#endif // DECK_H
