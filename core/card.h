#ifndef CARD_H
#define CARD_H

#include <string>

class Action;
class Card
{

private:
    unsigned short value;
    std::string name;

protected:
    Card(std::string name, unsigned short value);

public:
    virtual void activeEffect(Action & a) = 0;

};

#endif // CARD_H
