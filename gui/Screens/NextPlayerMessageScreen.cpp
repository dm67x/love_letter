#include "NextPlayerMessageScreen.h"
#include "ScreenManager.h"
#include "../../core/game.h"

NextPlayerMessageScreen::NextPlayerMessageScreen()
    : Screen("nextplayermessage")
{

}


NextPlayerMessageScreen::~NextPlayerMessageScreen()
{

}

void NextPlayerMessageScreen::loadContent()
{
    Screen::loadContent();

    sf::Vector2u size = getSize();

    font.loadFromFile("data/Another day in Paradise.ttf");

    // Text
    this->next_player_turn_msg.setString("Next player turn");
    this->next_player_turn_msg.setFont(font);
    this->next_player_turn_msg.setStyle(sf::Text::Bold);
    this->next_player_turn_msg.setCharacterSize(35);
    this->next_player_turn_msg.setFillColor(sf::Color::Black);

    sf::FloatRect nptm_rect = this->next_player_turn_msg.getLocalBounds();
    this->next_player_turn_msg.setOrigin(nptm_rect.left + nptm_rect.width / 2.0f,
                                         nptm_rect.top + nptm_rect.height / 2.0f);
    this->next_player_turn_msg.setPosition(sf::Vector2f(size.x / 2, size.y / 2));

    sf::FloatRect nptm_rect_gb = this->next_player_turn_msg.getGlobalBounds();

    // Text's Background
    this->txt_background.setSize(sf::Vector2f(nptm_rect_gb.width + 20.0f, nptm_rect_gb.height + 10.0f));
    this->txt_background.setFillColor(sf::Color::White);
    this->txt_background.setPosition(sf::Vector2f(nptm_rect_gb.left - 10.0f, nptm_rect_gb.top - 5.0f));
}

void NextPlayerMessageScreen::input(sf::Event evt)
{
    switch (evt.type)
    {
        case sf::Event::MouseButtonPressed:
        {
            if (evt.mouseButton.button == sf::Mouse::Left) {
                timer = 0;
                ScreenManager::getInstance()->switchTo(ScreenManager::getInstance()->getPrevious()->getName());
            }
            break;
        }

        default:
        break;
    }
}

void NextPlayerMessageScreen::update(float dt)
{
    timer += dt;

    if(timer >= sf::seconds(3).asSeconds()) {
        timer = 0;
        ScreenManager::getInstance()->switchTo(ScreenManager::getInstance()->getPrevious()->getName());
    }
}

void NextPlayerMessageScreen::draw(sf::RenderWindow & window)
{
    window.clear(sf::Color::Black);
    window.draw(this->txt_background);
    window.draw(this->next_player_turn_msg);
}
