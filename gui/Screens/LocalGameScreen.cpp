#include "LocalGameScreen.h"
#include "SinglePlayerMenuScreen.h"
#include "ScreenManager.h"
#include "MainWindow.h"
#include "core/cards/all.h"

#include <iostream>

int LocalGameScreen::playing_card(int index, Core::Card *card)
{
    std::vector<Core::Player *> players = game->getPlayers();
    unsigned int protected_players = 0;
    for (auto it = players.begin(); it != players.end(); it++) {
        if (*it != current_zone->getPlayer() && (*it)->hasShield()) {
            protected_players++;
        }
    }

    std::cout << card->getName() << std::endl;

    // Handmaid or prince can target himself
    if (card->getValue() == 5 || card->getValue() == 4)
        protected_players = 0; // deactivate protection

    if (protected_players != players.size() - 1) {
        // Target
        if ((state == NORMAL || state == TARGET_START) && card->needTarget()) {
            state = TARGET_START;
            target_func(card);
        }

        // Guess
        if ((state == TARGET_END || state == GUESS_START) && card->needGuess()) {
            state = GUESS_START;
            guess_func(card);
        }

        if (state == NORMAL || (!card->needGuess() && state == TARGET_END)) {
            current_zone->getPlayer()->discard(index);
            state = NORMAL;
            game->update();
            if (!game->roundOver()) {
                nextPlayerTurn();
                ScreenManager::getInstance()->switchTo("nextplayermessage");
            }
            return -1;
        }
    } else {
        current_zone->getPlayer()->discardWithoutEffect(index);
        state = NORMAL;
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
    current_zone->setMask(true);
    board->getDeck()->pickCard();
    Core::Player * p = game->startTurn();
    current_zone = getCurrentZone(p);
    current_zone->getHand()->addCard(new Card(p->pickCard()));
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

void LocalGameScreen::target_func(Core::Card * card)
{
    bool target_selected = false;

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        std::cout << "clicked" << std::endl;
        sf::Vector2i mpos = sf::Mouse::getPosition(*MainWindow::getInstance()->getWindow());
        std::vector<PlayerZone *> zones = board->getZones();
        for (unsigned int i = 0; i < zones.size(); i++) {
            sf::Transform transf = board->getTransform() * zones[i]->getTransform();
            sf::FloatRect rect = transf.transformRect(zones[i]->getBounds());
            if (rect.contains(static_cast<sf::Vector2f>(mpos))) {
                if (zones[i] == current_zone && !card->targetHimself()) break;
                if (zones[i]->getPlayer()->hasShield()) break;
                target_player = zones[i]->getPlayer();
                target_selected = true;
                if (card->getValue() == 2) {
                    // Priest
                    zones[i]->setMask(false);
                }
                break;
            }
        }
    }

    // Find index of target
    if (target_selected) {
        auto players = game->getPlayers();
        for (unsigned int i = 0; i < players.size(); i++) {
            if (players[i] == target_player) {
                game->pickTarget(i);
                state = TARGET_END;
                break;
            }
        }
        target_player = NULL;
    }
}

void LocalGameScreen::guess_func(Core::Card *card)
{
    bool guessed = false;
    guess_dialog->open();

    // Get mouse click on card
    std::string name = guess_dialog->getClickedCardName();
    if (name != "") {
        game->guessCard(name);
        guessed = true;
    }

    if (guessed) {
        guess_dialog->close();
        state = NORMAL;
    }
}

LocalGameScreen::LocalGameScreen()
    : Screen("localgame")
{
    game = NULL;
    board = NULL;
    target_player = NULL;
    state = NORMAL;
}

LocalGameScreen::~LocalGameScreen()
{
    if (game)
        delete game;

    if (board)
        delete board;

    if (guess_dialog)
        delete guess_dialog;
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

    if (players.size() == 2) {
        if (current == players[0]) {
            board->addPlayer(players[0], BOTTOM);
            board->addPlayer(players[1], TOP);
        } else {
            board->addPlayer(players[0], TOP);
            board->addPlayer(players[1], BOTTOM);
        }
    } else if (players.size() == 3) {
        if (current == players[0]) {
            board->addPlayer(players[0], BOTTOM);
            board->addPlayer(players[1], RIGHT);
            board->addPlayer(players[2], TOP);
        } else if (current == players[1]) {
            board->addPlayer(players[0], TOP);
            board->addPlayer(players[1], BOTTOM);
            board->addPlayer(players[2], RIGHT);
        } else {
            board->addPlayer(players[0], RIGHT);
            board->addPlayer(players[1], TOP);
            board->addPlayer(players[2], BOTTOM);
        }
    } else { // 4 players
        if (current == players[0]) {
            board->addPlayer(players[0], BOTTOM);
            board->addPlayer(players[1], RIGHT);
            board->addPlayer(players[2], TOP);
            board->addPlayer(players[3], LEFT);
        } else if (current == players[1]) {
            board->addPlayer(players[0], LEFT);
            board->addPlayer(players[1], BOTTOM);
            board->addPlayer(players[2], RIGHT);
            board->addPlayer(players[3], TOP);
        } else if (current == players[2]) {
            board->addPlayer(players[0], TOP);
            board->addPlayer(players[1], LEFT);
            board->addPlayer(players[2], BOTTOM);
            board->addPlayer(players[3], RIGHT);
        } else {
            board->addPlayer(players[0], RIGHT);
            board->addPlayer(players[1], TOP);
            board->addPlayer(players[2], LEFT);
            board->addPlayer(players[3], BOTTOM);
        }
    }

    std::vector<PlayerZone *> zones = board->getZones();
    for (auto it = zones.begin(); it != zones.end(); it++) {
        (*it)->getHand()->playing(&Screen::playing_card, static_cast<Screen *>(this));
    }

    current_zone = getCurrentZone(current);

    // Give card to current player (initialization)
    board->getDeck()->pickCard();
    current_zone->getHand()->addCard(new Card(current->pickCard()));

    // Guessed cards
    guess_dialog = new GuessDialog(sf::Vector2f(600, 300));
    guess_dialog->move(size.x / 2.0f, size.y / 2.0f);
}

void LocalGameScreen::unloadContent()
{
    Screen::unloadContent();

    if (game) delete game;
    if (board) delete board;
    if (guess_dialog) delete guess_dialog;
}

void LocalGameScreen::input(sf::Event evt)
{
    board->input(evt);
    current_zone->input(evt, board->getTransform());
    guess_dialog->input(evt);

    if (evt.type == sf::Event::KeyPressed && evt.key.code == sf::Keyboard::T
            && game->getDeck()->getCards().size() > 0)
        board->nextTurn();
}

void LocalGameScreen::update(float dt)
{
    game->update();
    board->update(dt);
    guess_dialog->update(dt);

    // Update every time hand of current player
    current_zone->update(dt, board->getTransform());
    current_zone->setMask(false);

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
    window.draw(*guess_dialog);
}
