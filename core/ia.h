#ifndef IA_H
#define IA_H

#include "card.h"
#include "deck.h"
#include "game.h"
#include "cards/all.h"

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
    int getIndexSecondMostProbableCard(int max);

    void updateProbabilities();
    double calculateProbability(Core::Card *c);
};

#endif // IA_H
