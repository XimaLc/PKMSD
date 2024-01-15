#pragma once
#include "StateManager.h"

class MainMenuState : public MenuState
{
public:
	void InitScene()override;
	void UpdateScene(sf::RenderWindow* _window)override;
	void DrawScene(sf::RenderWindow* _window)override;

private:

};

