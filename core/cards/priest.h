#ifndef PRIEST_CORE_H
#define PRIEST_CORE_H

#include "../card.h"

namespace Core {

class Priest : public Card
{

public:
    Priest();
    void activeEffect();

};

}

#endif // PRIEST_CORE_H
