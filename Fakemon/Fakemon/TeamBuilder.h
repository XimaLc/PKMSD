#pragma once
#include <SFML/Graphics.hpp>
#include "PokemonTab.h"
#include "Button.h"
#include "Team.h"
#include "TeamSlot.h"
#include "PokemonBuilder.h"

class TeamBuilder
{
private:
	sf::RectangleShape shape;
	std::vector<Pokemon> pokemons;
	std::vector<PokemonTab> tabs;
	std::vector<TeamSlot> slots;

	Team team;
	PokemonBuilder pb;

	int start;
	int amount;

	int currentTeamIndex;

	sf::Texture texture;

	std::map<std::string, Button*> boutons;
	
	bool editTeam;
public:
	TeamBuilder();
	~TeamBuilder();

	void loadPokemon();
	void update(sf::RenderWindow* _window);
	void draw(sf::RenderWindow* _window);
};

