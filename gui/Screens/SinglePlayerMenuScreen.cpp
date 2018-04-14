#include "SingleplayermenuScreen.h"
#include "ScreenManager.h"
#include "MainWindow.h"
#include "Buttons/MenuButton.h"

SingleplayermenuScreen::SingleplayermenuScreen()
    : Screen("singleplayermenu")
{   
}

SingleplayermenuScreen::~SingleplayermenuScreen()
{
    delete play_button;
}

void SingleplayermenuScreen::loadContent()
{
    content_loaded = true;

    sf::Vector2u size = getSize();

    // Background
    bg_texture.loadFromFile("data/back_menu_credits.jpg");
    background.setTexture(bg_texture);
    background.setOrigin(bg_texture.getSize().x / 2.0f, bg_texture.getSize().y / 2.0f);
    background.setPosition(size.x / 2.0f, size.y / 2.0f);
    background.setScale(size.x / (bg_texture.getSize().x * 1.0f),
                        size.y / (bg_texture.getSize().y * 1.0f));

    // Play button
    play_button = new MenuButton("Start Game",
        sf::Vector2f(size.x / 2, 375.0f * background.getScale().y + 2 * space_between_menu));
    play_button->onClick(&playButtonClicked);
}

void SingleplayermenuScreen::update(sf::Event evt, float dt)
{
    play_button->update();
}

void SingleplayermenuScreen::draw(sf::RenderWindow &window)
{
    window.clear(sf::Color::Black);

    window.draw(background);
    play_button->draw(window);
}

void SingleplayermenuScreen::playButtonClicked()
{
    ScreenManager::getInstance()->switchTo("singleplayer");
}
