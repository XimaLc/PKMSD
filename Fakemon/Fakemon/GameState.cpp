#include "GameState.h"

int GameState::state; 

GameState::GameState()
{
}

void GameState::updateScene(sf::RenderWindow* _window)
{
	if(state == menu)
		showdown.update(_window);
}

void GameState::drawScene(sf::RenderWindow* _window)
{
	if (state == menu)
		showdown.draw(_window);
	else if (state == teamBuilder)
		tb.draw(_window);
}
