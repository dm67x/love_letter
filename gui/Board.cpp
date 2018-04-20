#include "Board.h"
#include "MainWindow.h"
#include "Message.h"
#include "ScreenManager.h"

int Board::playing(int index, Core::Card *card)
{
    bool target_selected = false, guessed = false;
    // Target
    if (!target_selected && card->needTarget()) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sf::Vector2i mpos = sf::Mouse::getPosition(*MainWindow::getInstance());
            for (unsigned int i = 0; i < zones.size(); i++) {
                sf::Transform transf = zones[i]->getTransform();
                sf::FloatRect rect = transf.transformRect(zones[i]->getBounds());
                if (rect.contains(static_cast<sf::Vector2f>(mpos))) {
                    if (zones[i] == current_player_zone && !card->targetHimself()) break;
                    target_player = zones[i]->getPlayer();
                    target_selected = true;
                    break;
                }
            }
        }

        // Find index of target
        auto players = game->getPlayers();
        for (unsigned int i = 0; i < players.size(); i++) {
            if (players[i] == target_player) {
                game->pickTarget(i);
                break;
            }
        }
        target_player = NULL;
    }

    // Guess
    std::cout << "[" << index << "]" << " " << card->getName() << std::endl;

    if ((card->getValue() == 1 && target_selected && guessed) || target_selected) {
        current_player_zone->getPlayer()->discard(index);
        for (unsigned int i = 0; i < zones.size(); i++)
            zones[i]->getHand()->updateCards();
        return -1;
    }
    return index;
}

Board::Board(Core::Game *game, sf::FloatRect board_rect)
    : Object("board")
{
    this->game = game;
    this->board_rect = board_rect;
    target_player = NULL;

    sf::Vector2f deck_position;
    deck_position.x = board_rect.left + board_rect.width / 2.0f;
    deck_position.y = board_rect.top + board_rect.height / 2.0f;
    deck = new Deck(game->getDeck());
    deck->setPosition(deck_position);

    // Players zones
    std::vector<Core::Player *> players = game->getPlayers();
    Core::Player * current = game->startTurn();

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
            current_zone = i;
        } else {
            switch (y) {
            // TOP
            case 0:
                zone->rotate(180.0f);
                zone->setPosition(board_rect.left + board_rect.width / 2.0f,
                                  board_rect.top + zone_bounds.height / 2.0f);
                break;

            // RIGHT
            case 1:
                zone->rotate(270.0f);
                zone->setPosition(board_rect.left + board_rect.width - zone_bounds.height / 2.0f,
                                  board_rect.top + board_rect.height / 2.0f);
                break;

            // LEFT
            case 2:
                zone->rotate(90.0f);
                zone->setPosition(board_rect.left + zone_bounds.height / 2.0f,
                                  board_rect.top + board_rect.height / 2.0f);
                break;
            }
            y++;
        }

        zones.push_back(zone);
        zones.back()->getHand()->playing(&Board::playing, this);
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
    //rotate(90.0f);
}

void Board::input(sf::Event evt)
{
    current_player_zone->input(evt);
}

void Board::update(float dt)
{
    current_player_zone->update(dt);
}

void Board::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(*deck);
    for (unsigned int i = 0; i < zones.size(); i++)
        target.draw(*zones[i], states);
}
