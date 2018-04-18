#ifndef HANDMAID_CORE_H
#define HANDMAID_CORE_H

#include "../card.h"

namespace Core {

class Handmaid : public Card
{

public:
    Handmaid();

    bool needGuess() { return false; }
    bool needTarget() { return false; }
    void activeEffect();

};

}

#endif // HANDMAID_CORE_H
