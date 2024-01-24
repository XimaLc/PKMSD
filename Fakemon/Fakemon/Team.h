#pragma once
#include "Pokemon.h"
#include <iostream>

class Team
{
private:
	std::string name;
	Pokemon team[6];

public:
	inline void addPokemon(Pokemon _p, int i) { team[i] = _p; }
};

