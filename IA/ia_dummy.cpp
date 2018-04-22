#include <string>
#include "ia_dummy.h"
#include "utils.h"

namespace IA {

int IA_Dummy::number_of_objects = 0;

IA_Dummy::IA_Dummy()
    : Player("ComputerDummy" + id)
{
    number_of_objects++;
    id = number_of_objects;
}


int IA_Dummy::chooseCard(){
    return Utils::generateRandom(0, 1);
}

int IA_Dummy::assumeCard(){
    return Utils::generateRandom(1,8);
}

int IA_Dummy::choosePlayer(vector<Core::Player *> players){
    int max=players.size();
    return Utils::generateRandom(1,max);
}

}






