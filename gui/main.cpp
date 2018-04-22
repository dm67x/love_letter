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
#include "Screens/RulesScreen.h"
#include "Screens/SingleplayerModeChoiceScreen.h"
#include "Screens/LocalAIGameScreen.h"

int main(void)
{
    MainWindow * mainWindow = MainWindow::getInstance();

#if FULLSCREEN
    mainWindow->setFullscreen();
#endif

    sf::RenderWindow * window = mainWindow->getWindow();
    window->setFramerateLimit(60);

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
    screenManager->add(new RulesScreen());
    screenManager->add(new SingleplayerModeChoiceScreen());
    screenManager->add(new LocalAIGameScreen());

    sf::Clock clock;
    while (mainWindow->getWindow()->isOpen())
    {
        sf::Time elapsed;
        sf::Event evt;
        while (mainWindow->getWindow()->pollEvent(evt))
        {
            switch (evt.type)
            {
            case sf::Event::Closed:
                mainWindow->getWindow()->close();
                break;

            case sf::Event::Resized:
                break;
            }

            screenManager->getCurrent()->input(evt);
        }        

        elapsed = clock.getElapsedTime();
        screenManager->getCurrent()->update(elapsed.asSeconds());
        clock.restart();

        mainWindow->getWindow()->clear();
        screenManager->getCurrent()->draw(*mainWindow->getWindow());
        mainWindow->getWindow()->display();
    }

    delete screenManager;
    delete mainWindow;

    return 0;
}
