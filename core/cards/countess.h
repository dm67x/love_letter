#ifndef COUNTESS_CORE_H
#define COUNTESS_CORE_H

#include "../card.h"

namespace Core {

class Countess : public Card
{

public:
    Countess();

    bool needGuess() { return false; }
    bool needTarget() { return false; }
    void activeEffect();

};

}

#endif // COUNTESS_CORE_H
