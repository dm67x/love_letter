#ifndef CARD_H
#define CARD_H

#include <SFML/Graphics.hpp>
#include "Animation.h"

class Card : public sf::Sprite
{

private:
	sf::Texture texture;
    Animation * animation;
    static sf::Texture * dos_card;
    bool show;

public:
	Card();
	Card(sf::Vector2f position);
	~Card();

    void setAnimation(Animation * anim);
    void clearAnimation();
    Animation * getAnimation();
    void update(float dt);
    void reveal();
    void mask();

};

#endif
