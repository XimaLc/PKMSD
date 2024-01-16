#pragma once
#include "StateManager.h"

class Showdown
{
private:
	std::map<std::string, Button*> boutons;

public:
	void update();
	void draw(sf::RenderWindow * _window);

	Showdown();
};

