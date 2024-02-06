#include "MoveSlot.h"

MoveSlot::MoveSlot()
{
	color = sf::Color::Red;
	moveShape.setFillColor(color);
	moveShape.setSize({ 550,100 });

	state = moveslotIDLE;

	categoryTexture.loadFromFile("../Files/Textures/Categories.png");
	typeTexture.loadFromFile("../Files/Textures/Types.png");

	categorySprite.setScale({ 0.6,0.6 });
	typeSprite.setScale({ 0.6,0.6 });

	typeSprite.setTextureRect({ 0, 44 * (20 - 1), 200, 44 });
	categorySprite.setTextureRect({ 0, 44 * 3, 200, 44 });

	font.loadFromFile("../Files/Font/Pokemon.ttf");

	name.setFillColor(sf::Color::Black);
	stats.setFillColor(sf::Color::Black);

	clearMove();
}

MoveSlot::MoveSlot(Move _move)
{
	clearMove();
	setMove(_move);

	color = sf::Color::Red;
	moveShape.setFillColor(color);
	moveShape.setSize({ 550,100 });

	state = moveslotIDLE;

	categoryTexture.loadFromFile("../Files/Textures/Categories.png");
	typeTexture.loadFromFile("../Files/Textures/Types.png");

	categorySprite.setScale({ 0.6,0.6 });
	typeSprite.setScale({ 0.6,0.6 });

	typeSprite.setTextureRect({ 0, 44 * (20 - 1), 200, 44 });
	categorySprite.setTextureRect({ 0, 44 * 3, 200, 44 });

	font.loadFromFile("../Files/Font/Pokemon.ttf");

	name.setFillColor(sf::Color::Black);
	stats.setFillColor(sf::Color::Black);

	
}

void MoveSlot::setMove(Move _move)
{
	move = _move;
	if (move.getName() != "")
	{
		name.setString(_move.getName());
		typeSprite.setTextureRect({ 0, 44 * (_move.getType() - 1), 200, 44 });
		categorySprite.setTextureRect({ 0, 44 * (_move.getCategory()), 200, 44 });
		stats.setString(std::to_string(_move.getPP()) + "/" + std::to_string(_move.getPower()) + "/" + std::to_string(_move.getAccuracy()));
	}
	else
	{
		clearMove();
	}
}

void MoveSlot::clearMove()
{
	name.setString("");
	typeSprite.setTextureRect({ 0, 44 * (20 - 1), 200, 44 });
	categorySprite.setTextureRect({ 0, 44 * 3, 200, 44 });
	stats.setString("x/x/x");
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

	if (this->moveShape.getGlobalBounds().contains(mousePos) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
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

void MoveSlot::setPosition(float x, float y)
{
	moveShape.setPosition(x, y);
	name.setPosition(x + 5, y + 35);
	typeSprite.setPosition(x + 240, y + 15);
	categorySprite.setPosition(x + 240, y + 54);
	stats.setPosition(x + 390, y + 35);
}

void MoveSlot::draw(sf::RenderWindow* _window)
{
	_window->draw(moveShape);
	
	categorySprite.setTexture(categoryTexture);
	_window->draw(categorySprite);
	
	typeSprite.setTexture(typeTexture);
	_window->draw(typeSprite);
	
	name.setFont(font);
	_window->draw(name);
	
	stats.setFont(font);
	_window->draw(stats);
}

