#ifndef IA_H
#define IA_H

#include "card.h"
#include "deck.h"
#include "game.h"

#include <vector>

class IA : public Player
{

private:
    static int number_of_objects;
    int id;
    Deck * deck;
    Game * game;
    Player * opponent;
    vector<Card *> probableCards;
    vector<double> probabilities;


public:
    IA(Game *g);
    int chooseCard();
    int getIndexMostProbableCard();
    //int assumeCard(int player_index);
    //int choosePlayer(vector<Player *> players);
    //void updateIA();
};

#endif // IA_H
