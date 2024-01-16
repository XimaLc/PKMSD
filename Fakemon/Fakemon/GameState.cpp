#include "GameState.h"

GameState::GameState()
{
}

void GameState::updateScene(sf::RenderWindow* _window)
{
	showdown.update();
}

void GameState::drawScene(sf::RenderWindow* _window)
{
	showdown.draw(_window);
}
