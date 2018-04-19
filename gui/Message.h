#ifndef MESSAGE_H
#define MESSAGE_H

#include "Object.h"

class Message : public Object
{

private:
    Message(std::string message);
    ~Message();

    sf::Font font;
    sf::Text text;
    sf::RectangleShape rectangle;

public:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    static void show(std::string message);
    static void show(std::string message, sf::Vector2f where);

};

#endif // MESSAGE_H
