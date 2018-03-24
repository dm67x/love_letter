#ifndef BOARD_H
#define BOARD_H

#include <SFML/Graphics.hpp>
#include <list>
#include "Card.h"

class Board
{

private:
    static Board * instance;
    std::list<Card *> deck;

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
