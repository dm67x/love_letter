#include "Animation.h"

Animation::Animation(float time, sf::Sprite * object_to_animate)
{
	this->time = time;
	this->object_to_animate = object_to_animate;
	stop_anim = true;
}

void Animation::start()
{
}

void Animation::update(float dt)
{
	if (!stop_anim) {
		time -= dt;
		if (time <= 0.0f) {
			stop();
		}
	}
}

void Animation::stop()
{
	stop_anim = true;
}
