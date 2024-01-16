#pragma once
#include "StateManager.h"

class OptionState : public State
{
public:
	OptionState();
	~OptionState() {}

	void updateScene(sf::RenderWindow* _window)override;
	void drawScene(sf::RenderWindow* _window)override;
};

