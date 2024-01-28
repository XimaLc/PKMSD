#include "MoveSlot.h"

MoveSlot::MoveSlot()
{
	moveShape.setFillColor(sf::Color::Red);
	moveShape.setSize({ 550,100 });
}

void MoveSlot::update(const sf::Vector2f mousePos)
{
	timer += GetDeltaTime();

	if (this->moveShape.getGlobalBounds().contains(mousePos) && sf::Mouse::isButtonPressed(sf::Mouse::Left) && timer >= 0.1)
	{
		color.a = 100;
		this->moveShape.setFillColor(color);

		this->state = moveslotPRESSED;

		timer = 0;
	}
	else if (this->moveShape.getGlobalBounds().contains(mousePos))
	{
		this->state = moveslotHOVER;
		color.a = 100;
		this->moveShape.setFillColor(color);
	}
	else
	{
		this->state = moveslotIDLE;
		color.a = 255;
		this->moveShape.setFillColor(color);
	}
}

void MoveSlot::setPosition(int x, int y)
{
	moveShape.setPosition(x, y);
}

void MoveSlot::draw(sf::RenderWindow* _window)
{
	_window->draw(moveShape);
}
