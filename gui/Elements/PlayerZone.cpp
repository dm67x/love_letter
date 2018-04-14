#include "PlayerZone.h"
#include "MainWindow.h"

PlayerZone::PlayerZone(Core::Player *player, enum ZONES zone)
    : sf::Transformable(), sf::Drawable()
{
    this->zone = zone;
    this->player = player;

    // Position calculate through zone and window
    rotate = 0.0f;
    sf::Vector2u window_size = MainWindow::getInstance()->getSize();
    switch (zone) {
    case BOTTOM:
        position = sf::Vector2f(window_size.x / 2.0f, window_size.y);
        rotate = 0.0f;
        break;

    case TOP:
        position = sf::Vector2f(window_size.x / 2.0f, 0.0f);
        rotate = 180.0f;
        break;

    case LEFT:
        position = sf::Vector2f(0.0f, window_size.y / 2.0f);
        rotate = 90.0f;
        break;

    case RIGHT:
        position = sf::Vector2f(window_size.x, window_size.y / 2.0f);
        rotate = 270.0f;
        break;
    }

    // For hand cards
    hand_transform.translate(position);
    hand_transform.rotate(rotate);

    // For label (name)
    name_transform.translate(position);
    name_transform.rotate(rotate);
    name_transform.translate(-position);

    hand = new Hand();
    hand->addCard(new Card(player->getCard()));

    font.loadFromFile("data/Another day in Paradise.ttf");

    player_name.setFont(font);
    player_name.setString(player->getName());
    player_name.setCharacterSize(20);
    sf::FloatRect player_name_rect = player_name.getLocalBounds();
    player_name.setOrigin(player_name_rect.left + player_name_rect.width / 2.0f,
                          player_name_rect.top + player_name_rect.height / 2.0f);
    player_name.setPosition(position - sf::Vector2f(200.0f, 20.0f));

    // Score configuration
    score_number.setFont(font);
    score_number.setString(std::to_string(player->getPoints()));
    score_number.setCharacterSize(20);
    sf::FloatRect score_number_rect = score_number.getLocalBounds();
    score_number.setOrigin(score_number_rect.left + score_number_rect.width / 2.0f,
                           score_number_rect.top + score_number_rect.height / 2.0f);
    score_number.setPosition(position - sf::Vector2f(-200.0f, 20.0f));
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
    target.draw(*hand, states.transform * hand_transform);
    target.draw(player_name, states.transform * name_transform);
    target.draw(score_number, states.transform * name_transform);
}
