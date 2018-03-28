#ifndef CARD_H
#define CARD_H

#include <SFML/Graphics.hpp>
#include "core/card.h"
#include "Animation.h"

class Card : public sf::Sprite
{

private:
	sf::Texture texture;
    Animation * animation;
    static sf::Texture * dos_card;
    bool show;
    Core::Card * card;

public:
    Card(Core::Card * card);
    Card(Core::Card * card, sf::Vector2f position);
	~Card();

    void setAnimation(Animation * anim);
    void clearAnimation();
    Animation * getAnimation();
    void update(float dt);
    void reveal();
    void mask();

};

#endif
