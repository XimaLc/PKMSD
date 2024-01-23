#pragma once
#include "tools.h"

class Obstacle
{
private:
	sf::Vector2f pos;
	sf::Vector2f size;
	sf::Sprite spr;
	

public:
	Obstacle();
	Obstacle(sf::Vector2f _pos, sf::Vector2f _size, sf::Texture _txt);
	~Obstacle();

	sf::Vector2f getPos() { return pos; }
	sf::Vector2f getSize() { return size; }
	sf::Sprite getSpr() { return spr; }

	void draw(sf::RenderWindow* _window, sf::Texture _txt);
};