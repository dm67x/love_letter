#include "ScreenManager.h"
#include "MainWindow.h"
#include "core/game.h"
#include "Screens/MenuScreen.h"
#include "Screens/PlayScreen.h"
#include "Screens/CreditsScreen.h"

int main(void)
{
    MainWindow * window = MainWindow::getInstance();
    window->setFramerateLimit(60);
    window->setFullscreen();

#if FULLSCREEN
    window->setFullscreen();
#endif

    Core::Game * game = new Core::Game(4);

    // ScreenManager
    ScreenManager * screenManager = ScreenManager::getInstance();

    // Add screens
    screenManager->add(new MenuScreen());
    screenManager->add(new PlayScreen());
    screenManager->add(new CreditsScreen());

    sf::Clock clock;
    while (window->isOpen())
    {
        sf::Event evt;
        if (window->pollEvent(evt))
        {
            switch (evt.type)
            {
            case sf::Event::Closed:
                window->close();
                break;
            }
        }

        sf::Time elapsed = clock.getElapsedTime();

        screenManager->getCurrent()->update(elapsed.asSeconds());

        clock.restart();

        window->clear();
        screenManager->getCurrent()->draw(*window);
        window->display();
    }

    delete screenManager;

    return 0;
}
