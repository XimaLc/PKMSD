#include "MenuState.h"

MenuState::MenuState() : menu()
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
