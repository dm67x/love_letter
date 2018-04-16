#ifndef HAND_H
#define HAND_H

#include "Card.h"
#include "core/player.h"
#include "DebugBounds.h"

class Hand : public sf::Transformable, public sf::Drawable
{

private:
    Card * cards[2];
    sf::FloatRect bounds;
    Core::Player * player;
    bool target_selected;
    bool guessed;
    void (*played_function)(int, Core::Card *);

    // Debug
    DebugBounds * debug;

public:
    Hand(Core::Player * player, sf::FloatRect bounds);
    ~Hand();

    void addCard(Card * card);
    void reveal();
    void mask();
    void onPlayed(void (*played_function)(int, Core::Card *));

    void update(float dt);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;

};

#endif // HAND_H
