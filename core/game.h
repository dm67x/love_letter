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
    void startTurn(Card c);
    void update();
    void checkEnd();
    void givePoint();
    void giveCard(Player p);
    void pickTarget(Player p);
    void guessCard(Card c);

private:
    std::list <Player> players;//to implement
    std::list <Card *> cards;//to implement
    int maxPoints;
    int nb_players;
    int nb_cards;
    int current_player;

};

#endif // GAME_H
