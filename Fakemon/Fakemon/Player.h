#pragma once
#include "tools.h"
#include "Obstacle.h"

class Player
{
private:
	sf::Sprite spr;
	sf::Texture txt;
	sf::IntRect rect;
	sf::Vector2f pos;
	Direction dir;
	int frameX;
	float animTime;
	bool canMove;

public:
	Player();
	~Player();

	inline sf::Vector2f getPos() { return pos; }

	void playerAnim();
	void update(sf::RenderWindow* _window, sf::View* _view, vector<Obstacle> _obs);
	void draw(sf::RenderWindow* _window);
};

