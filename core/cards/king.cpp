#include "king.h"
#include "../action.h"

King::King()
    : Card("King", 6, "Trade hands with another player of your choice.")
{
}

void King::activeEffect(Action & a) {
    // Switch your hand with another player
    a.current->switchHand(a.target);
}
