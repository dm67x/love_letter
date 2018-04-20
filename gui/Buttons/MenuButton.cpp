#include "MenuButton.h"
#include "MainWindow.h"

MenuButton::MenuButton(std::string text, sf::Vector2f position)
    : Button(position)
{
    n_color = sf::Color(226, 26, 57);
    h_color = sf::Color(0, 128, 128);
    p_color = sf::Color(100, 100, 100);

    // Font & text
    font.loadFromFile("data/Another day in Paradise.ttf");

    this->text.setFont(font);
    this->text.setString(text);
    this->text.setCharacterSize(35);
    this->text.setFillColor(n_color);
    this->text.setStyle(sf::Text::Bold);

    sf::FloatRect text_rect = this->text.getLocalBounds();
    this->text.setOrigin(text_rect.left + text_rect.width / 2.0f, text_rect.top + text_rect.height / 2);
    this->text.setPosition(position);

    rect = this->text.getGlobalBounds();

    isPressed = false;
}

MenuButton::~MenuButton()
{

}

void MenuButton::input(sf::Event evt)
{
    Button::input(evt);
}

void MenuButton::update(float dt)
{
    Button::update(dt);

    if (mouseInside(sf::Mouse::getPosition(*MainWindow::getInstance()->getWindow()))) {
        button.setTexture(hover);
        text.setFillColor(h_color);
    } else {
        button.setTexture(normal);
        if(isPressed) {
            text.setFillColor(p_color);
        } else {
            text.setFillColor(n_color);
        }
    }
}

void MenuButton::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(button, states);
    target.draw(text, states);
}

void MenuButton::buttonPressed()
{
    isPressed = true;
}

void MenuButton::buttonUnpressed()
{
    isPressed = false;
}
