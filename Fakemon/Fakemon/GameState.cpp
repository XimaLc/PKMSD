#include "GameState.h"

int GameState::state; 

GameState::GameState()
{
	state = menu;
}

void GameState::updateScene(sf::RenderWindow* _window)
{
	if (state == safariMode)
		safari.update(_window);
	else if (state == menu)
		showdown.update(_window);
	else if (state == teamBuilder)
		tb.update(_window);
	else if (state == combat)
		cb.update(_window);
}

void GameState::drawScene(sf::RenderWindow* _window)
{
	if (state == safariMode)
		safari.draw(_window);
	else if (state == menu)
		showdown.draw(_window);
	else if (state == teamBuilder)
		tb.draw(_window);
	else if (state == combat)
		cb.draw(_window);
}
