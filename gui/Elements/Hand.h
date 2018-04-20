#ifndef HAND_H
#define HAND_H

#include "Object.h"
#include "Card.h"
#include "core/player.h"
#include "DebugBounds.h"

class Board;

typedef int (Board::*FUNC)(int, Core::Card*);

class Hand : public Object
{

private:
    Card * cards[2];
    sf::FloatRect bounds;
    Core::Player * player;
    bool target_selected;
    bool guessed;

    FUNC function;
    Board * elem;
    int selected_card; // for update

    // Debug
    DebugBounds * debug;

public:
    Hand(Core::Player * player, sf::FloatRect bounds);
    ~Hand();

    void addCard(Card * card);
    void reveal();
    void mask();
    void updateCards();

    void playing(FUNC func, Board * elem);

    void input(sf::Event evt, sf::Transform transf);
    void update(float dt, sf::Transform transf);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;

};

#endif // HAND_H
