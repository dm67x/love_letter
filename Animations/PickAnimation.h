#pragma once

#include "../Animation.h"

class PickAnimation : public Animation
{

private:
	float scale_factor, origin_scale_factor;
	sf::Vector2f position, original_position;

public:
	PickAnimation(sf::Sprite * object_to_animate);

	void start();
	void update(float dt);
	void stop();

};