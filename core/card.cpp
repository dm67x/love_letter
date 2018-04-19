#include "card.h"

namespace Core {

Card::Card(string name, unsigned short value, unsigned short nbCopies, string description)
    : value(value), name(name), nbCopies(nbCopies), description(description)
{
}

Card::~Card()
{
}

bool Card::isTheSameCardAs(string card_name){
    return this->name == card_name;

}
}


