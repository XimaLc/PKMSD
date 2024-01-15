#pragma once
#include "StateManager.h"

class Menu
{
public:
	Menu();
	void UpdateMenu(sf::RenderWindow* _window);
	void DrawMenu(sf::RenderWindow* _window);

	std::map<std::string, Button*> bouttons;
	sf::Sprite fondSpr;
	sf::Texture fondTex;
	sf::Sprite TitreSpr;
	sf::Texture TitreTex;
	
};

