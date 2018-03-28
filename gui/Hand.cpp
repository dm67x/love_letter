#include "Hand.h"
#include "Utils.h"
#include "Animations/ScaleAnimation.h"

Hand::Hand(sf::Vector2f position)
    : Hand(position, 0)
{
}

Hand::Hand(sf::Vector2f position, float rotation)
{
    this->rotation = rotation;
    this->position = position;

    cards[0] = NULL;
    cards[1] = NULL;

    card_transforms[0].rotate(rotation, position);
    card_transforms[0].translate(-80, 0);

    card_transforms[1].rotate(rotation, position);
    card_transforms[1].translate(80, 0);
}

Hand::~Hand()
{
}

void Hand::addCard(Card * c)
{
    if (cards[0])
        cards[1] = c;
    else
        cards[0] = c;
}

sf::Vector2f Hand::getPosition()
{
    return position;
}

Card * Hand::getCard(unsigned short index)
{
    return cards[index];
}

void Hand::update(sf::RenderWindow &window, float dt)
{
    if (cards[0]) {
        sf::FloatRect rect;
        sf::Vector2f position = cards[0]->getPosition(), scale = cards[0]->getScale();
        sf::Vector2u size = cards[0]->getTexture()->getSize();

        rect.top = position.y - (size.y / 2) * scale.y;
        rect.left = position.x - (size.x / 2) * scale.x;
        rect.width = position.x + (size.x / 2) * scale.x;
        rect.height = position.y + (size.y / 2) * scale.y;

        if (Utils::mouseInside(card_transforms[0].transformRect(rect), sf::Mouse::getPosition(window)))
            cards[0]->setAnimation(new ScaleAnimation(cards[0], sf::Vector2f(1.0f, 1.0f)));
        else
            cards[0]->setAnimation(new ScaleAnimation(cards[0], sf::Vector2f(0.5f, 0.5f)));
        cards[0]->update(dt);
    }

    if (cards[1]) {
        sf::FloatRect rect;
        sf::Vector2f position = cards[1]->getPosition(), scale = cards[1]->getScale();
        sf::Vector2u size = cards[1]->getTexture()->getSize();

        rect.top = position.y - (size.y / 2) * scale.y;
        rect.left = position.x - (size.x / 2) * scale.x;
        rect.width = position.x + (size.x / 2) * scale.x;
        rect.height = position.y + (size.y / 2) * scale.y;

        if (Utils::mouseInside(card_transforms[1].transformRect(rect), sf::Mouse::getPosition(window)))
            cards[1]->setAnimation(new ScaleAnimation(cards[1], sf::Vector2f(0.75f, 0.75f)));
        else
            cards[1]->setAnimation(new ScaleAnimation(cards[1], sf::Vector2f(0.5f, 0.5f)));
        cards[1]->update(dt);
    }
}

void Hand::draw(sf::RenderWindow &window)
{
    if (cards[0])
        window.draw(*cards[0], card_transforms[0]);
    if (cards[1])
        window.draw(*cards[1], card_transforms[1]);
}
