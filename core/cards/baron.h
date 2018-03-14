#ifndef BARON_H
#define BARON_H

#include "../card.h"

class Baron : public Card
{

public:
    Baron();

    void activeEffect(Action & a);

};

#endif // BARON_H
