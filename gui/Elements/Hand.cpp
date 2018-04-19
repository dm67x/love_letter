#include "Hand.h"
#include "MainWindow.h"
#include "Animations/MoveAnimation.h"
#include "ScreenManager.h"

Hand::Hand(Core::Player * player, sf::FloatRect bounds)
    : Object("hand")
{
    this->player = player;
    this->bounds = bounds;

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

void Hand::updateCards()
{
    if (cards[0]) {
        delete cards[0];
        cards[0] = NULL;
    }

    if (cards[1]) {
        delete cards[1];
        cards[1] = NULL;
    }

    if (player->getCard())
        addCard(new Card(player->getCard()));
}

void Hand::playing(FUNC func, Board * elem)
{
    this->function = func;
    this->elem = elem;
}

void Hand::input(sf::Event evt, sf::Transform transf)
{
    for (int i = 0; i < 2; i++)
    {
        Card * card = cards[i];
        if (card) {
            sf::Transform transform = transf * getTransform();
            sf::Vector2f card_pos = card->getPosition();
            sf::Vector2f card_dim = card->getDimensions();
            sf::FloatRect card_bounds = transform.transformRect(
                sf::FloatRect(card_pos.x - card_dim.x / 2.0f,
                              card_pos.y - card_dim.y / 2.0f,
                              card_dim.x, card_dim.y));

            if (card_bounds.contains(evt.mouseButton.x, evt.mouseButton.y)) {
                if (evt.type == sf::Event::MouseButtonReleased
                        && evt.mouseButton.button == sf::Mouse::Left) {
                    (elem->*function)(evt, i, player->getCard(i));
                }
            }
        }
    }
}

void Hand::update(float dt, sf::Transform transf)
{
    for (int i = 0; i < 2; i++)
    {
        Card * card = cards[i];
        if (card) {
            sf::Transform transform = transf * getTransform();
            sf::Vector2f card_pos = card->getPosition();
            sf::Vector2f card_dim = card->getDimensions();
            sf::FloatRect card_bounds = transform.transformRect(
                sf::FloatRect(card_pos.x - card_dim.x / 2.0f,
                              card_pos.y - card_dim.y / 2.0f,
                              card_dim.x, card_dim.y));
            sf::Vector2f mpos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(*MainWindow::getInstance()));

            if (card_bounds.contains(mpos)) {
                card->setHover(true);
            } else {
                card->setHover(false);
            }

            card->update(dt);
        }
    }
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
