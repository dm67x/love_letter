#include "guard.h"
#include "../action.h"

Guard::Guard()
    : Card("Guard", 1, "Name a non-Guard card and choose another player. \
        If that player has that card, he or she is out of the round.")
{
}

void Guard::activeEffect()
{
   Action * action = Action::getInstance();
   Player * target = action->target;

   if (action->guess != "Guard" &&
        (target->hasCard(action->guess) == 0 ||
         target->hasCard(action->guess) == 1))
       target->setDead(true);
}


