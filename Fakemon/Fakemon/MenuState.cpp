#include "MenuState.h"

void MainMenuState::InitScene()
{
	suu.setRadius(20);
	suu.setPosition(sf::Vector2f(50, 50));
	suu.setFillColor(sf::Color::Green);
}

void MainMenuState::UpdateScene()
{
}

void MainMenuState::DrawScene(sf::RenderWindow* _window)
{
	_window->draw(suu);
}
