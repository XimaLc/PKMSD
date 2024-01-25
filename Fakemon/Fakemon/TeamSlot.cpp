#include "TeamSlot.h"

TeamSlot::TeamSlot()
{
	shape.setFillColor(sf::Color::Green);
	shape.setSize({ 140.f,140.f });
	sprite.setScale({ 0.15, 0.15 });
}

void TeamSlot::setPokemon(Pokemon _p)
{
	pokemon = _p;
	texture.loadFromFile("../Files/Textures/Pokemons/Base/" + pokemon.getPath() + ".png");
}

void TeamSlot::update(const sf::Vector2f mousePos)
{
	timer += GetDeltaTime();

	if (this->shape.getGlobalBounds().contains(mousePos) && sf::Mouse::isButtonPressed(sf::Mouse::Left) && timer >= 0.1)
	{
		color.a = 100;
		this->shape.setFillColor(color);

		this->state = slotPRESSED;

		timer = 0;
	}
	else if (this->shape.getGlobalBounds().contains(mousePos))
	{
		this->state = slotHOVER;
		color.a = 200;
		this->shape.setFillColor(color);
	}
	else
	{
		this->state = slotIDLE;
		color.a = 255;
		this->shape.setFillColor(color);
	}
}

void TeamSlot::setPos(sf::Vector2f _pos)
{
	shape.setPosition(_pos);
	sprite.setPosition(_pos.x + 5, _pos.y + 5);
}

void TeamSlot::draw(sf::RenderWindow* _window)
{
	sprite.setTexture(texture);
	_window->draw(shape);
	_window->draw(sprite);
}
