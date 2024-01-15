#pragma once
#include "SFML/Graphics.hpp"

class State
{
public:
	virtual ~State() = default;
	virtual void InitScene() = 0;
	virtual void UpdateScene() = 0;
	virtual void DrawScene(sf::RenderWindow* _window) = 0;
};

class GameState : public State {};
class MenuState : public State {};
class OptionState : public State {};


class StateManager
{
public:
	StateManager();

	State* currentState;

	void switchToMenu();
	void switchToGame();
	void switchToOption();

	void updateCurrentState();
	void displayCurrentState();

public:
	sf::RenderWindow window;
};

