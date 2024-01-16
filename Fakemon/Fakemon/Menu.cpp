#include "Menu.h"

Menu::Menu()
{
	this->boutons["PSEUDO_BOUTTON"] = new Button(750, 470, 400, 80, "PSEUDO", 50);
	this->boutons["PASSWORD_BOUTTON"] = new Button(750, 600, 400, 80, "PASSWORD", 50);
	this->boutons["PLAY_BOUTTON"] = new Button(850, 750, 200, 80, "PLAY", 50);
	this->boutons["REGISTER_BOUTTON"] = new Button(1500, 950, 400, 80, "REGISTER", 50);

	if (fondTex.loadFromFile("../Files/Textures/Pokemons/fond.png"))
	{
		fondSpr.setTexture(fondTex);
		fondSpr.setPosition(0, 0);
	}
	if (TitreTex.loadFromFile("../Files/Textures/Pokemons/FAKEMON.png"))
	{
		TitreSpr.setTexture(TitreTex);
		TitreSpr.setPosition(580,80);
		TitreSpr.setScale(0.7,0.7);
	}
}

void Menu::updateMenu(sf::RenderWindow* _window)
{
	sf::Vector2f mousePos(static_cast<float>(sf::Mouse::getPosition(*_window).x), static_cast<float>(sf::Mouse::getPosition(*_window).y));

	for (auto& it : this->boutons)
		it.second->update(mousePos);

	if (boutons["PLAY_BOUTTON"]->isPressed())
	{
		StateManager::getInstance()->switchToGame();
	}
}

void Menu::drawMenu(sf::RenderWindow * _window)
{
	_window->draw(fondSpr);
	_window->draw(TitreSpr);
	for (auto& it : this->boutons)
		it.second->render(_window);
}
