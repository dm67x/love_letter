#include "countess.h"

namespace Core {

Countess::Countess()
    : Card("Countess", 7, "If you have this card and the King or Prince in your hand, \
         you must discard this card.")
{
}

void Countess::activeEffect()
{
    // If you have King or Prince in your hand with Countess, you must play Countess
}

}
