#ifndef KING_H
#define KING_H

#include "../card.h"

class King : public Card
{

public:
    King();

    void activeEffect(Action & a);

};

#endif // KING_H
