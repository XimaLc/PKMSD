#pragma once
#include "Pokemon.h"
#include <SFML/Graphics.hpp>

class PokemonTab
{
private:
	Pokemon pokemon;
	sf::Sprite sprite;
	sf::Texture texture;
public:
	PokemonTab();
	PokemonTab(Pokemon _pokemon);

	void setPosition(sf::Vector2f _pos);
	void draw(sf::RenderWindow* _window);
};

