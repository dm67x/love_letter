#include "prince.h"
#include "../action.h"

namespace Core {

Prince::Prince()
    : Card("Prince", 5, "Choose any player (including yourself) to discard \
        his or her hand and draw a new card.")
{
}

void Prince::activeEffect()
{

    Action * action = Action::getInstance();
    action->target->discard(); // Discard a card
    action->target->pickCard(*Deck::getInstance()); // Draw a new card
}

}
