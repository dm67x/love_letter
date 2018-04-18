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
    virtual ~Card();

    inline unsigned short getValue() const { return value; }
    inline string getName() const { return name; }
    inline string getDescription() const { return description; }

    virtual bool needTarget() = 0;
    virtual bool needGuess() = 0;
    virtual void activeEffect() = 0;

};

}

#endif // CARD_CORE_H
