#include "card.h"

Card::Card(std::string name, unsigned short value, std::string description)
    : value(value), name(name), description(description)
{
}

unsigned short Card::getValue()
{
    return value;
}

std::string Card::getName()
{
    return name;
}

std::string Card::getDescription()
{
    return description;
}
