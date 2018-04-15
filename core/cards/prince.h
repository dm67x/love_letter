#ifndef PRINCE_CORE_H
#define PRINCE_CORE_H

#include "../card.h"

namespace Core {

class Prince : public Card
{

public:
    Prince();

    void activeEffect();

};

}

#endif // PRINCE_CORE_H
