#pragma once
#include "SFML/Graphics.hpp"
#include "Button.h"

class State
{
public:
	virtual ~State() = default;
	virtual void InitScene() = 0;
	virtual void UpdateScene(sf::RenderWindow* _window) = 0;
	virtual void DrawScene(sf::RenderWindow* _window) = 0;

	std::map<std::string, Button*> bouttons;

};

class GameState : public State {};
class MenuState : public State {};
class OptionState : public State {};


class StateManager
{
public:
	StateManager();

	static State* currentState; 

	static StateManager* getInstance();

	static void switchToMenu();
	static void switchToGame();
	void switchToOption();

	void updateCurrentState();
	void displayCurrentState();

	sf::RenderWindow window;
	
};

