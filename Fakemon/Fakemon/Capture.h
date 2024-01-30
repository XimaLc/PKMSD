#pragma once
#include "StateManager.h"


class Capture
{
private:

public:
	Capture();
	~Capture();

	void update(sf::RenderWindow* _window);
	void draw(sf::RenderWindow* _window);

};

