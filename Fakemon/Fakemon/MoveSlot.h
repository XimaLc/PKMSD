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

	sf::Text name;
	sf::Text stats;

	sf::Texture categoryTexture;
	sf::Texture typeTexture;
	
	sf::Sprite categorySprite;
	sf::Sprite typeSprite;

	sf::Font font;
public:
	MoveSlot();
	MoveSlot(Move _move);

	void setMove(Move _move);
	void clearMove();


	const bool isPressed() const;

	inline void setIndex(int i) { index = i; }
	
	inline int getIndex() { return index; }

	void update(const sf::Vector2f mousePos);
	void setPosition(float x, float y);
	void draw(sf::RenderWindow* window);
};

