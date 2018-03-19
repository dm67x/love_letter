#ifndef PLAYER_H
#define PLAYER_H

#include <stack>
#include <string.h>
#include "card.h"
#include "deck.h"


using namespace std;

class Player
{

private:
    string name;
    Card * cards[2];
    stack<Card *> played_cards;
    bool dead;
    bool protection;
    unsigned int points;


public:

    Player(string name);
    string getName();

    unsigned int getPoints();

    bool isDead();
    bool hasProtection(); //player protected from the handmaid
    bool hasCard(string cardName);

    void givePoint();
    void setDead(bool value);
    void pickCard(Deck & d);
    void switchHand(Player &p);
    void setProtection(bool value);
    void discard();
    void play(int index);

    Card * getCard(int i=0);
};

#endif // PLAYER_H
