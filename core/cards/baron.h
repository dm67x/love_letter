#ifndef BARON_CORE_H
#define BARON_CORE_H

#include "../card.h"

namespace Core {

class Baron : public Card
{

public:
    Baron();

    void activeEffect();

};

}

#endif // BARON_CORE_H
