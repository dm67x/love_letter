#include "guard.h"

Guard::Guard()
    : Card("Guard", 1)
{
}

void Guard::activeEffect(Action & a)
{
    if (a.target->hasCard(a.c1)) {
        a.target->setDead(true);
    }
}

