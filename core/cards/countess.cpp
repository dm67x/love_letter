#include "countess.h"

Countess::Countess()
    : Card("Countess", 7, "If you have this card and the King or Prince in your hand, \
         you must discard this card.")
{
}

void Countess::activeEffect(Action & a)
{
    Card * c = a.current->getCard();
    if (c->getValue() == 5 || c->getValue() == 6)
        break;
}
