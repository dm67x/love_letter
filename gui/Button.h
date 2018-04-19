#ifndef BUTTON_H
#define BUTTON_H

#include "Object.h"

class Button : public Object
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
    bool mouseInside(sf::Vector2i m_position);

    void onClick(void (*functionPtr)());
    virtual void input(sf::Event evt);
    virtual void update(float dt);
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const = 0;

};

#endif // BUTTON_H
