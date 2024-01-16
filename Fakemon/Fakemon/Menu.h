#pragma once
#include "StateManager.h"
#include "AccountManager.h"
#include "tools.h"

enum STATE_LOGIN { LOGIN, REGISTER };

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

	sf::Sprite fogSpr;
	sf::Texture fogTex;
	sf::Sprite fogSpr2;
	sf::Texture fogTex2;

	AccountManager accountManager;

	STATE_LOGIN login;

	float timer;
};

