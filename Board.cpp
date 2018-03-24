#include "Board.h"
#include "Animations/PickAnimation.h"
#include "Animations/HoverAnimation.h"

Board * Board::instance = NULL;

Board * Board::getInstance()
{
    if (instance == NULL)
        instance = new Board();
    return instance;
}

Board::Board()
{
    for (int i = 0; i < 16; i++) {
        Card * c = new Card(sf::Vector2f(400, 300));
        c->setScale(0.25f, 0.25f);
        deck.push_back(c);
    }
}

Board::~Board()
{
}

void Board::update(sf::RenderWindow & window, float dt)
{
    Card * c = deck.front();
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) &&
            c->mouseInside(sf::Mouse::getPosition(window))) {
        c->setAnimation(new PickAnimation(c, sf::Vector2f(0, 600)));
    }

    // If pick animation end
    /*if (c->getAnimation() && c->getAnimation()->getState() == STOP) {
        if (c->mouseInside(sf::Mouse::getPosition(window))) {
            if (!c->getAnimation()->isRevertEnabled())
                c->setAnimation(new HoverAnimation(c));
        } else if (c->getAnimation()->isRevertEnabled()) {
            c->getAnimation()->setState(REVERT);
        }
    }*/

    c->update(dt);
}

void Board::draw(sf::RenderWindow &window)
{
    window.draw(*deck.front());
}

void Board::clear()
{

}


