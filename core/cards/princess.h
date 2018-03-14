#ifndef PRINCESS_H
#define PRINCESS_H

#include "../card.h"

class Princess : public Card
{

public:
    Princess();

    void activeEffect(Action & a);

};

#endif // PRINCESS_H
