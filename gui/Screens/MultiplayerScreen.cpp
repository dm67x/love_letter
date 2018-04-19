#include "MultiplayerScreen.h"
#include "ScreenManager.h"
#include "MainWindow.h"
#include "Buttons/MenuButton.h"

MultiplayerScreen::MultiplayerScreen()
    : Screen("multiplayermenu")
{
}

MultiplayerScreen::~MultiplayerScreen()
{
    delete create_game_button;
    delete join_game_button;
}

void MultiplayerScreen::loadContent()
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

    // Create Game button
    create_game_button = new MenuButton("Create Game",
        sf::Vector2f(size.x / 2, 375.0f * background.getScale().y + space_between_menu));
    create_game_button->onClick(&create_gameButtonClicked);
    sf::FloatRect sp_button_rect = create_game_button->getBounds();

    // Join Game button
    join_game_button = new MenuButton("Join Game",
        sf::Vector2f(size.x / 2, sp_button_rect.top + sp_button_rect.height + space_between_menu));
    join_game_button->onClick(&join_gameButtonClicked);
}

void MultiplayerScreen::input(sf::Event evt)
{
    create_game_button->input(evt);
    join_game_button->input(evt);
}

void MultiplayerScreen::update(float dt)
{
    create_game_button->update(dt);
    join_game_button->update(dt);
}

void MultiplayerScreen::draw(sf::RenderWindow &window)
{
    window.clear(sf::Color::Black);

    window.draw(background);
    window.draw(*create_game_button);
    window.draw(*join_game_button);
}

void MultiplayerScreen::create_gameButtonClicked()
{
    //TODO
}

void MultiplayerScreen::join_gameButtonClicked()
{
    //TODO
}
