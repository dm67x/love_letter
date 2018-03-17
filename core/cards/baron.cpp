#include "baron.h"
#include "../action.h"

Baron::Baron()
    : Card("Baron", 3, "You and another player secretly compare hands. \
         The player with the lower value is out of the round.")
{
}

void Baron::activeEffect(Action & a)
{
    unsigned short v1 = a.current->getCard()->getValue();
    unsigned short v2 = a.target->getCard()->getValue();
    if (v1 < v2) {
        a.current->setDead(true);
    } else if (v1 > v2) {
        a.target->setDead(true);
    }
}
