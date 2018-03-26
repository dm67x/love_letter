#include "Card.h"

sf::Texture * Card::dos_card = new sf::Texture();

Card::Card()
	: Card(sf::Vector2f(0, 0))
{
}

Card::Card(sf::Vector2f position)
	: Sprite()
{
    animation = NULL;
    dos_card->loadFromFile("data/custom_dos.jpg");
    dos_card->setSmooth(true);

    texture.loadFromFile("data/guard.jpg");
	texture.setSmooth(true);

    setTexture(*dos_card);
	setPosition(position);
	setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);

    show = false;
}

Card::~Card()
{
    delete animation;
}

void Card::setAnimation(Animation * anim)
{
    animation = anim;
}

Animation * Card::getAnimation()
{
    return animation;
}

void Card::clearAnimation()
{
    animation = NULL;
}

void Card::reveal()
{
    show = true;
}

void Card::mask()
{
    show = false;
}

void Card::update(float dt)
{
    if (animation) {
        if (animation->getState() == NOT_LAUNCH)
            animation->start();
        animation->update(dt);
    }

    if (show)
        setTexture(texture);
    else
        setTexture(*dos_card);
}
