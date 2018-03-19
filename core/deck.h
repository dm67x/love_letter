#ifndef DECK_H
#define DECK_H

#include <list>
#include "card.h"

using namespace std;

class Deck
{

private:
    list<Card *> cards;
    unsigned int number_of_cards;

public:
    Deck(unsigned int number_of_cards);
    ~Deck();

    Card * pickCard();

};

#endif // DECK_H
