#include "ScreenManager.h"
#include "MainWindow.h"
#include "Screens/MenuScreen.h"
#include "Screens/SingleplayerScreen.h"
#include "Screens/SingleplayermenuScreen.h"
#include "Screens/MultiplayerScreen.h"
#include "Screens/CreateGame.h"
#include "Screens/JoinGame.h"
#include "Screens/CreditsScreen.h"

int main(void)
{
    MainWindow * window = MainWindow::getInstance();
    window->setFramerateLimit(60);
    window->setKeyRepeatEnabled(false);

#if FULLSCREEN
    window->setFullscreen();
#endif

    // ScreenManager
    ScreenManager * screenManager = ScreenManager::getInstance();

    // Add screens
    screenManager->add(new MenuScreen());
    screenManager->add(new SingleplayerScreen());
    screenManager->add(new SingleplayermenuScreen());
    screenManager->add(new MultiplayerScreen());
    screenManager->add(new CreateGame());
    screenManager->add(new JoinGame());
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

        screenManager->getCurrent()->update(evt, elapsed.asSeconds());

        clock.restart();

        window->clear();
        screenManager->getCurrent()->draw(*window);
        window->display();
    }

    delete screenManager;
    delete window;

    return 0;
}
