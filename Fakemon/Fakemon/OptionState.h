#pragma once
#include "StateManager.h"

class OptionState : public State
{
public:
	OptionState();
	~OptionState() {}

	void UpdateScene(sf::RenderWindow* _window)override;
	void DrawScene(sf::RenderWindow* _window)override;
};

