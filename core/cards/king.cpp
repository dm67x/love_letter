#include "king.h"
#include "../action.h"

namespace Core {

King::King()
    : Card("King", 6, 1, "Trade hands with another player of your choice.")
{
}

void King::activeEffect() {
    // Switch your hand with another player
    Action * action = Action::getInstance();
    action->current->switchHand(*action->target);
}

}
