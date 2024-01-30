#pragma once
#include "Pokemon.h"
#include <iostream>

class Team
{
private:
	std::string name;
	std::vector<Pokemon> team;

public:
	Team();

	inline void addPokemon(Pokemon _p, int i) { team[i] = _p; }
	inline std::vector<Pokemon> getPokemons() { return team; }
};

