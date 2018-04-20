#ifndef IA_H
#define IA_H

#include "card.h"
#include "deck.h"
#include "game.h"
#include "cards/all.h"

#include <vector>

using namespace Core;

class IA : public Player
{

private:
    static int number_of_objects;
    int id;
    Deck * deck;
    Game * game;
    Player *opponent;
    vector<Card *> probableCards;
    vector<double> probabilities;


public:
    IA(Game *g);
    int chooseCard();
    int getIndexMostProbableCard();
    int getIndexSecondMostProbableCard(int max);

    void updateProbabilities();
    double calculateProbability(Core::Card *c);
};

#endif // IA_H
