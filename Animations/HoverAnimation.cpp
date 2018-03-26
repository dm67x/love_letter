#include "HoverAnimation.h"

HoverAnimation::HoverAnimation(sf::Sprite * object)
    : Animation(1.0f, object)
{
    scale_animation = new ScaleAnimation(1.0f, object, sf::Vector2f(0.6f, 0.6f));
}

void HoverAnimation::update(float dt)
{
    Animation::update(dt);
    if (state == PLAYING) {
        scale_animation->start();
        scale_animation->update(dt);
    }
}
