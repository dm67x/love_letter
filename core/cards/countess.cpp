#include "countess.h"
#include "action.h"

namespace Core {

Countess::Countess()
    : Card("Countess", 7, 1, "If you have this card and the King or Prince in your hand, you must discard this card.")
{
}

void Countess::activeEffect()
{
    // Player (class) manage this effect
}

}
