#pragma once

#include <SFML\Graphics.hpp>
#include "Animation.h"

class Card : public sf::Sprite
{

private:
	sf::Texture texture;
	Animation * animation;
	sf::Vector2f position;
	bool animation_start;

public:
	Card();
	Card(sf::Vector2f position);
	~Card();

	void setAnimation(Animation * anim);
	void clearAnimation();
	void update(float dt);

};