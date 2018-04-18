#ifndef UTILS_H
#define UTILS_H

#include <list>
#include "card.h"

class Utils
{

public:
    static void myswap(Card * current, Card * target);
    static int generateRandom(int min, int max); //return a random integer betxween min, max


private:
    Utils();
};

#endif // UTILS_H
