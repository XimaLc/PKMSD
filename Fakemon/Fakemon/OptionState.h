#pragma once
#include "StateManager.h"

class MainOptionState : public OptionState
{
public:
	void InitScene()override;
	void UpdateScene()override;
	void DrawScene(sf::RenderWindow* _window)override;
};

