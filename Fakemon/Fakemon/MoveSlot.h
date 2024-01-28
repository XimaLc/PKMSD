#pragma once
#include "Move.h"
#include "tools.h"

#include <SFML/Graphics.hpp>

enum moveslotStates {moveslotPRESSED, moveslotHOVER, moveslotIDLE};

class MoveSlot
{
private:
	Move move;

	int index;

	sf::RectangleShape moveShape;

	float timer;
	int state;
	sf::Color color;
public:
	MoveSlot();

	inline void setMove(Move _move) { move = _move; }
	inline void setIndex(int i) { index = i; }

	void update(const sf::Vector2f mousePos);
	void setPosition(int x, int y);
	void draw(sf::RenderWindow* window);
};

