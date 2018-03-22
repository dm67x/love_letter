#include "PickAnimation.h"

PickAnimation::PickAnimation(sf::Sprite * object_to_animate)
	: PickAnimation(object_to_animate, sf::Vector2f(0, 0))
{
}

PickAnimation::PickAnimation(sf::Sprite * object_to_animate, sf::Vector2f to_position)
	: PickAnimation(1.5f, object_to_animate, to_position)
{
}

PickAnimation::PickAnimation(float anim_speed, sf::Sprite * object_to_animate, sf::Vector2f to_position)
	: Animation(anim_speed, object_to_animate), scale_objective(0.75f), to_position(to_position)
{
}

void PickAnimation::start()
{
	scale_factor = origin_scale_factor = object_to_animate->getScale().x;
	position = original_position = object_to_animate->getPosition();
	stop_anim = false;
	// v = d / time (=> time because time - 0 = time) ;)
	speed = fabs(original_position.y - to_position.y) / time;
	scale_speed = (scale_objective - origin_scale_factor) / time;
}

void PickAnimation::update(float dt)
{
	Animation::update(dt);
	if (!stop_anim) {
		scale_factor = origin_scale_factor + current_time * scale_speed;
		if (to_position.y != 0.0f)
			position.y = original_position.y + current_time * speed;

		object_to_animate->setPosition(position);
		object_to_animate->setScale(scale_factor, scale_factor);
	}
}

void PickAnimation::stop()
{
	Animation::stop();
}
