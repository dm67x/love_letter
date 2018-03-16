#include "handmaid.h"
#include "../action.h"

Handmaid::Handmaid()
    : Card("Handmaid", 4, "Until your next turn, \
        ignore all effects from other players cards.")
{
}

void Handmaid::activeEffect(Action & a)
{
    a.current->setProtection(true);
}
