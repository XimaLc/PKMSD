#include "MenuState.h"

MenuState::MenuState(Client& _client) : menu(_client)
{
	
}

void MenuState::updateScene(sf::RenderWindow* _window)
{
	menu.updateMenu(_window);
}

void MenuState::drawScene(sf::RenderWindow* _window)
{
	menu.drawMenu(_window);
}
