#pragma once

#include "../Animation.h"

class PickAnimation : public Animation
{

private:
	float scale_factor, origin_scale_factor, scale_objective, speed, scale_speed;
	sf::Vector2f position, original_position, to_position;

public:
	PickAnimation(sf::Sprite * object_to_animate);
	PickAnimation(sf::Sprite * object_to_animate, sf::Vector2f to_position);
	PickAnimation(float anim_speed, sf::Sprite * object_to_animate, sf::Vector2f to_position);

	void start();
	void update(float dt);
	void stop();

};