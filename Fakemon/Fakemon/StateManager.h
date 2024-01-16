#pragma once
#include "SFML/Graphics.hpp"
#include "Button.h"

#define stateManager StateManager::getInstance()

class State
{
public:
	State() {}
	~State() {}

	virtual void UpdateScene(sf::RenderWindow* _window) = 0;
	virtual void DrawScene(sf::RenderWindow* _window) = 0;

};


class StateManager
{
public:
	static StateManager* m_instance;
	StateManager();
	State* currentState; 

	static StateManager* getInstance();

	void switchToMenu();
	void switchToGame();
	void switchToOption();

	void updateCurrentState();
	void displayCurrentState();

	sf::RenderWindow window;
	
};

