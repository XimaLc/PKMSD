#pragma once
#include "StateManager.h"
#include "Menu.h"

class MenuState : public State
{
public:
	MenuState(Client& _client);
	~MenuState() {}

	void updateScene(sf::RenderWindow* _window)override;
	void drawScene(sf::RenderWindow* _window)override;

private:
	Menu menu;

};

