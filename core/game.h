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
    void update();
    void checkEnd();
    void givePoint();
    void giveCard(Player p);

private:
    std::list <Player> players;//to implement
    std::list <Card *> cards;//to implement
    int maxPoints;
    int nb_players;
    int nb_cards;

};

#endif // GAME_H
