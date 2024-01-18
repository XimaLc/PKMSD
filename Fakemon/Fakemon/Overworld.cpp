#include "Overworld.h"

Overworld::Overworld()
{
	fondTxt.loadFromFile(TexturePath"fond_herbe.png");
	fondSpr.setPosition({ -1920.f, -1080.f });
	fondSpr.setTextureRect({ 0, 0, 3840, 2160 });
	fondSpr.setTexture(fondTxt);
}

Overworld::~Overworld()
{

}

void Overworld::update(sf::RenderWindow* _window)
{
	
}

void Overworld::draw(sf::RenderWindow* _window)
{
	_window->draw(fondSpr);
}
