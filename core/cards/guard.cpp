#include "guard.h"
#include "../action.h"

namespace Core {

Guard::Guard()
    : Card("Guard", 1, "Name a non-Guard card and choose another player. If that player has that card, he or she is out of the round.")
{
}

void Guard::activeEffect()
{
   Action * action = Action::getInstance();
   Player * target = action->target;

   if (action->guess != "Guard" && target->getCard()->getName() == action->guess)
       target->kill();
}

}


