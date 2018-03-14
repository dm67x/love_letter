#ifndef COUNTESS_H
#define COUNTESS_H

#include "../card.h"

class Countess : public Card
{

public:
    Countess();

    void activeEffect(Action & a);

};

#endif // COUNTESS_H
