#pragma once

#include <SFML\Graphics.hpp>

class Animation
{

protected:
	float time, current_time;
	sf::Sprite * object_to_animate;
	bool stop_anim;

public:
	Animation(float time, sf::Sprite * object_to_animate);

	virtual void start();
	virtual void update(float dt);
	virtual void stop();

};