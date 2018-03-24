#include "PickAnimation.h"

PickAnimation::PickAnimation(sf::Sprite * object)
    : PickAnimation(object, sf::Vector2f(0, 0))
{
}

PickAnimation::PickAnimation(sf::Sprite * object, sf::Vector2f to_position)
    : Animation(1.0f, object)
{
    position = object->getPosition();
    scale = object->getScale().x;
    current_scale = scale;
    current_position_y = position.y;

    // Calculate speed of scale and move animations
    move_speed = fabs(position.y - to_position.y) / time;
    scale_speed = (target_scale - scale) / time;
}

void PickAnimation::update(float dt)
{
	Animation::update(dt);
    if (state == PLAYING) {
        current_scale = scale + current * scale_speed;
        current_position_y = position.y + current * move_speed;

        object->setPosition(sf::Vector2f(position.x, current_position_y));
        object->setScale(current_scale, current_scale);
    }
}
