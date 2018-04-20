#ifndef CARD_CORE_H
#define CARD_CORE_H

#include <string>

using namespace std;

namespace Core {

class Card
{

private:
    string name;
    unsigned short value;
    unsigned short nbCopies;
    string description;

protected:
    Card(string name, unsigned short value, unsigned short nbCopies, string description);

public:
    virtual ~Card();

    inline unsigned short getValue() const { return value; }
    inline unsigned short getNbCopies() const { return nbCopies; }
    inline string getName() const { return name; }
    inline string getDescription() const { return description; }

    virtual bool needTarget() = 0;
    virtual bool needGuess() = 0;
    virtual bool targetHimself();
    virtual void activeEffect() = 0;

    bool isTheSameCardAs(string card_name);

};

}

#endif // CARD_CORE_H
