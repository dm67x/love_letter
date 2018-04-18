#ifndef GUARD_CORE_H
#define GUARD_CORE_H

#include "../card.h"

namespace Core {

class Guard : public Card
{

public:
    Guard();

    bool needGuess() { return true; }
    bool needTarget() { return true; }
    void activeEffect();

};

}


#endif // GUARD_CORE_H
