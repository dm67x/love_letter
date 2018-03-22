#include "Animations/PickAnimation.h"
#include "Card.h"

int main(void)
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "LoveLetter - IHM", sf::Style::Close);
	window.setFramerateLimit(60);

	Card guard;
	guard.setPosition(sf::Vector2f(window.getSize().x / 2 + 125, 300));
	guard.setScale(0.25f, 0.25f);
	guard.setAnimation(new PickAnimation(5.0f, &guard, sf::Vector2f(0, window.getSize().y)));

	Card guard2;
	guard2.setPosition(sf::Vector2f(window.getSize().x / 2 - 125, 300));
	guard2.setScale(0.25f, 0.25f);
	guard2.setAnimation(new PickAnimation(2.5f, &guard2, sf::Vector2f(0, window.getSize().y)));

	sf::Clock clock;
	while (window.isOpen())
	{
		sf::Event evt;
		if (window.pollEvent(evt))
		{
			switch (evt.type)
			{
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::KeyPressed:
				if (evt.key.code == sf::Keyboard::Escape)
					window.close();
				break;
			}
		}

		sf::Time elapsed = clock.getElapsedTime();

		guard.update(elapsed.asSeconds());
		guard2.update(elapsed.asSeconds());

		clock.restart();

		window.clear();
		window.draw(guard);
		window.draw(guard2);
		window.display();
	}

	return 0;
}