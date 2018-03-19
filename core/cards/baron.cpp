#include "baron.h"
#include "../action.h"

Baron::Baron()
    : Card("Baron", 3, "You and another player secretly compare hands. \
         The player with the lower value is out of the round.")
{
}

void Baron::activeEffect()
{

    Action * action = Action::getInstance();

    unsigned short v1 = action->current->getCard()->getValue();
    unsigned short v2 = action->target->getCard()->getValue();
    if (v1 < v2) {
        action->current->setDead(true);
    } else if (v1 > v2) {
        action->target->setDead(true);
    }
}
