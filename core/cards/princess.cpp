#include "princess.h"

Princess::Princess()
    : Card("Princess", 8, "If you discard this card, you are out of the round.")
{
}

void Princess::activeEffect(Action & a) {
    a.current->setDead(true);
}
