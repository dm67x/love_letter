#include "MenuScreen.h"
#include "ScreenManager.h"
#include "MainWindow.h"
#include "Buttons/MenuButton.h"

#include <iostream>

MenuScreen::MenuScreen()
    : Screen("menu")
{
}

MenuScreen::~MenuScreen()
{
    delete localgame_button;
    delete multiplayer_button;
    delete credits_button;
    delete rules_button;
}

void MenuScreen::loadContent()
{
    Screen::loadContent();

    sf::Vector2u size = getSize();

    // Background
    if (!bg_texture.loadFromFile("data/back_menu_credits.jpg")) {
        std::cerr << "error cannot found texture file" << std::endl;
        exit(1);
    }

    bg_texture.setSmooth(true);
    background.setTexture(bg_texture);
    background.setOrigin(bg_texture.getSize().x / 2.0f, bg_texture.getSize().y / 2.0f);
    background.setPosition(size.x / 2.0f, size.y / 2.0f);
    background.setScale(size.x / (bg_texture.getSize().x * 1.0f),
                        size.y / (bg_texture.getSize().y * 1.0f));

    // Singleplayer button
    localgame_button = new MenuButton("Local",
        sf::Vector2f(size.x / 2, 355.0f * background.getScale().y));
    localgame_button->onClick(&singleplayerButtonClicked);
    sf::FloatRect sp_button_rect = localgame_button->getBounds();

    // Multiplayer button
    multiplayer_button = new MenuButton("Multiplayer",
        sf::Vector2f(size.x / 2, sp_button_rect.top + sp_button_rect.height + space_between_menu));
    multiplayer_button->onClick(&multiplayerButtonClicked);
    sf::FloatRect mp_button_rect = multiplayer_button->getBounds();

    // Rules button
    rules_button = new MenuButton("Rules",
        sf::Vector2f(size.x / 2, mp_button_rect.top + mp_button_rect.height + space_between_menu));
    rules_button->onClick(&rulesButtonClicked);
    sf::FloatRect rules_button_rect = rules_button->getBounds();

    // Credits button
    credits_button = new MenuButton("Credits",
        sf::Vector2f(size.x / 2, rules_button_rect.top + rules_button_rect.height + space_between_menu));
    credits_button->onClick(&creditsButtonClicked);
    sf::FloatRect credits_button_rect = credits_button->getBounds();

    // Exit button
    quit_button = new MenuButton("Exit",
        sf::Vector2f(size.x / 2, credits_button_rect.top + credits_button_rect.height + space_between_menu));
    quit_button->onClick(&quitButtonClicked);
}

void MenuScreen::input(sf::Event evt)
{
    localgame_button->input(evt);
    multiplayer_button->input(evt);
    rules_button->input(evt);
    credits_button->input(evt);
    quit_button->input(evt);
}

void MenuScreen::update(float dt)
{
    localgame_button->update(dt);
    multiplayer_button->update(dt);
    rules_button->update(dt);
    credits_button->update(dt);
    quit_button->update(dt);
}

void MenuScreen::draw(sf::RenderWindow &window)
{
    window.clear(sf::Color::Black);

    window.draw(background);
    window.draw(*localgame_button);
    window.draw(*multiplayer_button);
    window.draw(*rules_button);
    window.draw(*credits_button);
    window.draw(*quit_button);
}

void MenuScreen::singleplayerButtonClicked()
{
    ScreenManager::getInstance()->switchTo("singleplayermenu");
}

void MenuScreen::multiplayerButtonClicked()
{
    ScreenManager::getInstance()->switchTo("multiplayermenu");
}

void MenuScreen::rulesButtonClicked()
{
    ScreenManager::getInstance()->switchTo("rules");
}

void MenuScreen::creditsButtonClicked()
{
    ScreenManager::getInstance()->switchTo("credits");
}

void MenuScreen::quitButtonClicked()
{
    MainWindow::getInstance()->getWindow()->close();
}
