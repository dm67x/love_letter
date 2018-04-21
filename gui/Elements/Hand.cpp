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

    selected_card = -1;

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
    Core::Card * c1 = player->getCard();
    Core::Card * c2 = player->getCard(1);
    Card * card;

    if (cards[0] && c1 && c1->getValue() != cards[0]->getCard()->getValue()) {
        card = new Card(c1);
        card->setScale(0.5f, 0.5f);
        card->setPosition(bounds.left, bounds.top + bounds.height);
        cards[0] = card;
    }

    if (cards[1] && c2 && c2->getValue() != cards[1]->getCard()->getValue()) {
        card = new Card(c2);
        card->setScale(0.5f, 0.5f);
        card->setPosition(bounds.left + bounds.width, bounds.top + bounds.height);
        cards[1] = card;
    } else if (c2 == NULL) {
        cards[1] = NULL;
    }
}

void Hand::playing(FUNC function, Screen * elem)
{
    this->function = function;
    this->elem = elem;
}

void Hand::input(sf::Event evt, sf::Transform transf)
{
    for (int i = 0; i < 2; i++)
    {
        Card * card = cards[i];
        if (card && card->getCard()->isPlayable()) {
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
                    selected_card = i;
                }
            }
        }
    }
}

void Hand::update(float dt, sf::Transform transf)
{
    if (selected_card != -1) {
        selected_card = (elem->*function)(selected_card, player->getCard(selected_card));
    }

    updateCards();

    for (int i = 0; i < 2; i++)
    {
        Card * card = cards[i];
        if (card && card->getCard()->isPlayable()) {
            sf::Transform transform = transf * getTransform();
            sf::Vector2f card_pos = card->getPosition();
            sf::Vector2f card_dim = card->getDimensions();
            sf::FloatRect card_bounds = transform.transformRect(
                sf::FloatRect(card_pos.x - card_dim.x / 2.0f,
                              card_pos.y - card_dim.y / 2.0f,
                              card_dim.x, card_dim.y));
            sf::Vector2f mpos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(*MainWindow::getInstance()->getWindow()));

            if (selected_card == i) {
                card->setHover(true);
            } else {
                if (card_bounds.contains(mpos)) {
                    card->setHover(true);
                } else {
                    card->setHover(false);
                }
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
