#include "MenuState.h"

void MainMenuState::InitScene()
{
	this->bouttons["GAME_BOUTTON"] = new Button(850, 500, 200, 100, sf::Color::Red, "PLAY",50);
}

void MainMenuState::UpdateScene(sf::RenderWindow* _window)
{
	sf::Vector2f mousePos(static_cast<float>(sf::Mouse::getPosition(*_window).x), static_cast<float>(sf::Mouse::getPosition(*_window).y));

	for (auto& it : this->bouttons)
		it.second->update(mousePos);

	if (bouttons["GAME_BOUTTON"]->isPressed())
	{
		StateManager::switchToGame();
	}
}

void MainMenuState::DrawScene(sf::RenderWindow* _window)
{
	for (auto& it : this->bouttons)
		it.second->render(_window);
}
