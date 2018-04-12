#ifndef HAND_H
#define HAND_H

#include "Card.h"

class Hand : public sf::Transformable, public sf::Drawable
{

private:
    sf::Vector2f position;
    Card * cards[2];

public:
    Hand();
    ~Hand();

    void addCard(Card * card);
    void update(float dt);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;

};

#endif // HAND_H
