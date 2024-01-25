#pragma once
#include "Pokemon.h"
#include "tools.h"
#include "DB.h"

#include <SFML/Graphics.hpp>

enum states { tabIDLE = 0, tabHOVER, tabPRESSED };

class PokemonTab
{
private:
	Pokemon pokemon;

	sf::Sprite type1Sprite;
	sf::Sprite type2Sprite;
	sf::Sprite pokemonSprite;

	sf::Text text;
	sf::Text statsText;
	sf::RectangleShape shape;
	sf::Color color;

	sf::Texture typeTexture;
	sf::Texture pokemonTexture;

	sf::Font font;

	float timer;
	short unsigned buttonState;
	short unsigned selectedState;
public:
	PokemonTab();
	PokemonTab(Pokemon _pokemon);

	const bool isPressed() const;

	void setPosition(sf::Vector2f _pos);
	void update(const sf::Vector2f mousePos);
	void draw(sf::RenderWindow* _window);

	inline Pokemon getPokemon() { return pokemon; }
};

