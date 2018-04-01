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
    content_loaded = true;

    font.loadFromFile("data/Airplanes in the Night Sky.ttf");

    // Love Letter logo
    love_letter_texture.loadFromFile("data/love-letter-logo.png");
    love_letter.setTexture(love_letter_texture);
    love_letter.setOrigin(love_letter_texture.getSize().x / 2,
                          love_letter_texture.getSize().y / 2);
    love_letter.setPosition(getSize().x / 2, 100);

    // Seiji Kanai
    text_seiji.setFont(font);
    text_seiji.setString("by Seiji Kanai");
    text_seiji.setCharacterSize(25);
    text_seiji.setFillColor(sf::Color::Black);
    text_seiji.setStyle(sf::Text::Bold);

    sf::FloatRect text_rect_seiji = text_seiji.getLocalBounds();
    text_seiji.setPosition((getSize().x - text_rect_seiji.width) / 2,
                           love_letter.getPosition().y + love_letter_texture.getSize().y);

    // Developed by (Title)
    text_title.setFont(font);
    text_title.setString("/****** Game Developed by ******/");
    text_title.setCharacterSize(25);
    text_title.setFillColor(sf::Color::Black);
    text_title.setStyle(sf::Text::Bold);

    sf::FloatRect text_rect_title = text_title.getLocalBounds();
    text_title.setPosition((getSize().x - text_rect_title.width) / 2,
                           text_seiji.getGlobalBounds().top + text_seiji.getGlobalBounds().height + 30);

    // Dev 1 (Mehmet)
    text_dev1.setFont(font);
    text_dev1.setString("Mehmet Ozkan");
    text_dev1.setCharacterSize(25);
    text_dev1.setFillColor(sf::Color::Black);
    text_dev1.setStyle(sf::Text::Bold);

    sf::FloatRect text_rect_dev1 = text_dev1.getLocalBounds();
    text_dev1.setPosition((getSize().x - text_rect_dev1.width) / 2,
                          text_title.getGlobalBounds().top + text_title.getGlobalBounds().height + 30);

    // Dev 2 (Jawed)
    text_dev2.setFont(font);
    text_dev2.setString("Jawed Bernardone");
    text_dev2.setCharacterSize(25);
    text_dev2.setFillColor(sf::Color::Black);
    text_dev2.setStyle(sf::Text::Bold);

    sf::FloatRect text_rect_dev2 = text_dev2.getLocalBounds();
    text_dev2.setPosition((getSize().x - text_rect_dev2.width) / 2,
                          text_dev1.getGlobalBounds().top + text_dev1.getGlobalBounds().height + 30);

    // Dev 3 (Marija)
    text_dev3.setFont(font);
    text_dev3.setString("Marija Kirandjiska");
    text_dev3.setCharacterSize(25);
    text_dev3.setFillColor(sf::Color::Black);
    text_dev3.setStyle(sf::Text::Bold);

    sf::FloatRect text_rect_dev3 = text_dev3.getLocalBounds();
    text_dev3.setPosition((getSize().x - text_rect_dev3.width) / 2,
                          text_dev2.getGlobalBounds().top + text_dev2.getGlobalBounds().height + 30);

    // Dev 4 (Emine)
    text_dev4.setFont(font);
    text_dev4.setString("Emine Bernardone");
    text_dev4.setCharacterSize(25);
    text_dev4.setFillColor(sf::Color::Black);
    text_dev4.setStyle(sf::Text::Bold);

    sf::FloatRect text_rect_dev4 = text_dev4.getLocalBounds();
    text_dev4.setPosition((getSize().x - text_rect_dev4.width) / 2,
                          text_dev3.getGlobalBounds().top + text_dev3.getGlobalBounds().height + 30);
}

void CreditsScreen::update(float dt)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        ScreenManager::getInstance()->switchTo("menu");
    }
}

void CreditsScreen::draw(sf::RenderWindow &window)
{
    window.clear(sf::Color(242, 242, 242));
    window.draw(love_letter);
    window.draw(text_seiji);
    window.draw(text_title);
    window.draw(text_dev1);
    window.draw(text_dev2);
    window.draw(text_dev3);
    window.draw(text_dev4);
}
