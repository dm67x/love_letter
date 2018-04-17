#ifndef PRINCESS_CORE_H
#define PRINCESS_CORE_H

#include "../card.h"

namespace Core {

class Princess : public Card
{

public:
    Princess();

    bool needGuess() { return false; }
    bool needTarget() { return false; }
    void activeEffect();

};

}

#endif // PRINCESS_CORE_H
