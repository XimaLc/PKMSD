#include "TeamSlot.h"

TeamSlot::TeamSlot()
{
	shape.setFillColor(sf::Color::Green);
	shape.setSize({ 100.f,100.f });
}

void TeamSlot::setPos(sf::Vector2f _pos)
{
	shape.setPosition(_pos);
}

void TeamSlot::draw(sf::RenderWindow* _window)
{
	_window->draw(shape);
}
