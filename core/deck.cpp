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
    cards.clear();
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

// Manually build the Deck with a given string
void Deck::buildDeck(string d){
    cards.clear();
    for(std::string::size_type i = 0; i < d.size(); ++i) {
        switch (d[i]) {
        case 'G':
            cards.push_back(new Guard());
            break;
        case 'P':
            cards.push_back(new Priest());
        case 'B':
            cards.push_back(new Baron());
        case 'H':
            cards.push_back(new Handmaid());
        case 'Y':
            cards.push_back(new Prince());
        case 'K':
            cards.push_back(new King());
        case 'C':
            cards.push_back(new Countess());
        case 'Z':
            cards.push_back(new Princess());
        default:
            break;
        }
    }
}

}
