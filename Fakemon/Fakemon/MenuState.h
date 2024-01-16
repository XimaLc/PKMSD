#pragma once
#include "StateManager.h"
#include "Menu.h"

class MenuState : public State
{
public:
	MenuState();
	~MenuState() {}

	void UpdateScene(sf::RenderWindow* _window)override;
	void DrawScene(sf::RenderWindow* _window)override;

private:
	Menu menu;

};

