#include "Obstacle.h"

Obstacle::Obstacle()
{
}

Obstacle::Obstacle(sf::Vector2f _pos, sf::Vector2f _size, sf::Texture _txt) : pos(_pos), size(_size)
{
	spr.setPosition(pos);
	spr.setTexture(_txt);
	spr.setScale({ 3.f, 3.f });
	center = { spr.getGlobalBounds().left + spr.getGlobalBounds().width / 2, spr.getGlobalBounds().top + 70.f };
}

Obstacle::~Obstacle()
{
}

void Obstacle::draw(sf::RenderWindow* _window, sf::Texture _txt)
{
	spr.setTexture(_txt);
	_window->draw(spr);
}
