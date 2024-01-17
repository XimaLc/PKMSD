#pragma once
#include <SFML/Graphics.hpp>
#include "DB.h"
#include "PokemonTab.h"
class TeamBuilder
{
private:
	std::vector<Pokemon> pokemons;
	std::vector<PokemonTab> tabs;
public:
	TeamBuilder();
	~TeamBuilder();

	void update(sf::RenderWindow* _window);
	void draw(sf::RenderWindow* _window);
};

