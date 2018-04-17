#include "JoinGame.h"
#include "ScreenManager.h"
#include "MainWindow.h"
#include "Buttons/MenuButton.h"

std::string JoinGame::player_ip_adress;

JoinGame::JoinGame()
    : Screen("multiplayer/joingame")
{
    player_ip_adress = "";
}

JoinGame::~JoinGame()
{
    delete join_button;
    delete ip_adress_ta;
}

void JoinGame::loadContent()
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

    font.loadFromFile("data/Another day in Paradise.ttf");

    ip_adress_color = sf::Color(226, 26, 57);

    // IP adress
    ip_adress_text.setFont(font);
    ip_adress_text.setFillColor(ip_adress_color);
    ip_adress_text.setStyle(sf::Text::Bold);
    ip_adress_text.setString("IP Adress :");
    ip_adress_text.setCharacterSize(35);
    sf::FloatRect ip_adress_text_rect = ip_adress_text.getLocalBounds();
    ip_adress_text.setOrigin(ip_adress_text_rect.left + ip_adress_text_rect.width / 2.0f,
                          ip_adress_text_rect.top + ip_adress_text_rect.height / 2.0f);
    ip_adress_text.setPosition(sf::Vector2f(size.x / 2.5, 375.0f * background.getScale().y));
    sf::FloatRect ipa_label_rect = ip_adress_text.getGlobalBounds();

    ip_adress_ta = new TextArea(sf::Vector2f(ipa_label_rect.left + ipa_label_rect.width + 15.0f,
                                             ipa_label_rect.top), 14);

    // Join button
    join_button = new MenuButton("Join",
        sf::Vector2f(size.x / 2,
                     ipa_label_rect.height + ipa_label_rect.top + 2 * space_between_menu));
    join_button->onClick(&joinButtonClicked);
}

void JoinGame::update(sf::Event evt, float dt)
{
    join_button->update();
    ip_adress_ta->update(evt);
}

void JoinGame::draw(sf::RenderWindow &window)
{
    window.clear(sf::Color::Black);

    window.draw(background);
    join_button->draw(window);
    ip_adress_ta->draw(window);
    window.draw(ip_adress_text);
}

void JoinGame::joinButtonClicked()
{
    // TODO: Link to Jawed's part
}
