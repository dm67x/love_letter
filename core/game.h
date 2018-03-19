#ifndef GAME_H
#define GAME_H

#include <vector>
#include "deck.h"
#include "player.h"
#include "action.h"

using namespace std;

class Game
{

private:
    vector<Player *> players;
    Deck * deck;
    Action * action;

    int current_player; // index of current player
    unsigned int nb_players;
    unsigned int max_points;
    unsigned int nb_dead; // count how many are dead

    bool game_end; //game finished
    bool round_end; //round_finished

public:
    Game(unsigned int nb_players);
    ~Game();

    void startRound();
    void update();
    void pickTarget(int target_index);
    void guessCard(string name);

    Player * startTurn();
    Player *getCurrentPlayer();
    Deck * getDeck();

    unsigned int getMaxPoints();

    bool roundOver(); //isFinished
    bool gameOver(); //isEnd




};

#endif // GAME_H
