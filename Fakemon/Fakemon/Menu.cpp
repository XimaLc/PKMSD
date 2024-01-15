#include "Menu.h"

Menu::Menu()
{
	this->bouttons["PSEUDO_BOUTTON"] = new Button(800, 470, 300, 80, sf::Color(54,95,172), "PSEUDO", 50);
	this->bouttons["PASSWORD_BOUTTON"] = new Button(800, 600, 300, 80, sf::Color(54, 95, 172), "PASSWORD", 50);
	this->bouttons["PLAY_BOUTTON"] = new Button(850, 750, 200, 80, sf::Color(54, 95, 172), "PLAY", 50);
	this->bouttons["REGISTER_BOUTTON"] = new Button(1550, 950, 300, 80, sf::Color(54, 95, 172), "REGISTER", 50);

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

void Menu::UpdateMenu(sf::RenderWindow* _window)
{
	sf::Vector2f mousePos(static_cast<float>(sf::Mouse::getPosition(*_window).x), static_cast<float>(sf::Mouse::getPosition(*_window).y));

	for (auto& it : this->bouttons)
		it.second->update(mousePos);

	/*if (bouttons["GAME_BOUTTON"]->isPressed())
	{
		StateManager::getInstance()->switchToGame();
	}*/
}

void Menu::DrawMenu(sf::RenderWindow * _window)
{
	_window->draw(fondSpr);
	_window->draw(TitreSpr);
	for (auto& it : this->bouttons)
		it.second->render(_window);
}
