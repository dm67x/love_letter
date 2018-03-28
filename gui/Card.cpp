#include "Card.h"

sf::Texture * Card::dos_card = new sf::Texture();

Card::Card(Core::Card * card)
    : Card(card, sf::Vector2f(0, 0))
{
}

Card::Card(Core::Card * card, sf::Vector2f position)
    : Sprite()
{
    this->card = card;
    animation = NULL;
    dos_card->loadFromFile("data/custom_dos.jpg");
    dos_card->setSmooth(true);

    switch (card->getValue()) {
    case 1:
        texture.loadFromFile("data/guard.jpg");
        break;

    default:
        texture.loadFromFile("data/custom_dos.jpg");
        break;
    }
	texture.setSmooth(true);

    setTexture(*dos_card);
	setPosition(position);
	setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);

    show = false;
}

Card::~Card()
{
    delete animation;
    delete card;
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
