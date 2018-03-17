#ifndef CARD_H
#define CARD_H

#include <string>

class Action;

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
    bool isTheSameCardAs(Card & c);

};

#endif // CARD_H
