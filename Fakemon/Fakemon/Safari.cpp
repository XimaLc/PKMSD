#include "Safari.h"
#include "GameState.h"
int Safari::stateSafari;

Safari::Safari()
{
	
}

Safari::~Safari()
{

}

void Safari::update(sf::RenderWindow* _window)
{
	if (stateSafari == overworldS)
		overworld.update(_window);
	else if (stateSafari == captureS)
		capture.update(_window);
	else if (stateSafari == shopS)
		shop.update(_window);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
		GameState::setState(menu);
}

void Safari::draw(sf::RenderWindow* _window)
{
	if (stateSafari == overworldS)
		overworld.draw(_window);
	else if (stateSafari == captureS)
		capture.draw(_window);
	else if (stateSafari == shopS)
		shop.draw(_window);
}