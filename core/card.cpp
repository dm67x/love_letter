#include "card.h"

namespace Core {

Card::Card(string name, unsigned short value, string description)
    : value(value), name(name), description(description), is_playable(true)
{
}

Card::~Card()
{
}

bool Card::targetHimself()
{
    return true;
}

void Card::setActive(bool value)
{
    is_playable = value;
}

}


