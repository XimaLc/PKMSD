#pragma once
#include "Pokemon.h"
#include <SFML/Graphics.hpp>

class PokemonTab
{
private:
	Pokemon pokemon;
	sf::Sprite type1Sprite;
	sf::Sprite type2Sprite;
	sf::Sprite pokemonSprite;
	sf::Text text;


	sf::Texture typeTexture;
	sf::Texture pokemonTexture;
	sf::Font font;
public:
	PokemonTab();
	PokemonTab(Pokemon _pokemon);

	void setPosition(sf::Vector2f _pos);
	void draw(sf::RenderWindow* _window);
};

