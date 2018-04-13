#include "Board.h"

Board::Board(Core::Game *game, sf::Vector2f position)
{
    this->game = game;
    this->position = position;
    deck = new Deck(game->getDeck(), position);

    // Players zones
    std::vector<Core::Player *> players = game->getPlayers();
    Core::Player * current = game->getCurrentPlayer();

    unsigned int i = 0, y = 0;
    for (; i < players.size(); i++)
    {
        if (current == players[i]) {
            zones.push_back(new PlayerZone(players[i], BOTTOM));
            current_zone = i;
        } else {
            switch (y) {
            case 0:
                zones.push_back(new PlayerZone(players[i], RIGHT));
                break;

            case 1:
                zones.push_back(new PlayerZone(players[i], TOP));
                break;

            case 2:
                zones.push_back(new PlayerZone(players[i], LEFT));
                break;
            }
            y++;
        }
    }

    current_player_zone = zones[current_zone];

    // Give card to current player (initialization)
    deck->pickCard();
    current_player_zone->getHand()->addCard(
                new Card(current->pickCard()));
    current_player_zone->getHand()->reveal();

    transform = sf::Transform::Identity;
}

Board::~Board()
{
    for (std::vector<PlayerZone *>::iterator it = zones.begin();
         it != zones.end(); it++) {
        delete *it;
    }

    delete deck;
}

void Board::clear()
{

}

void Board::nextTurn()
{
    unsigned int nb_players = game->getPlayers().size();
    current_player_zone->getHand()->mask();
    current_zone = (current_zone + 1) % nb_players;
    current_player_zone = zones[current_zone];

    // Next player
    deck->pickCard();
    game->startTurn();
    current_player_zone->getHand()->addCard(
                new Card(game->getCurrentPlayer()->pickCard()));
    current_player_zone->getHand()->reveal();

    // Rotate board
    //transform.rotate(90.0f, position);
}

void Board::update(float dt)
{
    for (std::vector<PlayerZone *>::iterator it = zones.begin();
         it != zones.end(); it++) {
        (*it)->update(dt);
    }
}

void Board::draw(sf::RenderWindow &window)
{
    deck->draw(window);
    for (std::vector<PlayerZone *>::iterator it = zones.begin();
         it != zones.end(); it++) {
        window.draw(*(*it), transform);
    }
}
