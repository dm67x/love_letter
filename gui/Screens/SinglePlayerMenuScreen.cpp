#include "SinglePlayerMenuScreen.h"
#include "ScreenManager.h"
#include "MainWindow.h"
#include "Buttons/MenuButton.h"

int SingleplayermenuScreen::players_number;
MenuButton * SingleplayermenuScreen::two_players_button;
MenuButton * SingleplayermenuScreen::three_players_button;
MenuButton * SingleplayermenuScreen::four_players_button;

SingleplayermenuScreen::SingleplayermenuScreen()
    : Screen("singleplayermenu")
{   
    players_number = 2;
}

SingleplayermenuScreen::~SingleplayermenuScreen()
{
    delete play_button;
}

void SingleplayermenuScreen::loadContent()
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

    font.loadFromFile("data/Another day in Paradise.ttf");

    number_players_choice_color = sf::Color(226, 26, 57);

    // Player number choice
    // Label
    number_players_choice_text.setFont(font);
    number_players_choice_text.setFillColor(number_players_choice_color);
    number_players_choice_text.setStyle(sf::Text::Bold);
    number_players_choice_text.setString("Choose the number of players :");
    number_players_choice_text.setCharacterSize(35);
    sf::FloatRect number_players_choice_text_rect = number_players_choice_text.getLocalBounds();
    number_players_choice_text.setOrigin(number_players_choice_text_rect.left + number_players_choice_text_rect.width / 2.0f,
                          number_players_choice_text_rect.top + number_players_choice_text_rect.height / 2.0f);
    number_players_choice_text.setPosition(sf::Vector2f(size.x / 2.2, 375.0f * background.getScale().y));
    sf::FloatRect npc_button_rect = number_players_choice_text.getGlobalBounds();

    // Sub button
    two_players_button = new MenuButton("2",
        sf::Vector2f(npc_button_rect.left + npc_button_rect.width + space_players_choice, npc_button_rect.top + npc_button_rect.height / 2));
    two_players_button->onClick(&two_playersButtonClicked);
    sf::FloatRect twop_button_rect = two_players_button->getBounds();
    two_players_button->buttonPressed();

    // Sub button
    three_players_button = new MenuButton("3",
        sf::Vector2f(twop_button_rect.left + twop_button_rect.width + space_players_choice, npc_button_rect.top + npc_button_rect.height / 2));
    three_players_button->onClick(&three_playersButtonClicked);
    sf::FloatRect threep_button_rect = three_players_button->getBounds();

    // Sub button
    four_players_button = new MenuButton("4",
        sf::Vector2f(threep_button_rect.left + threep_button_rect.width + space_players_choice, npc_button_rect.top + npc_button_rect.height / 2));
    four_players_button->onClick(&four_playersButtonClicked);

    // Play button
    play_button = new MenuButton("Start Game",
        sf::Vector2f(size.x / 2, npc_button_rect.top + npc_button_rect.height + space_between_menu * 2));
    play_button->onClick(&playButtonClicked);
}

void SingleplayermenuScreen::input(sf::Event evt)
{
    two_players_button->input(evt);
    three_players_button->input(evt);
    four_players_button->input(evt);
    play_button->input(evt);
}

void SingleplayermenuScreen::update(float dt)
{
    two_players_button->update(dt);
    three_players_button->update(dt);
    four_players_button->update(dt);
    play_button->update(dt);
}

void SingleplayermenuScreen::draw(sf::RenderWindow &window)
{
    window.clear(sf::Color::Black);

    window.draw(background);
    window.draw(*two_players_button);
    window.draw(*three_players_button);
    window.draw(*four_players_button);
    window.draw(*play_button);
    window.draw(number_players_choice_text);
}

void SingleplayermenuScreen::two_playersButtonClicked()
{
    players_number = 2;
    two_players_button->buttonPressed();
    three_players_button->buttonUnpressed();
    four_players_button->buttonUnpressed();
}

void SingleplayermenuScreen::three_playersButtonClicked()
{
    players_number = 3;
    two_players_button->buttonUnpressed();
    three_players_button->buttonPressed();
    four_players_button->buttonUnpressed();
}

void SingleplayermenuScreen::four_playersButtonClicked()
{
    players_number = 4;
    two_players_button->buttonUnpressed();
    three_players_button->buttonUnpressed();
    four_players_button->buttonPressed();
}

void SingleplayermenuScreen::playButtonClicked()
{
    ScreenManager::getInstance()->switchTo("localgame");
    // TODO: trouver le moyen de faire passer en argument
    // le nombre de joueurs sélectionné
}
