#include "SingleplayerModeChoiceScreen.h"
#include "ScreenManager.h"
#include "MainWindow.h"
#include "Buttons/MenuButton.h"

SingleplayerModeChoiceScreen::SingleplayerModeChoiceScreen()
    : Screen("singleplayermodechoice")
{   
    this->play_vs_humans_button = NULL;
    this->play_solo_vs_ai_button = NULL;
}

SingleplayerModeChoiceScreen::~SingleplayerModeChoiceScreen()
{
    if(this->play_vs_humans_button != NULL)
        delete this->play_vs_humans_button;
    if(this->play_solo_vs_ai_button != NULL)
        delete this->play_solo_vs_ai_button;
}

void SingleplayerModeChoiceScreen::loadContent()
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

    // Play vs human(s)
    play_vs_humans_button = new MenuButton("Play vs humans",
        sf::Vector2f(size.x / 2, 375.0f * background.getScale().y));
    play_vs_humans_button->onClick(&play_vs_humansButtonClicked);
    sf::FloatRect pvh_rect = play_vs_humans_button->getBounds();

    // Play solo vs AI
    play_solo_vs_ai_button = new MenuButton("Play solo vs AI",
        sf::Vector2f(size.x / 2, pvh_rect.top + pvh_rect.height + space_between_menu));
    play_solo_vs_ai_button->onClick(&play_solo_vs_aiButtonClicked);
}

void SingleplayerModeChoiceScreen::input(sf::Event evt)
{
    play_vs_humans_button->input(evt);
    play_solo_vs_ai_button->input(evt);
}

void SingleplayerModeChoiceScreen::update(float dt)
{
    play_vs_humans_button->update(dt);
    play_solo_vs_ai_button->update(dt);
}

void SingleplayerModeChoiceScreen::draw(sf::RenderWindow &window)
{
    window.clear(sf::Color::Black);

    window.draw(background);
    window.draw(*play_vs_humans_button);
    window.draw(*play_solo_vs_ai_button);
}

void SingleplayerModeChoiceScreen::play_vs_humansButtonClicked()
{
    ScreenManager::getInstance()->switchTo("singleplayermenu");
}

void SingleplayerModeChoiceScreen::play_solo_vs_aiButtonClicked()
{
    ScreenManager::getInstance()->switchTo("localaigame");
}
