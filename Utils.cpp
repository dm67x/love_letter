#include "Utils.h"

bool Utils::mouseInside(sf::FloatRect rect, sf::Vector2i mousePosition)
{
    return rect.top <= mousePosition.y && rect.left <= mousePosition.x &&
            rect.height >= mousePosition.y && rect.width >= mousePosition.x;
}
