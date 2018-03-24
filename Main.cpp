#include "Board.h"

int main(void)
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "LoveLetter - IHM", sf::Style::Close);
    window.setFramerateLimit(60);

    Board * board = Board::getInstance();

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

        board->update(window, elapsed.asSeconds());

		clock.restart();

		window.clear();
        board->draw(window);
		window.display();
	}

	return 0;
}
