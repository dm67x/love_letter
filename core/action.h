#ifndef ACTION_H
#define ACTION_H

#include "player.h"

class Card;
class Action
{

public:
    static Action * getInstance();

private:
    Action();

    static Action * instance;

public:
    Player * current;
    Player * target;
    Card * c1;
    Card * c2;

    void empty();

};

#endif // ACTION_H
