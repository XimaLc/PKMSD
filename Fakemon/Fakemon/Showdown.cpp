#include "Showdown.h"
#include "GameState.h"
Showdown::Showdown()
{
	this->boutons["teamCreate"] = new Button(250, 280, 400, 80, "Create team", 30);
	this->boutons["teamEdit"] = new Button(250, 380, 400, 80, "Edit team", 30);
	this->boutons["teamDelete"] = new Button(250, 480, 400, 80, "Delete team", 30);
	this->boutons["fightRandom"] = new Button(1270, 280, 400, 80, "Random opponent", 30);
	this->boutons["findFriend"] = new Button(1270, 380, 400, 80, "Search opponent", 30);
	this->boutons["quit"] = new Button(100, 950, 400, 80, "Quit", 30);
}

void Showdown::update(sf::RenderWindow* _window)
{
	sf::Vector2f mousePos(static_cast<float>(sf::Mouse::getPosition(*_window).x), static_cast<float>(sf::Mouse::getPosition(*_window).y));

	for (auto& it : this->boutons)
		it.second->update(mousePos);

	if(boutons["quit"]->isPressed())
		StateManager::getInstance()->switchToMenu();

	if (boutons["teamCreate"]->isPressed())
		GameState::setState(teamBuilder);
}

void Showdown::draw(sf::RenderWindow * _window)
{
	for (auto& it : this->boutons)
		it.second->render(_window);
}