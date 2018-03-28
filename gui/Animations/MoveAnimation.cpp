#include "MoveAnimation.h"

MoveAnimation::MoveAnimation(sf::Sprite * object, sf::Vector2f to)
    : MoveAnimation(1.5f, object, to)
{
}

MoveAnimation::MoveAnimation(float duration, sf::Sprite * object, sf::Vector2f to)
    : Animation(duration, object)
{
    where = to;
    position = object->getPosition();
}

void MoveAnimation::update(float dt)
{
    Animation::update(dt);
    if (state == PLAYING) {
        float ease = Animation::in_cubic_ease(time, 0.005, 1.000, 1.000);
        move_speed = (where - position) / ease;
        updated_position = position + current * move_speed;
        object->setPosition(updated_position);
    }
}
