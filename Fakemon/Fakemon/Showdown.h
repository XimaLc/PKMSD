#pragma once
#include "StateManager.h"

class Showdown
{
private:
	std::map<std::string, Button*> boutons;

public:
	void update(sf::RenderWindow* _window);
	void draw(sf::RenderWindow * _window);

	Showdown();
};

