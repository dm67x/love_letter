#ifndef UTILS_H
#define UTILS_H

#include <SFML/Graphics.hpp>

class Utils
{

public:
    static bool mouseInside(sf::FloatRect rect, sf::Vector2i mousePosition);

};

#endif // UTILS_H
