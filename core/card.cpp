#include "card.h"

namespace Core {

Card::Card(string name, unsigned short value, string description)
    : value(value), name(name), description(description)
{
}

Card::~Card()
{
}

}


