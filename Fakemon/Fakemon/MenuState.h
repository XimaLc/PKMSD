#pragma once
#include "StateManager.h"
#include "Menu.h"

class MenuState : public State
{
public:
	MenuState();
	~MenuState() {}

	void updateScene(sf::RenderWindow* _window)override;
	void drawScene(sf::RenderWindow* _window)override;

private:
	Menu menu;

};

