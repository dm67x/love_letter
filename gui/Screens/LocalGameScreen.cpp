#include "LocalGameScreen.h"
#include "SinglePlayerMenuScreen.h"
#include "ScreenManager.h"
#include "MainWindow.h"
#include "SingleplayerModeChoiceScreen.h"
#include "core/cards/all.h"

int LocalGameScreen::playing_card(int index, Core::Card *card)
{
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
        if(card->getName() == "Priest") {
            getCurrentZone(target_player)->getHand()->reveal();
            sf::sleep(sf::seconds(2));
            getCurrentZone(target_player)->getHand()->mask();
        }

        current_zone->getPlayer()->discard(index);
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

void LocalGameScreen::target_func(Core::Card * card)
{
    bool target_selected = false;

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2i mpos = sf::Mouse::getPosition(*MainWindow::getInstance()->getWindow());
        std::vector<PlayerZone *> zones = board->getZones();
        for (unsigned int i = 0; i < zones.size(); i++) {
            sf::Transform transf = zones[i]->getTransform();
            sf::FloatRect rect = transf.transformRect(zones[i]->getBounds());
            if (rect.contains(static_cast<sf::Vector2f>(mpos))) {
                if (zones[i] == current_zone && !card->targetHimself()) break;
                if (zones[i]->getPlayer()->hasShield()) break;
                target_player = zones[i]->getPlayer();
                target_selected = true;
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
    for (auto it = guess_cards.begin(); it != guess_cards.end(); it++) {
        (*it)->show();
    }

    // Get mouse click on card
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2i mpos = sf::Mouse::getPosition(*MainWindow::getInstance()->getWindow());
        for (auto it = guess_cards.begin(); it != guess_cards.end(); it++) {
            sf::Vector2f position = (*it)->getPosition();
            sf::Vector2f dimension = (*it)->getDimensions();
            sf::FloatRect rect = sf::FloatRect(position.x - dimension.x / 2.0f,
                                               position.y - dimension.y / 2.0f,
                                               dimension.x, dimension.y);
            if (rect.contains(static_cast<sf::Vector2f>(mpos))) {
                game->guessCard((*it)->getCard()->getName());
                guessed = true;
                break;
            }
        }
    }

    if (guessed) {
        for (auto it = guess_cards.begin(); it != guess_cards.end(); it++) {
            (*it)->hide();
        }
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

    // Guessed cards
    guess_cards.push_back(new Card(new Core::Priest()));
    guess_cards.push_back(new Card(new Core::Baron()));
    guess_cards.push_back(new Card(new Core::Handmaid()));
    guess_cards.push_back(new Card(new Core::Prince()));
    guess_cards.push_back(new Card(new Core::King()));
    guess_cards.push_back(new Card(new Core::Countess()));
    guess_cards.push_back(new Card(new Core::Princess()));

    for (unsigned int i = 0; i < guess_cards.size(); i++) {
        guess_cards[i]->setScale(0.4f, 0.4f);
        guess_cards[i]->hide();
        guess_cards[i]->reveal();
        sf::Vector2f dimensions = guess_cards[i]->getDimensions();
        guess_cards[i]->setPosition(
                    (dimensions.x + 10) * i + (size.x - (7 * dimensions.x + 60)),
                    size.y / 2.0f);
    }
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
    for (auto it = guess_cards.begin(); it != guess_cards.end(); it++) {
        window.draw(*(*it));
    }
}
