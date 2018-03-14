#ifndef HANDMAID_H
#define HANDMAID_H

#include "../card.h"

class Handmaid : public Card
{

public:
    Handmaid();

    void activeEffect(Action & a);

};

#endif // HANDMAID_H
