#ifndef CARD_H
#define CARD_H

#include <string>

using namespace std;

class Card
{

private:
    unsigned short value;
    string name;
    string description;

protected:
    Card(string name, unsigned short value, string description);

public:
    virtual void activeEffect() = 0;
    unsigned short getValue();
    string getName();
    string getDescription();

    bool isTheSameCardAs(string card_name);




};

#endif // CARD_H
