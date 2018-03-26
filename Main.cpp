#include "Board.h"

int main(void)
{
#if FULLSCREEN
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "LoveLetter - IHM", sf::Style::Fullscreen);
#else
    sf::RenderWindow window(sf::VideoMode(800, 600), "Love Letter - IHM", sf::Style::Close);
#endif
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

        window.clear(sf::Color::White);
        board->draw(window);
		window.display();
	}

	return 0;
}
