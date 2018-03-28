#include "MoveAnimation.h"

MoveAnimation::MoveAnimation(sf::Sprite * object, sf::Vector2f to)
    : MoveAnimation(1.5f, object, to)
{
}

MoveAnimation::MoveAnimation(float duration, sf::Sprite * object, sf::Vector2f to)
    : Animation(duration, object)
{
    where = to;
}

void MoveAnimation::update(float dt)
{
    Animation::update(dt);
    if (state == PLAYING) {
        position = object->getPosition();
        move_speed = (where - position) / time;
        object->move(current * move_speed);
    }
}
