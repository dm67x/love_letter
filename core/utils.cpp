#include <random>
#include "utils.h"

Utils::Utils()
{
}

void Utils::myswap(Card *current, Card* target){
    Card * tmp = &current[0];
    current[0] = target[0];
    target[0] = *tmp;
}

int Utils::generateRandom(int min, int max){

    std::random_device rd;     // only used once to initialise (seed) engine
    std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
    std::uniform_int_distribution<int> uni(min,max); // guaranteed unbiased
    return uni(rng);
}
