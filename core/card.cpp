#include "card.h"

namespace Core {

Card::Card(string name, unsigned short value, string description)
    : value(value), name(name), description(description)
{
}

Card::~Card()
{
}

bool Card::isTheSameCardAs(string card_name){
    return this->name == card_name;

}
}


