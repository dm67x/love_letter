#ifndef PLAYER_H
#define PLAYER_H

#include <list>
#include <string.h>
#include "card.h"

using namespace std;

class Player
{

private:
    string name;
    list<Card *> cards;
    int points                  = 0;
    bool dead                   = false;
    bool isProtected            = false;

public:
    Player(string name);
    string getName();
    list<Card *> getCards();

    int getPoints();

    bool isDead();
    bool hasProtection(); //player protected from the handmaid
    bool hasCard(Card &c);

    void setDead(bool value);
    void addPoint();
    void pickCard(Card &c);
    void switchHand(Player &p);
    void setProtection(bool value);
    void discard();
    void play(Card &c);

    Card * showHand();
};

#endif // PLAYER_H
