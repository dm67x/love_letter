#include <random>
#include <algorithm>
#include <iterator>
#include <iostream>

#include "deck.h"
#include "cards/all.h"

namespace Core {

Deck * Deck::instance = NULL;

// Argument can be ignored if instance already exist
Deck * Deck::getInstance()
{
    if (instance == NULL)
        instance = new Deck();
    return instance;
}

Deck::Deck()
{
    clear();
}

// Shuffle the deck
void Deck::shuffle_me()
{
   vector<Card*> V( cards.begin(), cards.end() );
   shuffle( V.begin(), V.end(), mt19937{ random_device{}() } );
   cards.assign( V.begin(), V.end() );
}

// Pick card from deck
Card * Deck::pickCard()
{
    if (cards.size() == 0) return NULL;
    Card * c = cards.front();
    cards.pop_front();
    return c;
}

// Reset
void Deck::clear()
{
    cards.push_back(new Guard());
    cards.push_back(new Guard());
    cards.push_back(new Guard());
    cards.push_back(new Guard());
    cards.push_back(new Guard());
    cards.push_back(new Priest());
    cards.push_back(new Priest());
    cards.push_back(new Baron());
    cards.push_back(new Baron());
    cards.push_back(new Handmaid());
    cards.push_back(new Handmaid());
    cards.push_back(new Prince());
    cards.push_back(new Prince());
    cards.push_back(new King());
    cards.push_back(new Countess());
    cards.push_back(new Princess());

    shuffle_me();
}

// Remove card from deck
void Deck::removeCard()
{
    removed_cards.push_back(pickCard());
}

}
