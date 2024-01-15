#pragma once
#include "StateManager.h"

class MainGameState : public GameState
{
public:
	void InitScene()override;
	void UpdateScene()override;
	void DrawScene(sf::RenderWindow* _window)override;
};

