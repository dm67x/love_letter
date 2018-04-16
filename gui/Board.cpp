#include "Board.h"
#include <iostream>
#include <thread>
#include <unistd.h>

Board::Board(Core::Game *game, sf::FloatRect board_rect)
    : sf::Transformable(), sf::Drawable()
{
    this->game = game;
    this->board_rect = board_rect;

    sf::Vector2f deck_position;
    deck_position.x = board_rect.left + board_rect.width / 2.0f;
    deck_position.y = board_rect.top + board_rect.height / 2.0f;
    deck = new Deck(game->getDeck(), deck_position);

    // Players zones
    std::vector<Core::Player *> players = game->getPlayers();
    Core::Player * current = game->getCurrentPlayer();

    sf::FloatRect zone_bounds;
    zone_bounds.top = board_rect.top + (board_rect.height * 3) / 4.0f;
    zone_bounds.left = board_rect.left + board_rect.width / 4.0f;
    zone_bounds.width = board_rect.width / 2.0f;
    zone_bounds.height = board_rect.height / 4.0f;

    PlayerZone * zone;

    unsigned int i = 0, y = 0;
    for (; i < players.size(); i++)
    {
        zone = new PlayerZone(players[i], zone_bounds);

        if (current == players[i]) {
            // BOTTOM
            zone_transforms[i] = sf::Transform::Identity;
            current_zone = i;
        } else {
            switch (y) {
            // TOP
            case 0:
                zone_transforms[i].rotate(180.0f, sf::Vector2f(board_rect.left + board_rect.width / 2.0f,
                                                           board_rect.top + board_rect.height / 2.0f));
                break;

            // RIGHT
            case 1:
                zone_transforms[i].translate(sf::Vector2f(zone_bounds.top / 2.0f, 0.0f));
                zone_transforms[i].rotate(270.0f, sf::Vector2f(board_rect.left + board_rect.width / 2.0f,
                                                           board_rect.top + board_rect.height / 2.0f));
                break;

            // LEFT
            case 2:
                zone_transforms[i].translate(sf::Vector2f(-zone_bounds.top / 2.0f, 0.0f));
                zone_transforms[i].rotate(90.0f, sf::Vector2f(board_rect.left + board_rect.width / 2.0f,
                                                           board_rect.top + board_rect.height / 2.0f));
                break;
            }
            y++;
        }

        zones.push_back(zone);
        zones.back()->getHand()->onPlayed(played);
    }

    current_player_zone = zones[current_zone];

    // Give card to current player (initialization)
    deck->pickCard();
    current_player_zone->getHand()->addCard(new Card(current->pickCard()));
    current_player_zone->getHand()->reveal();
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

void Board::target_func()
{
    std::cout << "Target" << std::endl;
    sleep(2);
}

void Board::guess_func()
{
    std::cout << "Guess" << std::endl;
    sleep(2);
}

void Board::played(int index, Core::Card *card)
{
    if (card->needTarget()) {
        std::thread target_thread(target_func);
        target_thread.join();
    }

    if (card->needGuess()) {
        std::thread guess_thread(guess_func);
        guess_thread.join();
    }

    std::cout << card->getName() << std::endl;
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
    //setRotation(90.0f);
}

void Board::update(float dt)
{
    for (std::vector<PlayerZone *>::iterator it = zones.begin();
         it != zones.end(); it++) {
        (*it)->update(dt);
    }
}

void Board::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(*deck);
    for (int i = 0; i < zones.size(); i++) {
        target.draw(*zones[i], states.transform * zone_transforms[i]);
    }
}
