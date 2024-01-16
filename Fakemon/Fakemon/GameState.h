#pragma once
#include "Showdown.h"

class GameState : public State
{
private:
	Showdown showdown;

public:
	GameState();
	~GameState() {}

	void updateScene(sf::RenderWindow* _window)override;
	void drawScene(sf::RenderWindow* _window)override;
};

