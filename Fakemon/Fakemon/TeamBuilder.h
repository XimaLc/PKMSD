#pragma once
#include <SFML/Graphics.hpp>
#include "DB.h"
#include "PokemonTab.h"
#include "Button.h"
#include "Team.h"
#include "TeamSlot.h"

class TeamBuilder
{
private:
	sf::RectangleShape shape;
	std::vector<Pokemon> pokemons;
	std::vector<PokemonTab> tabs;
	std::vector<TeamSlot> slot;

	Team team;


	int start;
	int amount;

	int currentTeamIndex;

	sf::Texture texture;

	std::map<std::string, Button*> boutons;
public:
	TeamBuilder();
	~TeamBuilder();

	void update(sf::RenderWindow* _window);
	void draw(sf::RenderWindow* _window);
};

