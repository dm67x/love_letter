#ifndef IA_H
#define IA_H

#include "card.h"
#include "player.h"
#include <vector>

using namespace std;

class IA_Dummy : public Core::Player
{

private:
    static int number_of_objects;
    int id; // id of the current ia object

public:
    IA_Dummy();
    /* in the ihm, if current player is IA_dummy then
     *          call methods p->pickTarget(choosePlayer(players));
     *                       p->guessCard(assumeCard());
     *                       p->play(chooseBetween());
     */
    int chooseCard(); //returns index of chosen card
    int assumeCard(/*int player_index*/); //returns index of chosen card
    int choosePlayer(vector<Player *> players); //returns index of chosen player
};

#endif // IA_H
