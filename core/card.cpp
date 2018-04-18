#include "card.h"

Card::Card(string name, unsigned short value, string description)
    : value(value), name(name), description(description)
{
}

unsigned short Card::getValue()
{
    return value;
}

string Card::getName()
{
    return name;
}

string Card::getDescription()
{
    return description;
}

bool Card::isTheSameCardAs(string card_name){
    if (name == card_name)
        return true;
    return false;
}



