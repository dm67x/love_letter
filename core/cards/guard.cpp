#include "guard.h"

Guard::Guard()
    : Card("Guard", 1, "Name a non-Guard card and choose another player. \
        If that player has that card, he or she is out of the round.")
{
}

void Guard::activeEffect(Action & a)
{
    if (a.c1->getValue() != 1 && a.target->hasCard(a.c1)) {
        a.target->setDead(true);
    }
}

