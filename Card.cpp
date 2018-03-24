#include "Card.h"

Card::Card()
	: Card(sf::Vector2f(0, 0))
{
}

Card::Card(sf::Vector2f position)
	: Sprite()
{
    animation = NULL;
    texture.loadFromFile("data/guard.jpg");
	texture.setSmooth(true);

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
}

void Card::update(float dt)
{
    if (animation) {
        if (animation->getState() == NOT_LAUNCH)
            animation->start();
        animation->update(dt);
    }
}

bool Card::mouseInside(sf::Vector2i mouse_position)
{
    sf::Vector2f position = getPosition();
    sf::Vector2u textureSize = texture.getSize();

    float top = position.y - (textureSize.y / 2) * getScale().y;
    float bottom = position.y + (textureSize.y / 2) * getScale().y;
    float left = position.x - (textureSize.x / 2) * getScale().x;
    float right = position.x + (textureSize.x / 2) * getScale().x;

    return mouse_position.x >= left && mouse_position.x <= right &&
            mouse_position.y >= top && mouse_position.y <= bottom;
}
