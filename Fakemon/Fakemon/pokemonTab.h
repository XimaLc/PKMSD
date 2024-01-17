#pragma once
#include "Pokemon.h"
#include <SFML/Graphics.hpp>

enum button_states { BUTTON_IDLE = 0, BUTTON_HOVER, BUTTON_PRESSED, BUTTON_SELECTED };

class PokemonTab
{
private:
	Pokemon pokemon;
	sf::Sprite type1Sprite;
	sf::Sprite type2Sprite;
	sf::Sprite pokemonSprite;
	sf::Text text;
	sf::RectangleShape shape;

	sf::Texture typeTexture;
	sf::Texture pokemonTexture;
	sf::Font font;
public:
	PokemonTab();
	PokemonTab(Pokemon _pokemon);

	const bool isPressed() const;

	void setPosition(sf::Vector2f _pos);
	void update(const sf::Vector2f mousePos);
	void draw(sf::RenderWindow* _window);
};

