#include "player.h"
#include <algorithm>
#include <list>

Player::Player(std::string name)
      : name(name)
{
}

std::string Player::getName()
{
    return name;
}

std::list<Card> getCards()
{
    return cards;
}

bool isDead()
{
    return dead;
}

void setDead()
{
    dead=true;
}

void addPoint()
{
    points++;
}

int getPoints()
{
    return points;
}

void setProtection(bool value)
{
    isProtected=value;
}

// add a method bool isTheSameCardAs(Card * c) to compare one card with a given card c
bool hasCard(Card * c)
{
    bool res;
    if (cards.empty())
    {
        res=false;
    }
    else
    {
        if(cards.front.isTheSameCardAs(c)  ||
           cards.back.isTheSameCardAs(c))
        {
               res=true;
        }
    }
    return res;
}

//add the newly picked card last in the list
void addCard(Card c)
{
    cards.push_back(c);
}

//switch cards with another player p
void switchHand(Player * p)
{
    cards.swap (p->getCards());
}

//discard the only card the plays has in their hands
//normally used to implement the effect of the Prince just before picking a new card
void discard()
{
    cards.pop_front();
}

//play a chosen card
//precond: c is in the list of cards and is chosen by the player (determined through the GUI)
void play(Card * c){
    if(cards.front.isTheSameCardAs(c))
        cards.pop_front();
    else cards.pop_back();
}

//returns the current and only card that the player has in his hand
Card * getCard(){
    return cards.front();
}

Card * showHand(Player * p);


