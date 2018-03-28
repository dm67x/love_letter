#ifndef CARD_CORE_H
#define CARD_CORE_H

#include <string>

using namespace std;

namespace Core {

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

};

}

#endif // CARD_CORE_H
