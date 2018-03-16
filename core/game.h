#ifndef GAME_H
#define GAME_H
#include <list>
#include "card.h"
#include "player.h"


class Game
{

public:
    Game(int nb_players);
    void start();
    void startRound();
    void startTurn(Card * c);
    void update();
    void checkEnd();
    void givePoint();
    void giveCard(Player p);
    void pickTarget(Player p);
    void guessCard(Card * c);
    bool isOver();

private:
    Player * players;//to implement
    std::list <Card *> cards;//to implement
    int max_points;
    int nb_players;
    int nb_cards;
    int current_player; // index of current player
    int nb_dead; // count how many are dead
    bool end;
    Action * action;

};

#endif // GAME_H
