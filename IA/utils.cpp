#include <random>
#include "utils.h"

namespace IA {

Utils::Utils()
{
}

int Utils::generateRandom(int min, int max){

    std::random_device rd;     // only used once to initialise (seed) engine
    std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
    std::uniform_int_distribution<int> uni(min,max); // guaranteed unbiased
    return uni(rng);
}

}
