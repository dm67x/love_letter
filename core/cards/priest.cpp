#include "priest.h"
#include "../action.h"

Priest::Priest()
    : Card("Priest", 2, "Look at another player's hand.")
{
}

void Priest::activeEffect() {
    Action * action = Action::getInstance();
    action->target->getCard(/*a.current*/);
}
