#include "utils.h"

Utils::Utils()
{
}

void Utils::myswap(Card *current, Card* target){
    Card * tmp = &current[0];
    current[0] = target[0];
    target[0] = *tmp;
}
