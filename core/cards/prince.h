#ifndef PRINCE_H
#define PRINCE_H

#include "../card.h"

class Prince : public Card
{

public:
    Prince();

    void activeEffect(Action & a);

};

#endif // PRINCE_H
