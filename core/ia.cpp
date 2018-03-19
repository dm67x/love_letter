#include <string.h>
#include "ia.h"


IA::IA(int numberofOpp)
    : Player("Computer" + IA.getId()++)
{
    numberOfOpponents=numberofOpp;
}
