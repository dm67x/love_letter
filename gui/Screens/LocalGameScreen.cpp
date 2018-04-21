#include "LocalGameScreen.h"
#include "SinglePlayerMenuScreen.h"
#include "ScreenManager.h"
#include "MainWindow.h"

int LocalGameScreen::playing_card(int index, Core::Card *card)
{
    bool target_selected = false, guessed = false;
    // Target
    if (!target_selected && card->needTarget()) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sf::Vector2i mpos = sf::Mouse::getPosition(*MainWindow::getInstance()->getWindow());
            std::vector<PlayerZone *> zones = board->getZones();
            for (unsigned int i = 0; i < zones.size(); i++) {
                sf::Transform transf = zones[i]->getTransform();
                sf::FloatRect rect = transf.transformRect(zones[i]->getBounds());
                if (rect.contains(static_cast<sf::Vector2f>(mpos))) {
                    if (zones[i] == current_zone && !card->targetHimself()) break;
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
    if ((card->needGuess() && guessed && target_selected) ||
            (card->needTarget() && target_selected) || (!card->needTarget())) {
        current_zone->getPlayer()->discard(index);
        game->update();
        if (!game->roundOver()) {
            nextPlayerTurn();
            ScreenManager::getInstance()->switchTo("nextplayermessage");
        }
        return -1;
    }
    return index;
}

void LocalGameScreen::nextPlayerTurn()
{
    // rotate board
    board->nextTurn();

    // Next player
    current_zone->getHand()->mask();
    board->getDeck()->pickCard();
    Core::Player * p = game->startTurn();
    current_zone = getCurrentZone(p);
    current_zone->getHand()->addCard(new Card(p->pickCard()));
    current_zone->getHand()->reveal();
}

PlayerZone * LocalGameScreen::getCurrentZone(Core::Player * p)
{
    PlayerZone * zone = NULL;
    std::vector<PlayerZone *> zones = board->getZones();
    for (auto it = zones.begin(); it != zones.end(); it++) {
        if (p == (*it)->getPlayer()) {
            zone = (*it);
            break;
        }
    }
    return zone;
}

LocalGameScreen::LocalGameScreen()
    : Screen("localgame")
{
    game = NULL;
    board = NULL;
    target_player = NULL;
}

LocalGameScreen::~LocalGameScreen()
{
    if (game)
        delete game;

    if (board)
        delete board;
}

void LocalGameScreen::loadContent()
{
    Screen::loadContent();

    // Init game
    game = new Core::Game(SingleplayermenuScreen::players_number);
    game->startRound();

    // Board
    sf::Vector2u size = getSize();
    board = new Board(game, sf::FloatRect(0, 0, size.x, size.y));

    // Player zones
    std::vector<Core::Player *> players = game->getPlayers();
    Core::Player * current = game->startTurn();

    unsigned int i = 0, y = 0;
    for (; i < players.size(); i++)
    {
        if (current != players[i]) {
            switch (y) {
            // TOP
            case 0:
                board->addPlayer(players[i], TOP);
                break;

            // RIGHT
            case 1:
                board->addPlayer(players[i], RIGHT);
                break;

            // LEFT
            case 2:
                board->addPlayer(players[i], LEFT);
                break;
            }
            y++;
        } else {
            board->addPlayer(players[i], BOTTOM);
        }

        board->getZones().back()
                ->getHand()
                ->playing(&Screen::playing_card, static_cast<Screen *>(this));
    }

    current_zone = getCurrentZone(current);

    // Give card to current player (initialization)
    board->getDeck()->pickCard();
    current_zone->getHand()->addCard(new Card(current->pickCard()));
}

void LocalGameScreen::unloadContent()
{
    Screen::unloadContent();

    if (game) delete game;
    if (board) delete board;
}

void LocalGameScreen::input(sf::Event evt)
{
    board->input(evt);
    current_zone->input(evt);

    if (evt.type == sf::Event::KeyPressed && evt.key.code == sf::Keyboard::T
            && game->getDeck()->getCards().size() > 0)
        board->nextTurn();
}

void LocalGameScreen::update(float dt)
{
    game->update();
    board->update(dt);

    // Update every time hand of current player
    current_zone->update(dt);
    current_zone->getHand()->reveal();

    if (game->roundOver()) {
        game->startRound();
        board->resetDeck();
        Core::Player * current = game->startTurn();
        current_zone = board->getZones()[game->getCurrentWinner()];
        current_zone->getHand()->addCard(new Card(current->pickCard()));
        // set winner screen and restart round
    }

    if (game->gameOver()) {
        unloadContent();
        ScreenManager::getInstance()->switchTo("menu");
    }
}

void LocalGameScreen::draw(sf::RenderWindow &window)
{
    window.clear();
    window.draw(*board);
}
