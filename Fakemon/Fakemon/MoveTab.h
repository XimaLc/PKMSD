#pragma once
#include "Move.h"
#include "tools.h"
#include <SFML/Graphics.hpp>

enum movetabState { movetabIDLE, movetabHOVER, movetabPRESSED };

class MoveTab
{
private:
	Move move;

	sf::Text name;
	sf::Text pp;
	sf::Text power;
	sf::Text accuracy;

	sf::Texture categoryTexture;
	sf::Texture typeTexture;

	sf::Sprite categorySprite;
	sf::Sprite typeSprite;

	sf::RectangleShape shape;
	sf::Color color;

	sf::Font font;

	float timer;
	short unsigned state;
public:
	MoveTab();
	MoveTab(Move _move);

	const bool isPressed() const;

	void setPosition(sf::Vector2f _pos);
	void update(const sf::Vector2f mousePos);
	void draw(sf::RenderWindow* _window);

	inline Move getMove() { return move; }
};

