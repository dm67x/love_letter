#ifndef OBJECT_H
#define OBJECT_H

#include <SFML/Graphics.hpp>

class Object : public sf::Transformable, public sf::Drawable
{

private:
    std::string id;

protected:
    Object(std::string id);
    virtual ~Object();

public:
    virtual void input(sf::Event evt);
    virtual void input(sf::Event evt, sf::Transform transf);
    virtual void update(float dt);
    virtual void update(float dt, sf::Transform transf);
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const = 0;

};

#endif // OBJECT_H
