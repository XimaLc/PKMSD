#include "MenuState.h"

MenuState::MenuState() : menu()
{
}

void MenuState::UpdateScene(sf::RenderWindow* _window)
{
	menu.UpdateMenu(_window);
}

void MenuState::DrawScene(sf::RenderWindow* _window)
{
	menu.DrawMenu(_window);
}
