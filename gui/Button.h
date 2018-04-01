#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>

class Button
{

private:
    std::string text;
    void (*functionPtr)(void);
    sf::Texture texture, hover_texture;
    sf::Sprite sprite;
    sf::Font font;
    sf::Text d_text; // draw text
    sf::Vector2f position;

public:
    Button(std::string text, sf::Vector2f position);
    ~Button();

    sf::Vector2f getPosition() const { return position; }

    void onClick(void (*functionPtr)());
    void update();
    void draw(sf::RenderWindow & window);

};

#endif // BUTTON_H
