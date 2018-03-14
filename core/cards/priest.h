#ifndef PRIEST_H
#define PRIEST_H

#include "../card.h"

class Priest : public Card
{

public:
    Priest();

    void activeEffect(Action & a);

};

#endif // PRIEST_H
