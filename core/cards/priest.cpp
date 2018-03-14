#include "priest.h"

Priest::Priest()
    : Card("Priest", 2)
{
}

void Priest::activeEffect(Action & a) {
    a.target->showHand(a.current);
}
