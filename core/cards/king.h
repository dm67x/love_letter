#ifndef KING_CORE_H
#define KING_CORE_H

#include "../card.h"

namespace Core {

class King : public Card
{

public:
    King();

    void activeEffect();

};

}

#endif // KING_CORE_H
