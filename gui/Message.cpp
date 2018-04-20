#include "Message.h"
#include "MainWindow.h"

Message::Message(std::string message)
    : Object("message")
{
    // Font & Text
    font.loadFromFile("data/Another day in Paradise.ttf");
    text.setFont(font);
    text.setFillColor(sf::Color::White);
    text.setString(message);
    text.setCharacterSize(30);
    sf::FloatRect text_rect = text.getLocalBounds();
    text.setOrigin(text_rect.left + text_rect.width / 2.0f,
                   text_rect.top + text_rect.height / 2);
    text.setPosition(0, 0);

    // Background (rectangle)
    rectangle.setFillColor(sf::Color(0, 0, 0, 120));
    rectangle.setSize(sf::Vector2f(text_rect.left + text_rect.width,
                                   text_rect.top + text_rect.height));
    rectangle.setOrigin(rectangle.getSize().x / 2.0f, rectangle.getSize().y / 2.0f);
    rectangle.setPosition(0, 0);
}

Message::~Message()
{
}

void Message::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(rectangle, states);
    target.draw(text, states);
}

void Message::show(std::string message)
{
    sf::Vector2u size = MainWindow::getInstance()->getWindow()->getSize();
    sf::Vector2f center_screen = sf::Vector2f(size.x / 2.0f, size.y / 2.0f);
    Message::show(message, center_screen);
}

void Message::show(std::string message, sf::Vector2f where)
{
    Message msg(message);
    msg.setPosition(where);
    MainWindow::getInstance()->getWindow()->draw(msg);
}
