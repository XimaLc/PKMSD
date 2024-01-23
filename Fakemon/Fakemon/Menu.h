#pragma once
#include "StateManager.h"
#include "tools.h"

#include "Client.h"

enum STATE_LOGIN { LOGIN, REGISTER };

class Menu
{
public:
	Menu(Client& _client);
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

	sf::Sprite transitionSprite;
	sf::Texture transitionTexture;
	int frameX = 0;
	int frameY = 0;
	sf::IntRect sourceRect;

	sf::Text notif;
	bool activNotif = false;
	float timeNotif = 0;


	STATE_LOGIN login;

	float timer;
	float timerAnim = 0;

	bool verifAccount = false;

private:
	static sf::Font fonts;
	Client& client;


	
	std::string username;
	std::string password;
	bool isAuthenticated = false;
	sf::Packet usernamePacket;
	sf::Packet passwordPacket;
	sf::Packet resultPacket;
};

