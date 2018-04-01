#include "MainWindow.h"

MainWindow::MainWindow()
    : sf::RenderWindow(sf::VideoMode(1024, 600), "Love Letter - IHM", sf::Style::Close)
{
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
    delete instance;
    instance = (MainWindow *)new sf::RenderWindow(
                sf::VideoMode::getDesktopMode(),
                "Love Letter - IHM",
                sf::Style::Fullscreen);
}
