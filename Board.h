#ifndef BOARD_H
#define BOARD_H

#include <SFML/Graphics.hpp>
#include "Deck.h"
#include "Hand.h"
#include <vector>

class Board
{

private:
    static Board * instance;
    Deck * deck;
    std::vector<Hand *> hands;
    unsigned short current_player;

private:
    Board();
    ~Board();

public:
    static Board * getInstance();

    //void addPlayer(Player * player);

    void update(sf::RenderWindow & window, float dt);
    void draw(sf::RenderWindow & window);
    void clear();

};

#endif // BOARD_H
