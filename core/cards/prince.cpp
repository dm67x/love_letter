#include "prince.h"
#include "../action.h"

namespace Core {

Prince::Prince()
    : Card("Prince", 5, 2, "Choose any player (including yourself) to discard his or her hand and draw a new card.")
{
}

void Prince::activeEffect()
{
    Action * action = Action::getInstance();
    action->target->discardWithoutEffect(0); // Discard a card
    action->target->pickCard(); // Draw a new card
}

}
