#ifndef CARD_H
#define CARD_H

#include <string>

#include "action.h"

class Card
{

private:
    unsigned short value;
    std::string name;
    std::string description;

protected:
    Card(std::string name, unsigned short value, std::string description);

public:
    virtual void activeEffect(Action & a) = 0;

    unsigned short getValue();
    std::string getName();
    std::string getDescription();

};

#endif // CARD_H
