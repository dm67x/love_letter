#include "PlayerZone.h"
#include "MainWindow.h"

PlayerZone::PlayerZone(Core::Player * player, sf::FloatRect bounds)
    : sf::Transformable(), sf::Drawable()
{
    this->player = player;

    // name (pos + rotation)
    font.loadFromFile("data/Another day in Paradise.ttf");

    player_name.setFont(font);
    player_name.setString(player->getName());
    player_name.setCharacterSize(20);
    sf::FloatRect player_name_rect = player_name.getLocalBounds();
    player_name.setOrigin(player_name_rect.left + player_name_rect.width / 2.0f,
                          player_name_rect.top + player_name_rect.height / 2.0f);
    player_name.move(bounds.left + bounds.width / 2.0f, bounds.top);

    // hand
    sf::FloatRect hand_rect;
    hand_rect.top = bounds.top;
    hand_rect.left = bounds.left + bounds.width / 4.0f;
    hand_rect.width = bounds.width / 2.0f;
    hand_rect.height = bounds.height;

    hand = new Hand(player, hand_rect);
    hand->addCard(new Card(player->getCard()));

    // Debug
    debug = new DebugBounds(bounds);
}

PlayerZone::~PlayerZone()
{
    if (hand)
        delete hand;
}

void PlayerZone::update(float dt)
{
    hand->update(dt);
}

void PlayerZone::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    //target.draw(*debug, states);
    target.draw(*hand, states);
    target.draw(player_name, states);
}
