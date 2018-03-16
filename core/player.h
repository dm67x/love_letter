#ifndef PLAYER_H
#define PLAYER_H

#include "card.h"
#include <list>


class Player
{

private:
    std::string name;
    std::list<Card> cards;
    int points                  = 0;
    bool isProtected            = false;
    bool isDead                 = false;


public:
    Player(std::string name);
    std::string getName();
    std::list<Card> getCards();

    int getPoints();

    bool isDead();
    bool hasCard(Card * c);

    void setDead();
    void addPoint();
    void addCard(Card c);
    void switchHand(Player * p);
    void pickCard();
    void setProtection(bool value);
    void discard();
    void throwCard(Card * c);

    Card * getCard();
    Card * showHand(Player * p);


};

#endif // PLAYER_H
