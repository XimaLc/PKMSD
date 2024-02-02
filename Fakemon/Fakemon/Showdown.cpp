#include "Showdown.h"
#include "GameState.h"
Showdown::Showdown()
{
	this->boutons["teamCreate"] = new Button("../Files/Textures/button.png", 250, 280, 400, 80, "Create team", 30);
	this->boutons["safari"] = new Button("../Files/Textures/button.png", 250, 380, 400, 80, "Safari", 30);
	this->boutons["teamDelete"] = new Button("../Files/Textures/button.png", 250, 480, 400, 80, "Delete team", 30);
	this->boutons["fightRandom"] = new Button("../Files/Textures/button.png", 1270, 280, 400, 80, "Random opponent", 30);
	this->boutons["findFriend"] = new Button("../Files/Textures/button.png", 1270, 380, 400, 80, "Search opponent", 30);
	this->boutons["quit"] = new Button("../Files/Textures/button.png", 100, 950, 400, 80, "Quit", 30);
}

void Showdown::update(sf::RenderWindow* _window)
{
	sf::Vector2f mousePos(static_cast<float>(sf::Mouse::getPosition(*_window).x), static_cast<float>(sf::Mouse::getPosition(*_window).y));

	for (auto& it : this->boutons)
		it.second->update(mousePos);


	if (boutons["teamCreate"]->isPressed())
		GameState::setState(teamBuilder);
	
	if (boutons["safari"]->isPressed())
		GameState::setState(safariMode);

	if (boutons["fightRandom"]->isPressed())
		GameState::setState(combat);

	if(boutons["quit"]->isPressed())
		StateManager::getInstance()->switchToMenu();
}

void Showdown::draw(sf::RenderWindow * _window)
{
	for (auto& it : this->boutons)
		it.second->render(_window);
}