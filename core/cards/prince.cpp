#include "prince.h"

Prince::Prince()
    : Card("Prince", 5, "Choose any player (including yourself) to discard \
        his or her hand and draw a new card.")
{
}

void Prince::activeEffect(Action & a)
{
    a.target->discard(); // Discard a card
    a.target->pickCard(); // Draw a new card
}
