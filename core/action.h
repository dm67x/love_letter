#ifndef ACTION_H
#define ACTION_H

#include "player.h"

class Action
{

private:
    Action();
    static Action * instance;

public:
    static Action * getInstance();
    void clear();

    std::string guess;
    Player * current, * target;
    Deck * deck;

};

#endif // ACTION_H
