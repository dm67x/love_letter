#include "CreditsScreen.h"
#include "ScreenManager.h"

CreditsScreen::CreditsScreen()
    : Screen("credits")
{
}

CreditsScreen::~CreditsScreen()
{
}

void CreditsScreen::loadContent()
{
    Screen::loadContent();

    // Size
    sf::Vector2u size = getSize();

    // Colors
    sf::Color text_color = sf::Color(226, 26, 57);

    // Background
    bg_texture.loadFromFile("data/back_menu_credits.jpg");
    background.setTexture(bg_texture);
    background.setOrigin(bg_texture.getSize().x / 2.0f, bg_texture.getSize().y / 2.0f);
    background.setPosition(size.x / 2.0f, size.y / 2.0f);
    background.setScale(size.x / (bg_texture.getSize().x * 1.0f),
                        size.y / (bg_texture.getSize().y * 1.0f));

    font.loadFromFile("data/Another day in Paradise.ttf");

    // Seiji Kanai
    text_seiji.setFont(font);
    text_seiji.setString("Love Letter by Seiji Kanai");
    text_seiji.setCharacterSize(35);
    text_seiji.setFillColor(sf::Color::Black);
    text_seiji.setStyle(sf::Text::Bold);

    sf::FloatRect text_rect_seiji = text_seiji.getLocalBounds();
    text_seiji.setPosition((getSize().x - text_rect_seiji.width) / 2,
                           375.0f * background.getScale().y);

    // Developed by (Title)
    text_title.setFont(font);
    text_title.setString("Made with \"LOVE\" by ...");
    text_title.setCharacterSize(25);
    text_title.setFillColor(text_color);
    text_title.setStyle(sf::Text::Bold);

    sf::FloatRect text_rect_title = text_title.getLocalBounds();
    text_title.setPosition((getSize().x - text_rect_title.width) / 2,
                           text_seiji.getGlobalBounds().top + text_seiji.getGlobalBounds().height + space);

    // Dev 1 (Mehmet)
    text_dev1.setFont(font);
    text_dev1.setString("Mehmet Ozkan");
    text_dev1.setCharacterSize(20);
    text_dev1.setFillColor(text_color);

    sf::FloatRect text_rect_dev1 = text_dev1.getLocalBounds();
    text_dev1.setPosition((getSize().x - text_rect_dev1.width) / 2,
                          text_title.getGlobalBounds().top + text_title.getGlobalBounds().height + space);

    // Dev 2 (Jawed)
    text_dev2.setFont(font);
    text_dev2.setString("Jawed Bernardone");
    text_dev2.setCharacterSize(20);
    text_dev2.setFillColor(text_color);

    sf::FloatRect text_rect_dev2 = text_dev2.getLocalBounds();
    text_dev2.setPosition((getSize().x - text_rect_dev2.width) / 2,
                          text_dev1.getGlobalBounds().top + text_dev1.getGlobalBounds().height + space);

    // Dev 3 (Marija)
    text_dev3.setFont(font);
    text_dev3.setString("Marija Kirandjiska");
    text_dev3.setCharacterSize(20);
    text_dev3.setFillColor(text_color);

    sf::FloatRect text_rect_dev3 = text_dev3.getLocalBounds();
    text_dev3.setPosition((getSize().x - text_rect_dev3.width) / 2,
                          text_dev2.getGlobalBounds().top + text_dev2.getGlobalBounds().height + space);

    // Dev 4 (Emine)
    text_dev4.setFont(font);
    text_dev4.setString("Emine Bernardone");
    text_dev4.setCharacterSize(20);
    text_dev4.setFillColor(text_color);

    sf::FloatRect text_rect_dev4 = text_dev4.getLocalBounds();
    text_dev4.setPosition((getSize().x - text_rect_dev4.width) / 2,
                          text_dev3.getGlobalBounds().top + text_dev3.getGlobalBounds().height + space);
}

void CreditsScreen::input(sf::Event evt)
{
    if (evt.type == sf::Event::KeyPressed && evt.key.code == sf::Keyboard::Escape) {
        ScreenManager::getInstance()->switchTo("menu");
    }
}

void CreditsScreen::draw(sf::RenderWindow &window)
{
    window.clear(sf::Color::Black);
    window.draw(background);
    window.draw(love_letter);
    window.draw(text_seiji);
    window.draw(text_title);
    window.draw(text_dev1);
    window.draw(text_dev2);
    window.draw(text_dev3);
    window.draw(text_dev4);
}
