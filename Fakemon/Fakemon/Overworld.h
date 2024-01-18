#pragma once
#include "StateManager.h"

class Overworld
{
private:
	sf::Sprite fondSpr;
	sf::Texture fondTxt;
	sf::View viewOverworld;
public:
	Overworld();
	~Overworld();

	void update(sf::RenderWindow* _window);
	void draw(sf::RenderWindow* _window);

};

