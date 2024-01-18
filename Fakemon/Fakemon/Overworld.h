#pragma once
#include "StateManager.h"
#include "Player.h"

class Overworld
{
private:
	sf::Sprite fondSpr;
	sf::Texture fondTxt;
	sf::View viewOverworld;
	Player player;
public:
	Overworld();
	~Overworld();

	void update(sf::RenderWindow* _window);
	void draw(sf::RenderWindow* _window);

};

