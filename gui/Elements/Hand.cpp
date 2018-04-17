#include "Hand.h"
#include "MainWindow.h"
#include "Animations/MoveAnimation.h"
#include "ScreenManager.h"
#include <iostream>

Hand::Hand(Core::Player * player, sf::FloatRect bounds)
    : sf::Transformable(), sf::Drawable()
{
    this->player = player;
    this->bounds = bounds;

    played_function = NULL;

    cards[0] = NULL;
    cards[1] = NULL;

    // Debug
    debug = new DebugBounds(bounds);
}

Hand::~Hand()
{
    if (cards[0])
        delete cards[0];

    if (cards[1])
        delete cards[1];
}

void Hand::addCard(Card *card)
{
    card->setScale(0.5f, 0.5f);
    if (!cards[0]) {
        card->setPosition(bounds.left, bounds.top + bounds.height);
        cards[0] = card;
    } else {
        card->setPosition(bounds.left + bounds.width, bounds.top + bounds.height);
        cards[1] = card;
    }
}

void Hand::reveal()
{
    if (cards[0])
        cards[0]->reveal();
    if (cards[1])
        cards[1]->reveal();
}

void Hand::mask()
{
    if (cards[0])
        cards[0]->mask();
    if (cards[1])
        cards[1]->mask();
}

void Hand::onPlayed(void (*played_function)(int, Core::Card *))
{
    this->played_function = played_function;
}

void Hand::update(float dt)
{
    sf::Vector2i mouse_pos = sf::Mouse::getPosition(*MainWindow::getInstance());

    /*for (int i = 0; i < 2; i++)
    {
        Card * card = cards[i];
        if (card) {
            sf::Vector2f card_pos = card->getPosition();
            sf::Vector2f card_dim = card->getDimensions();
            sf::FloatRect card_bounds;
            card_bounds.top = card_pos.y - card_dim.y / 2.0f;
            card_bounds.left = card_pos.x - card_dim.x / 2.0f;
            card_bounds.width = card_dim.x;
            card_bounds.height = card_dim.y;

            if (card_bounds.contains(mouse_pos.x, mouse_pos.y)) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    if (!card->getAnimation()) {
                        card->setAnimation(new MoveAnimation(card->getSprite(),
                                               sf::Vector2f(0.0f, -card_dim.y * 2.0f)));
                    }

                    played_function(i, player->getCard(i));
                }
            }

            card->update(dt);
        }
    }*/
}

void Hand::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(*debug, states);

    if (cards[0])
        target.draw(*cards[0], states);

    if (cards[1])
        target.draw(*cards[1], states);
}
