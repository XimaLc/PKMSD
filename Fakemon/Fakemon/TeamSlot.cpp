#include "TeamSlot.h"

TeamSlot::TeamSlot()
{
	slotShape.setFillColor(sf::Color::Green);
	slotShape.setSize({ 140.f,140.f });

	sprite.setScale({ 0.15, 0.15 });

	texture = nullptr;
}

void TeamSlot::setPokemon(Pokemon _p)
{	
	if (pokemon.getPath() != "")
		texture = DB::getTexture(pokemon.getPath());

	pokemon = _p;
}

void TeamSlot::update(const sf::Vector2f mousePos)
{
	timer += GetDeltaTime();

	if (this->slotShape.getGlobalBounds().contains(mousePos) && sf::Mouse::isButtonPressed(sf::Mouse::Left) && timer >= 0.1)
	{
		color.a = 100;
		this->slotShape.setFillColor(color);

		this->state = slotPRESSED;

		timer = 0;
	}
	else if (this->slotShape.getGlobalBounds().contains(mousePos))
	{
		this->state = slotHOVER;
		color.a = 200;
		this->slotShape.setFillColor(color);
	}
	else
	{
		this->state = slotIDLE;
		color.a = 255;
		this->slotShape.setFillColor(color);
	}
}

const bool TeamSlot::isPressed() const
{
	if (state == slotPRESSED)
	{
		return true;
	}
	return false;
}

void TeamSlot::setPos(sf::Vector2f _pos)
{
	slotShape.setPosition(_pos);
	sprite.setPosition(_pos.x + 5, _pos.y + 5);
}

void TeamSlot::draw(sf::RenderWindow* _window)
{
	_window->draw(slotShape);
	if (texture != nullptr)
	{
		sprite.setTexture(*texture);
		_window->draw(sprite);
	}
}
