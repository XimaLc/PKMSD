#pragma once
#include "StateManager.h"

class GameState : public State
{
public:
	GameState();
	~GameState() {}

	void UpdateScene(sf::RenderWindow* _window)override;
	void DrawScene(sf::RenderWindow* _window)override;
};

