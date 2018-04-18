#ifndef IA_H
#define IA_H

#include "card.h"
#include "deck.h"
#include "game.h"

#include <vector>

class IA : public Core::Player
{

private:
    static int number_of_objects;
    int id;
    Core::Deck * deck;
    Core::Game * game;
    Core::Player *opponent;
    vector<Core::Card *> probableCards;
    vector<double> probabilities;


public:
    IA(Core::Game *g);
    int chooseCard();
    int getIndexMostProbableCard();
    //int assumeCard(int player_index);
    //int choosePlayer(vector<Player *> players);
    void updateProbableCards(Core::Card *c, double proba);
};

#endif // IA_H
