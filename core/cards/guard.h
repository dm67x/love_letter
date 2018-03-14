#ifndef GUARD_H
#define GUARD_H

#include "../card.h"

class Guard : public Card
{

public:
    Guard();

    void activeEffect(Action & a);

};

#endif // GUARD_H
