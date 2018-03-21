#include "PickAnimation.h"

PickAnimation::PickAnimation(sf::Sprite * object_to_animate)
	: Animation(2.0f, object_to_animate)
{
}

void PickAnimation::start()
{
	scale_factor = origin_scale_factor = object_to_animate->getScale().x;
	position = original_position = object_to_animate->getPosition();
	stop_anim = false;
}

void PickAnimation::update(float dt)
{
	Animation::update(dt);
	if (!stop_anim) {
		scale_factor += dt * time * 0.2f;
		position.y += dt * time * 100.0f;

		object_to_animate->setPosition(position);
		object_to_animate->setScale(scale_factor, scale_factor);
	}
}

void PickAnimation::stop()
{
	Animation::stop();
}
