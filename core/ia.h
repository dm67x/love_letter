#ifndef IA_H
#define IA_H

#include "card.h"
using namespace std;

class IA : public Player
{

private:
    static int id = 1;
    int numberOfOpponents;

public:
    IA(int numberofOpp);
    int getId();
    Card * chooseBetween(Card &c1, Card &c2);
    Card * assumeCard(Player & p);
    Player * choosePlayer();
};

#endif // IA_H
