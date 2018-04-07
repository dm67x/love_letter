#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>

class Button
{

private:
    void (*functionPtr)(void);
    sf::Vector2f position;

protected:
    sf::FloatRect rect;

public:
    Button(sf::Vector2f position);
    virtual ~Button();

    inline sf::Vector2f getPosition() const { return position; }
    inline sf::FloatRect getBounds() const { return rect; }
    bool mouseInside();

    void onClick(void (*functionPtr)());
    virtual void update();
    virtual void draw(sf::RenderWindow & window) = 0;

};

#endif // BUTTON_H
