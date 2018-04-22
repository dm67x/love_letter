#ifndef DIALOGBOX_H
#define DIALOGBOX_H

#include "Object.h"
#include "DebugBounds.h"

class DialogBox : public Object
{

protected:
    bool is_open;
    sf::Vector2f size;

public:
    DialogBox(std::string title_text, sf::Vector2f size);

    virtual void open();
    virtual void close();

    virtual void input(sf::Event evt);
    virtual void update(float dt);
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const = 0;

};

#endif // DIALOGBOX_H
