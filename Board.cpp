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
    deck = new Deck(sf::Vector2f(400, 300));
    hands.push_back(new Hand(sf::Vector2f(400, 600)));
    hands.push_back(new Hand(sf::Vector2f(800, 300), -90));
    hands.push_back(new Hand(sf::Vector2f(400, 0), 180));
    hands.push_back(new Hand(sf::Vector2f(0, 300), 90));

    current_player = 0;

    for (int i = 0; i < 4; i++) {
        Card * c = deck->pickCard();
        c->setPosition(hands[i]->getPosition());
        c->setScale(0.5f, 0.5f);
        hands[i]->addCard(c);
    }

    for (int i = 0; i < 2; i++) {
        Card * c = hands[current_player]->getCard(i);
        if (c)
            c->reveal();
    }
}

Board::~Board()
{
    delete deck;
}

void Board::update(sf::RenderWindow & window, float dt)
{
    Card * c = deck->top();
    if (c) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
                c->mouseInside(sf::Mouse::getPosition(window)) && !c->getAnimation()) {
            c->setAnimation(new PickAnimation(c, hands[0]->getPosition()));
            c->reveal();
        }
        c->update(dt);
        if (c->getAnimation() && c->getAnimation()->getState() == STOP) {
            deck->pickCard();
            hands[0]->addCard(c);
        }
    }

    for (int i = 0; i < 4; i++) {
        hands[i]->update(window, dt);
    }
}

void Board::draw(sf::RenderWindow &window)
{
    deck->draw(window);
    for (std::vector<Hand *>::iterator it = hands.begin(); it != hands.end(); it++)
        (*it)->draw(window);
}

void Board::clear()
{
}


