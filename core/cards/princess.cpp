#include "princess.h"
#include "../action.h"

namespace Core {

Princess::Princess()
    : Card("Princess", 8, 1, "If you discard this card, you are out of the round.")
{
}

// Active if you discard Princess
void Princess::activeEffect()
{
    Action * action = Action::getInstance();
    action->current->kill();
}

}
