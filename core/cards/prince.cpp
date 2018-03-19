#include "prince.h"
#include "../action.h"

Prince::Prince()
    : Card("Prince", 5, "Choose any player (including yourself) to discard \
        his or her hand and draw a new card.")
{
}

void Prince::activeEffect()
{

    Action * action = Action::getInstance();
    action.target->discard(); // Discard a card
    action.target->pickCard(); // Draw a new card
}
