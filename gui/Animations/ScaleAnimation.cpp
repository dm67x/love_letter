#include "ScaleAnimation.h"

ScaleAnimation::ScaleAnimation(sf::Sprite *object, sf::Vector2f to)
    : ScaleAnimation(1.0f, object, to)
{
}

ScaleAnimation::ScaleAnimation(float duration, sf::Sprite * object, sf::Vector2f to)
    : Animation(duration, object)
{
    scale = object->getScale();
    this->to = to;
}

void ScaleAnimation::update(float dt)
{
    Animation::update(dt);
    if (state == PLAYING) {
        float ease = Animation::in_cubic_ease(time, 0.005, 1.000, 1.000);
        scale_speed = (to - scale) / ease;
        updated_scale = scale + current * scale_speed;
        object->setScale(updated_scale);
    }
}
