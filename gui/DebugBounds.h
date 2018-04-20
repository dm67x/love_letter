#ifndef DEBUGBOUNDS_H
#define DEBUGBOUNDS_H

#include "Object.h"

class DebugBounds : public Object
{

private:
    sf::RectangleShape rect;

public:
    DebugBounds(sf::FloatRect bounds);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const;

};

#endif // DEBUGBOUNDS_H
