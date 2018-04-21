#include "MenuScreen.h"
#include "ScreenManager.h"
#include "MainWindow.h"
#include "Buttons/MenuButton.h"

MenuScreen::MenuScreen()
    : Screen("menu")
{
}

MenuScreen::~MenuScreen()
{
    delete localgame_button;
    delete multiplayer_button;
    delete credits_button;
}

void MenuScreen::loadContent()
{
    Screen::loadContent();

    sf::Vector2u size = getSize();

    // Background
    bg_texture.loadFromFile("data/back_menu_credits.jpg");
    background.setTexture(bg_texture);
    background.setOrigin(bg_texture.getSize().x / 2.0f, bg_texture.getSize().y / 2.0f);
    background.setPosition(size.x / 2.0f, size.y / 2.0f);
    background.setScale(size.x / (bg_texture.getSize().x * 1.0f),
                        size.y / (bg_texture.getSize().y * 1.0f));

    // Singleplayer button
    localgame_button = new MenuButton("Local",
        sf::Vector2f(size.x / 2, 375.0f * background.getScale().y));
    localgame_button->onClick(&singleplayerButtonClicked);
    sf::FloatRect sp_button_rect = localgame_button->getBounds();

    // Multiplayer button
    multiplayer_button = new MenuButton("Multiplayer",
        sf::Vector2f(size.x / 2, sp_button_rect.top + sp_button_rect.height + space_between_menu));
    multiplayer_button->onClick(&multiplayerButtonClicked);
    sf::FloatRect mp_button_rect = multiplayer_button->getBounds();

    // Credits button
    credits_button = new MenuButton("Credits",
        sf::Vector2f(size.x / 2, mp_button_rect.top + mp_button_rect.height + space_between_menu));
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
    credits_button->input(evt);
    quit_button->input(evt);
}

void MenuScreen::update(float dt)
{
    localgame_button->update(dt);
    multiplayer_button->update(dt);
    credits_button->update(dt);
    quit_button->update(dt);
}

void MenuScreen::draw(sf::RenderWindow &window)
{
    window.clear(sf::Color::Black);

    window.draw(background);
    window.draw(*localgame_button);
    window.draw(*multiplayer_button);
    window.draw(*credits_button);
    window.draw(*quit_button);
}

void MenuScreen::singleplayerButtonClicked()
{
    ScreenManager::getInstance()->switchTo("singleplayermodechoice");
}

void MenuScreen::multiplayerButtonClicked()
{
    ScreenManager::getInstance()->switchTo("multiplayermenu");
}

void MenuScreen::creditsButtonClicked()
{
    ScreenManager::getInstance()->switchTo("credits");
}

void MenuScreen::quitButtonClicked()
{
    MainWindow::getInstance()->getWindow()->close();
}
