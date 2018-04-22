#include "card.h"

namespace Core {

Card::Card(string name, unsigned short value, unsigned short nbCopies, string description)
    : name(name), value(value), nbCopies(nbCopies), description(description), is_playable(true)
{
}

Card::~Card()
{
}

bool Card::targetHimself()
{
    return true;
}

bool Card::isTheSameCardAs(string card_name)
{
    return this->name == card_name;
}

void Card::setActive(bool value)
{
    is_playable = value;
}

}


