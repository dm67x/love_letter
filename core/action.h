#ifndef ACTION_CORE_H
#define ACTION_CORE_H

#include "player.h"
#include "deck.h"

namespace Core {

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

}

#endif // ACTION_CORE_H
