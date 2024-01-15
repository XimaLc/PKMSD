#include "Button.h"

sf::Font Button::font;

Button::Button(double x, double y, double width, double height, sf::Color _color, std::string text, int font_size, bool updateAlpha, bool _locked) : color(_color)
{
	this->buttonState = BUTTON_IDLE;
	this->shape.setSize(sf::Vector2f(width, height));
	this->shape.setPosition(sf::Vector2f(x, y));
	if (!_locked)
	{
		_color.a = 255;
		this->shape.setFillColor(_color);
	}

	if (font.getInfo().family.empty())
	{
		if (!font.loadFromFile("../Files/Font/Pokemon.ttf"))
		{
			std::cerr << "Erreur lors du chargement de la police." << std::endl;
		}
	}
	this->text.setFont(font);
	this->text.setString(text);
	this->text.setCharacterSize(font_size);
	this->text.setPosition
	(
		this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f - this->text.getLetterSpacing(),
		this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().height / 1.5f - this->text.getLineSpacing()
	);
	if (updateAlpha)
	{
		this->shape.setFillColor(sf::Color(255, 255, 255, 0));
		this->text.setFillColor(sf::Color(176, 169, 255, 0));
	}
	if (_locked) 
	{
		_color.a = 100;
		this->shape.setFillColor(_color);
		locked = true;
	}
}

Button::~Button()
{

}

const bool Button::isPressed() const
{
	if (this->buttonState == BUTTON_PRESSED || locked)
		return true;
	return false;
}

void Button::setPosition(sf::Vector2f pos)
{
	this->shape.setPosition(pos);
	this->text.setPosition(pos.x + 5.f, pos.y + 10.f);
}

void Button::setSize(sf::Vector2f size)
{
	this->shape.setSize(size);
}

void Button::setText(std::string string)
{
	this->text.setString(string);	
	this->text.setPosition
	(
		this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f - this->text.getLetterSpacing(),
		this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().height / 1.5f - this->text.getLineSpacing()
	);
}
void Button::setTextSize(int data)
{
	this->text.setCharacterSize(data);
}
void Button::update(const sf::Vector2f mousePos)
{
	/* Update the state for hover and pressed */
	// Idle
	if (!locked)
	{
		// Pressed
		if ((this->shape.getGlobalBounds().contains(mousePos) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) || locked)
		{
			this->buttonState = BUTTON_PRESSED;
				this->text.setFillColor(sf::Color(240, 131, 131, 255));
				color.a = 100;
				this->shape.setFillColor(color);
		}
		else if (this->shape.getGlobalBounds().contains(mousePos))
		{
			this->buttonState = BUTTON_HOVER;
				this->text.setFillColor(sf::Color(132, 241, 215, 255));
				color.a = 200;
				this->shape.setFillColor(color);
		}
		else
		{
			this->buttonState = BUTTON_IDLE;
				this->text.setFillColor(sf::Color(176, 169, 255, 255));
				color.a = 255;
				this->shape.setFillColor(color);
		}
	}
}

void Button::render(sf::RenderWindow* (target))
{
	target->draw(this->shape);
	target->draw(this->text);
}