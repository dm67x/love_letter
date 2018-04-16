#ifndef DEBUGBOUNDS_H
#define DEBUGBOUNDS_H

#include <SFML/Graphics.hpp>

class DebugBounds : public sf::Drawable
{

private:
    sf::RectangleShape rect;

public:
    DebugBounds(sf::FloatRect bounds);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const;

};

#endif // DEBUGBOUNDS_H
