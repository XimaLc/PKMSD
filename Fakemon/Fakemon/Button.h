#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>


enum button_states { BUTTON_IDLE = 0, BUTTON_HOVER, BUTTON_PRESSED };

class Button
{
private:
	short unsigned buttonState;
	static sf::Font font;
	sf::Color color;

public:
	sf::RectangleShape shape;
	sf::Texture texture;
	sf::Text text;
	bool locked = false;
	bool modif = false;
	Button(bool modif,double x, double y, double width, double height, std::string text, int font_size = 25, bool updateAlpha = false, bool locked = false);
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

	void handleTextInput(const sf::Event& event);
	bool isTextEntering = false;
	sf::String inputText;
	float timer1;
	float timer2;
};

