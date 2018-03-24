#ifndef CARD_H
#define CARD_H

#include <SFML\Graphics.hpp>
#include "Animation.h"

class Card : public sf::Sprite
{

private:
	sf::Texture texture;
    Animation * animation;

public:
	Card();
	Card(sf::Vector2f position);
	~Card();

    void setAnimation(Animation * anim);
    void clearAnimation();
    void update(float dt);
    bool mouseInside(sf::Vector2i mouse_position);

};

#endif
