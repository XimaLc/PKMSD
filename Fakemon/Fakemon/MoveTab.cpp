#include "MoveTab.h"

MoveTab::MoveTab()
{

}

MoveTab::MoveTab(Move _move)
{
	move = _move;

	color = sf::Color::Red;

	shape.setSize({ 1000,90 });
	shape.setFillColor(color);

	categoryTexture.loadFromFile("../Files/Textures/Categories.png");
	typeTexture.loadFromFile("../Files/Textures/Types.png");
	font.loadFromFile("../Files/Font/Pokemon.ttf");

	typeSprite.setTextureRect({ 0, 44 * (_move.getType() - 1), 200, 44 });
	typeSprite.setScale({ 0.6,0.6 });
	categorySprite.setTextureRect({ 0, 44 * (_move.getCategory()), 200, 44 });
	categorySprite.setScale({ 0.6,0.6 });

	name.setString(_move.getName());	
	name.setFillColor(sf::Color::Black);

	pp.setFillColor(sf::Color::Black);
	power.setFillColor(sf::Color::Black);
	accuracy.setFillColor(sf::Color::Black);

	pp.setString("PP " + std::to_string(move.getPP()));
	power.setString("Power " + std::to_string(move.getPower()));
	accuracy.setString("Accuracy " + std::to_string(move.getAccuracy()));
}

const bool MoveTab::isPressed() const
{
	if (state == movetabPRESSED)
		return true;

	return false;
}

void MoveTab::setPosition(sf::Vector2f _pos)
{
	shape.setPosition(_pos.x - 5, _pos.y + 5);
	name.setPosition(_pos.x+5, _pos.y+25);
	typeSprite.setPosition(_pos.x + 250, _pos.y + 20);
	categorySprite.setPosition(_pos.x + 250, _pos.y + 55);
	pp.setPosition(_pos.x+400, _pos.y+30);
	power.setPosition(_pos.x+550, _pos.y+30);
	accuracy.setPosition(_pos.x+750, _pos.y+30);
}

void MoveTab::update(const sf::Vector2f mousePos)
{
	timer += GetDeltaTime();

	if (this->shape.getGlobalBounds().contains(mousePos) && sf::Mouse::isButtonPressed(sf::Mouse::Left) && timer >= 0.1)
	{
		color.a = 100;
		this->shape.setFillColor(color);

		this->state = movetabPRESSED;

		timer = 0;
	}
	else if (this->shape.getGlobalBounds().contains(mousePos))
	{
		this->state = movetabHOVER;
		color.a = 200;
		this->shape.setFillColor(color);
	}
	else
	{
		this->state = movetabIDLE;
		color.a = 255;
		this->shape.setFillColor(color);
	}
}

void MoveTab::draw(sf::RenderWindow* _window)
{
	_window->draw(shape);

	name.setFont(font);
	_window->draw(name);

	typeSprite.setTexture(typeTexture);
	_window->draw(typeSprite);

	categorySprite.setTexture(categoryTexture);
	_window->draw(categorySprite);

	pp.setFont(font);
	_window->draw(pp);

	power.setFont(font);
	_window->draw(power);

	accuracy.setFont(font);
	_window->draw(accuracy);

}
