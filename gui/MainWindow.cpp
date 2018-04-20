#include "MainWindow.h"

MainWindow::MainWindow()
{
    window = new sf::RenderWindow(sf::VideoMode(1024, 600), "Love Letter - IHM", sf::Style::Close);
}

MainWindow * MainWindow::instance = NULL;

MainWindow * MainWindow::getInstance()
{
    if (instance == NULL)
        instance = new MainWindow();
    return instance;
}

void MainWindow::setFullscreen()
{
    delete window;
    window = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), "Love Letter - IHM", sf::Style::Fullscreen);
}
