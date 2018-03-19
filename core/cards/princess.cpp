#include "princess.h"
#include "../action.h"

Princess::Princess()
    : Card("Princess", 8, "If you discard this card, you are out of the round.")
{
}

// Active if you discard Princess
void Princess::activeEffect()
{
    Action * action = Action::getInstance();
    action->current->setDead(true);
}

