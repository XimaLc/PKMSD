#pragma once
#include "SFML/Graphics.hpp"
#include "Button.h"

#define stateManager StateManager::getInstance()

class State
{
public:
	State() {}
	~State() {}

	virtual void updateScene(sf::RenderWindow* _window) = 0;
	virtual void drawScene(sf::RenderWindow* _window) = 0;

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

	sf::Event event;
	
};

