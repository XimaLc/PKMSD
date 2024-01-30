#include "MoveSlot.h"

MoveSlot::MoveSlot()
{
	color = sf::Color::Red;
	moveShape.setFillColor(color);
	moveShape.setSize({ 550,100 });

	state = moveslotIDLE;
}

MoveSlot::MoveSlot(Move _move)
{
	move = _move;

	color = sf::Color::Red;
	moveShape.setFillColor(color);
	moveShape.setSize({ 550,100 });

	state = moveslotIDLE;
}

const bool MoveSlot::isPressed() const
{
	if (state == moveslotPRESSED)
	{
		return true;
	}
	return false;
}

void MoveSlot::update(const sf::Vector2f mousePos)
{
	timer += GetDeltaTime();
	index;

	if (this->moveShape.getGlobalBounds().contains(mousePos) && sf::Mouse::isButtonPressed(sf::Mouse::Left) && timer >= 0.1)
	{
		this->state = moveslotPRESSED;
		color.a = 100;
		this->moveShape.setFillColor(color);

		timer = 0;
	}
	else if (this->moveShape.getGlobalBounds().contains(mousePos))
	{
		this->state = moveslotHOVER;
		color.a = 200;
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
