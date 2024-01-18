#include "StateManager.h"
#include "GameState.h"
#include "MenuState.h"
#include "OptionState.h"

#include "tools.h"

StateManager* StateManager::m_instance = nullptr;

StateManager::StateManager() : window(sf::VideoMode(1920, 1080), "FAKEMON DE ZINZIN", Style::Close), currentState(new MenuState())
{
}

StateManager* StateManager::getInstance()
{
	if (m_instance == nullptr)
		m_instance = new StateManager();

	return m_instance;
}

void StateManager::switchToMenu()
{
	if (currentState != nullptr)
		delete currentState;

	currentState = new MenuState();
}

void StateManager::switchToGame()
{
	if (currentState != nullptr)
		delete currentState;

	currentState = new GameState();
}

void StateManager::switchToOption()
{
	if (currentState != nullptr)
		delete currentState;

	currentState = new OptionState();
}


void StateManager::updateCurrentState()
{
	srand(time(NULL));
	while (window.isOpen())
	{
		restartClock();

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();
		}

		currentState->updateScene(&window);

		window.clear();
		currentState->drawScene(&window);
		window.display();
	}
}

void StateManager::displayCurrentState()
{
	

}
	
