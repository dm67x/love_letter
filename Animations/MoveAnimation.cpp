#include "MoveAnimation.h"

MoveAnimation::MoveAnimation(sf::Sprite * object, sf::Vector2f to)
    : MoveAnimation(1.5f, object, to)
{
}

MoveAnimation::MoveAnimation(float duration, sf::Sprite * object, sf::Vector2f to)
    : Animation(duration, object)
{
    position = object->getPosition();
    // calculate speed of movement
    move_speed = (to - position) / time;
}

void MoveAnimation::update(float dt)
{
    Animation::update(dt);
    if (state == PLAYING) {
        updated_position = position + current * move_speed;
        object->setPosition(updated_position);
    }
}
