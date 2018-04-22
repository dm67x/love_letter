#include "DebugBounds.h"

DebugBounds::DebugBounds(sf::FloatRect bounds)
    : Object("debug_bounds")
{
    rect.setFillColor(sf::Color::Transparent);
    rect.setOutlineColor(sf::Color::Black);
    rect.setOutlineThickness(3.0f);
    rect.setPosition(bounds.left, bounds.top);
    rect.setSize(sf::Vector2f(bounds.width, bounds.height));
}

void DebugBounds::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(rect, states);
}
