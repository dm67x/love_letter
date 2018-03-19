
#include <random>
#include <algorithm>
#include <iterator>
#include <iostream>

#include "deck.h"
#include "cards/all.h"


Deck::Deck(unsigned int number_of_cards)
{
    this->number_of_cards = number_of_cards;
    cards.push_back(new Guard());
    cards.push_back(new Guard());
    cards.push_back(new Guard());
    cards.push_back(new Guard());
    cards.push_back(new Guard());
    cards.push_back(new Guard());
    cards.push_back(new Guard());
    cards.push_back(new Guard());
    cards.push_back(new Guard());
    cards.push_back(new Guard());
    cards.push_back(new Guard());
    cards.push_back(new Guard());
    cards.push_back(new Guard());
    cards.push_back(new Guard());
    cards.push_back(new Princess());
    cards.push_back(new Guard());
}

Deck::~Deck()
{
}

Card * Deck::pickCard()
{
    Card * c = cards.front();
    cards.pop_front();
    return c;
}

// Shuffle the deck
void listShuffle(){
   vector<Card*> V( deck.begin(), deck.end() );
   shuffle( V.begin(), V.end(), mt19937{ random_device{}() } );
   deck.assign( V.begin(), V.end() );
}
