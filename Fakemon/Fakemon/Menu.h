#pragma once
#include "StateManager.h"

class Menu
{
public:
	Menu();
	void updateMenu(sf::RenderWindow* _window);
	void drawMenu(sf::RenderWindow* _window);

	std::map<std::string, Button*> boutons;
	sf::Sprite fondSpr;
	sf::Texture fondTex;
	sf::Sprite TitreSpr;
	sf::Texture TitreTex;
	
};

