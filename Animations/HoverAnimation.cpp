#include "HoverAnimation.h"

HoverAnimation::HoverAnimation(sf::Sprite * object)
    : Animation(1.0f, object)
{
    scale = object->getScale().x;
    current_scale = scale;

    // calculate scale speed
    scale_speed = (target_scale - scale) / time;
}

void HoverAnimation::update(float dt)
{
    Animation::update(dt);
    if (state == PLAYING) {
        current_scale = scale + current * scale_speed;
        object->setScale(current_scale, current_scale);
    }
}
