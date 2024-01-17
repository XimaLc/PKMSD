#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>


enum button_states { BUTTON_IDLE = 0, BUTTON_HOVER, BUTTON_PRESSED, BUTTON_SELECTED };

class Button
{
private:
	short unsigned buttonState;
	short unsigned selectedState;
	static sf::Font font;
	sf::Color color;

public:
	sf::RectangleShape shape;
	sf::Texture texture;
	sf::Text text;
	bool locked = false;
	bool modif = false;

	Button(std::string path, double x, double y, double witdh, double height);
	Button(double x, double y, double width, double height, std::string text, int font_size = 25, bool modif = false, bool updateAlpha = false, bool locked = false);
	~Button();

	// Accessors
	const bool isPressed() const;

	// Function
	void setPosition(sf::Vector2f pos);
	void setSize(sf::Vector2f size);
	void setText(std::string string);
	void setTextSize(int data);
	void update(const sf::Vector2f mousePos);
	void render(sf::RenderWindow* (target));


	std::string getText() const;

	void handleTextInput();

	sf::String inputText;
	float timer1;
	float timer2;
};

