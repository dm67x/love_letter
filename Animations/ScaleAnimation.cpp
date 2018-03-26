#include "ScaleAnimation.h"

ScaleAnimation::ScaleAnimation(sf::Sprite *object, sf::Vector2f to)
    : ScaleAnimation(1.0f, object, to)
{
}

ScaleAnimation::ScaleAnimation(float duration, sf::Sprite * object, sf::Vector2f to)
    : Animation(duration, object)
{
    scale = object->getScale();
    // calculate speed
    scale_speed = (to - scale) / time;
}

void ScaleAnimation::update(float dt)
{
    Animation::update(dt);
    if (state == PLAYING) {
        updated_scale = scale + current * scale_speed;
        object->setScale(updated_scale);
    }
}
