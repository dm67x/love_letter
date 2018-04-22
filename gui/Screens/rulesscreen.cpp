#include "RulesScreen.h"
#include "ScreenManager.h"

RulesScreen::RulesScreen()
    : Screen("rules")
{
}

RulesScreen::~RulesScreen()
{
}

void RulesScreen::loadContent()
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

    // Rules (title)
    text_title.setFont(font);
    text_title.setString("Rules");
    text_title.setCharacterSize(25);
    text_title.setFillColor(text_color);
    text_title.setStyle(sf::Text::Bold);

    sf::FloatRect text_rect_title = text_title.getLocalBounds();
    text_title.setPosition((getSize().x - text_rect_title.width) / 2,
                           text_seiji.getGlobalBounds().top + text_seiji.getGlobalBounds().height + space);

    // Rules text
    text_rules.setFont(font);
    text_rules.setString("In this card game your goal is that the person\n"
                         "(the card) closest to the princess (with higher value) holds your love letter\n"
                         "at the end of the day, so it reaches her first (and so you win).\n"
                         "To select a card to throw, a target player and his card, double click the card chosen.\n"
                         "May the best player win the heart of the princess Annette");
    text_rules.setCharacterSize(23);
    text_rules.setFillColor(sf::Color::Black);

    sf::FloatRect text_rect_rules = text_rules.getLocalBounds();
    text_rules.setOrigin(text_rect_rules.left + text_rect_rules.width / 2.0f,
                         text_rect_rules.top + text_rect_rules.height / 2.0f);
    text_rules.setPosition(getSize().x / 2,
                          text_title.getGlobalBounds().top + text_title.getGlobalBounds().height +
                           text_rect_rules.height / 2.0f + space);

}

void RulesScreen::input(sf::Event evt)
{
    if (evt.type == sf::Event::KeyPressed && evt.key.code == sf::Keyboard::Escape) {
        ScreenManager::getInstance()->switchTo("menu");
    }
}

void RulesScreen::draw(sf::RenderWindow &window)
{
    window.clear(sf::Color::Black);
    window.draw(background);
    window.draw(love_letter);
    window.draw(text_seiji);
    window.draw(text_title);
    window.draw(text_rules);
}
