#pragma once

#include "PokemonTab.h"
#include "Button.h"
#include "Team.h"
#include "TeamSlot.h"
#include "PokemonBuilder.h"
#include "MoveSlot.h"
#include "MoveTab.h"

enum ListTypes { POKEMONS, MOVES };

class TeamBuilder
{
private:
	sf::RectangleShape shape;
	std::vector<Pokemon> pokemons;
	std::vector<PokemonTab> pokemonTabs;

	std::vector<Move> moves;
	std::vector<MoveTab> moveTabs;

	std::vector<TeamSlot> slots;

	Team team;
	PokemonBuilder pb;

	int pkmStart;
	int moveStart;

	int amount;

	int currentTeamIndex;
	int currentMoveIndex;

	sf::Texture texture;

	std::map<std::string, Button*> boutons;
	
	bool editTeam;

	int listType;
public:
	TeamBuilder();
	~TeamBuilder();

	void loadPokemon();
	void loadMove(Pokemon pokemon);

	void update(sf::RenderWindow* _window);
	void draw(sf::RenderWindow* _window);
};

