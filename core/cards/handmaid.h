#ifndef HANDMAID_CORE_H
#define HANDMAID_CORE_H

#include "../card.h"

namespace Core {

class Handmaid : public Card
{

public:
    Handmaid();

    void activeEffect();

};

}

#endif // HANDMAID_CORE_H
