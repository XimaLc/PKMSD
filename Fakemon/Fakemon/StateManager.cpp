#include "StateManager.h"
#include "GameState.h"
#include "MenuState.h"
#include "OptionState.h"

State* currentState = StateManager::currentState;

StateManager::StateManager() : window(sf::VideoMode(1920, 1080), "FAKEMON DE ZINZIN")
{
	switchToMenu();
}

StateManager* StateManager::getInstance()
{
	static StateManager* instance;

	return instance;
}

void StateManager::switchToMenu()
{
	currentState = new MainMenuState();
	currentState->InitScene();
}

void StateManager::switchToGame()
{
	State* tmp = new MainGameState();

	currentState = tmp;
	currentState->InitScene();
}

void StateManager::switchToOption()
{
	currentState = new MainOptionState();
	currentState->InitScene();
}


void StateManager::updateCurrentState()
{
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();
		}

		currentState->UpdateScene(&window);

		window.clear();
		currentState->DrawScene(&window);
		window.display();
	}
}

void StateManager::displayCurrentState()
{
	

}
	
