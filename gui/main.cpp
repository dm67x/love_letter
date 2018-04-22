#include "ScreenManager.h"
#include "MainWindow.h"
#include "Screens/MenuScreen.h"
#include "Screens/LocalGameScreen.h"
#include "Screens/SinglePlayerMenuScreen.h"
#include "Screens/MultiplayerScreen.h"
#include "Screens/CreateGame.h"
#include "Screens/JoinGame.h"
#include "Screens/CreditsScreen.h"
#include "Screens/NextPlayerMessageScreen.h"

int main(void)
{
    MainWindow * mainWindow = MainWindow::getInstance();
#if FULLSCREEN
    mainWindow->setFullscreen();
#endif

    sf::RenderWindow * window = mainWindow->getWindow();
    window->setFramerateLimit(60);
    window->setKeyRepeatEnabled(false);

    // ScreenManager
    ScreenManager * screenManager = ScreenManager::getInstance();

    // Add screens
    screenManager->add(new MenuScreen());
    screenManager->add(new LocalGameScreen());
    screenManager->add(new SingleplayermenuScreen());
    screenManager->add(new MultiplayerScreen());
    screenManager->add(new CreateGame());
    screenManager->add(new JoinGame());
    screenManager->add(new CreditsScreen());
    screenManager->add(new NextPlayerMessageScreen());

    sf::Clock clock;
    while (window->isOpen())
    {
        sf::Time elapsed;
        sf::Event evt;
        while (window->pollEvent(evt))
        {
            switch (evt.type)
            {
            case sf::Event::Closed:
                window->close();
                break;

            case sf::Event::Resized:
                break;
            }

            screenManager->getCurrent()->input(evt);
        }        

        elapsed = clock.getElapsedTime();
        screenManager->getCurrent()->update(elapsed.asSeconds());
        clock.restart();

        window->clear();
        screenManager->getCurrent()->draw(*window);
        window->display();
    }

    delete screenManager;
    delete window;

    return 0;
}
