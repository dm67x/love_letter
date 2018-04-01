#include "MenuScreen.h"
#include "ScreenManager.h"
#include "MainWindow.h"

MenuScreen::MenuScreen()
    : Screen("menu")
{
}

MenuScreen::~MenuScreen()
{
    delete singleplayer_button;
    delete multiplayer_button;
    delete credits_button;
}

void MenuScreen::loadContent()
{
    content_loaded = true;

    sf::Vector2u size = getSize();

    // Love Letter logo
    love_letter_texture.loadFromFile("data/love-letter-logo.png");
    love_letter.setTexture(love_letter_texture);
    love_letter.setOrigin(love_letter_texture.getSize().x / 2,
                          love_letter_texture.getSize().y / 2);
    love_letter.setPosition(size.x / 2, 100);

    singleplayer_button = new Button("SinglePlayer",
                                     sf::Vector2f(size.x / 2, 100 + love_letter_texture.getSize().y));
    singleplayer_button->onClick(&singleplayerButtonClicked);

    multiplayer_button = new Button("Multiplayer",
                                    sf::Vector2f(size.x / 2, singleplayer_button->getPosition().y + 100));
    multiplayer_button->onClick(&multiplayerButtonClicked);

    credits_button = new Button("Credits",
                                sf::Vector2f(size.x / 2, multiplayer_button->getPosition().y + 100));
    credits_button->onClick(&creditsButtonClicked);

    quit_button = new Button("Exit",
                             sf::Vector2f(size.x / 2, credits_button->getPosition().y + 100));
    quit_button->onClick(&quitButtonClicked);
}

void MenuScreen::update(float dt)
{
    singleplayer_button->update();
    multiplayer_button->update();
    credits_button->update();
    quit_button->update();
}

void MenuScreen::draw(sf::RenderWindow &window)
{
    window.clear(sf::Color(255, 135, 120));
    window.draw(love_letter);
    singleplayer_button->draw(window);
    multiplayer_button->draw(window);
    credits_button->draw(window);
    quit_button->draw(window);
}

void MenuScreen::singleplayerButtonClicked()
{
    ScreenManager::getInstance()->switchTo("play");
}

void MenuScreen::multiplayerButtonClicked()
{

}

void MenuScreen::creditsButtonClicked()
{
    ScreenManager::getInstance()->switchTo("credits");
}

void MenuScreen::quitButtonClicked()
{
    MainWindow::getInstance()->close();
}
