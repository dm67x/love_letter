#include "LocalAIGameScreen.h"
#include "SinglePlayerMenuScreen.h"
#include "ScreenManager.h"
#include "MainWindow.h"
#include "SingleplayerModeChoiceScreen.h"

#include <iostream>

LocalAIGameScreen::LocalAIGameScreen()
    : Screen("localaigame")
{
    game = NULL;
    board = NULL;
}

LocalAIGameScreen::~LocalAIGameScreen()
{
    if (game)
        delete game;

    if (board)
        delete board;
}

int LocalAIGameScreen::playing_card(int index, Core::Card * card)
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
        std::cout << "Human played " + card->getName() << std::endl;
        current_zone->getPlayer()->discard(index);
        game->update();
        if (!game->roundOver()) {
            std::cout << "AI playing..." << std::endl;
            nextPlayerTurn();
        }
        return -1;
    }
    return index;
}

void LocalAIGameScreen::playing_card_AI(int index, Core::Card * card)
{
    bool target_selected = true, guessed = false;

    // Guess
    if ((card->needGuess() && guessed && target_selected) ||
            (card->needTarget() && target_selected) || (!card->needTarget())) {
        std::cout << "AI played " + card->getName() << std::endl;
        current_zone->getPlayer()->discard(index);
        game->update();
        if (!game->roundOver()) {
            std::cout << "Human playing..." << std::endl;
            nextPlayerTurn();          
            ScreenManager::getInstance()->switchTo("nextplayermessage");
        }
    }
}

void LocalAIGameScreen::nextPlayerTurn()
{
    // rotate board
    board->nextTurn();

    unsigned int nb_players = game->getPlayers().size();
    current_zone->getHand()->mask();
    current_zone_index = (current_zone_index + 1) % nb_players;
    current_zone = board->getZones()[current_zone_index];

    // Next player
    board->getDeck()->pickCard();
    Core::Player * p = game->startTurn();
    current_zone->getHand()->addCard(new Card(p->pickCard()));
    current_zone->getHand()->reveal();

    if(current_zone->getPlayer()->getName() == "player 2") {
        int chosenCard = ia->chooseCard();
        playing_card_AI(chosenCard, current_zone->getPlayer()->getCard(chosenCard));
    }
}

void LocalAIGameScreen::loadContent()
{
    Screen::loadContent();

    // Init game
    game = new Core::Game(2);
    ia = new IA::IA_intel(game);
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
            current_zone_index = i;
        }

        board->getZones().back()
                ->getHand()
                ->playing(&Screen::playing_card, static_cast<Screen *>(this));
    }

    current_zone = board->getZones()[current_zone_index];

    // Give card to current player (initialization)
    board->getDeck()->pickCard();
    current_zone->getHand()->addCard(new Card(current->pickCard()));
}

void LocalAIGameScreen::unloadContent()
{
    Screen::unloadContent();

    if (game) delete game;
    if (board) delete board;
}

void LocalAIGameScreen::input(sf::Event evt)
{
    board->input(evt);
    current_zone->input(evt);

    if (evt.type == sf::Event::KeyPressed && evt.key.code == sf::Keyboard::T
            && game->getDeck()->getCards().size() > 0)
        board->nextTurn();
}

void LocalAIGameScreen::update(float dt)
{
    game->update();
    board->update(dt);

    // Update every time hand of current player
    current_zone->getHand()->reveal();

    if (game->roundOver()) {
        game->startRound();
        Core::Player * current = game->startTurn();
        current_zone = board->getZones()[game->getCurrentWinner()];
        current_zone->getHand()->addCard(new Card(current->pickCard()));
        // set winner screen and restart round

        if(current_zone->getPlayer()->getName() == "player 2") {
            int chosenCard = ia->chooseCard();
            playing_card_AI(chosenCard, current_zone->getPlayer()->getCard(chosenCard));
        }
    }

    if (game->gameOver()) {
        unloadContent();
        ScreenManager::getInstance()->switchTo("menu");
    }
}

void LocalAIGameScreen::draw(sf::RenderWindow &window)
{
    window.clear();
    window.draw(*board);
}
