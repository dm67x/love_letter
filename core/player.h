#ifndef PLAYER_H
#define PLAYER_H

#include <list>
#include "card.h"


class Player
{

private:
    std::string name;
    std::list<Card *> cards;
    int points                  = 0;
    bool dead                   = false;
    bool isProtected            = false;



public:
    Player(std::string name);
    std::string getName();
    std::list<Card> getCards();

    int getPoints();

    bool isDead();
    bool hasProtection(); //player protected from the handmaid
    bool hasCard(Card * c);

    void setDead(bool value);
    void addPoint();
    void pickCard(Card * c);
    void switchHand(Player * p);
    void setProtection(bool value);
    void discard();
    void play(Card * c);

    Card * showHand(Player * p);
};

#endif // PLAYER_H
