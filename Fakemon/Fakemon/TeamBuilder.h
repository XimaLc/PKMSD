#pragma once
#include <SFML/Graphics.hpp>
#include "DB.h"
#include "PokemonTab.h"
#include "Button.h"

class TeamBuilder
{
private:
	std::vector<Pokemon> pokemons;
	std::vector<PokemonTab> tabs;
	sf::RectangleShape shape;

	sf::Texture texture;

	std::map<std::string, Button*> boutons;
public:
	TeamBuilder();
	~TeamBuilder();

	void update(sf::RenderWindow* _window);
	void draw(sf::RenderWindow* _window);
};

