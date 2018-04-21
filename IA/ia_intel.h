#ifndef IA_INTEL_H
#define IA_INTEL_H

#include "../core/card.h"
#include "../core/deck.h"
#include "../core/game.h"
#include "../core/cards/all.h"

#include <vector>

namespace IA {

class IA_intel : public Core::Player
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
    IA_intel(Core::Game *g);
    int chooseCard();
    int getIndexMostProbableCard();
    int getIndexSecondMostProbableCard(int max);

    void updateProbabilities();
    double calculateProbability(Core::Card *c);
};

}

#endif // IA_INTEL_H
