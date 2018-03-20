
#include <random>
#include <algorithm>
#include <iterator>
#include <iostream>

#include "deck.h"
#include "cards/all.h"

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

Card * Deck::pickCard()
{
    if (number_of_cards == 0) return NULL;
    Card * c = cards.front();
    cards.pop_front();
    return c;
}

void Deck::clear()
{
    number_of_cards = 16;
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

unsigned int Deck::count()
{
    return number_of_cards;
}

// Shuffle the deck
void listShuffle()
{
   // deck was not declared in this scope
   /*vector<Card*> V( deck.begin(), deck.end() );
   shuffle( V.begin(), V.end(), mt19937{ random_device{}() } );
   deck.assign( V.begin(), V.end() );*/
}
