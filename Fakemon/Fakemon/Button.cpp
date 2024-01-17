#include "Button.h"
#include <time.h>
#include "tools.h"

sf::Font Button::font;

Button::Button(std::string path, double x, double y, double width, double height)
{
	this->selectedState = BUTTON_IDLE;
	this->buttonState = BUTTON_IDLE;
	this->shape.setSize(sf::Vector2f(width, height));
	this->shape.setPosition(sf::Vector2f(x, y));
	color = sf::Color::White;

	this->texture.loadFromFile(path);

	this->shape.setTexture(&texture);
}

Button::Button(double x, double y, double width, double height, std::string text, int font_size, bool _modif, bool updateAlpha, bool _locked)
{
	timer1 = 0;
	timer2 = 0;
	this->selectedState = BUTTON_IDLE;
	this->buttonState = BUTTON_IDLE;
	this->shape.setSize(sf::Vector2f(width, height));
	this->shape.setPosition(sf::Vector2f(x, y));
	color = sf::Color::White;
	if (!_locked)
	{
		this->texture.loadFromFile("../Files/Textures/button.png");
	}
	this->shape.setTexture(&texture);
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
	this->text.setOutlineThickness(5);
	this->text.setOutlineColor(sf::Color(11, 75, 137, 255));
	this->text.setPosition
	(
		this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f - this->text.getLetterSpacing(),
		this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().height / 2.f - this->text.getLineSpacing()
	);
	if (updateAlpha)
	{
		this->shape.setFillColor(sf::Color(255, 255, 255, 0));
		this->text.setFillColor(sf::Color(176, 169, 255, 0));
	}
	if (_locked) 
	{
		locked = true;
	}
	if (_modif)
	{
		modif = true;
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
	this->text.setPosition
	(
		this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f - this->text.getLetterSpacing(),
		this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().height / 2.f - this->text.getLineSpacing()
	);
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
		this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f - this->text.getLetterSpacing(), this->text.getPosition().y
		/*this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().height / 1.5f - this->text.getLineSpacing()*/
	);
}
void Button::setTextSize(int data)
{
	this->text.setCharacterSize(data);
}
void Button::update(const sf::Vector2f mousePos)
{
	timer1 += GetDeltaTime();

	if (!locked)
	{
		
		if (this->shape.getGlobalBounds().contains(mousePos) && sf::Mouse::isButtonPressed(sf::Mouse::Left) && timer1 >= 0.1)
		{
			this->text.setFillColor(sf::Color(240, 131, 131, 255));
			color.a = 100;
			this->shape.setFillColor(color);

			if(modif && selectedState != BUTTON_SELECTED)
				selectedState = BUTTON_SELECTED;
			else
				this->buttonState = BUTTON_PRESSED;

			timer1 = 0;
		}
		else if (this->shape.getGlobalBounds().contains(mousePos))
		{
			this->buttonState = BUTTON_HOVER;
			this->text.setFillColor(sf::Color(184, 147, 1, 255));
			color.a = 200;
			this->shape.setFillColor(color);
		}
		else
		{
			this->buttonState = BUTTON_IDLE;
			this->text.setFillColor(sf::Color(255, 204, 1, 255));
			color.a = 255;
			this->shape.setFillColor(color);
		}

		if (selectedState == BUTTON_SELECTED && sf::Mouse::isButtonPressed(sf::Mouse::Left) && !this->shape.getGlobalBounds().contains(mousePos) && timer1 >= 0.1)
		{
			selectedState = BUTTON_IDLE;
			timer1 = 0;
		}

	}
}

void Button::render(sf::RenderWindow* (target))
{
	this->shape.setTexture(&texture);
	target->draw(this->shape);
	target->draw(this->text);
}


std::string Button::getText() const
{
	return this->text.getString();
}

void Button::handleTextInput()
{
	timer2 += GetDeltaTime();
		
	if (selectedState == BUTTON_SELECTED)
	{
		color.a = 100;
		this->shape.setFillColor(color);

		if (timer2 >= 0.1)
		{
			sf::Keyboard::Key pressedKey = sf::Keyboard::Unknown;

			for (int i = sf::Keyboard::A; i <= sf::Keyboard::Numpad9; ++i)
			{
				if (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(i)))
				{
					pressedKey = static_cast<sf::Keyboard::Key>(i);
					break;
				}
			}

			if (pressedKey != sf::Keyboard::Unknown)
			{
				if (pressedKey == sf::Keyboard::BackSpace && inputText.getSize() > 0)
				{
					inputText.erase(inputText.getSize() - 1);
				}
				else if (pressedKey >= sf::Keyboard::A && pressedKey <= sf::Keyboard::Z && inputText.getSize() < 15)
				{
					char unicodeChar = static_cast<char>('a' + (pressedKey - sf::Keyboard::A));
					inputText += unicodeChar;
				}
				else if (pressedKey >= sf::Keyboard::Num0 && pressedKey <= sf::Keyboard::Num9 && inputText.getSize() < 15)
				{
					char unicodeChar = static_cast<char>('0' + (pressedKey - sf::Keyboard::Num0));
					inputText += unicodeChar;
				}
				else if (pressedKey >= sf::Keyboard::Numpad0 && pressedKey <= sf::Keyboard::Numpad9 && inputText.getSize() < 15)
				{
					char unicodeChar = static_cast<char>('0' + (pressedKey - sf::Keyboard::Numpad0));
					inputText += unicodeChar;
				}
				setText(inputText);
			}
			timer2 = 0;
		}	
	}

	
	/*static sf::Clock inputClock;

	if (isTextEntering)
	{
		if (event.type == sf::Event::TextEntered)
		{
			if (inputClock.getElapsedTime().asMilliseconds() > 100)
			{
				inputClock.restart();

				if (event.text.unicode == '\b' && inputText.getSize() > 0)
				{
					inputText.erase(inputText.getSize() - 1);
				}
				else if (event.text.unicode < 128 && inputText.getSize() < 15)
				{
					inputText += event.text.unicode;
				}
				setText(inputText);
			}
		}
	}*/
}
