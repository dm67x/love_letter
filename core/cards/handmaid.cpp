#include "handmaid.h"
#include "../action.h"

namespace Core {

Handmaid::Handmaid()
    : Card("Handmaid", 4, 2, "Until your next turn, ignore all effects from other players cards.")
{
}

void Handmaid::activeEffect()
{
    Action * action = Action::getInstance();
    action->current->activateShield();
}

}
