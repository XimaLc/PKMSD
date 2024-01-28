#pragma once
#include <SFML/Graphics.hpp>
#include "Pokemon.h"
#include "DB.h"

class PokemonBuilder
{
private:
	Pokemon* pokemon;

	sf::Texture* pkmTexture;
	sf::Texture typeTexture;

	sf::Sprite pkmSprite;
	sf::Sprite type1Sprite;
	sf::Sprite type2Sprite;

	sf::RectangleShape shape;

	sf::Font font;
	sf::Text pkmName;

	std::map < std::string, sf::Text> statsTexts;
public:
	PokemonBuilder();

	void changePokemon(Pokemon* _p);
	void draw(sf::RenderWindow * _window);
};

