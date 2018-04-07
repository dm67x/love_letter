#include "PlayerZone.h"

PlayerZone::PlayerZone(Core::Player *player, sf::Vector2f position)
{
    this->player = player;
    this->position = position;

    hand = new Hand(position);
    hand->addCard(new Card(player->getCard()));

    font.loadFromFile("data/Another day in Paradise.ttf");

    player_name.setFont(font);
    player_name.setString(player->getName());
    player_name.setCharacterSize(20);
    sf::FloatRect player_name_rect = player_name.getLocalBounds();
    player_name.setOrigin(player_name_rect.left + player_name_rect.width / 2.0f,
                          player_name_rect.top + player_name_rect.height / 2.0f);
    player_name.setPosition(position - sf::Vector2f(200.0f, 0.0f));
}

PlayerZone::~PlayerZone()
{
    delete hand;
    delete player;
}

void PlayerZone::update(float dt)
{
    hand->update(dt);
}

void PlayerZone::draw(sf::RenderWindow &window)
{
    hand->draw(window);
    window.draw(player_name);
}
