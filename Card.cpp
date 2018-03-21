#include "Card.h"

Card::Card()
	: Card(sf::Vector2f(0, 0))
{
}

Card::Card(sf::Vector2f position)
	: Sprite()
{
	animation = NULL;
	texture.loadFromFile("../data/guard.jpg");
	texture.setSmooth(true);
	this->position = position;
	animation_start = false;

	setTexture(texture);
	setPosition(position);
	setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
}

Card::~Card()
{
	delete animation;
}

void Card::setAnimation(Animation * anim)
{
	animation = anim;
}

void Card::clearAnimation()
{
	animation = NULL;
	animation_start = false;
}

void Card::update(float dt)
{
	if (!animation_start && animation) {
		animation_start = true;
		animation->start();
	}

	animation->update(dt);
}
